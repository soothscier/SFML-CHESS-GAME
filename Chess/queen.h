#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include "piece.h"

class queen
{
private:
    const int CANDIDATE_MOVE_COORDINATES[8] = {-8, -1, 1, 8, -9, -7, 9, 7};
    int pieceTile;
    std::string alliance;
    int arrOfChess[64]{};

public:
    queen(const int Tile, std::string alliance, int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //---------------------------EXCLUSIONS

    bool firstColum(int tile, int offset);

    bool eighthColum(int tile, int offset);

    //---------------------------CALCULATIONS

    std::vector<int> getLegalMoves();

};

//----------------------------DEFINITIONS

queen::queen(const int Tile, std::string alliance, int chess[]) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = Tile;
    this->alliance = std::move(alliance);
}

bool queen::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool queen::firstColum(int tile, int offset) {
    int firstColumArr[] = {0,8,16,24,32,40,43,56};
    bool temp;

    for(int i: firstColumArr)
    {
        if(tile == i)
        {
            temp = true;
            break;
        }
        else{
            temp=false;
        }
    }

    return temp && (offset == -1 || offset == 7 || offset == -9);
}

bool queen::eighthColum(int tile, int offset) {
    int eighthColumArr[] = {7,15,23,31,39,47,55,63};
    bool temp;

    for(int i: eighthColumArr)
    {
        if(tile == i)
        {
            temp = true;
            break;
        }
        else{
            temp=false;
        }
    }

    return temp && (offset == 1 || offset == -7 || offset == 9);
}

std::vector<int> queen::getLegalMoves() {

    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    std::vector<int> legalMoves;
    for(int offset:CANDIDATE_MOVE_COORDINATES)
    {
        possibleDestinationTile = this->pieceTile;

/*        if (firstColum(possibleDestinationTile, offset) || eighthColum(possibleDestinationTile, offset))
        {
            continue;
        }*/
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
                    if(!(this->alliance == destinationTile.pieceAlliance(possibleDestinationTile, alliance)))
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
