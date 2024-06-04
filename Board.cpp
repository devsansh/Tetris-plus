#include "Board.h"
// Init
Board::Board(Pieces* pPieces, int pScreenHeight){
    mScreenHeight = pScreenHeight;
    mPieces = pPieces;
    InitBoard();
}
//Board with Free positions.
/*
    InitBoard --> Nested loop that initialise all the board pieces to POS_FREE.

*/
void Board::InitBoard(){
    for(int i = 0; i < BOARD_WIDTH;i++){
        for(int j = 0; j < BOARD_HEIGHT;j++){
            mBoard[i][j] = POS_FREE; 
        }
    }
}
//Store Picece
/*
    This method, just stores the board with approprite block as POS_Filled.
*/

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation){
    //Store each block of the piece to board.
    for(int i1 = pX, i2 = 0; i1 < pX +PIECE_BLOCKS;i1++,i2++ ){
        for(int j1 = pX, j2 = 0; j1 < pY+PIECE_BLOCKS;j1++,j2++){
            if(mPieces->GetBlockType(pPiece,pRotation,j2,j2) != 0)
            mBoard[i1][j1] = POS_FILLED;
        }
    }
}
