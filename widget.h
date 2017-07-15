#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>

class QStandardItemModel;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_spinnerNumberOfResistances_valueChanged(int arg1);
    void on_btnCalculate_clicked();
    double getValueAt(int row, int col);
    void on_rbtnSeries_clicked(bool checked);
    void on_rbtnParallel_clicked(bool checked);

private:
    static const int PRECISION = 4;
    static const int WINDOW_WIDTH = 350, WINDOW_HEIGHT = 340;
    Ui::Widget *ui;
    QButtonGroup *m_rbGroup;
    QStandardItemModel *m_model;
    enum class ConnectionType {Series, Parallel};
    ConnectionType m_conType = ConnectionType::Series;
};

#endif // WIDGET_H
