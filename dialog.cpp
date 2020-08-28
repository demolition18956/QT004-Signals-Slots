#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // QT 4
    QObject::connect(ui->numSlider, SIGNAL(valueChanged(int)), ui->numLabel, SLOT(setNum(int)));
    //               sending        signal function            recieving     slot function
}

Dialog::~Dialog()
{
    delete ui;
}
