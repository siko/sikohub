/*
 * =====================================================================================
 *
 *       Filename:  communicate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:58:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef COMMUNICATE_H
#define COMMUNICATE_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class Communicate : public QWidget
{
  Q_OBJECT

  public:
    Communicate(QWidget *parent = 0);


  private slots:
    void OnPlus();
    void OnMinus();

  private:
    QLabel *label;

};

#endif

