#include "doublespinboxdelegate.h"
#include <QDoubleSpinBox>

DoubleSpinBoxDelegate::DoubleSpinBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

QWidget *DoubleSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    auto spinner = new QDoubleSpinBox(parent);
    spinner->setMinimum(0.0);
    spinner->setMaximum(999999999.999);
    spinner->setSingleStep(0.1);
    spinner->setDecimals(4);
    return spinner;
}

void DoubleSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    auto spinner = static_cast<QDoubleSpinBox *>(editor);
    spinner->setValue(index.data().toDouble());

}

void DoubleSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto spinner = static_cast<QDoubleSpinBox*>(editor);
    model->setData(index, spinner->value());
}

void DoubleSpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}
