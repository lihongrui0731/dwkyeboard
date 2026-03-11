#ifndef QMLINPUTCONTROLLER_H
#define QMLINPUTCONTROLLER_H

#include <QObject>
#include <QStringList>
#include <QKeyEvent>
#include <inputengine.h>
#include <dwkeyboard_global.h>

namespace QtVirtualKeyboard {

class DWKEYBOARDSHARED_EXPORT QmlInputController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int candidateCount READ candidateCount NOTIFY candidatesChanged)
    Q_PROPERTY(QString preeditText READ preeditText NOTIFY preeditTextChanged)

public:
    explicit QmlInputController(QObject *parent = nullptr);
    ~QmlInputController();

    static QmlInputController *instance();
    static void registerQmlType();

    enum ViewMode
    {
        ViewABC = 0,
        ViewNum0 = 1,
        ViewNum1 = 2,
        ViewMask = 3
    };

    Q_INVOKABLE int candidateCount() const;
    Q_INVOKABLE QString candidateAt(int index) const;
    Q_INVOKABLE void updateCandidates();

    Q_INVOKABLE QString preeditText() const;
    Q_INVOKABLE void selectCandidate(int index);

    Q_INVOKABLE void emitLayoutChanged();

    Q_INVOKABLE int keyCount(int row) const;
    Q_INVOKABLE qreal keyWidthRatio(int row, int index) const;
    Q_INVOKABLE QString keyIcon(int row, int index) const;
    Q_INVOKABLE QString keyText(int row, int index) const;

    Q_INVOKABLE void keyPress(int row, int index);
    Q_INVOKABLE void keyRelease(int row, int index);

    void setMainObject(QObject *main);

signals:
    void candidatesChanged();
    void virtualKeyPress(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers, bool isAutoRepeat);
    void virtualKeyRelease(Qt::Key key, const QString &text, Qt::KeyboardModifiers modifiers);
    void closeInput();
    void layoutChanged();
    void preeditTextChanged();
    void commitText(const QString &text);

private slots:
    void onPreeditTextChanged();

private:
    QString GetShowText(int key, bool bshift, bool bcaplock, InputEngine::InputMode mode) const;
    QString GetValueText(int key, bool bshift, bool bcaplock, InputEngine::InputMode mode) const;
    bool SwitchInputMode(InputEngine::InputMode mode);
    void SwitchShiftMode();
    void SwitchViewMode(ViewMode mode);
    void DoQuitView();
    void ResetShiftStyle(bool bshift, bool bcaplock, InputEngine::InputMode mode);

    ViewMode m_ViewMode;
    QObject* main_object;
    QStringList m_candidates;
    int getKeyValue(int row, int index) const;
};

} // namespace QtVirtualKeyboard

#endif // QMLINPUTCONTROLLER_H
