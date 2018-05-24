#pragma once
#include <iostream>
#include <vector>

class Piece
{
private:
	int arrayOfChess[64];

public:
	Piece(int Chess[]);

	bool isTileOccupied(int tile);

	std::string pieceAlliance(int tile, std::string alliance);

};

//----------------------------DEFINITIONS

Piece::Piece(int *Chess) {

	for(unsigned i = 0; i < 64; ++i) {
		arrayOfChess[i] = Chess[i];
	}
}

bool Piece::isTileOccupied(int tile) {
	if(arrayOfChess[tile] == 0)
		return false;
	else
		return true;
}

std::string Piece::pieceAlliance(int tile, std::string alliance) {
	if(alliance == "white")
	{
		if(arrayOfChess[tile] < 0)
		{
			return "black";
		}
		else
		{
			return "white";
		}
	}

	else if(alliance == "black")
	{
		if (arrayOfChess[tile] > 0)
		{
			return "white";
		}
		else
			return "black";
	}
}
