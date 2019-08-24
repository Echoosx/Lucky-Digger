#include "GameBoard.h"

//#include<QtGui>
#include<QPushButton>
#include<QLayout>
#include<QLabel>
#include<stdlib.h>
#include<math.h>
#include<QSound>
#include <QPixmap>
#include <QPalette>
using namespace std;

int X,Y;
int Xp,Yp;
int havebeenStart=0;
bool isstart,startagain;
int LIFE=3,SCORE=0;
int fibl=1;
//构造函数

Menu::Menu(QWidget *parent):QWidget(parent){
    Play=new QPushButton();
    Quit=new QPushButton();
    Play->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/play1.png);width:120px;height:40px;}"
                        "QPushButton:hover{border-image:url(:/new/prefix1/play2.png);width:120px;height:40px;}");
    Quit->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/quit1.png);width:120px;height:45px;}"
                        "QPushButton:hover{border-image:url(:/new/prefix1/quit2.png);width:120px;height:45px;}");

    connect(Quit,SIGNAL(clicked()),this,SLOT(close()));
    QVBoxLayout *menupq=new QVBoxLayout;
    menupq->addStretch();
    menupq->addWidget(Play);
    menupq->addWidget(Quit);
    menupq->addStretch();
    menupq->setSpacing(40);

    QHBoxLayout *allmenu=new QHBoxLayout;
    allmenu->addStretch();
    allmenu->addLayout(menupq);
    allmenu->addStretch();

    setLayout(allmenu);
    setWindowTitle(tr("Menu"));
    setFixedSize(562,618);

    QPixmap pixmap(":/new/prefix1/menu.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}

Menu::~Menu(){
}

Win::Win(QWidget *parent):QWidget(parent){
    Again=new QPushButton();
    backMenu=new QPushButton();
    Next=new QPushButton();

    Again->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/again2.png);width:120px;height:35px;}"
                         "QPushButton:hover{border-image:url(:/new/prefix1/again1.png);width:120px;height:35px;}");
    backMenu->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/menu2.png);width:120px;height:35px;}"
                            "QPushButton:hover{border-image:url(:/new/prefix1/menu1.png);width:120px;height:35px;}");
    Next->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/next2.png);width:120px;height:35px;}"
                        "QPushButton:hover{border-image:url(:/new/prefix1/next1.png);width:120px;height:35px;}");

    QHBoxLayout *GIF=new QHBoxLayout;
    gif=new QLabel;
    movie=new QMovie(":/new/prefix1/win.gif");
    GIF->addStretch();
    GIF->addWidget(gif);
    GIF->addStretch();
    gif->setMovie(movie);
    movie->start();
    movie->setScaledSize(QSize(370,370));


    QHBoxLayout *Star=new QHBoxLayout;
    star=new QLabel;

    movies_1=new QMovie(":/new/prefix1/one.gif");
    movies_1->setScaledSize(QSize(50,50));
    movies_2=new QMovie(":/new/prefix1/two.gif");
    movies_2->setScaledSize(QSize(142,50));
    movies_3=new QMovie(":/new/prefix1/three.gif");
    movies_3->setScaledSize(QSize(112,50));
    movies_4=new QMovie(":/new/prefix1/four.gif");
    movies_4->setScaledSize(QSize(131,50));
    movies_5=new QMovie(":/new/prefix1/five.gif");
    movies_5->setScaledSize(QSize(123,50));

    Star->addStretch();
    Star->addWidget(star);
    Star->addStretch();
    //movies_1->start();


    QVBoxLayout *win=new QVBoxLayout;
    win->addStretch();
    win->addWidget(Next);
    win->addWidget(Again);
    win->addWidget(backMenu);
    win->setSpacing(30);

    QHBoxLayout *allwin=new QHBoxLayout;
    allwin->addStretch();
    allwin->addLayout(win);
    allwin->addStretch();

    QVBoxLayout *all =new QVBoxLayout;
    all->addLayout(GIF);
    all->addStretch();
    all->addLayout(Star);
    all->addLayout(allwin);

    setLayout(all);
    setWindowTitle("WIN");
    setFixedSize(528,586);

    QPixmap pixmap(":/new/prefix1/background.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);

}

Win::~Win(){

}

Lose::Lose(QWidget *parent):QWidget(parent){
    Again=new QPushButton();
    backMenu=new QPushButton();

    Again->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/again2.png);width:120px;height:35px;}"
                         "QPushButton:hover{border-image:url(:/new/prefix1/again1.png);width:120px;height:35px;}");
    backMenu->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/menu2.png);width:120px;height:35px;}"
                            "QPushButton:hover{border-image:url(:/new/prefix1/menu1.png);width:120px;height:35px;}");

    QVBoxLayout *lose=new QVBoxLayout;
    lose->addStretch();
    lose->addStretch();
    lose->addStretch();
    lose->addStretch();
    lose->addStretch();
    lose->addStretch();
    lose->addStretch();
    lose->addWidget(Again);
    lose->addWidget(backMenu);
    lose->setSpacing(30);

    QHBoxLayout *alllose=new QHBoxLayout;
    alllose->addStretch();
    alllose->addLayout(lose);
    alllose->addStretch();

    setLayout(alllose);
    setWindowTitle("LOSE");
    setFixedSize(528,586);

    QPixmap pixmap(":/new/prefix1/theggbackground.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
}

Lose::~Lose(){

}

FirstBlood::FirstBlood(QWidget *parent):QWidget(parent){
    first=new QPushButton;
    first->setStyleSheet("border-image:url(:/new/prefix1/firstblood.png);color:rgba(0,0,0,0);width:512px;height:126px;");
    QHBoxLayout *fb=new QHBoxLayout;
    fb->addWidget(first);

    setLayout(fb);
    connect(first,SIGNAL(clicked()),this,SLOT(close()));
}

FirstBlood::~FirstBlood(){

}

Main::Main(QWidget *parent):QWidget(parent){
    menu=new Menu;
    gameboard=new GameBoard;
    winw=new Win;
    losew=new Lose;
    firstblood=new FirstBlood;
    connect(this->menu->Play,SIGNAL(clicked()),this,SLOT(TurntoGame()));
    //connect(this->gameboard,SIGNAL(win()),this,SLOT(TurntoWin()));
    //connect(this->gameboard,SIGNAL(lose()),this,SLOT(TurntoLose()));
    connect(this->winw->Again,SIGNAL(clicked()),this,SLOT(Again()));
    connect(this->losew->Again,SIGNAL(clicked()),this,SLOT(Again()));
    connect(this->winw->Next,SIGNAL(clicked()),this,SLOT(Again()));
    connect(this->winw->backMenu,SIGNAL(clicked()),this,SLOT(BacktoMenu()));
    connect(this->losew->backMenu,SIGNAL(clicked()),this,SLOT(BacktoMenu()));
    menu->show();
}

Main::~Main(){

}

void Main::TurntoGame(){
    this->menu->close();
    gameboard=new GameBoard;
    connect(this->gameboard,SIGNAL(win()),this,SLOT(TurntoWin()));
    connect(this->gameboard,SIGNAL(lose()),this,SLOT(TurntoLose()));
    connect(this->gameboard->Again,SIGNAL(clicked()),this,SLOT(Again()));
    connect(this->gameboard,SIGNAL(firstblood()),this->firstblood,SLOT(show()));
    this->gameboard->show();
}
void Main::TurntoWin(){
    this->gameboard->MusicOff();
    this->gameboard->close();

    if(SCORE<=3000){
    this->winw->star->setMovie(this->winw->movies_1);
    this->winw->show();
    this->winw->movies_1->start();
}
    else if(SCORE<=5000){
        this->winw->star->setMovie(this->winw->movies_2);
        this->winw->show();
        this->winw->movies_2->start();
    }
    else if(SCORE<=7000){
        this->winw->star->setMovie(this->winw->movies_3);
        this->winw->show();
        this->winw->movies_3->start();
    }
    else if(SCORE<=10000){
        this->winw->star->setMovie(this->winw->movies_4);
        this->winw->show();
        this->winw->movies_4->start();
    }
    else{
        this->winw->star->setMovie(this->winw->movies_5);
        this->winw->show();
        this->winw->movies_5->start();
    }
}

