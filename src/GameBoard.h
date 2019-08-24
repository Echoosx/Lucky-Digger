#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#define ROW 10
#define COL 7
//#include<QtGui>
#include<QMainWindow>
#include<QLayout>
#include<QSound>
#include <QDialog>
#include <QtWidgets>
#include <QWidget>
#include<QMovie>

class QPushButton;
class QLabel;
class QSound;
class QMovie;

class stBlock{
public:
    int color;
    int havePerson;
    int haveBlock;
    int boom;
    int change;
public:
    stBlock():havePerson(0),haveBlock(0),boom(0),change(0){}
    void setChange();
};

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);
    ~GameBoard();

public:
    QPushButton *Block[ROW+2][COL+2];
    stBlock block[ROW+2][COL+2];
private:
    void makeBlocks();
    void setBlockArray();
    QVBoxLayout *setHLayout();
    void setColor();
    void setEnabledf();
    void Connects();

    //反馈
    void Reflection();
    //消失
    void disappear();
    //连锁爆炸
    bool Chain(int q,int t);
    bool EndBoom();
    void ChainBoom();
    //移动
    void LookforPerson();
    bool fall();
    void FallPerson();
    void MovePersonR();
    void MovePersonL();
    void unlocked();
    //砖块出 object
    void showObject(int x,int y);
    void changeTo();
    void Change();
    void get();
    void winlose();

public:
    QPushButton *Start;
    QPushButton *Exit;
    QPushButton *Again;
    QSound *player;

private:
    QPushButton *Block_00;
    QPushButton *Block_01;
    QPushButton *Block_02;
    QPushButton *Block_03;
    QPushButton *Block_04;
    QPushButton *Block_05;
    QPushButton *Block_06;
    QPushButton *Block_07;
    QPushButton *Block_08;
    QPushButton *Block_10;
    QPushButton *Block_11;
    QPushButton *Block_12;
    QPushButton *Block_13;
    QPushButton *Block_14;
    QPushButton *Block_15;
    QPushButton *Block_16;
    QPushButton *Block_17;
    QPushButton *Block_18;
    QPushButton *Block_20;
    QPushButton *Block_21;
    QPushButton *Block_22;
    QPushButton *Block_23;
    QPushButton *Block_24;
    QPushButton *Block_25;
    QPushButton *Block_26;
    QPushButton *Block_27;
    QPushButton *Block_28;
    QPushButton *Block_30;
    QPushButton *Block_31;
    QPushButton *Block_32;
    QPushButton *Block_33;
    QPushButton *Block_34;
    QPushButton *Block_35;
    QPushButton *Block_36;
    QPushButton *Block_37;
    QPushButton *Block_38;
    QPushButton *Block_40;
    QPushButton *Block_41;
    QPushButton *Block_42;
    QPushButton *Block_43;
    QPushButton *Block_44;
    QPushButton *Block_45;
    QPushButton *Block_46;
    QPushButton *Block_47;
    QPushButton *Block_48;
    QPushButton *Block_50;
    QPushButton *Block_51;
    QPushButton *Block_52;
    QPushButton *Block_53;
    QPushButton *Block_54;
    QPushButton *Block_55;
    QPushButton *Block_56;
    QPushButton *Block_57;
    QPushButton *Block_58;
    QPushButton *Block_60;
    QPushButton *Block_61;
    QPushButton *Block_62;
    QPushButton *Block_63;
    QPushButton *Block_64;
    QPushButton *Block_65;
    QPushButton *Block_66;
    QPushButton *Block_67;
    QPushButton *Block_68;
    QPushButton *Block_70;
    QPushButton *Block_71;
    QPushButton *Block_72;
    QPushButton *Block_73;
    QPushButton *Block_74;
    QPushButton *Block_75;
    QPushButton *Block_76;
    QPushButton *Block_77;
    QPushButton *Block_78;
    QPushButton *Block_80;
    QPushButton *Block_81;
    QPushButton *Block_82;
    QPushButton *Block_83;
    QPushButton *Block_84;
    QPushButton *Block_85;
    QPushButton *Block_86;
    QPushButton *Block_87;
    QPushButton *Block_88;
    QPushButton *Block_90;
    QPushButton *Block_91;
    QPushButton *Block_92;
    QPushButton *Block_93;
    QPushButton *Block_94;
    QPushButton *Block_95;
    QPushButton *Block_96;
    QPushButton *Block_97;
    QPushButton *Block_98;
    QPushButton *Block_100;
    QPushButton *Block_101;
    QPushButton *Block_102;
    QPushButton *Block_103;
    QPushButton *Block_104;
    QPushButton *Block_105;
    QPushButton *Block_106;
    QPushButton *Block_107;
    QPushButton *Block_108;
    QPushButton *Block_110;
    QPushButton *Block_111;
    QPushButton *Block_112;
    QPushButton *Block_113;
    QPushButton *Block_114;
    QPushButton *Block_115;
    QPushButton *Block_116;
    QPushButton *Block_117;
    QPushButton *Block_118;

    QLabel *time;
    QLabel *score;

    QPushButton *life_1;
    QPushButton *life_2;
    QPushButton *life_3;

