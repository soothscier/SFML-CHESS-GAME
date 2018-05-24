#pragma once
#include <iostream>
#include <vector>
#include "piece.h"

class rook
{
private:
	const int CANDIDATE_MOVE_COORDINATES[4] = {-8, -1, 1, 8};
	int pieceTile;
    std::string alliance;
    int arrOfChess[64];

public:
	rook(const int Tile, std::string alliance, int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    //---------------------------EXCLUSIONS

    bool firstColum(int tile, int offset);

    bool eighthColum(int tile, int offset);

    //---------------------------CALCULATIONS

    std::vector<int> getLegalMoves();

};

//----------------------------DEFINITIONS

rook::rook(const int Tile, std::string alliance, int chess[]) {
    for( int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = Tile;
    this->alliance = alliance;
}

bool rook::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool rook::firstColum(int tile, int offset) {
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

    return temp && (offset == -1);
}

bool rook::eighthColum(int tile, int offset) {
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

    return temp && (offset == 1);
}

//std::vector<int> rook::getLegalMoves() {
//
//    Piece destinationTile(arrOfChess);
//    int possibleDestinationTile;
//    std::vector<int> legalMoves;
//    for(int offset:CANDIDATE_MOVE_COORDINATES)
//    {
//        possibleDestinationTile = this->pieceTile;
//
//        if (firstColum(possibleDestinationTile, offset) || eighthColum(possibleDestinationTile, offset))
//        {
//            continue;
//        }
//
//        while(isValidTileCoordinate(possibleDestinationTile)) {
//            if (firstColum(possibleDestinationTile, offset) || eighthColum(possibleDestinationTile, offset))
//            {
//                break;
//            }
//
//            possibleDestinationTile += offset;
//            if (isValidTileCoordinate(possibleDestinationTile))
//            {
//                if (!destinationTile.isTileOccupied(possibleDestinationTile))
//                {
//                    legalMoves.push_back(possibleDestinationTile);
//                }
//                else
//                {
//                    if(!(this->alliance == destinationTile.pieceAlliance(possibleDestinationTile, alliance)))
//                    {
//                        legalMoves.push_back(possibleDestinationTile);
//                    }
//                    break;
//                }
//            }
//        }
//    }
//
//    return legalMoves;
//}

std::vector<int> rook::getLegalMoves() {

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