void Main::TurntoLose(){
    this->gameboard->MusicOff();
    this->gameboard->close();

    this->losew->show();

}

void Main::BacktoMenu(){
    this->winw->close();
    this->losew->close();
    this->gameboard->close();
    this->menu->show();
}

void Main::Again(){
    this->winw->close();
    this->losew->close();
    this->gameboard->MusicOff();
    this->gameboard->close();
    gameboard=new GameBoard;
    connect(this->gameboard,SIGNAL(win()),this,SLOT(TurntoWin()));
    connect(this->gameboard,SIGNAL(lose()),this,SLOT(TurntoLose()));
    connect(this->gameboard->Again,SIGNAL(clicked()),this,SLOT(Again()));
    connect(this->gameboard,SIGNAL(firstblood()),this->firstblood,SLOT(show()));
    this->gameboard->show();
}

GameBoard::GameBoard(QWidget *parent)
        : QWidget(parent)
{
    Start=new QPushButton(tr("开始游戏"));
    Again=new QPushButton(tr("重新开始"));
    Exit=new QPushButton(tr("结束游戏"));

    time=new QLabel;
    score=new QLabel;
    life_1=new QPushButton;
    life_2=new QPushButton;
    life_3=new QPushButton;

    LIFE=3;SCORE=0;havebeenStart=0;fibl=1;
    isstart=true;startagain=false;
    Xp=0;Yp=1;block[0][1].havePerson=1;
    score->setText(QString::number(SCORE));
    life_1->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    life_2->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    life_3->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");

    makeBlocks();
    setBlockArray();
    setColor();     //
    setEnabledf();  //

    connect(Start,SIGNAL(clicked()),this,SLOT(setEnabledt()));  //
    connect(Exit,SIGNAL(clicked()),this,SLOT(close ()));         //

    //connect(QSound,SIGNAL(isFinished ()),this,SLOT(MusicOn()));
    Connects();             //
    setLayout(setHLayout());        //
    setWindowTitle(tr("Lucky Digger"));     //
    setFixedHeight(sizeHint().height());        //

    //计时功能
    QVBoxLayout *view=new QVBoxLayout;
    create_input();
    view->addWidget(inputbox);
    //this->setLayout(view);

    //背景图片
    QPixmap pixmap(":/new/prefix1/background.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);

    player=new QSound(":/new/prefix1/BGM.wav");
    player->setLoops(10);
}

GameBoard::~GameBoard(){

}
void GameBoard::makeBlocks(){
    Block_00=new QPushButton("00");
    Block_01=new QPushButton("01");
    Block_02=new QPushButton("02");
    Block_03=new QPushButton("03");
    Block_04=new QPushButton("04");
    Block_05=new QPushButton("05");
    Block_06=new QPushButton("06");
    Block_07=new QPushButton("07");
    Block_08=new QPushButton("08");
    Block_10=new QPushButton("10");
    Block_11=new QPushButton("11");
    Block_12=new QPushButton("12");
    Block_13=new QPushButton("13");
    Block_14=new QPushButton("14");
    Block_15=new QPushButton("15");
    Block_16=new QPushButton("16");
    Block_17=new QPushButton("17");
    Block_18=new QPushButton("18");
    Block_20=new QPushButton("20");
    Block_21=new QPushButton("21");
    Block_22=new QPushButton("22");
    Block_23=new QPushButton("23");
    Block_24=new QPushButton("24");
    Block_25=new QPushButton("25");
    Block_26=new QPushButton("26");
    Block_27=new QPushButton("27");
    Block_28=new QPushButton("28");
    Block_30=new QPushButton("30");
    Block_31=new QPushButton("31");
    Block_32=new QPushButton("32");
    Block_33=new QPushButton("33");
    Block_34=new QPushButton("34");
    Block_35=new QPushButton("35");
    Block_36=new QPushButton("36");
    Block_37=new QPushButton("37");
    Block_38=new QPushButton("38");
    Block_40=new QPushButton("40");
    Block_41=new QPushButton("41");
    Block_42=new QPushButton("42");
    Block_43=new QPushButton("43");
    Block_44=new QPushButton("44");
    Block_45=new QPushButton("45");
    Block_46=new QPushButton("46");
    Block_47=new QPushButton("47");
    Block_48=new QPushButton("48");
    Block_50=new QPushButton("50");
    Block_51=new QPushButton("51");
    Block_52=new QPushButton("52");
    Block_53=new QPushButton("53");
    Block_54=new QPushButton("54");
    Block_55=new QPushButton("55");
    Block_56=new QPushButton("56");
    Block_57=new QPushButton("57");
    Block_58=new QPushButton("58");
    Block_60=new QPushButton("60");
    Block_61=new QPushButton("61");
    Block_62=new QPushButton("62");
    Block_63=new QPushButton("63");
    Block_64=new QPushButton("64");
    Block_65=new QPushButton("65");
    Block_66=new QPushButton("66");
    Block_67=new QPushButton("67");
    Block_68=new QPushButton("68");
    Block_70=new QPushButton("70");
    Block_71=new QPushButton("71");
    Block_72=new QPushButton("72");
    Block_73=new QPushButton("73");
    Block_74=new QPushButton("74");
    Block_75=new QPushButton("75");
    Block_76=new QPushButton("76");
    Block_77=new QPushButton("77");
    Block_78=new QPushButton("78");
    Block_80=new QPushButton("80");
    Block_81=new QPushButton("81");
    Block_82=new QPushButton("82");
    Block_83=new QPushButton("83");
    Block_84=new QPushButton("84");
    Block_85=new QPushButton("85");
    Block_86=new QPushButton("86");
    Block_87=new QPushButton("87");
    Block_88=new QPushButton("88");
    Block_90=new QPushButton("90");
    Block_91=new QPushButton("91");
    Block_92=new QPushButton("92");
    Block_93=new QPushButton("93");
    Block_94=new QPushButton("94");
    Block_95=new QPushButton("95");
    Block_96=new QPushButton("96");
    Block_97=new QPushButton("97");
    Block_98=new QPushButton("98");
    Block_100=new QPushButton("100");
    Block_101=new QPushButton("101");
    Block_102=new QPushButton("102");
    Block_103=new QPushButton("103");
    Block_104=new QPushButton("104");
    Block_105=new QPushButton("105");
    Block_106=new QPushButton("106");
    Block_107=new QPushButton("107");
    Block_108=new QPushButton("108");
    Block_110=new QPushButton("110");
    Block_111=new QPushButton("111");
    Block_112=new QPushButton("112");
    Block_113=new QPushButton("113");
    Block_114=new QPushButton("114");
    Block_115=new QPushButton("115");
    Block_116=new QPushButton("116");
    Block_117=new QPushButton("117");
    Block_118=new QPushButton("118");
}

void GameBoard::setBlockArray(){
    Block[0][0]=Block_00;
    Block[0][1]=Block_01;
    Block[0][2]=Block_02;
    Block[0][3]=Block_03;
    Block[0][4]=Block_04;
    Block[0][5]=Block_05;
    Block[0][6]=Block_06;
    Block[0][7]=Block_07;
    Block[0][8]=Block_08;
    Block[1][0]=Block_10;
    Block[1][1]=Block_11;
    Block[1][2]=Block_12;
    Block[1][3]=Block_13;
    Block[1][4]=Block_14;
    Block[1][5]=Block_15;
    Block[1][6]=Block_16;
    Block[1][7]=Block_17;
    Block[1][8]=Block_18;
    Block[2][0]=Block_20;
    Block[2][1]=Block_21;
    Block[2][2]=Block_22;
    Block[2][3]=Block_23;
    Block[2][4]=Block_24;
    Block[2][5]=Block_25;
    Block[2][6]=Block_26;
    Block[2][7]=Block_27;
    Block[2][8]=Block_28;
    Block[3][0]=Block_30;
    Block[3][1]=Block_31;
    Block[3][2]=Block_32;
    Block[3][3]=Block_33;
    Block[3][4]=Block_34;
    Block[3][5]=Block_35;
    Block[3][6]=Block_36;
    Block[3][7]=Block_37;
    Block[3][8]=Block_38;
    Block[4][0]=Block_40;
    Block[4][1]=Block_41;
    Block[4][2]=Block_42;
    Block[4][3]=Block_43;
    Block[4][4]=Block_44;
    Block[4][5]=Block_45;
    Block[4][6]=Block_46;
    Block[4][7]=Block_47;
    Block[4][8]=Block_48;
    Block[5][0]=Block_50;
    Block[5][1]=Block_51;
    Block[5][2]=Block_52;
    Block[5][3]=Block_53;
    Block[5][4]=Block_54;
    Block[5][5]=Block_55;
    Block[5][6]=Block_56;
    Block[5][7]=Block_57;
    Block[5][8]=Block_58;
    Block[6][0]=Block_60;
    Block[6][1]=Block_61;
    Block[6][2]=Block_62;
    Block[6][3]=Block_63;
    Block[6][4]=Block_64;
    Block[6][5]=Block_65;
    Block[6][6]=Block_66;
    Block[6][7]=Block_67;
    Block[6][8]=Block_68;
    Block[7][0]=Block_70;
    Block[7][1]=Block_71;
    Block[7][2]=Block_72;
    Block[7][3]=Block_73;
    Block[7][4]=Block_74;
    Block[7][5]=Block_75;
    Block[7][6]=Block_76;
    Block[7][7]=Block_77;
    Block[7][8]=Block_78;
    Block[8][0]=Block_80;
    Block[8][1]=Block_81;
    Block[8][2]=Block_82;
    Block[8][3]=Block_83;
    Block[8][4]=Block_84;
    Block[8][5]=Block_85;
    Block[8][6]=Block_86;
    Block[8][7]=Block_87;
    Block[8][8]=Block_88;
    Block[9][0]=Block_90;
    Block[9][1]=Block_91;
    Block[9][2]=Block_92;
    Block[9][3]=Block_93;
    Block[9][4]=Block_94;
    Block[9][5]=Block_95;
    Block[9][6]=Block_96;
    Block[9][7]=Block_97;
    Block[9][8]=Block_98;
    Block[10][0]=Block_100;
    Block[10][1]=Block_101;
    Block[10][2]=Block_102;
    Block[10][3]=Block_103;
    Block[10][4]=Block_104;
    Block[10][5]=Block_105;
    Block[10][6]=Block_106;
    Block[10][7]=Block_107;
    Block[10][8]=Block_108;
    Block[11][0]=Block_110;
    Block[11][1]=Block_111;
    Block[11][2]=Block_112;
    Block[11][3]=Block_113;
    Block[11][4]=Block_114;
    Block[11][5]=Block_115;
    Block[11][6]=Block_116;
    Block[11][7]=Block_117;
    Block[11][8]=Block_118;
}

QVBoxLayout *GameBoard::setHLayout(){
   QHBoxLayout *StartGame = new QHBoxLayout;
     StartGame->addStretch();
     StartGame->addWidget(Start);
     StartGame->addWidget(Again);
     StartGame->addWidget(Exit);
     StartGame->addStretch();

     QHBoxLayout *HLayout_0 = new QHBoxLayout;
     HLayout_0->addWidget(Block_00);
     HLayout_0->addWidget(Block_01);
     HLayout_0->addWidget(Block_02);
     HLayout_0->addWidget(Block_03);
     HLayout_0->addWidget(Block_04);
     HLayout_0->addWidget(Block_05);
     HLayout_0->addWidget(Block_06);
     HLayout_0->addWidget(Block_07);
     HLayout_0->addWidget(Block_08);
     HLayout_0->setSpacing(15);

     QHBoxLayout *HLayout_1 = new QHBoxLayout;
     HLayout_1->addWidget(Block_10);
     HLayout_1->addWidget(Block_11);
     HLayout_1->addWidget(Block_12);
     HLayout_1->addWidget(Block_13);
     HLayout_1->addWidget(Block_14);
     HLayout_1->addWidget(Block_15);
     HLayout_1->addWidget(Block_16);
     HLayout_1->addWidget(Block_17);
     HLayout_1->addWidget(Block_18);
     HLayout_1->setSpacing(15);

     QHBoxLayout *HLayout_2 = new QHBoxLayout;
     HLayout_2->addWidget(Block_20);
     HLayout_2->addWidget(Block_21);
     HLayout_2->addWidget(Block_22);
     HLayout_2->addWidget(Block_23);
     HLayout_2->addWidget(Block_24);
     HLayout_2->addWidget(Block_25);
     HLayout_2->addWidget(Block_26);
     HLayout_2->addWidget(Block_27);
     HLayout_2->addWidget(Block_28);
     HLayout_2->setSpacing(15);

     QHBoxLayout *HLayout_3 = new QHBoxLayout;
     HLayout_3->addWidget(Block_30);
     HLayout_3->addWidget(Block_31);
     HLayout_3->addWidget(Block_32);
     HLayout_3->addWidget(Block_33);
     HLayout_3->addWidget(Block_34);
     HLayout_3->addWidget(Block_35);
     HLayout_3->addWidget(Block_36);
     HLayout_3->addWidget(Block_37);
     HLayout_3->addWidget(Block_38);
     HLayout_3->setSpacing(15);

     QHBoxLayout *HLayout_4 = new QHBoxLayout;
     HLayout_4->addWidget(Block_40);
     HLayout_4->addWidget(Block_41);
     HLayout_4->addWidget(Block_42);
     HLayout_4->addWidget(Block_43);
     HLayout_4->addWidget(Block_44);
     HLayout_4->addWidget(Block_45);
     HLayout_4->addWidget(Block_46);
     HLayout_4->addWidget(Block_47);
     HLayout_4->addWidget(Block_48);
     HLayout_4->setSpacing(15);

     QHBoxLayout *HLayout_5 = new QHBoxLayout;
     HLayout_5->addWidget(Block_50);
     HLayout_5->addWidget(Block_51);
     HLayout_5->addWidget(Block_52);
     HLayout_5->addWidget(Block_53);
     HLayout_5->addWidget(Block_54);
     HLayout_5->addWidget(Block_55);
     HLayout_5->addWidget(Block_56);
     HLayout_5->addWidget(Block_57);
     HLayout_5->addWidget(Block_58);
     HLayout_5->setSpacing(15);

     QHBoxLayout *HLayout_6 = new QHBoxLayout;
     HLayout_6->addWidget(Block_60);
     HLayout_6->addWidget(Block_61);
     HLayout_6->addWidget(Block_62);
     HLayout_6->addWidget(Block_63);
     HLayout_6->addWidget(Block_64);
     HLayout_6->addWidget(Block_65);
     HLayout_6->addWidget(Block_66);
     HLayout_6->addWidget(Block_67);
     HLayout_6->addWidget(Block_68);
     HLayout_6->setSpacing(15);

     QHBoxLayout *HLayout_7 = new QHBoxLayout;
     HLayout_7->addWidget(Block_70);
     HLayout_7->addWidget(Block_71);
     HLayout_7->addWidget(Block_72);
     HLayout_7->addWidget(Block_73);
     HLayout_7->addWidget(Block_74);
     HLayout_7->addWidget(Block_75);
     HLayout_7->addWidget(Block_76);
     HLayout_7->addWidget(Block_77);
     HLayout_7->addWidget(Block_78);
     HLayout_7->setSpacing(15);

     QHBoxLayout *HLayout_8 = new QHBoxLayout;
     HLayout_8->addWidget(Block_80);
     HLayout_8->addWidget(Block_81);
     HLayout_8->addWidget(Block_82);
     HLayout_8->addWidget(Block_83);
     HLayout_8->addWidget(Block_84);
     HLayout_8->addWidget(Block_85);
     HLayout_8->addWidget(Block_86);
     HLayout_8->addWidget(Block_87);
     HLayout_8->addWidget(Block_88);
     HLayout_8->setSpacing(15);

     QHBoxLayout *HLayout_9 = new QHBoxLayout;
     HLayout_9->addWidget(Block_90);
     HLayout_9->addWidget(Block_91);
     HLayout_9->addWidget(Block_92);
     HLayout_9->addWidget(Block_93);
     HLayout_9->addWidget(Block_94);
     HLayout_9->addWidget(Block_95);
     HLayout_9->addWidget(Block_96);
     HLayout_9->addWidget(Block_97);
     HLayout_9->addWidget(Block_98);
     HLayout_9->setSpacing(15);

     QHBoxLayout *HLayout_10 = new QHBoxLayout;
     HLayout_10->addWidget(Block_100);
     HLayout_10->addWidget(Block_101);
     HLayout_10->addWidget(Block_102);
     HLayout_10->addWidget(Block_103);
     HLayout_10->addWidget(Block_104);
     HLayout_10->addWidget(Block_105);
     HLayout_10->addWidget(Block_106);
     HLayout_10->addWidget(Block_107);
     HLayout_10->addWidget(Block_108);
     HLayout_10->setSpacing(15);

     QHBoxLayout *HLayout_11 = new QHBoxLayout;
     HLayout_11->addWidget(Block_110);
     HLayout_11->addWidget(Block_111);
     HLayout_11->addWidget(Block_112);
     HLayout_11->addWidget(Block_113);
     HLayout_11->addWidget(Block_114);
     HLayout_11->addWidget(Block_115);
     HLayout_11->addWidget(Block_116);
     HLayout_11->addWidget(Block_117);
     HLayout_11->addWidget(Block_118);
     HLayout_11->setSpacing(15);

   QVBoxLayout *GameBox = new QVBoxLayout;
   GameBox->addLayout(HLayout_0);
   GameBox->addLayout(HLayout_1);
   GameBox->addLayout(HLayout_2);
   GameBox->addLayout(HLayout_3);
   GameBox->addLayout(HLayout_4);
   GameBox->addLayout(HLayout_5);
   GameBox->addLayout(HLayout_6);
   GameBox->addLayout(HLayout_7);
   GameBox->addLayout(HLayout_8);
   GameBox->addLayout(HLayout_9);
   GameBox->addLayout(HLayout_10);
   GameBox->addLayout(HLayout_11);
   GameBox->setSpacing(3);

   life_1->setEnabled(false);
   life_2->setEnabled(false);
   life_3->setEnabled(false);

   QHBoxLayout *life=new QHBoxLayout;
   life->addStretch();
   life->addWidget(life_1);
   life->addWidget(life_2);
   life->addWidget(life_3);
   life->addStretch();
   life->addSpacing(5);

   QLabel *namescore=new QLabel(tr("SCORE:"));
   QVBoxLayout *Person =new QVBoxLayout;
   Person->addLayout(life);
   Person->addStretch();
   Person->addWidget(namescore);
   Person->addWidget(score);
   Person->addStretch();
   Person->addSpacing(20);

   QHBoxLayout *AllBox = new QHBoxLayout;
   AllBox->addWidget(time);
   AllBox->addStretch();
   AllBox->addLayout(GameBox);
   AllBox->addStretch();
   AllBox->addLayout(Person);
   AllBox->addStretch();

   QVBoxLayout *Main = new QVBoxLayout;
   Main->addLayout(StartGame);
   Main->addLayout(AllBox);

   return Main;
}

void GameBoard::MusicOn()//音乐开
{
    player->play();
    //connect(player,SIGNAL(aboutToFinish()),this,SLOT(MusicOn()));
}
void GameBoard::MusicOff()//音乐关
{
      player->stop();
}


void GameBoard::setColor(){
    int i,j,randColor;
    for(i=1;i<ROW+1;i++)
        for(j=1;j<COL+1;j++){
            randColor=rand()%4;
            switch(randColor){
                case 0:Block[i][j]->setStyleSheet("QPushButton{background:rgba(222,222,222); border-radius: 2px;height:35px;width:35px;border: 2px groove gray;border-style: outset;color:rgba(0,0,0,0);}"
                                                  "QPushButton:pressed{border-style: inset;}");break;
                case 1:Block[i][j]->setStyleSheet("QPushButton{background:rgba(243,123,106,1); border-radius: 2px;height:35px;width:35px;border: 2px groove gray;border-style: outset;color:rgba(0,0,0,0);}"
                                                  "QPushButton:pressed{border-style: inset;}");break;
                case 2:Block[i][j]->setStyleSheet("QPushButton{background:rgba(108,176,65); border-radius: 2px;height:35px;width:35px;border: 2px groove gray;border-style: outset;color:rgba(0,0,0,0);}"
                                                  "QPushButton:pressed{border-style: inset;}");break;
                case 3:Block[i][j]->setStyleSheet("QPushButton{background:rgba(234,214,65);border-radius: 2px;height:35px;width:35px;border: 2px groove gray;border-style: outset;color:rgba(0,0,0,0);}"
                                                  "QPushButton:pressed{border-style: inset;}");break;
            }
            block[i][j].haveBlock=1;
            block[i][j].color=randColor;
        }
    block[0][1].havePerson=1;
    Block[0][1]->setStyleSheet("border-image:url(:/new/prefix1/digger1.png);color:rgba(0,0,0,0);width:35px;height:35px;");
}

void GameBoard::setEnabledf(){
    int i,j;

    for(i=0;i<ROW+2;i++)
        for(j=0;j<COL+2;j++)
            if(!block[i][j].haveBlock){
                Block[i][j]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);");
                Block[i][j]->setEnabled(false);
            }

    for(i=1;i<=ROW;i++)
        for(j=1;j<=COL;j++){
            Block[i][j]->setStyleSheet("QPushButton{background:groove gray; opacity:0.5;border-radius: 2px;height:35px;width:35px;border: 2px groove gray;border-style: outset;color:rgba(0,0,0,0);}");
            Block[i][j]->setEnabled(false);
        }

}

