#include <iostream>
#include "cell.h"
#include "space.h"
#include <unistd.h>

int main() {

    space Space(5,5);

    Space.setNeighbours();

    int x = int(Space.getSizeX()/2);
    int y = int(Space.getSizeY()/2);

    Space.matrix[x][y].state = true;
    Space.matrix[x-1][y].state = true;
    Space.matrix[x+1][y].state = true;

    int licznik = 0;

    while (licznik < 5){
        Space.visualisation();
        Space.step();
        //usleep(500000);
        licznik = licznik + 1;
        std::cout << "\n";
    }

    return 0;
}
