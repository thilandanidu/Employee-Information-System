#ifndef ADDEMP_H
#define ADDEMP_H

#include <QWidget>

namespace Ui {
class Addemp;
}

class Addemp : public QWidget
{
    Q_OBJECT

public:
    explicit Addemp(QWidget *parent = nullptr);
    ~Addemp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_clear_clicked();

private:
    Ui::Addemp *ui;
};

#endif // ADDEMP_H
