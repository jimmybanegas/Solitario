#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include "carta.h"
#include "nodo.h"

class Label : public QLabel
{
    Q_OBJECT
public:
    Nodo *nodo;
    explicit Label(QWidget *parent = 0);

signals:

public slots:

};

#endif // LABEL_H