void GameBoard::setEnabledt(){
    int i,j;
    if(!havebeenStart){
    setColor();
    block[0][1].havePerson=1;
    for(i=0;i<=ROW;i++)
        for(j=1;j<=COL;j++){
            Block[i][j]->setEnabled(true);
        }
    unlocked();
    havebeenStart=1;
    //Start->setEnabled(false);
    MusicOn();
    }
}

void GameBoard::disappear(){
    Block[X][Y]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);");
}


//连锁爆炸
bool GameBoard::Chain(int q,int t){
    int flag=0;
    if(block[q-1][t].haveBlock!=0&&block[q-1][t].boom==0&&block[q-1][t].color==block[q][t].color)
    {
        block[q-1][t].boom=1;
        flag=1;
    }

    if(block[q+1][t].haveBlock!=0&&block[q+1][t].boom==0&&block[q+1][t].color==block[q][t].color)
    {
        block[q+1][t].boom=1;
        flag=1;
    }
    if(block[q][t-1].haveBlock!=0&&block[q][t-1].boom==0&&block[q][t-1].color==block[q][t].color)
    {
        block[q][t-1].boom=1;
        flag=1;
    }
    if(block[q][t+1].haveBlock!=0&&block[q][t+1].boom==0&&block[q][t+1].color==block[q][t].color)
    {
        block[q][t+1].boom=1;
        flag=1;
    }

    if(flag)
        return true;
    else
        return false;
}

