#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class bishop
{
private:
	const int CANDIDATE_MOVE_COORDINATES[4] = {-9, -7, 9, 7};
	int pieceTile;
    std::string alliance;
    int arrOfChess[64];

public:
	bishop(int pieceTile, std::string alliance, int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //----------------------------Exclusions

    bool firstColum(int pieceTile, int offset);

    bool eighthColum(int pieceTile, int offset);

    //----------------------------CALCULATIONS

    std::vector<int> getLegalMoves();
};

//----------------------------DEFINITIONS

bishop::bishop(int pieceTile, std::string alliance, int chess[]) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = alliance;
}

bool bishop::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool bishop::firstColum(int pieceTile, int offset) {
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

    return temp && (offset == 7 || offset == -9);
}

bool bishop::eighthColum(int pieceTile, int offset) {
    int eighthColumArr[] = {7,15,23,31,39,47,55,63};
    bool temp = false;

    for(int i: eighthColumArr)
    {
        if(pieceTile == i)
        {
            temp = true;
            break;
        }else
            temp = false;
    }

    return temp && (offset == -7 || offset == 9);
}

std::vector<int> bishop::getLegalMoves() {

    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    std::vector<int> legalMoves;
    for(int offset:CANDIDATE_MOVE_COORDINATES)
    {
        possibleDestinationTile = this->pieceTile;

        if (firstColum(possibleDestinationTile, offset) || eighthColum(possibleDestinationTile, offset))
        {
            continue;
        }
        while(isValidTileCoordinate(possibleDestinationTile)) {
            int temp = possibleDestinationTile;
            possibleDestinationTile += offset;
            if (firstColum(temp, offset) || eighthColum(temp, offset))
            {
                continue;
            }
            if (isValidTileCoordinate(possibleDestinationTile))
            {
                if (!destinationTile.isTileOccupied(possibleDestinationTile))
                {
                    legalMoves.push_back(possibleDestinationTile);
                }
                else
                {
                    if(!(this->alliance == destinationTile.pieceAlliance(possibleDestinationTile, this->alliance)))
                    {
                        legalMoves.push_back(possibleDestinationTile);
                    }
                    break;
                }
            }
        }
    }

    return legalMoves;
}

