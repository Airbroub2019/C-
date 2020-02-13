#include "qt.hh"
#include <iostream>

calcul::calcul()
    :QWidget() {
    resize(450,50);
    _operande1 = new QLineEdit("", this);
    _operande2 = new QLineEdit("", this);
    _operator = new QComboBox(this);
    _resultat = new QLabel("",this);
    _calculer = new QPushButton("=", this);
    _quitter = new QPushButton("Quitter", this);

    _operator ->addItem("+");
    _operator ->addItem("-");
    _operator ->addItem("*");
    _operator ->addItem("/");
    _operande1 -> setGeometry(10,10,70,30);
    _operande2 -> setGeometry(150,10,70,30);
    _operator -> setGeometry(90,10,50,30);
    _calculer -> setGeometry(230,10,50,30);
    _resultat -> setGeometry(290,10,50,30);
    _quitter -> setGeometry(350,10,70,30);

    connect(_quitter, &QPushButton::clicked, this, &calcul::close);
    connect(_calculer, &QPushButton::clicked, this, &calcul::oncliccalculer);

    connect(_operande1 , &QLineEdit::textChanged , this , &calcul::oncliccalculer);
    connect(_operande2 , &QLineEdit::textChanged , this , &calcul::oncliccalculer);
    connect(_operator , &QComboBox::currentTextChanged , this , &calcul::oncliccalculer);

}

void calcul::oncliccalculer() {
    float f1(0) , f2(0);
    auto v1(_operande1->text().toStdString());
    if (!v1.empty())
        f1 = std::stof(v1);
    auto v2(_operande2->text().toStdString());
    if (!v2.empty())
        f2 = std::stof(v2);
    std::cout << f1 << " " << f2 << std::endl;
    auto op(_operator->currentText().toStdString());
    float resultat;
    switch (_operator->currentText().toStdString()[0]) {
        case '+': resultat = f1+f2; break;
        case '-': resultat = f1-f2; break;
        case '*': resultat = f1*f2; break;
        case '/': resultat = f1/f2; break;

    }
    std::cout << resultat;
    _resultat->setText(QString::fromStdString(std::to_string(resultat)));

}