bool GameBoard::EndBoom(){
    int i,j,flag=0;
    for(i=1;i<=ROW;i++)
        for(j=1;j<=COL;j++){
            if(block[i][j].boom!=0&&Chain(i,j)){
                flag=1;
            }
        }
    if(flag)
        return false;
    else
        return true;
}

void GameBoard::ChainBoom(){
    int i,j;
    while(!EndBoom());
    for(i=1;i<=ROW;i++)
        for(j=1;j<=COL;j++)
        {
            if(block[i][j].boom!=0){
                block[i][j].haveBlock=0;
                X=i,Y=j;
                Change();
                //Block[i][j]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);");
                //block[i][j].change=block[i][j].block->SelectRand();  设置Change
                block[i][j].boom=0;
            }
        }
}

//移动
void GameBoard::LookforPerson(){
    int i,j;
    for(i=0;i<ROW+2;i++)
        for(j=0;j<COL+2;j++)
        {
            if(block[i][j].havePerson==1)
            {
                Xp=i;Yp=j;
                break;
            }
        }
}

bool GameBoard::fall(){
    LookforPerson();
    if(block[Xp+1][Yp].haveBlock==0&&Xp<ROW)
        return true;
    else return false;
}

void GameBoard::FallPerson(){
    while(fall()){
        LookforPerson();
        Block[Xp+1][Yp]->setStyleSheet("border-image:url(:/new/prefix1/digger11.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        //Block[Xp][Yp]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);");
        showObject(Xp,Yp);
        block[Xp][Yp].havePerson=0;
        block[Xp+1][Yp].havePerson=1;
        //Get(block[Xp+1][Yp].change);
        //get();
        //block[Xp+1][Yp].change=0;
    }
}

