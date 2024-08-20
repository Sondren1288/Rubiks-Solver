#include <string>
#include <iostream>

#include "graph.h"
#include "node.h"
#include "cube.h"



int main() {
    // Create type of 6 colors
    // Init graph
    // Init state
    // Calculate next positions
    cube::Cube cube = cube::Cube();
    
    std::cout << cube.cubeString() << std::endl << std::endl;
    cube.leftDown();
    std::cout << cube.cubeString() << std::endl << std::endl;
    cube.leftUp();
    std::cout << cube.cubeString() << std::endl;

    return 0;
}
