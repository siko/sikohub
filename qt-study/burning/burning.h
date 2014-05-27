/*
 * =====================================================================================
 *
 *       Filename:  burning.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/28/2014 12:18:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once

#include <QWidget>
#include <QSlider>
#include <QFrame>
#include "widget.h"

class Burning : public QFrame
{
  Q_OBJECT  

  public:
    Burning(QWidget *parent = 0);
    int getCurrentWidth();
    
  public slots:
    void valueChanged(int);
    
  private:
    QSlider *slider;
    Widget *widget;
    int cur_width;
    
    void initUI();
};

