#include <QStandardItemModel>
#include "widget.h"
#include "ui_widget.h"
#include "doublespinboxdelegate.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QStringLiteral("TeElectricResistanceCalculator"));
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    m_rbGroup = new QButtonGroup(this);
    m_rbGroup->addButton(ui->rbtnSeries);
    m_rbGroup->addButton(ui->rbtnParallel);
    ui->rbtnSeries->setChecked(true);
    m_model = new QStandardItemModel(this);
    m_model->setColumnCount(1);
    ui->tableView->setModel(m_model);
    ui->tableView->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->spinnerNumberOfResistances->setMinimum(0);
    ui->spinnerNumberOfResistances->setMaximum(INT_MAX);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_spinnerNumberOfResistances_valueChanged(int arg1)
{
    m_model->setRowCount(arg1);
}

void Widget::on_btnCalculate_clicked()
{
    const int numRes = m_model->rowCount();
    if(numRes == 0)
    {
        return;
    }
    double res = 0.0;
    for(int row = 0; row < numRes; ++row)
    {
        res += (m_conType == ConnectionType::Series) ? getValueAt(row, 0) :
               1 / getValueAt(row, 0);
    }
    res = (m_conType == ConnectionType::Series) ? res : 1 / res;
    ui->txtResult->setText(QString::number(res, 'f', PRECISION));
}

double Widget::getValueAt(int row, int col)
{
   auto pItem = m_model->item(row, col);
   return (pItem == nullptr)? 0.0 : pItem->text().toDouble();
}

void Widget::on_rbtnSeries_clicked(bool checked)
{
    if(checked) m_conType = ConnectionType::Series;
}

void Widget::on_rbtnParallel_clicked(bool checked)
{
    if(checked) m_conType = ConnectionType::Parallel;
}
