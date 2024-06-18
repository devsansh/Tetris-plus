#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "io.h"
#include <time.h>

#define WAIT_TIME 700 // Define the wait time in milliseconds

class Game {
    public:
        // Constructor to initialize the game with pointers to Board, Pieces, and IO classes, and the screen height
        Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

        // Public methods to draw the game scene and create a new piece
        void DrawScene();
        void CreateNewPiece();

        // Position of the piece that is falling down
        int mPosX, mPosY; 
        // Kind and rotation of the piece that is falling down
        int mPiece, mRotation; 

    private:
        // Screen height in pixels
        int mScreenHeight;
        // Position of the next piece
        int mNextPosX, mNextPosY;
        // Kind and rotation of the next piece
        int mNextPiece, mNextRotation;

        // Pointers to Board, Pieces, and IO classes
        Board *mBoard;
        Pieces *mPieces;
        IO *mIO;

        // Private methods for the game logic
        int GetRand(int pA, int pB); // Generate a random number between pA and pB
        void InitGame(); // Initialize the game
        void DrawPiece(int pX, int pY, int pPiece, int pRotation); // Draw a piece on the board
        void DrawBoard(); // Draw the game board
};

#endif
