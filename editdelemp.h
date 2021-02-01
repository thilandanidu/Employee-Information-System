#ifndef EDITDELEMP_H
#define EDITDELEMP_H

#include <QWidget>

namespace Ui {
class Editdelemp;
}

class Editdelemp : public QWidget
{
    Q_OBJECT

public:
    explicit Editdelemp(QWidget *parent = nullptr);
    ~Editdelemp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_clear_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Editdelemp *ui;
};

#endif // EDITDELEMP_H
