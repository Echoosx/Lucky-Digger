#include <QApplication>
#include<time.h>
#include "GameBoard.h"
//#include "MainWindow.h"

int main(int argc, char *argv[])
{
        srand(time(0));
        QApplication app(argc, argv);
        //GameBoard *game = new GameBoard;
        //game->show();
        Main *main=new Main;
        return app.exec();
}
