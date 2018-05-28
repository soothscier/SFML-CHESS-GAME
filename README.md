# SFML-CHESS-GAME

A two player chess game made in c++. 

Steps to compile and run CHESS game on your ubuntu system:

1~ First you need to install SFML in ubuntu. Open the terminal and write this command:
	"sudo apt-get install libsfml-dev"

2~ Second you need to cd(move) to the directory where you have saved the files from the terminal.

3~ Then for compiling main.cpp, run this command:
   "g++ -std=c++14 main.cpp -o chess -lsfml-graphics -lsfml-window -lsfml-system"   ## We have used c++14 syntax in major cases

4~ Lastly write "./chess" in the terminal and the game will run.

NOTE: While playing game, you need to select the piece with RIGHT-MOUSE-KEY, and select the position on which you want to move that piece with LEFT-MOUSE-KEY.
