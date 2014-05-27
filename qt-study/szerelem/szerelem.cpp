/*
 * =====================================================================================
 *
 *       Filename:  szerelem.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:07:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <QTextStream>
#include <QFile>

int main()
{
  QFile data("szerelem.txt");

  QString line;

  if (data.open(QFile::ReadOnly)) {
    QTextStream in(&data);
    QTextStream out(stdout);

    out.setCodec("UTF-8");
    in.setCodec("UTF-8");

    do {
      line = in.readLine();
      out << line << endl;
    } while (!line.isNull());
  }
}

