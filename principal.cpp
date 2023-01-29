#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(m_lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    m_lienzo.fill(Qt::white); //Se usa eso para darle transparecia al cuadro de dibujo

    QPainter painter(&m_lienzo);

    int x = 30;

    int tam1 = 4*m_nota_1;
    int tam2 = 4*m_nota_2;
    int tam3 = 4*m_nota_3;
    int promedio = 4*((m_nota_1 + m_nota_2 + m_nota_3) / 3);

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::black);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Dibujar primera barra
    painter.drawRect(x+50, (400-tam1+50),100,tam1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);
    //Crear color para la linea
    QColor colorLinea(0,0,0);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Dibujar segunda barra
    painter.drawRect(x+170, (400-tam2+50), 100, tam2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,(400-tam3+50),100,tam3);

    //Cambiar color del pincel
    pincel.setColor(colorLinea);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    //Dibujar linea
    painter.drawLine(x+50, (400-promedio+50), x+390, (400-promedio+50));
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (m_lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}


void Principal::on_in_Nota_1_valueChanged(int arg1)
{
    m_nota_1 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_in_Nota_2_valueChanged(int arg1)
{
    m_nota_2 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}


void Principal::on_in_Nota_3_valueChanged(int arg1)
{
    m_nota_3 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(m_lienzo);
}



