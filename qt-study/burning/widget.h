/*
 * =====================================================================================
 *
 *       Filename:  widget.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/28/2014 12:20:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#pragma once

#include <QFrame>

class Burning;

class Widget : public QFrame
{
  Q_OBJECT  

  public:
    Widget(QWidget *parent = 0);

  protected:
    void paintEvent(QPaintEvent *e);
    void drawWidget(QPainter &qp);

  private:
    QWidget *m_parent;
    Burning *burn;
};

