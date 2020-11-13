#pragma once

#include <iostream>
#include <string>
#include <random>

char Board[6][6];
char EmptyBoard[6][6];
int numberOfHits = 0;
int numberOfShots = 0;

void makeEmtyBoard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			Board[i][j] = ' ';
			EmptyBoard[i][j] = ' ';
		}
	}
}

int randomRow() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 5);
	return dis(gen);
}

int randomColumn() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 5);
	return dis(gen);
}

void writeLetters() {
	std::cout << " |1|2|3|4|5|6|" << std::endl;
}

void makeBoard(int numberOfShips) {
	for (int i = 0; i < numberOfShips; i++) {
		randomRow();
		randomColumn();
		Board[randomRow()][randomColumn()] = 'S';
	}
}

void printBoard() {
	writeLetters();
	std::cout << "A|" << Board[0][0] << "|" << Board[0][1] << "|" << Board[0][2] << "|" << Board[0][3] << "|" << Board[0][4] << "|" << Board[0][5] << "|" << std::endl;
	std::cout << "B|" << Board[1][0] << "|" << Board[1][1] << "|" << Board[1][2] << "|" << Board[1][3] << "|" << Board[1][4] << "|" << Board[1][5] << "|" << std::endl;
	std::cout << "C|" << Board[2][0] << "|" << Board[2][1] << "|" << Board[2][2] << "|" << Board[2][3] << "|" << Board[2][4] << "|" << Board[2][5] << "|" << std::endl;
	std::cout << "D|" << Board[3][0] << "|" << Board[3][1] << "|" << Board[3][2] << "|" << Board[3][3] << "|" << Board[3][4] << "|" << Board[3][5] << "|" << std::endl;
	std::cout << "E|" << Board[4][0] << "|" << Board[4][1] << "|" << Board[4][2] << "|" << Board[4][3] << "|" << Board[4][4] << "|" << Board[4][5] << "|" << std::endl;
	std::cout << "F|" << Board[5][0] << "|" << Board[5][1] << "|" << Board[5][2] << "|" << Board[5][3] << "|" << Board[5][4] << "|" << Board[5][5] << "|" << std::endl;
}

void printPlayerBoard() {
	writeLetters();
	std::cout << "A|" << EmptyBoard[0][0] << "|" << EmptyBoard[0][1] << "|" << EmptyBoard[0][2] << "|" << EmptyBoard[0][3] << "|" << EmptyBoard[0][4] << "|" << EmptyBoard[0][5] << "|" << std::endl;
	std::cout << "B|" << EmptyBoard[1][0] << "|" << EmptyBoard[1][1] << "|" << EmptyBoard[1][2] << "|" << EmptyBoard[1][3] << "|" << EmptyBoard[1][4] << "|" << EmptyBoard[1][5] << "|" << std::endl;
	std::cout << "C|" << EmptyBoard[2][0] << "|" << EmptyBoard[2][1] << "|" << EmptyBoard[2][2] << "|" << EmptyBoard[2][3] << "|" << EmptyBoard[2][4] << "|" << EmptyBoard[2][5] << "|" << std::endl;
	std::cout << "D|" << EmptyBoard[3][0] << "|" << EmptyBoard[3][1] << "|" << EmptyBoard[3][2] << "|" << EmptyBoard[3][3] << "|" << EmptyBoard[3][4] << "|" << EmptyBoard[3][5] << "|" << std::endl;
	std::cout << "E|" << EmptyBoard[4][0] << "|" << EmptyBoard[4][1] << "|" << EmptyBoard[4][2] << "|" << EmptyBoard[4][3] << "|" << EmptyBoard[4][4] << "|" << EmptyBoard[4][5] << "|" << std::endl;
	std::cout << "F|" << EmptyBoard[5][0] << "|" << EmptyBoard[5][1] << "|" << EmptyBoard[5][2] << "|" << EmptyBoard[5][3] << "|" << EmptyBoard[5][4] << "|" << EmptyBoard[5][5] << "|" << std::endl;
}

void shoot() {
	int x = 0;
	std::string cell = " ";
	std::cout << "What cell would you like to shooot at(exm. B3, use capital letters):";
	std::getline(std::cin, cell);
	std::cin >> cell;
	if (cell[0] == 'A') {
		x = 0;
	}
	if (cell[0] == 'B') {
		x = 1;
	}
	if (cell[0] == 'C') {
		x = 2;
	}
	if (cell[0] == 'D') {
		x = 3;
	}
	if (cell[0] == 'E') {
		x = 4;
	}
	if (cell[0] == 'F') {
		x = 5;
	}
	int y = cell[1] - 1;
	x = x - 2;
	if (Board[x][y] == 'S') {
		Board[x][y] = 'H';
		EmptyBoard[x][y] = 'H';
		numberOfHits++;
	}
	else if (Board[x][y] != 'S') {
		Board[x][y] = 'M';
		EmptyBoard[x][y] = 'M';
	}
	numberOfShots++;
}

void play() {
	int ShotsGiven = 20;
	int numberOfShips = 11;
	bool shipsRemaining = true;
	makeEmtyBoard();
	makeBoard(numberOfShips);
	do {
		printPlayerBoard();
		shoot();
		shipsRemaining = false;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (Board[i][j] == 'S') {
					shipsRemaining = true;
				}
			}
		}
	} while (numberOfShots < ShotsGiven || shipsRemaining == true);
	if (shipsRemaining == true) {
		std::cout << "You have lost the game" << std::endl;
	}
	else {
		std::cout << "Congratulation you have won the game" << std::endl;
	}



}
