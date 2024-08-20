#include <vector>

#include "cube.h"


using namespace cube;

Cube::Cube() {
    // Default face
    /* 
     *      [y]
     *  [o] [b] [r] [g]
     *      [w]
     */
    // [i][j] = y x coord
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            up[i][j] = 'y';    // Yellow
            left[i][j] = 'o';  // Orange
            front[i][j] = 'b'; // Blue
            right[i][j] = 'r'; // Red
            back[i][j] = 'g';  // Green
            down[i][j] = 'w';  // White
        }
    }
    // Debug
    up[0][0] = 'U';
    up[2][0] = 'u';

    left[0][2] = 't';
    left[1][2] = 'T';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            left[i][j] = i + j*3 + 65;
        }
    }

    front[0][0] = 'F';
    front[2][0] = 'f';

    down[0][0] = 'D';
    down[2][0] = 'd';

    back[0][2] = 'b';
    back[2][2] = 'B';
}


std::string Cube::cubeString() {
    std::vector<std::string> vecString = {"","","","","","","","",""};
    std::string retString = ""; 
    for (int i = 0; i < 3*6*2; i++) {
        for (int j = 0; j < 3*3; j++) {
            vecString[j].append(" ");
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vecString[i  ][j*2+3*2] = up[i][j]; 
            vecString[i+3][j*2    ] = left[i][j]; 
            vecString[i+3][j*2+3*2] = front[i][j]; 
            vecString[i+3][j*2+6*2] = right[i][j];
            vecString[i+3][j*2+9*2] = back[i][j];
            vecString[i+6][j*2+3*2] = down[i][j];
        }
    } 

    for (int i = 0; i < vecString.size(); i++) {
        if (i != 0) {
            retString += "\n";
        }
        retString += vecString[i];
    }

    return retString;
}

void Cube::replaceFace(char (&first)[3][3], char (&second)[3][3]) {
    // Replaces first with the second
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            first[i][j] = second[i][j];
        }
    }
}


void Cube::leftDown() {
    // Rotate left clockwise
    char tempFace[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tempFace[j][2-i] = left[i][j];
        }
    }
    replaceFace(left, tempFace);
    
    // move front[:][1] -> down[:][1]->back[:][3]->up[:][1]
    char temp;
    for (int i = 0; i < 3; i++) {
        temp = up[i][0];
        up[i][0] = back[2-i][2];
        back[2-i][2] = down[i][0];
        down[i][0] = front[i][0];
        front[i][0] = temp;
    }
}

void Cube::leftUp() {
    // Rotate left counter clockwise
    char tempFace[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tempFace[2-j][i] = left[i][j];
        }
    }
    replaceFace(left, tempFace);

    char temp;
    for (int i = 0; i < 3; i++) {
        temp = up[i][0];
        up[i][0] = front[i][0];
        front[i][0] = down[i][0];
        down[i][0] = back[2-i][2];
        back[2-i][2] = temp;
    }
}