private slots:

    void setEnabledt();
    void click_00();
    void click_01();
    void click_02();
    void click_03();
    void click_04();
    void click_05();
    void click_06();
    void click_07();
    void click_08();
    void click_10();
    void click_11();
    void click_12();
    void click_13();
    void click_14();
    void click_15();
    void click_16();
    void click_17();
    void click_18();
    void click_20();
    void click_21();
    void click_22();
    void click_23();
    void click_24();
    void click_25();
    void click_26();
    void click_27();
    void click_28();
    void click_30();
    void click_31();
    void click_32();
    void click_33();
    void click_34();
    void click_35();
    void click_36();
    void click_37();
    void click_38();
    void click_40();
    void click_41();
    void click_42();
    void click_43();
    void click_44();
    void click_45();
    void click_46();
    void click_47();
    void click_48();
    void click_50();
    void click_51();
    void click_52();
    void click_53();
    void click_54();
    void click_55();
    void click_56();
    void click_57();
    void click_58();
    void click_60();
    void click_61();
    void click_62();
    void click_63();
    void click_64();
    void click_65();
    void click_66();
    void click_67();
    void click_68();
    void click_70();
    void click_71();
    void click_72();
    void click_73();
    void click_74();
    void click_75();
    void click_76();
    void click_77();
    void click_78();
    void click_80();
    void click_81();
    void click_82();
    void click_83();
    void click_84();
    void click_85();
    void click_86();
    void click_87();
    void click_88();
    void click_90();
    void click_91();
    void click_92();
    void click_93();
    void click_94();
    void click_95();
    void click_96();
    void click_97();
    void click_98();
    void click_100();
    void click_101();
    void click_102();
    void click_103();
    void click_104();
    void click_105();
    void click_106();
    void click_107();
    void click_108();
    void click_110();
    void click_111();
    void click_112();
    void click_113();
    void click_114();
    void click_115();
    void click_116();
    void click_117();
    void click_118();
public:

    QLabel  *time_show;
    QTime *time_clock;
    QTimer *time_timer;
    QPushButton *begin,*end;
    QGroupBox *inputbox;

public slots:
    void create_input();
    void addtime();
    void timestart();
    void timeend();
    void MusicOn();
    void MusicOff();
signals:
    void win();
    void lose();
    void firstblood();
};

class Menu: public QWidget
{
    Q_OBJECT

public:
    Menu(QWidget *parent = 0);
    ~Menu();

public:
    QPushButton *Play;
    QPushButton *Quit;
private slots:
};

class Win:public QWidget{

    Q_OBJECT

public:
    Win(QWidget *parent = 0);
    ~Win();

public:
    QPushButton *Again;
    QPushButton *backMenu;
    QPushButton *Next;
    QLabel *gif;
    QLabel *star;
    QMovie *movie;
    QMovie *movies_1;
    QMovie *movies_2;
    QMovie *movies_3;
    QMovie *movies_4;
    QMovie *movies_5;
};

class Lose:public QWidget{

    Q_OBJECT

public:
    Lose(QWidget *parent = 0);
    ~Lose();

public:
    QPushButton *Again;
    QPushButton *backMenu;
};

class FirstBlood:public QWidget{
    Q_OBJECT

public:
    FirstBlood(QWidget *parent = 0);
    ~FirstBlood();

public:
    QPushButton *first;

};

class Main:public QWidget
{
    Q_OBJECT

public:
    Main(QWidget *parent = 0);
    ~Main();

public:
    Menu *menu;
    GameBoard *gameboard;
    Win *winw;
    Lose *losew;
    FirstBlood *firstblood;

public slots:
    void TurntoGame();
    void BacktoMenu();
    void TurntoWin();
    void TurntoLose();
    void Again();
};

#endif // GAMEBOARD_H
