#include "tetrixpiece.h"
#include<QRandomGenerator>
TetrixPiece::TetrixPiece() {
    setShape(NoShape);

}

void TetrixPiece::setShape(TetrixShape shape)
{
     //不同形状四个块的位置
    //NoShape
    //ZShape
    //SShape
    //LineShape
    //TShape
    //SquareShape
    //MirroredLShape
    //LShape
    static constexpr int coordsTable[8][4][2] = {
        { { 0, 0 },  { 0, 0 },  { 0, 0 },  { 0, 0 } },
        { { 0, -1 }, { 0, 0 },  { -1, 0 }, { -1, 1 } },
        { { 0, -1 }, { 0, 0 },  { 1, 0 },  { 1, 1 } },
        { { 0, -1 }, { 0, 0 },  { 0, 1 },  { 0, 2 } },
        { { -1, 0 }, { 0, 0 }, { 1, 0 },  { 0, 1 } },
        { { 0, 0 },  { 1, 0 },  { 0, 1 },  { 1, 1 } },
        { { -1, -1 }, { 0, -1 }, { 0, 0 },  { 0, 1 } },
        { { 1, -1 }, { 0, -1 }, { 0, 0 },  { 0, 1 } }
    };
      //设置具体的描述
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            coords[i][j]=coordsTable[shape][i][j];
        }
    }
    //设置抽象的描述
    pieceShape=shape;
}

void TetrixPiece::setRandomShape()
{
    setShape(TetrixShape(QRandomGenerator::global()->bounded(7)+1));
}

int TetrixPiece::minX()
{
    int min=coords[0][0];
    for(int i=1;i<4;i++)
        min=qMin(min,coords[i][0]);
    return min;
}

int TetrixPiece::maxX()
{
    int max=coords[0][0];
    for(int i=1;i<4;i++)
        max=qMax(max,coords[i][0]);
    return max;
}

int TetrixPiece::minY()
{
    int min=coords[0][1];
    for(int i=1;i<4;i++){
        min=qMin(min,coords[i][1]);
    }
    return min;
}

int TetrixPiece::maxY()
{
    int max=coords[0][1];
    for(int i=1;i<4;i++){
        max=qMax(max,coords[i][1]);
    }
    return max;
}

TetrixPiece TetrixPiece::rotatedLeft()
{
    if(pieceShape==SquareShape)return *this;
    TetrixPiece result;
    result.setShape(pieceShape);
    //旋转90度，改变四个小块的坐标//逆时针选择，y,-x,y轴正方向，向下
    for(int i=0;i<4;i++){
        result.setX(i,y(i));
        result.setY(i,-x(i));
    }
    return result;
}

TetrixPiece TetrixPiece::rotatedRight()
{
    if(pieceShape==SquareShape)return *this;
    TetrixPiece result;
    result.setShape(pieceShape);
    //顺时针旋转90度，改变四个小块的坐标//逆时针选择，-y,x，y轴正方向，向下
    for(int i=0;i<4;i++){
        result.setX(i,-y(i));
        result.setY(i,x(i));
    }
    return result;
}

