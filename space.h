//
// Created by Michał Laskowski on 10/05/2020.
//

#ifndef GAMEOFLIFE_SPACE_H
#define GAMEOFLIFE_SPACE_H

#include "cell.h"


class space {
public:
    int sizeX;
    int sizeY;

    cell** matrix;
    cell** newMatrix;

    space();
    space(int x, int y);
    ~space();

    int getSizeX();
    int getSizeY();

    void setSizeX(int x);
    void setSizeY(int y);

    void setNeighbours();
    void step();
    void visualisation();

};


#endif //GAMEOFLIFE_SPACE_H
