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

    QObject::disconnect(ui->numSlider, &QSlider::valueChanged, ui->numLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    QObject::connect(ui->pushButton,&QPushButton::clicked, this, &Dialog::bar);

    QObject::connect(this, &Dialog::foo, ui->numLabel, &QLabel::clear);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::bar()
{
    ui->numLabel->setText("Hello World");

    QObject::connect(ui->numSlider, &QSlider::valueChanged, ui->numLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));

    if (ui->numSlider->value() == 99){
        emit foo();
    }

}
