#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>



void login() {
	std::string password = "";
	std::fstream password_file("password.txt", std::ios::in);
	if (password_file) {
		perror("password_file exists");
		while (!password_file.eof()) {
			std::getline(password_file, password);
		}
	}
	else {
		perror("Storyfile  ");
	}
	password_file.close();
	std::string password_attempt = "";
	while (password_attempt != password) {
		char grid[16] = { '*', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
		char grid_original[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
		int position = 0;
		char ch = 'A';
		std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << grid[3] << " | " << std::endl;
		std::cout << "| " << grid[4] << " | " << grid[5] << " | " << grid[6] << " | " << grid[7] << " | " << std::endl;
		std::cout << "| " << grid[8] << " | " << grid[9] << " | " << grid[10] << " | " << grid[11] << " | " << std::endl;
		std::cout << "| " << grid[12] << " | " << grid[13] << " | " << grid[14] << " | " << grid[15] << " | " << std::endl;
		grid[0] = 'A';
		password_attempt = "";
		password_attempt.push_back(ch);
		for (int i = 0; i < password.size() - 1; i++) {
			std::cout << std::endl;
			ch = _getch();
			if (ch == 'W' || ch == 'w') {
				if (position != 0 && position != 1 && position != 2 && position != 3) {
					position = position - 4;
					password_attempt.push_back(grid[position]);
					grid[position] = '*';
					std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << grid[3] << " | " << std::endl;
					std::cout << "| " << grid[4] << " | " << grid[5] << " | " << grid[6] << " | " << grid[7] << " | " << std::endl;
					std::cout << "| " << grid[8] << " | " << grid[9] << " | " << grid[10] << " | " << grid[11] << " | " << std::endl;
					std::cout << "| " << grid[12] << " | " << grid[13] << " | " << grid[14] << " | " << grid[15] << " | " << std::endl;
					for (int j = 0; j < 16; j++) {
						grid[j] = grid_original[j];
					}
				}
			}
			if (ch == 'S' || ch == 's') {
				if (position != 12 && position != 13 && position != 14 && position != 15) {
					position = position + 4;
					password_attempt.push_back(grid[position]);
					grid[position] = '*';
					std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << grid[3] << " | " << std::endl;
					std::cout << "| " << grid[4] << " | " << grid[5] << " | " << grid[6] << " | " << grid[7] << " | " << std::endl;
					std::cout << "| " << grid[8] << " | " << grid[9] << " | " << grid[10] << " | " << grid[11] << " | " << std::endl;
					std::cout << "| " << grid[12] << " | " << grid[13] << " | " << grid[14] << " | " << grid[15] << " | " << std::endl;
					for (int j = 0; j < 16; j++) {
						grid[j] = grid_original[j];
					}
				}
			}
			if (ch == 'A' || ch == 'a') {
				if (position != 0 && position != 4 && position != 8 && position != 12) {
					position = position - 1;
					password_attempt.push_back(grid[position]);
					grid[position] = '*';
					std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << grid[3] << " | " << std::endl;
					std::cout << "| " << grid[4] << " | " << grid[5] << " | " << grid[6] << " | " << grid[7] << " | " << std::endl;
					std::cout << "| " << grid[8] << " | " << grid[9] << " | " << grid[10] << " | " << grid[11] << " | " << std::endl;
					std::cout << "| " << grid[12] << " | " << grid[13] << " | " << grid[14] << " | " << grid[15] << " | " << std::endl;
					for (int j = 0; j < 16; j++) {
						grid[j] = grid_original[j];
					}
				}
			}
			if (ch == 'D' || ch == 'd') {
				if (position != 3 && position != 7 && position != 11 && position != 15) {
					position = position + 1;
					password_attempt.push_back(grid[position]);
					grid[position] = '*';
					std::cout << "| " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << grid[3] << " | " << std::endl;
					std::cout << "| " << grid[4] << " | " << grid[5] << " | " << grid[6] << " | " << grid[7] << " | " << std::endl;
					std::cout << "| " << grid[8] << " | " << grid[9] << " | " << grid[10] << " | " << grid[11] << " | " << std::endl;
					std::cout << "| " << grid[12] << " | " << grid[13] << " | " << grid[14] << " | " << grid[15] << " | " << std::endl;
					for (int j = 0; j < 16; j++) {
						grid[j] = grid_original[j];
					}
				}
			}
		}
		if (password_attempt != password) {
			std::cout << std::endl;
			std::cout << "Wrong password, try again!" << std::endl;
			std::cout << std::endl;
		}
	}
}