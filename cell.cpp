//
// Created by Michał Laskowski on 10/05/2020.
//

#include "cell.h"

int cell::cellID = 0;

cell::cell() {
    ID = cellID++;
    state = false;
}

cell::~cell() {}

int cell::getCellID() {
    return ID;
}

bool cell::getCellState() {
    return state;
}

void cell::setCellState(bool newState) {
    state = newState;
}

std::vector<std::tuple<int,int>> cell::getNeighbours(){
    return neighbours;
}