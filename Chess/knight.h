
#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class knight
{
private:
    const int CANDIDATE_MOVE_COORDINATES[8] = {-17, -15, -10, -6, 6, 10, 15, 17};
    int pieceTile;
    std::string alliance;
    int arrOfChess[64];

public:
    knight(int pieceTile, std::string alliance, int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //-------------------------------EXCLUSIONS

    bool firstColum(int pieceTile, int offset);

    bool secondColum(int pieceTile, int offset);

    bool seventhColum(int pieceTile, int offset);

    bool eighthColum(int pieceTile, int offset);

    //--------------------EXCLUSIONS

    std::vector<int> getLegalMoves();
};


//----------------------------DEFINITIONS

knight::knight(int pieceTile, std::string alliance, int chess[]) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = alliance;
}

bool knight::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool knight::firstColum(int pieceTile, int offset) {
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

    return temp && ((offset == -17) || (offset == -10) || (offset == 6) || (offset == 15));
}

bool knight::secondColum(int pieceTile, int offset) {
    int secondColumArr[] = {1,9,17,25,33,41,49,55};
    bool temp = false;

    for(int i: secondColumArr)
    {
        if(pieceTile == i)
        {
            temp = true;
            break;
        }else
            temp = false;

    }

    return temp && ((offset == -10) || (offset == 6));
}

bool knight::seventhColum(int pieceTile, int offset) {
    int seventhColumArr[] = {6,14,22,30,38,46,54,62};
    bool temp = false;

    for(int i: seventhColumArr)
    {
        if(pieceTile == i)
        {
            temp = true;
            break;
        }else
            temp = false;

    }

    return temp && ((offset == -6) || (offset == 10));
}

bool knight::eighthColum(int pieceTile, int offset) {
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

    return temp &&  ((offset == -15) || (offset == -6) || (offset == 10) || (offset == 17));
}

std::vector<int> knight::getLegalMoves() {

    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    std::vector<int> legalMoves;

    for(int offset:CANDIDATE_MOVE_COORDINATES)
    {

        if (firstColum(this->pieceTile, offset) || secondColum(this->pieceTile, offset) ||
            seventhColum(this->pieceTile, offset) || eighthColum(this->pieceTile, offset))
        {
            continue;
        }
        possibleDestinationTile = this->pieceTile + offset;
        if (isValidTileCoordinate(possibleDestinationTile))
        {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, this->alliance)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
            } else {
                legalMoves.push_back(possibleDestinationTile);
            }

        }

    }
    return legalMoves;
}
