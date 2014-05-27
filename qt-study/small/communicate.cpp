/*
 * =====================================================================================
 *
 *       Filename:  communicate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:59:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "communicate.h"

Communicate::Communicate(QWidget *parent)
    : QWidget(parent)
{
  QPushButton *plus = new QPushButton("+", this);
  plus->setGeometry(50, 40, 75, 30);

  QPushButton *minus = new QPushButton("-", this);
  minus->setGeometry(50, 100, 75, 30);

  label = new QLabel("0", this);
  label->setGeometry(190, 80, 20, 30);

  connect(plus, SIGNAL(clicked()), this, SLOT(OnPlus()));
  connect(minus, SIGNAL(clicked()), this, SLOT(OnMinus()));
}

void Communicate::OnPlus()
{
  int val = label->text().toInt();
  val++;
  label->setText(QString::number(val));
}

void Communicate::OnMinus()
{
  int val = label->text().toInt();
  val--;
  label->setText(QString::number(val));
}