void GameBoard::MovePersonR(){
    LookforPerson();
    if((std::abs(Xp-X)+std::abs(Yp-Y))==1)
    {
        Block[Xp][Yp]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);"); //人消失
        block[Xp][Yp].havePerson=0;
        Block[X][Y]->setStyleSheet("border-image:url(:/new/prefix1/digger4.png);color:rgba(0,0,0,0);width:35px;height:35px;");  //人出现
        block[X][Y].havePerson=1;

        FallPerson();
    }
    else;
}

void GameBoard::MovePersonL(){
    LookforPerson();
    if((std::abs(Xp-X)+std::abs(Yp-Y))==1)
    {
        Block[Xp][Yp]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);"); //人消失
        block[Xp][Yp].havePerson=0;
        Block[X][Y]->setStyleSheet("border-image:url(:/new/prefix1/digger5.png);color:rgba(0,0,0,0);width:35px;height:35px;");  //人出现
        block[X][Y].havePerson=1;

        FallPerson();
    }
    else;
}

void GameBoard::unlocked(){
    int i,j;
    LookforPerson();
    for(i=0;i<ROW+2;i++)
        for(j=0;j<COL+2;j++)
            Block[i][j]->setEnabled(false);
    Block[Xp][Yp-1]->setEnabled(true);
    Block[Xp][Yp+1]->setEnabled(true);
    Block[Xp+1][Yp]->setEnabled(true);
    for(i=0;i<ROW+2;i++){
        Block[i][0]->setEnabled(false);
        Block[i][COL+1]->setEnabled(false);
    }
    for(i=1;i<COL;i++)
        Block[ROW+1][i]->setEnabled(false);
}

