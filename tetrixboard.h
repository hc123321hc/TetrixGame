#ifndef TETRIXBOARD_H
#define TETRIXBOARD_H
#include<QBasicTimer>
#include <QFrame>
#include<QLabel>
#include<QPointer>
#include"tetrixpiece.h"
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QAudioOutput>
class TetrixBoard : public QFrame
{
    Q_OBJECT
public:
    TetrixBoard(QWidget* parent = nullptr);
    void setNextPieceLabel(QLabel* label);
public slots:
      void puase();
    void start();
      void restart();
signals:
    void levelChanged(int level);
    void scoreChanged(int score);
    void linesRemovedChanged(int numLines);
private:

    void showNextPiece();
    void newPiece();
     void removeFullLines();
    enum{DropScore=7,BoardWidth=12,BoardHeight=22,NextLevelNumber=25};
    int squareWidth(){return contentsRect().width()/BoardWidth;}
    int squareHeight(){return contentsRect().height()/BoardHeight;}
    void oneLineDown();
    void pieceDropped(int dropHeight);
    void clearBoard();
    bool tryMove(const TetrixPiece &newPiece,int newX,int newY);
    TetrixShape& shapeAt(int x,int y){return boardBlocks[y*BoardWidth+x];}
    void drawSquare(QPainter &painter,int x,int y,TetrixShape shape);
    int timeoutTime(){return 500/(1+level);}
    void dropDown();
private:
    QPointer<QLabel> nextPieceLabel;
    TetrixPiece nextPiece;
    TetrixPiece curPiece;
    int curX;
    int curY;
    TetrixShape boardBlocks[BoardWidth*BoardHeight];
    bool isStarted=false;
    bool isPaused=false;
    int numLinesRemoved=0;
    int numPiecesDropped=0;
    int score=0;
    int level=1;
    QBasicTimer timer;
    QMediaPlayer bgMusic;
    QAudioOutput audioOutput;
    QSoundEffect removeSound;
    QSoundEffect downSound;
    QSoundEffect gameOverSound;
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // TETRIXBOARD_H
