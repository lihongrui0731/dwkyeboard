#include <qmlinputcontroller.h>
#include <KeyboardGlobal.h>
#include <QDebug>
#include <QQmlEngine>
#include <inputcontext.h>
#include <platforminputcontext.h>

namespace QtVirtualKeyboard {

const int line1Value[QmlInputController::ViewMask][11] = {
    {Qt::Key_Q, Qt::Key_W, Qt::Key_E, Qt::Key_R, Qt::Key_T, Qt::Key_Y, Qt::Key_U, Qt::Key_I, Qt::Key_O, Qt::Key_P, Qt::Key_Backspace},
    {Qt::Key_1, Qt::Key_2, Qt::Key_3, Qt::Key_4, Qt::Key_5, Qt::Key_6, Qt::Key_7, Qt::Key_8, Qt::Key_9, Qt::Key_0, Qt::Key_Backspace},
    {Qt::Key_1, Qt::Key_2, Qt::Key_3, Qt::Key_4, Qt::Key_5, Qt::Key_6, Qt::Key_7, Qt::Key_8, Qt::Key_9, Qt::Key_0, Qt::Key_Backspace}
};
const int line2Value[QmlInputController::ViewMask][10] = {
    {Qt::Key_A, Qt::Key_S, Qt::Key_D, Qt::Key_F, Qt::Key_G, Qt::Key_H, Qt::Key_J, Qt::Key_K, Qt::Key_L, Qt::Key_Enter},
    {Qt::Key_Plus, Qt::Key_Minus, Qt::Key_division, Qt::Key_multiply, Qt::Key_Asterisk, Qt::Key_Equal, Qt::Key_Underscore, Qt::Key_Semicolon, Qt::Key_Colon, Qt::Key_Enter},
    {Qt::Key_QuoteLeft, Qt::Key_AsciiTilde, Qt::Key_Exclam, Qt::Key_At, Qt::Key_NumberSign, Qt::Key_Dollar, Qt::Key_Percent, Qt::Key_AsciiCircum, Qt::Key_Ampersand, Qt::Key_Enter}
};
const int line3Value[QmlInputController::ViewMask][11] = {
    {Qt::Key_Shift, Qt::Key_Z, Qt::Key_X, Qt::Key_C, Qt::Key_V, Qt::Key_B, Qt::Key_N, Qt::Key_M, Qt::Key_Comma, Qt::Key_Period, Qt::Key_Shift},
    {Key_Pager, Qt::Key_Apostrophe, Key_ApostropheRight, Qt::Key_QuoteDbl, Key_QuoteDblRight, Qt::Key_Comma, 	Qt::Key_Period, Qt::Key_Slash, Qt::Key_Bar, Qt::Key_Backslash, Key_Pager},
    {Key_Pager, Qt::Key_ParenLeft, Qt::Key_ParenRight, Qt::Key_BracketLeft, Qt::Key_BracketRight, Qt::Key_BraceLeft, Qt::Key_BraceRight, Qt::Key_Less, Qt::Key_Greater, Qt::Key_Question, Key_Pager}
};
const int line4Value[QmlInputController::ViewMask][6] = {
    {Key_SwitchNumber, Key_SwitchLanguage, Qt::Key_Space, Qt::Key_Question, Key_Other, Key_Exit},
    {Key_SwitchABC, Key_SwitchLanguage, Qt::Key_Space, Qt::Key_Period, Key_Other, Key_Exit},
    {Key_SwitchABC, Key_SwitchLanguage, Qt::Key_Space, Qt::Key_Period, Key_Other, Key_Exit}
};

static QmlInputController *s_instance = nullptr;

QmlInputController *QmlInputController::instance()
{
    if (!s_instance) {
        s_instance = new QmlInputController();
        // Ensure it is not deleted by the QML engine
        QQmlEngine::setObjectOwnership(s_instance, QQmlEngine::CppOwnership);
        // Ensure globals are initialized
        GlobalInit();
    }
    return s_instance;
}

void QmlInputController::registerQmlType()
{
    qmlRegisterSingletonType<QmlInputController>("DWKeyboard", 1, 0, "InputController",
        [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject * {
            Q_UNUSED(engine)
            Q_UNUSED(scriptEngine)
            return QmlInputController::instance();
        });
}

QmlInputController::QmlInputController(QObject *parent)
    : QObject(parent), m_ViewMode(ViewABC), main_object(nullptr)
{
}

void QmlInputController::onPreeditTextChanged()
{
    emit preeditTextChanged();
}

QmlInputController::~QmlInputController()
{
}

void QmlInputController::setMainObject(QObject *main)
{
    main_object = main;
    if (main_object && main_object->parent()) {
        connect(this, SIGNAL(virtualKeyPress(Qt::Key, const QString &, Qt::KeyboardModifiers, bool)),
                main_object->parent(), SLOT(virtualKeyPress(Qt::Key, const QString &, Qt::KeyboardModifiers, bool)));
        connect(this, SIGNAL(virtualKeyRelease(Qt::Key, const QString &, Qt::KeyboardModifiers)),
                main_object->parent(), SLOT(virtualKeyRelease(Qt::Key, const QString &, Qt::KeyboardModifiers)));
    }
}

void QmlInputController::emitLayoutChanged()
{
    emit layoutChanged();
}

int QmlInputController::candidateCount() const
{
    return m_candidates.size();
}

QString QmlInputController::preeditText() const
{
    if (InputContextBase) {
        return InputContextBase->preeditText();
    }
    return QString();
}

QString QmlInputController::candidateAt(int index) const
{
    if (index >= 0 && index < m_candidates.size())
        return m_candidates.at(index);
    return QString();
}

void QmlInputController::updateCandidates()
{
    m_candidates.clear();
    if (InputEngineBase && InputEngineBase->inputMethod() && InputEngineBase->inputMode() == InputEngine::Pinyin)
    {
        int nCount = InputEngineBase->inputMethod()->selectionListItemCount(SelectionListModel::WordCandidateList);
        for (int i = 0; i < nCount; i++)
        {
            QVariant value = InputEngineBase->inputMethod()->selectionListData(SelectionListModel::WordCandidateList,
                i, SelectionListModel::DisplayRole);
            m_candidates.append(value.toString());
        }
    }
    emit candidatesChanged();
}

void QmlInputController::selectCandidate(int index)
{
    if (index >= 0 && index < m_candidates.size() && InputEngineBase && InputEngineBase->wordCandidateListModel())
    {
        InputEngineBase->wordCandidateListModel()->selectItem(index);
        updateCandidates();
    }
}

int QmlInputController::keyCount(int row) const
{
    switch (row) {
    case 0: return 11;
    case 1: return 10;
    case 2: return 11;
    case 3: return 6;
    default: return 0;
    }
}

int QmlInputController::getKeyValue(int row, int index) const
{
    switch (row) {
    case 0: return line1Value[m_ViewMode][index];
    case 1: return line2Value[m_ViewMode][index];
    case 2: return line3Value[m_ViewMode][index];
    case 3: return line4Value[m_ViewMode][index];
    default: return 0;
    }
}

qreal QmlInputController::keyWidthRatio(int row, int index) const
{
    if (row == 1 && index == 9) return 1.5; // Enter key is wider
    if (row == 3) {
        switch (index) {
        case 0: return 1.5;
        case 1: return 1.0;
        case 2: return 5.5; // Space bar
        case 3: return 1.0;
        case 4: return 1.0;
        case 5: return 1.5;
        }
    }
    return 1.0;
}

QString QmlInputController::keyIcon(int row, int index) const
{
    int key = getKeyValue(row, index);
    bool shift = false;
    bool capsLock = false;

    if (InputContextBase)
    {
        shift = InputContextBase->shift();
        capsLock = InputContextBase->capsLock();
    }

    switch (key)
    {
    case Qt::Key_Backspace:
        return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/backspace-868482.svg";
    case Qt::Key_Enter:
        return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/enter-868482.svg";
    case Key_Exit:
        return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/hidekeyboard-868482.svg";
    case Key_SwitchLanguage:
        return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/globe-868482.svg";
    case Qt::Key_Shift:
        if (capsLock)
            return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/shift-c5d6b6.svg";
        else if (shift)
            return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/shift-80c342.svg";
        else
            return "qrc:/QtQuick/VirtualKeyboard/content/styles/default/images/shift-868482.svg";
    }
    return "";
}

QString QmlInputController::keyText(int row, int index) const
{
    int key = getKeyValue(row, index);
    InputEngine::InputMode mode = InputEngine::Latin;
    bool shift = false;
    bool capsLock = false;

    if (InputContextBase)
    {
        mode = InputEngineBase->inputMode();
        shift = InputContextBase->shift();
        capsLock = InputContextBase->capsLock();
    }

    if (keyIcon(row, index) != "")
        return "";

    return GetShowText(key, shift, capsLock, mode);
}

void QmlInputController::keyPress(int row, int index)
{
    if (InputContextBase == NULL || InputEngineBase == NULL)
        return;

    int key = getKeyValue(row, index);
    InputEngine::InputMode mode = InputEngineBase->inputMode();
    bool shift = InputContextBase->shift();
    bool capsLock = InputContextBase->capsLock();
    QString strText = GetValueText(key, shift, capsLock, mode);

    switch (key)
    {
    case Qt::Key_1: case Qt::Key_2: case Qt::Key_3: case Qt::Key_4: case Qt::Key_5: case Qt::Key_6: case Qt::Key_7: case Qt::Key_8:
    case Qt::Key_9: case Qt::Key_0:
    case Qt::Key_A: case Qt::Key_B: case Qt::Key_C: case Qt::Key_D: case Qt::Key_E: case Qt::Key_F: case Qt::Key_G: case Qt::Key_H:
    case Qt::Key_I: case Qt::Key_J: case Qt::Key_K: case Qt::Key_L: case Qt::Key_M: case Qt::Key_N: case Qt::Key_O: case Qt::Key_P:
    case Qt::Key_Q: case Qt::Key_R: case Qt::Key_S: case Qt::Key_T: case Qt::Key_U: case Qt::Key_V: case Qt::Key_W: case Qt::Key_X:
    case Qt::Key_Y: case Qt::Key_Z: case Qt::Key_Space: case Qt::Key_Backspace: case Qt::Key_Enter: case Key_Other:
    case Qt::Key_QuoteLeft: case Qt::Key_AsciiTilde: case Qt::Key_Exclam: case Qt::Key_At: case Qt::Key_NumberSign: case Qt::Key_Dollar:
    case Qt::Key_Percent: case Qt::Key_AsciiCircum: case Qt::Key_Ampersand: case Qt::Key_Asterisk: case Qt::Key_Equal: case Qt::Key_Underscore:
    case Qt::Key_Semicolon: case Qt::Key_Colon: case Qt::Key_Comma: case Qt::Key_Period: case Qt::Key_Slash: case Qt::Key_Bar:
    case Qt::Key_Backslash: case Qt::Key_Question:
    case Qt::Key_Plus: case Qt::Key_Minus: case Qt::Key_division: case Qt::Key_multiply:
    case Qt::Key_ParenLeft: case Qt::Key_ParenRight: case Qt::Key_BracketLeft: case Qt::Key_BracketRight: case Qt::Key_BraceLeft: case Qt::Key_BraceRight:
    case Qt::Key_Less: case Qt::Key_Greater: case Qt::Key_Apostrophe: case Key_ApostropheRight: case Qt::Key_QuoteDbl: case Key_QuoteDblRight:
        emit virtualKeyPress((Qt::Key)key, strText, Qt::NoModifier, false);
        break;
    }
}

void QmlInputController::keyRelease(int row, int index)
{
    if (InputContextBase == NULL || InputEngineBase == NULL)
        return;

    int key = getKeyValue(row, index);
    InputEngine::InputMode mode = InputEngineBase->inputMode();
    bool shift = InputContextBase->shift();
    bool capsLock = InputContextBase->capsLock();
    QString strText = GetValueText(key, shift, capsLock, mode);

    switch (key)
    {
    case Qt::Key_Shift:
        SwitchShiftMode();
        break;
    case Key_SwitchLanguage:
        SwitchInputMode(mode);
        break;
    case Qt::Key_Enter:
        DoQuitView();
        break;
    case Key_Exit:
        DoQuitView();
        break;
    case Key_SwitchABC:
        SwitchViewMode(ViewABC);
        break;
    case Key_SwitchNumber:
        SwitchViewMode(ViewNum0);
        break;
    case Key_Pager:
        switch (m_ViewMode)
        {
        case ViewNum0: SwitchViewMode(ViewNum1); break;
        case ViewNum1: SwitchViewMode(ViewNum0); break;
        default: break;
        }
        break;
    case Qt::Key_1: case Qt::Key_2: case Qt::Key_3: case Qt::Key_4: case Qt::Key_5: case Qt::Key_6: case Qt::Key_7: case Qt::Key_8:
    case Qt::Key_9: case Qt::Key_0:
    case Qt::Key_A: case Qt::Key_B: case Qt::Key_C: case Qt::Key_D: case Qt::Key_E: case Qt::Key_F: case Qt::Key_G: case Qt::Key_H:
    case Qt::Key_I: case Qt::Key_J: case Qt::Key_K: case Qt::Key_L: case Qt::Key_M: case Qt::Key_N: case Qt::Key_O: case Qt::Key_P:
    case Qt::Key_Q: case Qt::Key_R: case Qt::Key_S: case Qt::Key_T: case Qt::Key_U: case Qt::Key_V: case Qt::Key_W: case Qt::Key_X:
    case Qt::Key_Y: case Qt::Key_Z: case Qt::Key_Space: case Qt::Key_Backspace: case Key_Other:
    case Qt::Key_QuoteLeft: case Qt::Key_AsciiTilde: case Qt::Key_Exclam: case Qt::Key_At: case Qt::Key_NumberSign: case Qt::Key_Dollar:
    case Qt::Key_Percent: case Qt::Key_AsciiCircum: case Qt::Key_Ampersand: case Qt::Key_Asterisk: case Qt::Key_Equal: case Qt::Key_Underscore:
    case Qt::Key_Semicolon: case Qt::Key_Colon: case Qt::Key_Comma: case Qt::Key_Period: case Qt::Key_Slash: case Qt::Key_Bar:
    case Qt::Key_Backslash: case Qt::Key_Question:
    case Qt::Key_Plus: case Qt::Key_Minus: case Qt::Key_division: case Qt::Key_multiply:
    case Qt::Key_ParenLeft: case Qt::Key_ParenRight: case Qt::Key_BracketLeft: case Qt::Key_BracketRight: case Qt::Key_BraceLeft: case Qt::Key_BraceRight:
    case Qt::Key_Less: case Qt::Key_Greater: case Qt::Key_Apostrophe: case Key_ApostropheRight: case Qt::Key_QuoteDbl: case Key_QuoteDblRight:
        emit virtualKeyRelease((Qt::Key)key, strText, Qt::NoModifier);
        updateCandidates();
        ResetShiftStyle(shift, capsLock, mode);
        break;
    }
}

QString QmlInputController::GetShowText(int key, bool bshift, bool bcaplock, InputEngine::InputMode mode) const
{
    bool bUpper = (bshift || bcaplock);

    switch (key)
    {
    case Qt::Key_Space:
        switch (mode)
        {
        case InputEngine::Latin: return QStringLiteral("English");
        case InputEngine::Pinyin: return QStringLiteral("简体中文");
        default: break;
        }
        break;
    case Qt::Key_Ampersand: return QStringLiteral("&&");
    case Qt::Key_Apostrophe: return QStringLiteral("‘");
    case Key_ApostropheRight: return QStringLiteral("’");
    case Qt::Key_QuoteDbl: return QStringLiteral("“");
    case Key_QuoteDblRight: return QStringLiteral("”");
    default: return GetValueText(key, bshift, bUpper, mode);
    }
    return QString("");
}

QString QmlInputController::GetValueText(int key, bool bshift, bool bcaplock, InputEngine::InputMode mode) const
{
    bool bUpper = (bshift || bcaplock);
    bool bEn = (mode == InputEngine::Latin);
    switch (key)
    {
    case Qt::Key_1: return QString("1");
    case Qt::Key_2: return QString("2");
    case Qt::Key_3: return QString("3");
    case Qt::Key_4: return QString("4");
    case Qt::Key_5: return QString("5");
    case Qt::Key_6: return QString("6");
    case Qt::Key_7: return QString("7");
    case Qt::Key_8: return QString("8");
    case Qt::Key_9: return QString("9");
    case Qt::Key_0: return QString("0");
    case Qt::Key_A: return bUpper ? QString("A") : QString("a");
    case Qt::Key_B: return bUpper ? QString("B") : QString("b");
    case Qt::Key_C: return bUpper ? QString("C") : QString("c");
    case Qt::Key_D: return bUpper ? QString("D") : QString("d");
    case Qt::Key_E: return bUpper ? QString("E") : QString("e");
    case Qt::Key_F: return bUpper ? QString("F") : QString("f");
    case Qt::Key_G: return bUpper ? QString("G") : QString("g");
    case Qt::Key_H: return bUpper ? QString("H") : QString("h");
    case Qt::Key_I: return bUpper ? QString("I") : QString("i");
    case Qt::Key_J: return bUpper ? QString("J") : QString("j");
    case Qt::Key_K: return bUpper ? QString("K") : QString("k");
    case Qt::Key_L: return bUpper ? QString("L") : QString("l");
    case Qt::Key_M: return bUpper ? QString("M") : QString("m");
    case Qt::Key_N: return bUpper ? QString("N") : QString("n");
    case Qt::Key_O: return bUpper ? QString("O") : QString("o");
    case Qt::Key_P: return bUpper ? QString("P") : QString("p");
    case Qt::Key_Q: return bUpper ? QString("Q") : QString("q");
    case Qt::Key_R: return bUpper ? QString("R") : QString("r");
    case Qt::Key_S: return bUpper ? QString("S") : QString("s");
    case Qt::Key_T: return bUpper ? QString("T") : QString("t");
    case Qt::Key_U: return bUpper ? QString("U") : QString("u");
    case Qt::Key_V: return bUpper ? QString("V") : QString("v");
    case Qt::Key_W: return bUpper ? QString("W") : QString("w");
    case Qt::Key_X: return bUpper ? QString("X") : QString("x");
    case Qt::Key_Y: return bUpper ? QString("Y") : QString("y");
    case Qt::Key_Z: return bUpper ? QString("Z") : QString("z");
    case Qt::Key_QuoteLeft: return bEn ? QStringLiteral("·") : QStringLiteral("、");
    case Qt::Key_AsciiTilde: return bEn ? QStringLiteral("~") : QStringLiteral("～");
    case Qt::Key_Exclam: return bEn ? QStringLiteral("!") : QStringLiteral("！");
    case Qt::Key_At: return bEn ? QStringLiteral("@") : QStringLiteral("@");
    case Qt::Key_NumberSign: return bEn ? QStringLiteral("#") : QStringLiteral("#");
    case Qt::Key_Dollar: return bEn ? QStringLiteral("$") : QStringLiteral("￥");
    case Qt::Key_Percent: return bEn ? QStringLiteral("%") : QStringLiteral("%");
    case Qt::Key_AsciiCircum: return bEn ? QStringLiteral("^") : QStringLiteral("…");
    case Qt::Key_Ampersand: return bEn ? QStringLiteral("&") : QStringLiteral("&");
    case Qt::Key_Asterisk: return bEn ? QStringLiteral("*") : QStringLiteral("*");
    case Qt::Key_Equal: return bEn ? QStringLiteral("=") : QStringLiteral("=");
    case Qt::Key_Underscore: return bEn ? QStringLiteral("_") : QStringLiteral("—");
    case Qt::Key_Semicolon: return bEn ? QStringLiteral(";") : QStringLiteral("；");
    case Qt::Key_Colon: return bEn ? QStringLiteral(":") : QStringLiteral("：");
    case Qt::Key_Comma: return bEn ? QStringLiteral(",") : QStringLiteral("，");
    case Qt::Key_Period: return bEn ? QStringLiteral(".") : QStringLiteral("。");
    case Qt::Key_Slash: return bEn ? QStringLiteral("/") : QStringLiteral("/");
    case Qt::Key_Bar: return bEn ? QStringLiteral("|") : QStringLiteral("|");
    case Qt::Key_Backslash: return bEn ? QStringLiteral("\\") : QStringLiteral("、");
    case Qt::Key_Question: return bEn ? QStringLiteral("?") : QStringLiteral("？");
    case Qt::Key_Plus: return bEn ? QStringLiteral("+") : QStringLiteral("+");
    case Qt::Key_Minus: return bEn ? QStringLiteral("-") : QStringLiteral("-");
    case Qt::Key_division: return bEn ? QStringLiteral("÷") : QStringLiteral("÷");
    case Qt::Key_multiply: return bEn ? QStringLiteral("×") : QStringLiteral("×");
    case Qt::Key_ParenLeft: return bEn ? QStringLiteral("(") : QStringLiteral("（");
    case Qt::Key_ParenRight: return bEn ? QStringLiteral(")") : QStringLiteral("）");
    case Qt::Key_BracketLeft: return bEn ? QStringLiteral("[") : QStringLiteral("【");
    case Qt::Key_BracketRight: return bEn ? QStringLiteral("]") : QStringLiteral("】");
    case Qt::Key_BraceLeft: return bEn ? QStringLiteral("{") : QStringLiteral("『");
    case Qt::Key_BraceRight: return bEn ? QStringLiteral("}") : QStringLiteral("』");
    case Qt::Key_Less: return bEn ? QStringLiteral("<") : QStringLiteral("《");
    case Qt::Key_Greater: return bEn ? QStringLiteral(">") : QStringLiteral("》");
    case Qt::Key_Apostrophe: return bEn ? QStringLiteral("'") : QStringLiteral("‘");
    case Key_ApostropheRight: return bEn ? QStringLiteral("'") : QStringLiteral("’");
    case Qt::Key_QuoteDbl: return bEn ? QStringLiteral("\"") : QStringLiteral("“");
    case Key_QuoteDblRight: return bEn ? QStringLiteral("\"") : QStringLiteral("”");
    case Key_Pager:
        switch (m_ViewMode)
        {
        case ViewABC: break;
        case ViewNum0: return bEn ? QStringLiteral("↓") : QStringLiteral("↓");
        case ViewNum1: return bEn ? QStringLiteral("↑") : QStringLiteral("↑");
        default: break;
        }
        break;
    case Qt::Key_Backspace: return QStringLiteral("");
    case Qt::Key_Enter: return QStringLiteral("");
    case Qt::Key_Shift: return QStringLiteral("");
    case Qt::Key_Space: return QStringLiteral(" ");
    case Key_SwitchNumber: return QStringLiteral("&&123");
    case Key_SwitchABC: return QStringLiteral("&&ABC");
    case Key_SwitchLanguage: return QStringLiteral("");
    case Key_Other: return QStringLiteral(":-)");
    case Key_Exit: return QStringLiteral("");
    }
    return QString("");
}

bool QmlInputController::SwitchInputMode(InputEngine::InputMode mode)
{
    if (InputEngineBase == NULL || PinyinInputMethodBase == NULL || InputContextBase == NULL || PlainInputMethodBase == NULL)
        return false;

    if (mode == InputEngine::Latin)
    {
        if (!PinyinInputMethodBase->inputModes("zh_CN").contains(InputEngine::Pinyin))
            return false;
        InputContextBase->setLocale("zh_CN");
        InputEngineBase->setInputMethod(PinyinInputMethodBase);
        InputEngineBase->setInputMode(InputEngine::Pinyin);
    }
    else if (mode == InputEngine::Pinyin)
    {
        if (!PlainInputMethodBase->inputModes("en_GB").contains(InputEngine::Latin))
            return false;
        InputContextBase->setLocale("en_GB");
        InputEngineBase->setInputMethod(PlainInputMethodBase);
        InputEngineBase->setInputMode(InputEngine::Latin);
    }
    InputContextBase->setShift(false);
    InputContextBase->setCapsLock(false);

    updateCandidates();
    emit layoutChanged();
    return true;
}

void QmlInputController::SwitchShiftMode()
{
    if (InputContextBase && InputContextBase->shiftHandler())
    {
        InputContextBase->shiftHandler()->toggleShift();
        emit layoutChanged();
    }
}

void QmlInputController::SwitchViewMode(ViewMode mode)
{
    m_ViewMode = mode;
    if (InputContextBase) {
        InputContextBase->setShift(false);
        InputContextBase->setCapsLock(false);
    }
    updateCandidates();
    emit layoutChanged();
}

void QmlInputController::DoQuitView()
{
    if (PlatformInputContextBase){
        PlatformInputContextBase->hideInputPanel();
        if (InputContextBase)
            emit InputContextBase->inputClose();
    }
    emit closeInput();
}

void QmlInputController::ResetShiftStyle(bool bshift, bool bcaplock, InputEngine::InputMode)
{
    if (bshift && !bcaplock && InputContextBase)
    {
        InputContextBase->setShift(false);
        emit layoutChanged();
    }
}

} // namespace QtVirtualKeyboard
