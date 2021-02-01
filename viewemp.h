#ifndef VIEWEMP_H
#define VIEWEMP_H

#include <QWidget>

namespace Ui {
class Viewemp;
}

class Viewemp : public QWidget
{
    Q_OBJECT

public:
    explicit Viewemp(QWidget *parent = nullptr);
    ~Viewemp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Viewemp *ui;
};

#endif // VIEWEMP_H
