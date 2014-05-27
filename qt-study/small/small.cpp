#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QIcon>
#include <QFrame>
#include <QGridLayout>
#include <QPushButton>
#include "communicate.h"


class Cursors : public QWidget
{
 public:
     Cursors(QWidget *parent = 0);
};


Cursors::Cursors(QWidget *parent)
    : QWidget(parent)
{  
  QFrame *frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  QFrame *frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  QFrame *frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  QGridLayout *grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 1, 0);
  grid->addWidget(frame3, 2, 0);

  setLayout(grid);
}

class MyButton : public QWidget
{
 public:
     MyButton(QWidget *parent = 0);
};

MyButton::MyButton(QWidget *parent)
    : QWidget(parent)
{   
  QPushButton *quit = new QPushButton("Quit", this);
  quit->setGeometry(50, 40, 75, 30);

  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}


int main(int argc, char *argv[])
{

  int WIDTH = 250;
  int HEIGHT = 150;

  int screenWidth;
  int screenHeight;

  int x, y;

  QApplication app(argc, argv);

  // QWidget window;
  // Cursors window;
  // MyButton window;
  Communicate window;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height(); 

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  window.resize(WIDTH, HEIGHT);
  window.move( x, y );
  window.setWindowTitle("Center");

  window.setWindowTitle("ToolTip");
  window.setToolTip("QWidget");

  window.setWindowTitle("icon");
  window.setWindowIcon(QIcon("web.png"));
  window.show();

  return app.exec();
}
