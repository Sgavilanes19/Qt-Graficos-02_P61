#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked(bool checked);

    void on_in_Nota_1_valueChanged(int arg1);

    void on_in_Nota_2_valueChanged(int arg1);

    void on_in_Nota_3_valueChanged(int arg1);


private:
    Ui::Principal *ui;
    QPixmap m_lienzo;
    int m_nota_1;
    int m_nota_2;
    int m_nota_3;
    void dibujar();
};
#endif // PRINCIPAL_H
