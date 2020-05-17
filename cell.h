//
// Created by Michał Laskowski on 10/05/2020.
//

#ifndef GAMEOFLIFE_CELL_H
#define GAMEOFLIFE_CELL_H

#include <vector>

class cell {
public:

    static int cellID;

    int ID;
    bool state;

    std::vector<std::tuple<int, int>> neighbours;

    cell();
    ~cell();

    int getCellID();
    bool getCellState();

    std::vector<std::tuple<int,int>> getNeighbours();

    void setCellState(bool state);

};


#endif //GAMEOFLIFE_CELL_H
