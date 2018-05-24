#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class pawn
{
private:
    const int CANDIDATE_MOVE_COORDINATES[4] = {7, 8, 9, 16};
    int pieceTile;
    int arrOfChess[64];
    std::string alliance;
    signed int direction;

public:
    pawn(int Tile, std::string alliance, int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //------------------------------------------------------------------EXCLUSIONS
    //---------------------------------COLUMN

    bool eighthColum(int tile);

    bool firstColum(int tile);

    bool isFirstMove(int tile);

    //-----------------CALCULATIONS

    std::vector<int> getLegalMoves();

};

//----------------------------DEFINITIONS

pawn::pawn(int Tile, std::string alliance, int *chess) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }

    this->pieceTile = Tile;
    this->alliance = alliance;

    if (this->alliance == "white")
    {
        direction = -1;
    }
    else if (this->alliance == "black")
    {
        direction = 1;
    }
}

bool pawn::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool pawn::eighthColum(int tile) {
    int eighthColumArr[] = {7,15,23,31,39,47,55,63};
    bool temp = false;

    for(int i: eighthColumArr)
    {
        if(tile == i)
        {
            temp = true;
            break;
        }else
            temp = false;
    }

    return temp;
}

bool pawn::firstColum(int tile) {
    int firstColumArr[] = {0,8,16,24,32,40,43,56};
    bool temp = false;

    for(int i: firstColumArr)
    {
        if(tile == i)
        {
            temp = true;
            break;
        }else
            temp = false;
    }

    return temp;
}

bool pawn::isFirstMove(int tile) {
    int secondRowArr[] = {8,9,10,11,12,13,14,15};
    int seventhRowArr[] = {48,49,50,51,52,53,54,55};

    if(alliance == "black")
    {
        for (int i : secondRowArr) {
            if (tile == i)
                return true;
        }
    }
    else if (alliance == "white")
    {
        for (int i : seventhRowArr) {
            if (tile == i)
                return true;
        }
    }

    return false;
}

std::vector<int> pawn::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    std::vector<int> legalMoves;

    for(int offset:CANDIDATE_MOVE_COORDINATES)
    {
        possibleDestinationTile = this->pieceTile + (direction * offset);

        if (!isValidTileCoordinate(possibleDestinationTile))
        {
            continue;
        }

        if (offset == 8 && !destinationTile.isTileOccupied(possibleDestinationTile))
        {
            legalMoves.push_back(possibleDestinationTile);
        }

        //TWO STEPS
        if (offset == 16  && isFirstMove(this->pieceTile))
        {
            int behindCandidate = this->pieceTile + (this->direction * 8);

            if (!destinationTile.isTileOccupied(behindCandidate) && !destinationTile.isTileOccupied(possibleDestinationTile))
            {
                legalMoves.push_back(possibleDestinationTile);
            }
        }


        if (offset == 7 && !((eighthColum(this->pieceTile) && this->alliance == "white") || (firstColum(this->pieceTile) && this->alliance == "black")))
        {
            if (destinationTile.isTileOccupied(possibleDestinationTile))
            {
                if(this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance))
                {
                    legalMoves.push_back(possibleDestinationTile);
                }
            }
        }
        if (offset == 9 && !((firstColum(this->pieceTile)&& this->alliance == "white") || (eighthColum(this->pieceTile) && this->alliance == "black")))
        {
            if (destinationTile.isTileOccupied(possibleDestinationTile))
            {
                if(this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance))
                {
                    legalMoves.push_back(possibleDestinationTile);
                }
            }
        }

    }

    return legalMoves;
}