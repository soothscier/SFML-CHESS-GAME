#include "king.h"
#include "queen.h"
#include "pawn.h"
//#include "piece.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
class Identity
{
public:
    bool chessKing(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {
        king king1(initialTile, alliance, arrOfChess);

        std::vector<int> v1;
        v1 =  king1.getLegalMoves();


        for(std::vector<int>::iterator it1 =v1.begin(); it1 !=v1.end(); ++it1) {
            if (*it1 == finalTile)
                return true;
        }

        return false;
    }

    bool chessQueen(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {

        queen queen1(initialTile, alliance, arrOfChess);

        std::vector<int>v2;
        v2 =  queen1.getLegalMoves();


        for(std::vector<int>::iterator it2 =v2.begin(); it2 !=v2.end(); ++it2) {
            if (*it2 == finalTile)
                return true;
        }

        return false;
    }

    bool chessPawn(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {
        pawn pawn1(initialTile, alliance, arrOfChess);

        std::vector<int>v3;
        v3 =  pawn1.getLegalMoves();


        for(std::vector<int>::iterator it3 =v3.begin(); it3 !=v3.end(); ++it3) {
            if (*it3 == finalTile)
                return true;
        }

        return false;
    }

    bool chessRook(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {
        rook rook1(initialTile, alliance, arrOfChess);

        std::vector<int> v4;
        v4 =  rook1.getLegalMoves();


        for(std::vector<int>::iterator it4 = v4.begin(); it4 != v4.end(); ++it4) {
            if (*it4 == finalTile)
                return true;
        }

        return false;
    }

    bool chessBishop(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {
        bishop bishop1(initialTile, alliance, arrOfChess);

        std::vector<int> v5;
        v5 =  bishop1.getLegalMoves();


        for(std::vector<int>::iterator it5 = v5.begin(); it5 != v5.end(); ++it5) {
            if (*it5 == finalTile)
                return true;
        }

        return false;
    }

    bool chessKnight(int initialTile, int finalTile, std::string alliance, int *arrOfChess) {
        knight knight1(initialTile, alliance, arrOfChess);

        std::vector<int> v6;
        v6 =  knight1.getLegalMoves();


        for(std::vector<int>::iterator it6 = v6.begin(); it6 != v6.end(); ++it6) {
            if (*it6 == finalTile)
                return true;
        }

        return false;
    }

    std::string checkAlliance(int piece) {
        if (piece > 0)
            return "white";
        else if(piece < 0)
            return "black";
    }

    bool identifier(int initialTile, int finalTile,int piece, int *arrOfChess)
    {
        std::string alliance = checkAlliance(piece);

        if(piece == -1 || piece == 1)
            return chessRook( initialTile,  finalTile, alliance,  arrOfChess);

        else if(piece == -2 || piece == 2)
            return chessKnight( initialTile,  finalTile, alliance,  arrOfChess);

        else if(piece == -3 || piece == 3)
            return chessBishop( initialTile,  finalTile, alliance,  arrOfChess);

        else if(piece == -4 || piece == 4)
            return chessQueen( initialTile,  finalTile, alliance,  arrOfChess);

        else if(piece == -5 || piece == 5)
            return chessKing( initialTile,  finalTile, alliance,  arrOfChess);

        else if(piece == -6 || piece == 6)
            return chessPawn( initialTile,  finalTile, alliance,  arrOfChess);

    }

};
