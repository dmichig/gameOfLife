//
// Created by Michał Laskowski on 10/05/2020.
//

#include "space.h"
#include "iostream"

void space::setSizeX(int x) {
    sizeX = x;
}

void space::setSizeY(int y) {
    sizeY = y;
}

int space::getSizeX() {
    return sizeX;
}

int space::getSizeY() {
    return sizeY;
}

void space::setNeighbours() {
    std::cout << "start setting neighbours\n";
    for(int i=0; i<space::sizeX; i++){
        for(int j=0; j<space::sizeY; j++){
            if (!matrix[i][j].neighbours.empty()){
                matrix[i][j].neighbours.clear();
            }
            for(int a=-1; a<2; a++){
                for(int b=-1; b<2; b++){
                    if(a==0 && b==0) {}
                    else if(i+a>=0 && i+a<space::sizeX && j+b>=0 && j+b<space::sizeY){
                            matrix[i][j].neighbours.insert(matrix[i][j].neighbours.end(), std::tuple<int,int> {i+a, j+b});
                        }
                    }
                }
            }
        }
    std::cout << "end setting neighbours\n";
}

void space::step() {
    std::cout << "start step\n";

    for(int i=0; i<space::sizeX; i++){
        for(int j=0; j<space::sizeY; j++) {
            newMatrix[i][j].state = matrix[i][j].state;
        }
    }


    for(int i=0; i<space::sizeX; i++){
        for(int j=0; j<space::sizeY; j++){
            int aliveCounter = 0;

            for (int c = 0; c < space::matrix[i][j].neighbours.size(); c++){
                std::tuple<int,int> it = space::matrix[i][j].neighbours[c];
                if (space::matrix[std::get<0>(it)][std::get<1>(it)].state == 1){
                    aliveCounter++;
                }
            }
            if (space::matrix[i][j].state == 1){
                if (aliveCounter < 2 || aliveCounter > 3){
                    space::newMatrix[i][j].state = false;
                }
            } else {
                if (aliveCounter == 3){
                    space::newMatrix[i][j].state = true;
                }
            }
        }
    }

    for(int i=0; i<space::sizeX; i++){
        for(int j=0; j<space::sizeY; j++) {
            matrix[i][j].state = newMatrix[i][j].state;
        }
    }

    std::cout << "end step\n";

}

void space::visualisation() {
    std::cout << "start visualisating\n";

    for(int i=0; i<space::sizeX; i++){
        for(int j=0; j<space::sizeY; j++){
            std::cout << space::matrix[i][j].state << " ";
        }
        std::cout << "\n";
    }
    std::cout << "end visualisating\n";

}

space::space() {
    int x,y;

    std::cout << "Podaj wymiar X przestrzeni: \n";
    std::cin >> x;
    std::cout << "Podaj wymiar Y przestrzeni: \n";
    std::cin >> y;

    setSizeX(x);
    setSizeY(y);

    matrix = new cell*[sizeX];

    for(int i=0;i<sizeX;i++){
        matrix[i] = new cell[sizeY];
    }

}

space::space(int x, int y) {

    setSizeX(x);
    setSizeY(y);

    matrix = new cell*[sizeX];
    newMatrix = new cell*[sizeX];

    for(int i=0;i<sizeX;i++){
        matrix[i] = new cell[sizeY];
        newMatrix[i] = new cell[sizeY];
    }

}

space::~space() {}