/****************************************************************************
** Meta object code from reading C++ file 'inputcontext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/inputcontext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputcontext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__InputContext_t {
    QByteArrayData data[66];
    char stringdata0[1112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__InputContext_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__InputContext_t qt_meta_stringdata_QtVirtualKeyboard__InputContext = {
    {
QT_MOC_LITERAL(0, 0, 31), // "QtVirtualKeyboard::InputContext"
QT_MOC_LITERAL(1, 32, 12), // "focusChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 18), // "focusEditorChanged"
QT_MOC_LITERAL(4, 65, 18), // "preeditTextChanged"
QT_MOC_LITERAL(5, 84, 23), // "inputMethodHintsChanged"
QT_MOC_LITERAL(6, 108, 22), // "surroundingTextChanged"
QT_MOC_LITERAL(7, 131, 19), // "selectedTextChanged"
QT_MOC_LITERAL(8, 151, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(9, 173, 22), // "cursorRectangleChanged"
QT_MOC_LITERAL(10, 196, 12), // "shiftChanged"
QT_MOC_LITERAL(11, 209, 15), // "capsLockChanged"
QT_MOC_LITERAL(12, 225, 24), // "keyboardRectangleChanged"
QT_MOC_LITERAL(13, 250, 23), // "previewRectangleChanged"
QT_MOC_LITERAL(14, 274, 21), // "previewVisibleChanged"
QT_MOC_LITERAL(15, 296, 16), // "animatingChanged"
QT_MOC_LITERAL(16, 313, 13), // "localeChanged"
QT_MOC_LITERAL(17, 327, 16), // "inputItemChanged"
QT_MOC_LITERAL(18, 344, 30), // "selectionControlVisibleChanged"
QT_MOC_LITERAL(19, 375, 20), // "navigationKeyPressed"
QT_MOC_LITERAL(20, 396, 3), // "key"
QT_MOC_LITERAL(21, 400, 12), // "isAutoRepeat"
QT_MOC_LITERAL(22, 413, 21), // "navigationKeyReleased"
QT_MOC_LITERAL(23, 435, 35), // "anchorRectIntersectsClipRectC..."
QT_MOC_LITERAL(24, 471, 35), // "cursorRectIntersectsClipRectC..."
QT_MOC_LITERAL(25, 507, 10), // "inputClose"
QT_MOC_LITERAL(26, 518, 7), // "inputOK"
QT_MOC_LITERAL(27, 526, 18), // "onInputItemChanged"
QT_MOC_LITERAL(28, 545, 22), // "updateAvailableLocales"
QT_MOC_LITERAL(29, 568, 16), // "availableLocales"
QT_MOC_LITERAL(30, 585, 14), // "hideInputPanel"
QT_MOC_LITERAL(31, 600, 12), // "sendKeyClick"
QT_MOC_LITERAL(32, 613, 4), // "text"
QT_MOC_LITERAL(33, 618, 9), // "modifiers"
QT_MOC_LITERAL(34, 628, 6), // "commit"
QT_MOC_LITERAL(35, 635, 11), // "replaceFrom"
QT_MOC_LITERAL(36, 647, 13), // "replaceLength"
QT_MOC_LITERAL(37, 661, 5), // "clear"
QT_MOC_LITERAL(38, 667, 10), // "fileExists"
QT_MOC_LITERAL(39, 678, 7), // "fileUrl"
QT_MOC_LITERAL(40, 686, 25), // "setSelectionOnFocusObject"
QT_MOC_LITERAL(41, 712, 9), // "anchorPos"
QT_MOC_LITERAL(42, 722, 9), // "cursorPos"
QT_MOC_LITERAL(43, 732, 5), // "focus"
QT_MOC_LITERAL(44, 738, 5), // "shift"
QT_MOC_LITERAL(45, 744, 8), // "capsLock"
QT_MOC_LITERAL(46, 753, 14), // "cursorPosition"
QT_MOC_LITERAL(47, 768, 16), // "inputMethodHints"
QT_MOC_LITERAL(48, 785, 20), // "Qt::InputMethodHints"
QT_MOC_LITERAL(49, 806, 11), // "preeditText"
QT_MOC_LITERAL(50, 818, 15), // "surroundingText"
QT_MOC_LITERAL(51, 834, 12), // "selectedText"
QT_MOC_LITERAL(52, 847, 15), // "cursorRectangle"
QT_MOC_LITERAL(53, 863, 17), // "keyboardRectangle"
QT_MOC_LITERAL(54, 881, 16), // "previewRectangle"
QT_MOC_LITERAL(55, 898, 14), // "previewVisible"
QT_MOC_LITERAL(56, 913, 9), // "animating"
QT_MOC_LITERAL(57, 923, 6), // "locale"
QT_MOC_LITERAL(58, 930, 9), // "inputItem"
QT_MOC_LITERAL(59, 940, 12), // "shiftHandler"
QT_MOC_LITERAL(60, 953, 32), // "QtVirtualKeyboard::ShiftHandler*"
QT_MOC_LITERAL(61, 986, 11), // "inputEngine"
QT_MOC_LITERAL(62, 998, 31), // "QtVirtualKeyboard::InputEngine*"
QT_MOC_LITERAL(63, 1030, 23), // "selectionControlVisible"
QT_MOC_LITERAL(64, 1054, 28), // "anchorRectIntersectsClipRect"
QT_MOC_LITERAL(65, 1083, 28) // "cursorRectIntersectsClipRect"

    },
    "QtVirtualKeyboard::InputContext\0"
    "focusChanged\0\0focusEditorChanged\0"
    "preeditTextChanged\0inputMethodHintsChanged\0"
    "surroundingTextChanged\0selectedTextChanged\0"
    "cursorPositionChanged\0cursorRectangleChanged\0"
    "shiftChanged\0capsLockChanged\0"
    "keyboardRectangleChanged\0"
    "previewRectangleChanged\0previewVisibleChanged\0"
    "animatingChanged\0localeChanged\0"
    "inputItemChanged\0selectionControlVisibleChanged\0"
    "navigationKeyPressed\0key\0isAutoRepeat\0"
    "navigationKeyReleased\0"
    "anchorRectIntersectsClipRectChanged\0"
    "cursorRectIntersectsClipRectChanged\0"
    "inputClose\0inputOK\0onInputItemChanged\0"
    "updateAvailableLocales\0availableLocales\0"
    "hideInputPanel\0sendKeyClick\0text\0"
    "modifiers\0commit\0replaceFrom\0replaceLength\0"
    "clear\0fileExists\0fileUrl\0"
    "setSelectionOnFocusObject\0anchorPos\0"
    "cursorPos\0focus\0shift\0capsLock\0"
    "cursorPosition\0inputMethodHints\0"
    "Qt::InputMethodHints\0preeditText\0"
    "surroundingText\0selectedText\0"
    "cursorRectangle\0keyboardRectangle\0"
    "previewRectangle\0previewVisible\0"
    "animating\0locale\0inputItem\0shiftHandler\0"
    "QtVirtualKeyboard::ShiftHandler*\0"
    "inputEngine\0QtVirtualKeyboard::InputEngine*\0"
    "selectionControlVisible\0"
    "anchorRectIntersectsClipRect\0"
    "cursorRectIntersectsClipRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__InputContext[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
      20,  262, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    0,  191,    2, 0x06 /* Public */,
       5,    0,  192,    2, 0x06 /* Public */,
       6,    0,  193,    2, 0x06 /* Public */,
       7,    0,  194,    2, 0x06 /* Public */,
       8,    0,  195,    2, 0x06 /* Public */,
       9,    0,  196,    2, 0x06 /* Public */,
      10,    0,  197,    2, 0x06 /* Public */,
      11,    0,  198,    2, 0x06 /* Public */,
      12,    0,  199,    2, 0x06 /* Public */,
      13,    0,  200,    2, 0x06 /* Public */,
      14,    0,  201,    2, 0x06 /* Public */,
      15,    0,  202,    2, 0x06 /* Public */,
      16,    0,  203,    2, 0x06 /* Public */,
      17,    0,  204,    2, 0x06 /* Public */,
      18,    0,  205,    2, 0x06 /* Public */,
      19,    2,  206,    2, 0x06 /* Public */,
      22,    2,  211,    2, 0x06 /* Public */,
      23,    0,  216,    2, 0x06 /* Public */,
      24,    0,  217,    2, 0x06 /* Public */,
      25,    0,  218,    2, 0x06 /* Public */,
      26,    0,  219,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      27,    0,  220,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      28,    1,  221,    2, 0x02 /* Public */,
      30,    0,  224,    2, 0x02 /* Public */,
      31,    3,  225,    2, 0x02 /* Public */,
      31,    2,  232,    2, 0x22 /* Public | MethodCloned */,
      34,    0,  237,    2, 0x02 /* Public */,
      34,    3,  238,    2, 0x02 /* Public */,
      34,    2,  245,    2, 0x22 /* Public | MethodCloned */,
      34,    1,  250,    2, 0x22 /* Public | MethodCloned */,
      37,    0,  253,    2, 0x02 /* Public */,
      38,    1,  254,    2, 0x02 /* Public */,
      40,    2,  257,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QStringList,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,   20,   32,   33,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   20,   32,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   32,   35,   36,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   32,   35,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QUrl,   39,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,   41,   42,

 // properties: name, type, flags
      43, QMetaType::Bool, 0x00495001,
      44, QMetaType::Bool, 0x00495103,
      45, QMetaType::Bool, 0x00495103,
      46, QMetaType::Int, 0x00495001,
      47, 0x80000000 | 48, 0x00495009,
      49, QMetaType::QString, 0x00495103,
      50, QMetaType::QString, 0x00495001,
      51, QMetaType::QString, 0x00495001,
      52, QMetaType::QRectF, 0x00495001,
      53, QMetaType::QRectF, 0x00495103,
      54, QMetaType::QRectF, 0x00495103,
      55, QMetaType::Bool, 0x00495103,
      56, QMetaType::Bool, 0x00495103,
      57, QMetaType::QString, 0x00495103,
      58, QMetaType::QObjectStar, 0x00495001,
      59, 0x80000000 | 60, 0x00095409,
      61, 0x80000000 | 62, 0x00095409,
      63, QMetaType::Bool, 0x00495001,
      64, QMetaType::Bool, 0x00495001,
      65, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       8,
       9,
       6,
       3,
       2,
       4,
       5,
       7,
      10,
      11,
      12,
      13,
      14,
      15,
       0,
       0,
      16,
      19,
      20,

       0        // eod
};

