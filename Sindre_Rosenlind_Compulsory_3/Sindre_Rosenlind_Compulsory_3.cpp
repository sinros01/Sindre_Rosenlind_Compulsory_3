#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "login.h"
#include "change_password.h"
#include "Battleships.h"







int main() {
	login();
	int choice = 0;
	bool loop = true;
	do {
		std::cout << std::endl;
		std::cout << "---------- Main Menu ----------" << std::endl;
		std::cout << "1. Change password" << std::endl;
		std::cout << "2. Play Battleships" << std::endl;
		std::cout << "3. Quit" << std::endl;
		std::cout << "Enter what you would like to do from 1-3:";
		std::cin >> choice;
		if (choice == 1) {
			change_password();
		}
		else if (choice == 2) {
			play();
		}
		else {
			loop = false;
		}
	} while (loop == true);

}