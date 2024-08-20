#ifndef CUBE
#define CUBE
#include <vector>
#include <string>
namespace cube {

    struct face {
        char faces[3][3];
    };
    class Cube {
        public:
            char up[3][3];
            char left[3][3];
            char front[3][3];
            char right[3][3];
            char back[3][3];
            char down[3][3];

            Cube();
            std::string cubeString();
            void replaceFace(char (&first)[3][3] , char (&second)[3][3]);

            

            // cubeState
            void leftDown();
            void leftUp();
            void rightDown();
            void rightUp();
            void upperRight();
            void upperLeft();
            void bottomRight();
            void bottomLeft();
            void faceClockwise();
            void faceCounterClockwise();
            void middleClockwise();
            void middleCounterClockwise();
            void backClockwise();
            void backCounterClockwise();

            // Rotation of the view as according to
            // the person facing the cube
            void spinLeft();
            void spinRight();
            void spinUp();
            void spinDown();

        private:
    };
        
};
#endif
