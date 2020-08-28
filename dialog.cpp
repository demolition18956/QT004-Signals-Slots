#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    // QT 4
//    QObject::connect(ui->numSlider, SIGNAL(valueChanged(int)), ui->numLabel, SLOT(setNum(int)));
//    //               sending        signal function            recieving     slot function

    // QT 5
    QObject::connect(ui->numSlider, &QSlider::valueChanged, ui->numLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    //               sending        signal function         recieving     slot function (static cast used to
    //                                                                                   differentiate btwn int and
    //                                                                                   float overloads)
}

Dialog::~Dialog()
{
    delete ui;
}
