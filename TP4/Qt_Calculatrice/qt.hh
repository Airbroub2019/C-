#pragma once
#include <QtWidgets>
class calcul
    : public QWidget {
Q_OBJECT
public:
    calcul();
public slots:
    void oncliccalculer();
private:

    QLineEdit * _operande1;
    QLineEdit * _operande2;
    QComboBox * _operator;
    QLabel * _resultat;
    QPushButton * _calculer;
    QPushButton * _quitter;

};
