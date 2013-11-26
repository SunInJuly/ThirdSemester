#include <QCoreApplication>
#include "AnalyzerTest.h"
#include "ParserTest.h"
/**
  *Есть связный неориентированный граф, в вершинах графа находится несколько роботов.
  * каждый ход роботы могут телепортироваться, перепрыгивая через одну вершину.
  * Например, если граф выглядит так: (R)----(*)----(*), то на следующем ходу робот может остаться на месте,
  * а может телепортироваться: (*)----(*)----(R). Если два или больше роботов телепортируются в одну вершину графа,
  * они самоуничтожаются. Задача --- по заданному графу и заданному начальному расположению роботов определить,
  * существует ли такая последовательность телепортаций, при которой все роботы самоуничтожатся.
  *
  * Программа принимает входной файл в формате txt, где данные описываются в следующем порядке - количество вершин,
  *количество дуг, количество роботов, вершины, в которых находятся роботы, дуги в виде пар чисел - начало и конец дуги.
  * Дает ответ на поставленный вопрос.
**/


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ParserTest test;
    AnalyzerTest test1;
    QTest::qExec(&test);
    QTest::qExec(&test1);
    return a.exec();
}