void QtVirtualKeyboard::InputContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InputContext *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->focusChanged(); break;
        case 1: _t->focusEditorChanged(); break;
        case 2: _t->preeditTextChanged(); break;
        case 3: _t->inputMethodHintsChanged(); break;
        case 4: _t->surroundingTextChanged(); break;
        case 5: _t->selectedTextChanged(); break;
        case 6: _t->cursorPositionChanged(); break;
        case 7: _t->cursorRectangleChanged(); break;
        case 8: _t->shiftChanged(); break;
        case 9: _t->capsLockChanged(); break;
        case 10: _t->keyboardRectangleChanged(); break;
        case 11: _t->previewRectangleChanged(); break;
        case 12: _t->previewVisibleChanged(); break;
        case 13: _t->animatingChanged(); break;
        case 14: _t->localeChanged(); break;
        case 15: _t->inputItemChanged(); break;
        case 16: _t->selectionControlVisibleChanged(); break;
        case 17: _t->navigationKeyPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->navigationKeyReleased((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->anchorRectIntersectsClipRectChanged(); break;
        case 20: _t->cursorRectIntersectsClipRectChanged(); break;
        case 21: _t->inputClose(); break;
        case 22: _t->inputOK(); break;
        case 23: _t->onInputItemChanged(); break;
        case 24: _t->updateAvailableLocales((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 25: _t->hideInputPanel(); break;
        case 26: _t->sendKeyClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 27: _t->sendKeyClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 28: _t->commit(); break;
        case 29: _t->commit((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 30: _t->commit((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 31: _t->commit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->clear(); break;
        case 33: { bool _r = _t->fileExists((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->setSelectionOnFocusObject((*reinterpret_cast< const QPointF(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::focusChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::focusEditorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::preeditTextChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::inputMethodHintsChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::surroundingTextChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::selectedTextChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::cursorPositionChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::cursorRectangleChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::shiftChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::capsLockChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::keyboardRectangleChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::previewRectangleChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::previewVisibleChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::animatingChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::localeChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::inputItemChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::selectionControlVisibleChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (InputContext::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::navigationKeyPressed)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (InputContext::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::navigationKeyReleased)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::anchorRectIntersectsClipRectChanged)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::cursorRectIntersectsClipRectChanged)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::inputClose)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (InputContext::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputContext::inputOK)) {
                *result = 22;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<InputContext *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->focus(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->shift(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->capsLock(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->cursorPosition(); break;
        case 4: *reinterpret_cast< Qt::InputMethodHints*>(_v) = _t->inputMethodHints(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->preeditText(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->surroundingText(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->selectedText(); break;
        case 8: *reinterpret_cast< QRectF*>(_v) = _t->cursorRectangle(); break;
        case 9: *reinterpret_cast< QRectF*>(_v) = _t->keyboardRectangle(); break;
        case 10: *reinterpret_cast< QRectF*>(_v) = _t->previewRectangle(); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->previewVisible(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->animating(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->locale(); break;
        case 14: *reinterpret_cast< QObject**>(_v) = _t->inputItem(); break;
        case 15: *reinterpret_cast< QtVirtualKeyboard::ShiftHandler**>(_v) = _t->shiftHandler(); break;
        case 16: *reinterpret_cast< QtVirtualKeyboard::InputEngine**>(_v) = _t->inputEngine(); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->selectionControlVisible(); break;
        case 18: *reinterpret_cast< bool*>(_v) = _t->anchorRectIntersectsClipRect(); break;
        case 19: *reinterpret_cast< bool*>(_v) = _t->cursorRectIntersectsClipRect(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<InputContext *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setShift(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setCapsLock(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setPreeditText(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setKeyboardRectangle(*reinterpret_cast< QRectF*>(_v)); break;
        case 10: _t->setPreviewRectangle(*reinterpret_cast< QRectF*>(_v)); break;
        case 11: _t->setPreviewVisible(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setAnimating(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setLocale(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QtVirtualKeyboard::InputContext::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QtVirtualKeyboard__InputContext.data,
    qt_meta_data_QtVirtualKeyboard__InputContext,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtVirtualKeyboard::InputContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::InputContext::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__InputContext.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QtVirtualKeyboard::InputContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 20;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 20;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::InputContext::focusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QtVirtualKeyboard::InputContext::focusEditorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QtVirtualKeyboard::InputContext::preeditTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QtVirtualKeyboard::InputContext::inputMethodHintsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QtVirtualKeyboard::InputContext::surroundingTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QtVirtualKeyboard::InputContext::selectedTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QtVirtualKeyboard::InputContext::cursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QtVirtualKeyboard::InputContext::cursorRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QtVirtualKeyboard::InputContext::shiftChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QtVirtualKeyboard::InputContext::capsLockChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QtVirtualKeyboard::InputContext::keyboardRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QtVirtualKeyboard::InputContext::previewRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QtVirtualKeyboard::InputContext::previewVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QtVirtualKeyboard::InputContext::animatingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void QtVirtualKeyboard::InputContext::localeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void QtVirtualKeyboard::InputContext::inputItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void QtVirtualKeyboard::InputContext::selectionControlVisibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void QtVirtualKeyboard::InputContext::navigationKeyPressed(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QtVirtualKeyboard::InputContext::navigationKeyReleased(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void QtVirtualKeyboard::InputContext::anchorRectIntersectsClipRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void QtVirtualKeyboard::InputContext::cursorRectIntersectsClipRectChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void QtVirtualKeyboard::InputContext::inputClose()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void QtVirtualKeyboard::InputContext::inputOK()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
