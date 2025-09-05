#ifndef TETRIXPIECE_H
#define TETRIXPIECE_H
//这里没写class，需要隐式转换为int
enum TetrixShape { NoShape, ZShape, SShape, LineShape, TShape, SquareShape,MirroredLShape ,LShape};

class TetrixPiece
{
public:
    TetrixPiece();
    void setShape(TetrixShape shape);
    TetrixShape shape(){return pieceShape;}
    void setRandomShape();
    int minX();
    int maxX();
    int minY();
    int maxY();
    TetrixPiece rotatedLeft();
    TetrixPiece rotatedRight();
    int x(int index) const{return coords[index][0];}
    int y(int index)const{return coords[index][1];}


private:
    void setX(int index,int value){coords[index][0]=value;}
    void setY(int index,int value){coords[index][1]=value;}

    TetrixShape pieceShape;//抽象的描述
    int coords[4][2];//具体的描述
};

#endif // TETRIXPIECE_H
