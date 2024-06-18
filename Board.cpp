#include "Board.h"

// Constructor: Initialize the board
Board::Board(Pieces* pPieces, int pScreenHeight) {
    mScreenHeight = pScreenHeight;
    mPieces = pPieces;
    InitBoard();
}

// Initialize the board with free positions
void Board::InitBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            mBoard[i][j] = POS_FREE;
        }
    }
}

// Store a piece in the board
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
                mBoard[i1][j1] = POS_FILLED;
            }
        }
    }
}

// Check if the game is over
bool Board::IsGameOver() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        if (mBoard[i][0] == POS_FILLED) {
            return true;
        }
    }
    return false;
}

// Delete a line from the board
void Board::DeleteLine(int pY) {
    for (int j = pY; j > 0; j--) {
        for (int i = 0; i < BOARD_WIDTH; i++) {
            mBoard[i][j] = mBoard[i][j - 1];
        }
    }
    for (int i = 0; i < BOARD_WIDTH; i++) {
        mBoard[i][0] = POS_FREE;
    }
}

// Delete all possible lines from the board
void Board::DeletePossibleLines() {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
        int i = 0;
        while (i < BOARD_WIDTH) {
            if (mBoard[i][j] != POS_FILLED) {
                break;
            }
            i++;
        }
        if (i == BOARD_WIDTH) {
            DeleteLine(j);
        }
    }
}

// Check if a block is free
bool Board::IsFreeBlock(int pX, int pY) {
    return mBoard[pX][pY] == POS_FREE;
}

// Get the X position in pixels
int Board::GetXPosInPixels(int pPos) {
    return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

// Get the Y position in pixels
int Board::GetYPosInPixels(int pPos) {
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

// Check if a movement is possible
bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
            if ((i1 < 0) || (i1 >= BOARD_WIDTH) || (j1 >= BOARD_HEIGHT)) {
                if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) {
                    return false;
                }
            } else if (j1 >= 0) {
                if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1))) {
                    return false;
                }
            }
        }
    }
    return true;
}
