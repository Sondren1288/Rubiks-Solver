#ifndef CUBE
#define CUBE
namespace cube {
    class Cube {
        public:
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

        private:
    };
        
};
#endif