//砖块出 object
void GameBoard::showObject(int x,int y){

    if(block[x][y].change==1)   //50%出现火
    {
        Block[x][y]->setStyleSheet("border-image:url(:/new/prefix1/fire.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else if(block[x][y].change==2)   // 10%出现钻石
    {
        Block[x][y]->setStyleSheet("border-image:url(:/new/prefix1/diamond.png);color:rgba(0,0,0,0);width:35px;height:35px;");

    }
    else if(block[x][y].change==3)  //10%出现金钱
    {
        Block[x][y]->setStyleSheet("border-image:url(:/new/prefix1/money.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else if(block[x][y].change==4)  //10%出现HP
    {
        Block[x][y]->setStyleSheet("border-image:url(:/new/prefix1/redheart.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else {
        Block[x][y]->setStyleSheet("background:rgba(0,0,0,0);border-radius: 2px;height:35px;width:35px;border: 2px rgba(0,0,0,0);border-style: outset;color:rgba(0,0,0,0);");
    }
}


void GameBoard::changeTo(){
    int randObject;
    randObject=rand()%100;
    if(block[X][Y].color==0)   //对应着灰色
    {
        if(0<=randObject&&randObject<=10)   //10%出现火
        {
            block[X][Y].change=1;//火
        }
        else if(11<=randObject&&randObject<=20)   // 10%出现钻石
        {
            block[X][Y].change=2;//钻石
        }
        else if(21<=randObject&&randObject<=30)  //10%出现金钱
        {
            block[X][Y].change=3;
        }
        else if(31<=randObject&&randObject<=40)  //10%出现HP
        {
            block[X][Y].change=4;
        }
        else {
            block[X][Y].change=0;
        }
    }
    else if(block[X][Y].color==1)   //对应着红色
    {
        if(0<=randObject&&randObject<=50)   //50%出现火
        {
            block[X][Y].change=1;
        }
        else if(51<=randObject&&randObject<=60)   // 10%出现钻石
        {
            block[X][Y].change=2;
        }
        else if(61<=randObject&&randObject<=70)  //10%出现金钱
        {
            block[X][Y].change=3;
        }
        else if(71<=randObject&&randObject<=90)  //20%出现HP
        {
            block[X][Y].change=4;
        }
        else {
            block[X][Y].change=0;
        }
    }
    else if(block[X][Y].color==2)   //对应着绿色，出现钻石的概率高
    {
        if(0<=randObject&&randObject<=30)   //30%出现火
        {
            block[X][Y].change=1;
        }
        else if(31<=randObject&&randObject<=60)   // 30%出现钻石
        {
            block[X][Y].change=2;
        }
        else if(61<=randObject&&randObject<=70)  //10%出现金钱
        {
            block[X][Y].change=3;
        }
        else if(71<=randObject&&randObject<=80)  //10%出现HP
        {
            block[X][Y].change=4;
        }
        else {
            block[X][Y].change=0;
        }
    }
    else if(block[X][Y].color==3)   //对应着黄色，出现钱的概率高
    {
        if(0<=randObject&&randObject<=30)   //30%出现火
        {
            block[X][Y].change=1;
        }
        else if(31<=randObject&&randObject<=40)   // 10%出现钻石
        {
            block[X][Y].change=2;
        }
        else if(41<=randObject&&randObject<=70)  //30%出现金钱
        {
            block[X][Y].change=3;
        }
        else if(71<=randObject&&randObject<=80)  //10%出现HP
        {
            block[X][Y].change=4;
        }
        else {
            block[X][Y].change=0;
        }
    }
    else;
}

void GameBoard::Change()
{
    changeTo();
    showObject(X,Y);
}

void GameBoard::get()
{
    if(block[Xp][Yp].change==1){   //对应着火
        LIFE--;
        Block[Xp][Yp]->setStyleSheet("border-image:url(:/new/prefix1/onfire.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        if(fibl==1){
            emit firstblood();
            fibl=0;
        }
    }
    else if(block[Xp][Yp].change==2) { //对应着钻石，加分
        SCORE=SCORE+1000;
        score->setText(QString::number(SCORE));
    }
    else if(block[Xp][Yp].change==3){   //对应着金币，加钱
        SCORE=SCORE+100;
        score->setText(QString::number(SCORE));
    }
    else if(block[Xp][Yp].change==4)   //对应着爱心加生命
        LIFE++;
    else;

    block[Xp][Yp].change=0;
    if(LIFE>=3){
        LIFE=3;
        life_1->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_2->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_3->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else if(LIFE==2){
        life_1->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_2->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_3->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else if(LIFE==1){
        life_1->setStyleSheet("border-image:url(:/new/prefix1/fulllife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_2->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_3->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
    else{
        life_1->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_2->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        life_3->setStyleSheet("border-image:url(:/new/prefix1/emptylife.png);color:rgba(0,0,0,0);width:35px;height:35px;");
    }
}

void GameBoard::winlose()
{
    LookforPerson();
    if(LIFE==0)
        lose();
    else if(Xp==ROW)
        win();
    else;
}

void GameBoard::Reflection(){
    if(block[X][Y].haveBlock)
    {
        LookforPerson();
        if(Y>Yp){
            Block[Xp][Yp]->setStyleSheet("border-image:url(:/new/prefix1/digger8.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        }
        else if(Y<Yp){
            Block[Xp][Yp]->setStyleSheet("border-image:url(:/new/prefix1/digger9.png);color:rgba(0,0,0,0);width:35px;height:35px;");
        }
        else;
        SCORE+=10;
        score->setText(QString::number(SCORE));
        //disappear();
        block[X][Y].boom=1;
        ChainBoom();
        Change();
        FallPerson();
    }
    else
    {
        LookforPerson();
        if(Y>Yp){
            Block[Xp][Yp]->setStyleSheet("border-image:url(:/new/prefix1/digger4.png);color:rgba(0,0,0,0);width:35px;height:35px;");
            MovePersonR();
        }
        else if(Y<Yp){
            Block[Xp][Yp]->setStyleSheet("border-image:url(:/new/prefix1/digger5.png);color:rgba(0,0,0,0);width:35px;height:35px;");
            MovePersonL();
        }
        else;
    }
    get();
    winlose();
    unlocked();
}


//click

void GameBoard::click_00(){X=0;Y=0;Reflection();}
void GameBoard::click_01(){X=0;Y=1;Reflection();}
void GameBoard::click_02(){X=0;Y=2;Reflection();}
void GameBoard::click_03(){X=0;Y=3;Reflection();}
void GameBoard::click_04(){X=0;Y=4;Reflection();}
void GameBoard::click_05(){X=0;Y=5;Reflection();}
void GameBoard::click_06(){X=0;Y=6;Reflection();}
void GameBoard::click_07(){X=0;Y=7;Reflection();}
void GameBoard::click_08(){X=0;Y=8;Reflection();}
void GameBoard::click_10(){X=1;Y=0;Reflection();}
void GameBoard::click_11(){X=1;Y=1;Reflection();}
void GameBoard::click_12(){X=1;Y=2;Reflection();}
void GameBoard::click_13(){X=1;Y=3;Reflection();}
void GameBoard::click_14(){X=1;Y=4;Reflection();}
void GameBoard::click_15(){X=1;Y=5;Reflection();}
void GameBoard::click_16(){X=1;Y=6;Reflection();}
void GameBoard::click_17(){X=1;Y=7;Reflection();}
void GameBoard::click_18(){X=1;Y=8;Reflection();}
void GameBoard::click_20(){X=2;Y=0;Reflection();}
void GameBoard::click_21(){X=2;Y=1;Reflection();}
void GameBoard::click_22(){X=2;Y=2;Reflection();}
void GameBoard::click_23(){X=2;Y=3;Reflection();}
void GameBoard::click_24(){X=2;Y=4;Reflection();}
void GameBoard::click_25(){X=2;Y=5;Reflection();}
void GameBoard::click_26(){X=2;Y=6;Reflection();}
void GameBoard::click_27(){X=2;Y=7;Reflection();}
void GameBoard::click_28(){X=2;Y=8;Reflection();}
void GameBoard::click_30(){X=3;Y=0;Reflection();}
void GameBoard::click_31(){X=3;Y=1;Reflection();}
void GameBoard::click_32(){X=3;Y=2;Reflection();}
void GameBoard::click_33(){X=3;Y=3;Reflection();}
void GameBoard::click_34(){X=3;Y=4;Reflection();}
void GameBoard::click_35(){X=3;Y=5;Reflection();}
void GameBoard::click_36(){X=3;Y=6;Reflection();}
void GameBoard::click_37(){X=3;Y=7;Reflection();}
void GameBoard::click_38(){X=3;Y=8;Reflection();}
void GameBoard::click_40(){X=4;Y=0;Reflection();}
void GameBoard::click_41(){X=4;Y=1;Reflection();}
void GameBoard::click_42(){X=4;Y=2;Reflection();}
void GameBoard::click_43(){X=4;Y=3;Reflection();}
void GameBoard::click_44(){X=4;Y=4;Reflection();}
void GameBoard::click_45(){X=4;Y=5;Reflection();}
void GameBoard::click_46(){X=4;Y=6;Reflection();}
void GameBoard::click_47(){X=4;Y=7;Reflection();}
void GameBoard::click_48(){X=4;Y=8;Reflection();}
void GameBoard::click_50(){X=5;Y=0;Reflection();}
void GameBoard::click_51(){X=5;Y=1;Reflection();}
void GameBoard::click_52(){X=5;Y=2;Reflection();}
void GameBoard::click_53(){X=5;Y=3;Reflection();}
void GameBoard::click_54(){X=5;Y=4;Reflection();}
void GameBoard::click_55(){X=5;Y=5;Reflection();}
void GameBoard::click_56(){X=5;Y=6;Reflection();}
void GameBoard::click_57(){X=5;Y=7;Reflection();}
void GameBoard::click_58(){X=5;Y=8;Reflection();}
void GameBoard::click_60(){X=6;Y=0;Reflection();}
void GameBoard::click_61(){X=6;Y=1;Reflection();}
void GameBoard::click_62(){X=6;Y=2;Reflection();}
void GameBoard::click_63(){X=6;Y=3;Reflection();}
void GameBoard::click_64(){X=6;Y=4;Reflection();}
void GameBoard::click_65(){X=6;Y=5;Reflection();}
void GameBoard::click_66(){X=6;Y=6;Reflection();}
void GameBoard::click_67(){X=6;Y=7;Reflection();}
void GameBoard::click_68(){X=6;Y=8;Reflection();}
void GameBoard::click_70(){X=7;Y=0;Reflection();}
void GameBoard::click_71(){X=7;Y=1;Reflection();}
void GameBoard::click_72(){X=7;Y=2;Reflection();}
void GameBoard::click_73(){X=7;Y=3;Reflection();}
void GameBoard::click_74(){X=7;Y=4;Reflection();}
void GameBoard::click_75(){X=7;Y=5;Reflection();}
void GameBoard::click_76(){X=7;Y=6;Reflection();}
void GameBoard::click_77(){X=7;Y=7;Reflection();}
void GameBoard::click_78(){X=7;Y=8;Reflection();}
void GameBoard::click_80(){X=8;Y=0;Reflection();}
void GameBoard::click_81(){X=8;Y=1;Reflection();}
void GameBoard::click_82(){X=8;Y=2;Reflection();}
void GameBoard::click_83(){X=8;Y=3;Reflection();}
void GameBoard::click_84(){X=8;Y=4;Reflection();}
void GameBoard::click_85(){X=8;Y=5;Reflection();}
void GameBoard::click_86(){X=8;Y=6;Reflection();}
void GameBoard::click_87(){X=8;Y=7;Reflection();}
void GameBoard::click_88(){X=8;Y=8;Reflection();}
void GameBoard::click_90(){X=9;Y=0;Reflection();}
void GameBoard::click_91(){X=9;Y=1;Reflection();}
void GameBoard::click_92(){X=9;Y=2;Reflection();}
void GameBoard::click_93(){X=9;Y=3;Reflection();}
void GameBoard::click_94(){X=9;Y=4;Reflection();}
void GameBoard::click_95(){X=9;Y=5;Reflection();}
void GameBoard::click_96(){X=9;Y=6;Reflection();}
void GameBoard::click_97(){X=9;Y=7;Reflection();}
void GameBoard::click_98(){X=9;Y=8;Reflection();}
void GameBoard::click_100(){X=10;Y=0;Reflection();}
void GameBoard::click_101(){X=10;Y=1;Reflection();}
void GameBoard::click_102(){X=10;Y=2;Reflection();}
void GameBoard::click_103(){X=10;Y=3;Reflection();}
void GameBoard::click_104(){X=10;Y=4;Reflection();}
void GameBoard::click_105(){X=10;Y=5;Reflection();}
void GameBoard::click_106(){X=10;Y=6;Reflection();}
void GameBoard::click_107(){X=10;Y=7;Reflection();}
void GameBoard::click_108(){X=10;Y=8;Reflection();}
void GameBoard::click_110(){X=11;Y=0;Reflection();}
void GameBoard::click_111(){X=11;Y=1;Reflection();}
void GameBoard::click_112(){X=11;Y=2;Reflection();}
void GameBoard::click_113(){X=11;Y=3;Reflection();}
void GameBoard::click_114(){X=11;Y=4;Reflection();}
void GameBoard::click_115(){X=11;Y=5;Reflection();}
void GameBoard::click_116(){X=11;Y=6;Reflection();}
void GameBoard::click_117(){X=11;Y=7;Reflection();}
void GameBoard::click_118(){X=11;Y=8;Reflection();}

//所有的connect

void GameBoard::Connects(){
    connect(Block[0][0],SIGNAL(clicked()),this,SLOT(click_00()));
    connect(Block[0][1],SIGNAL(clicked()),this,SLOT(click_01()));
    connect(Block[0][2],SIGNAL(clicked()),this,SLOT(click_02()));
    connect(Block[0][3],SIGNAL(clicked()),this,SLOT(click_03()));
    connect(Block[0][4],SIGNAL(clicked()),this,SLOT(click_04()));
    connect(Block[0][5],SIGNAL(clicked()),this,SLOT(click_05()));
    connect(Block[0][6],SIGNAL(clicked()),this,SLOT(click_06()));
    connect(Block[0][7],SIGNAL(clicked()),this,SLOT(click_07()));
    connect(Block[0][8],SIGNAL(clicked()),this,SLOT(click_08()));
    connect(Block[1][0],SIGNAL(clicked()),this,SLOT(click_10()));
    connect(Block[1][1],SIGNAL(clicked()),this,SLOT(click_11()));
    connect(Block[1][2],SIGNAL(clicked()),this,SLOT(click_12()));
    connect(Block[1][3],SIGNAL(clicked()),this,SLOT(click_13()));
    connect(Block[1][4],SIGNAL(clicked()),this,SLOT(click_14()));
    connect(Block[1][5],SIGNAL(clicked()),this,SLOT(click_15()));
    connect(Block[1][6],SIGNAL(clicked()),this,SLOT(click_16()));
    connect(Block[1][7],SIGNAL(clicked()),this,SLOT(click_17()));
    connect(Block[1][8],SIGNAL(clicked()),this,SLOT(click_18()));
    connect(Block[2][0],SIGNAL(clicked()),this,SLOT(click_20()));
    connect(Block[2][1],SIGNAL(clicked()),this,SLOT(click_21()));
    connect(Block[2][2],SIGNAL(clicked()),this,SLOT(click_22()));
    connect(Block[2][3],SIGNAL(clicked()),this,SLOT(click_23()));
    connect(Block[2][4],SIGNAL(clicked()),this,SLOT(click_24()));
    connect(Block[2][5],SIGNAL(clicked()),this,SLOT(click_25()));
    connect(Block[2][6],SIGNAL(clicked()),this,SLOT(click_26()));
    connect(Block[2][7],SIGNAL(clicked()),this,SLOT(click_27()));
    connect(Block[2][8],SIGNAL(clicked()),this,SLOT(click_28()));
    connect(Block[3][0],SIGNAL(clicked()),this,SLOT(click_30()));
    connect(Block[3][1],SIGNAL(clicked()),this,SLOT(click_31()));
    connect(Block[3][2],SIGNAL(clicked()),this,SLOT(click_32()));
    connect(Block[3][3],SIGNAL(clicked()),this,SLOT(click_33()));
    connect(Block[3][4],SIGNAL(clicked()),this,SLOT(click_34()));
    connect(Block[3][5],SIGNAL(clicked()),this,SLOT(click_35()));
    connect(Block[3][6],SIGNAL(clicked()),this,SLOT(click_36()));
    connect(Block[3][7],SIGNAL(clicked()),this,SLOT(click_37()));
    connect(Block[3][8],SIGNAL(clicked()),this,SLOT(click_38()));
    connect(Block[4][0],SIGNAL(clicked()),this,SLOT(click_40()));
    connect(Block[4][1],SIGNAL(clicked()),this,SLOT(click_41()));
    connect(Block[4][2],SIGNAL(clicked()),this,SLOT(click_42()));
    connect(Block[4][3],SIGNAL(clicked()),this,SLOT(click_43()));
    connect(Block[4][4],SIGNAL(clicked()),this,SLOT(click_44()));
    connect(Block[4][5],SIGNAL(clicked()),this,SLOT(click_45()));
    connect(Block[4][6],SIGNAL(clicked()),this,SLOT(click_46()));
    connect(Block[4][7],SIGNAL(clicked()),this,SLOT(click_47()));
    connect(Block[4][8],SIGNAL(clicked()),this,SLOT(click_48()));
    connect(Block[5][0],SIGNAL(clicked()),this,SLOT(click_50()));
    connect(Block[5][1],SIGNAL(clicked()),this,SLOT(click_51()));
    connect(Block[5][2],SIGNAL(clicked()),this,SLOT(click_52()));
    connect(Block[5][3],SIGNAL(clicked()),this,SLOT(click_53()));
    connect(Block[5][4],SIGNAL(clicked()),this,SLOT(click_54()));
    connect(Block[5][5],SIGNAL(clicked()),this,SLOT(click_55()));
    connect(Block[5][6],SIGNAL(clicked()),this,SLOT(click_56()));
    connect(Block[5][7],SIGNAL(clicked()),this,SLOT(click_57()));
    connect(Block[5][8],SIGNAL(clicked()),this,SLOT(click_58()));
    connect(Block[6][0],SIGNAL(clicked()),this,SLOT(click_60()));
    connect(Block[6][1],SIGNAL(clicked()),this,SLOT(click_61()));
    connect(Block[6][2],SIGNAL(clicked()),this,SLOT(click_62()));
    connect(Block[6][3],SIGNAL(clicked()),this,SLOT(click_63()));
    connect(Block[6][4],SIGNAL(clicked()),this,SLOT(click_64()));
    connect(Block[6][5],SIGNAL(clicked()),this,SLOT(click_65()));
    connect(Block[6][6],SIGNAL(clicked()),this,SLOT(click_66()));
    connect(Block[6][7],SIGNAL(clicked()),this,SLOT(click_67()));
    connect(Block[6][8],SIGNAL(clicked()),this,SLOT(click_68()));
    connect(Block[7][0],SIGNAL(clicked()),this,SLOT(click_70()));
    connect(Block[7][1],SIGNAL(clicked()),this,SLOT(click_71()));
    connect(Block[7][2],SIGNAL(clicked()),this,SLOT(click_72()));
    connect(Block[7][3],SIGNAL(clicked()),this,SLOT(click_73()));
    connect(Block[7][4],SIGNAL(clicked()),this,SLOT(click_74()));
    connect(Block[7][5],SIGNAL(clicked()),this,SLOT(click_75()));
    connect(Block[7][6],SIGNAL(clicked()),this,SLOT(click_76()));
    connect(Block[7][7],SIGNAL(clicked()),this,SLOT(click_77()));
    connect(Block[7][8],SIGNAL(clicked()),this,SLOT(click_78()));
    connect(Block[8][0],SIGNAL(clicked()),this,SLOT(click_80()));
    connect(Block[8][1],SIGNAL(clicked()),this,SLOT(click_81()));
    connect(Block[8][2],SIGNAL(clicked()),this,SLOT(click_82()));
    connect(Block[8][3],SIGNAL(clicked()),this,SLOT(click_83()));
    connect(Block[8][4],SIGNAL(clicked()),this,SLOT(click_84()));
    connect(Block[8][5],SIGNAL(clicked()),this,SLOT(click_85()));
    connect(Block[8][6],SIGNAL(clicked()),this,SLOT(click_86()));
    connect(Block[8][7],SIGNAL(clicked()),this,SLOT(click_87()));
    connect(Block[8][8],SIGNAL(clicked()),this,SLOT(click_88()));
    connect(Block[9][0],SIGNAL(clicked()),this,SLOT(click_90()));
    connect(Block[9][1],SIGNAL(clicked()),this,SLOT(click_91()));
    connect(Block[9][2],SIGNAL(clicked()),this,SLOT(click_92()));
    connect(Block[9][3],SIGNAL(clicked()),this,SLOT(click_93()));
    connect(Block[9][4],SIGNAL(clicked()),this,SLOT(click_94()));
    connect(Block[9][5],SIGNAL(clicked()),this,SLOT(click_95()));
    connect(Block[9][6],SIGNAL(clicked()),this,SLOT(click_96()));
    connect(Block[9][7],SIGNAL(clicked()),this,SLOT(click_97()));
    connect(Block[9][8],SIGNAL(clicked()),this,SLOT(click_98()));
    connect(Block[10][0],SIGNAL(clicked()),this,SLOT(click_100()));
    connect(Block[10][1],SIGNAL(clicked()),this,SLOT(click_101()));
    connect(Block[10][2],SIGNAL(clicked()),this,SLOT(click_102()));
    connect(Block[10][3],SIGNAL(clicked()),this,SLOT(click_103()));
    connect(Block[10][4],SIGNAL(clicked()),this,SLOT(click_104()));
    connect(Block[10][5],SIGNAL(clicked()),this,SLOT(click_105()));
    connect(Block[10][6],SIGNAL(clicked()),this,SLOT(click_106()));
    connect(Block[10][7],SIGNAL(clicked()),this,SLOT(click_107()));
    connect(Block[10][8],SIGNAL(clicked()),this,SLOT(click_108()));
    connect(Block[11][0],SIGNAL(clicked()),this,SLOT(click_110()));
    connect(Block[11][1],SIGNAL(clicked()),this,SLOT(click_111()));
    connect(Block[11][2],SIGNAL(clicked()),this,SLOT(click_112()));
    connect(Block[11][3],SIGNAL(clicked()),this,SLOT(click_113()));
    connect(Block[11][4],SIGNAL(clicked()),this,SLOT(click_114()));
    connect(Block[11][5],SIGNAL(clicked()),this,SLOT(click_115()));
    connect(Block[11][6],SIGNAL(clicked()),this,SLOT(click_116()));
    connect(Block[11][7],SIGNAL(clicked()),this,SLOT(click_117()));
    connect(Block[11][8],SIGNAL(clicked()),this,SLOT(click_118()));
}


void GameBoard::create_input(){
    inputbox=new QGroupBox;

    time_clock=new QTime;
    time_timer=new QTimer;

    begin=Start;
    end=Exit;
    time_show=time;
    time_show->setFixedSize(100,30);

    time_clock->setHMS(0,0,0,0);
    time_show->setText(time_clock->toString("hh:mm:ss.zzz"));

    connect(begin,&QPushButton::clicked,
            this,&GameBoard::timestart);
    connect(end,&QPushButton::clicked,
            this,&GameBoard::timeend);
}

void GameBoard::timestart(){//如果暂停了
    int i,j;
    if(isstart==false){
        begin->setText("继续游戏");
        isstart=true;//下一次开始
        time_timer->stop();//暂停计时
        for(i=0;i<=ROW;i++)
            for(j=1;j<=COL;j++)
                Block[i][j]->setEnabled(false);
        MusicOff();
        return;
    }
    else{
        isstart=false;//下一次结束
        begin->setText(tr("暂停游戏"));
        time_timer->start(47);//每47毫秒timeout一次
        if(startagain==false){//如果是第一次
            connect(time_timer,SIGNAL(timeout()),
                    this,SLOT(addtime()));//添加时间
            startagain=true;
        }
        for(i=0;i<=ROW;i++)
            for(j=1;j<=COL;j++)
                Block[i][j]->setEnabled(true);
        MusicOn();
    }
}

void GameBoard::timeend(){
    time_timer->stop();//计时停止
    begin->setText(tr("开始游戏"));
    time_clock->setHMS(0,0,0,0);//时间清空
    time_show->setText(time_clock->toString("hh:mm:ss.zzz"));//设置成00:00:00.000的形式
    isstart=true;
}

void GameBoard::addtime(){
    *time_clock=time_clock->addMSecs(47);//添加四十七毫秒，若是更短则会导致延迟现象
    time_show->setText(time_clock->toString("hh:mm:ss.zzz"));//设置成00:00:00.000的形式
}
