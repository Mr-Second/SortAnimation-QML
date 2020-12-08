#include "board.h"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "RandomGenerator.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board w;
    w.show();
    auto cmp = [](int i, int j) ->bool {return i < j;};
    ISort *sortTool = new QuickSort(rg->getData(50, 1, 100), cmp);
    sortTool->sort();
    return a.exec();
}
