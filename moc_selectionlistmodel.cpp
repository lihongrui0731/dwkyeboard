/****************************************************************************
** Meta object code from reading C++ file 'selectionlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "include/selectionlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectionlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t {
    QByteArrayData data[16];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel_t qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel = {
    {
QT_MOC_LITERAL(0, 0, 37), // "QtVirtualKeyboard::SelectionL..."
QT_MOC_LITERAL(1, 38, 17), // "activeItemChanged"
QT_MOC_LITERAL(2, 56, 0), // ""
QT_MOC_LITERAL(3, 57, 5), // "index"
QT_MOC_LITERAL(4, 63, 12), // "itemSelected"
QT_MOC_LITERAL(5, 76, 20), // "selectionListChanged"
QT_MOC_LITERAL(6, 97, 4), // "type"
QT_MOC_LITERAL(7, 102, 30), // "selectionListActiveItemChanged"
QT_MOC_LITERAL(8, 133, 10), // "selectItem"
QT_MOC_LITERAL(9, 144, 6), // "dataAt"
QT_MOC_LITERAL(10, 151, 4), // "role"
QT_MOC_LITERAL(11, 156, 4), // "Type"
QT_MOC_LITERAL(12, 161, 17), // "WordCandidateList"
QT_MOC_LITERAL(13, 179, 4), // "Role"
QT_MOC_LITERAL(14, 184, 11), // "DisplayRole"
QT_MOC_LITERAL(15, 196, 24) // "WordCompletionLengthRole"

    },
    "QtVirtualKeyboard::SelectionListModel\0"
    "activeItemChanged\0\0index\0itemSelected\0"
    "selectionListChanged\0type\0"
    "selectionListActiveItemChanged\0"
    "selectItem\0dataAt\0role\0Type\0"
    "WordCandidateList\0Role\0DisplayRole\0"
    "WordCompletionLengthRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtVirtualKeyboard__SelectionListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       2,   74, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   55,    2, 0x09 /* Protected */,
       7,    2,   58,    2, 0x09 /* Protected */,

 // methods: name, argc, parameters, tag, flags
       8,    1,   63,    2, 0x02 /* Public */,
       9,    2,   66,    2, 0x02 /* Public */,
       9,    1,   71,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::QVariant, QMetaType::Int, QMetaType::Int,    3,   10,
    QMetaType::QVariant, QMetaType::Int,    3,

 // enums: name, alias, flags, count, data
      11,   11, 0x0,    1,   84,
      13,   13, 0x0,    2,   86,

 // enum data: key, value
      12, uint(QtVirtualKeyboard::SelectionListModel::WordCandidateList),
      14, uint(QtVirtualKeyboard::SelectionListModel::DisplayRole),
      15, uint(QtVirtualKeyboard::SelectionListModel::WordCompletionLengthRole),

       0        // eod
};

void QtVirtualKeyboard::SelectionListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SelectionListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->activeItemChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->itemSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectionListChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selectionListActiveItemChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->selectItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { QVariant _r = _t->dataAt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 6: { QVariant _r = _t->dataAt((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SelectionListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectionListModel::activeItemChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SelectionListModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SelectionListModel::itemSelected)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtVirtualKeyboard::SelectionListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel.data,
    qt_meta_data_QtVirtualKeyboard__SelectionListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtVirtualKeyboard::SelectionListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtVirtualKeyboard::SelectionListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtVirtualKeyboard__SelectionListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int QtVirtualKeyboard::SelectionListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QtVirtualKeyboard::SelectionListModel::activeItemChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtVirtualKeyboard::SelectionListModel::itemSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
