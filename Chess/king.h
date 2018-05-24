#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class king
{
private:
	const int CANDIDATE_MOVE_COORDINATES[8] = {-9, -8, -7, -1, 1, 8, 7, 9};
	int pieceTile;
    std::string alliance;
    int arrOfChess[64];

public:
	king(int pieceTile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //-------------------------------EXCLUSIONS

    bool firstColum(int pieceTile, int offset);

	bool eighthColum(int pieceTile, int offset);

    //--------------------EXCLUSIONS

    std::vector<int> getLegalMoves();
};


//----------------------------DEFINITIONS

king::king(int pieceTile, std::string alliance, const int chess[]) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = alliance;
}

bool king::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool king::firstColum(int pieceTile, int offset) {
    int firstColumArr[] = {0,8,16,24,32,40,43,56};
    bool temp = false;

    for(int i: firstColumArr)
    {
        if(pieceTile == i)
        {
            temp = true;
            break;
        }else
            temp = false;

    }

    return temp && (offset == -9 || offset == -1 || offset == 7);
}

bool king::eighthColum(int pieceTile, int offset) {
    int eighthColumArr[] = {7,15,23,31,39,47,55,63};
    bool temp = false;

    for(int i: eighthColumArr)
    {
        if(pieceTile == i)
        {
            temp = true;
            break;
        }
        else
            temp = false;
    }

    return temp && (offset == -7 || offset == 1 || offset == 9);
}

std::vector<int> king::getLegalMoves() {

    Piece destinationTile(arrOfChess);
    int possibleDestinationTile = this->pieceTile;
    std::vector<int> legalMoves;
//     int=new x;

    for(int offset:CANDIDATE_MOVE_COORDINATES)
    {

        if (firstColum(this->pieceTile, offset) || eighthColum(this->pieceTile, offset))
        {
            continue;
        }
        possibleDestinationTile = this->pieceTile + offset;
        if (isValidTileCoordinate(possibleDestinationTile))
        {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
            } else {
                legalMoves.push_back(possibleDestinationTile);
            }

        }

    }
    return legalMoves;
}
