#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE

class Board : public QWidget
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);
    ~Board();

private:
    Ui::Board *ui;
};
#endif // BOARD_H
