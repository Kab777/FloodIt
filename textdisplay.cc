#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int n) :View(n){
	theDisplay = new int*[n];
	for (int i = 0; i < n; i++) {
		theDisplay[i] = new int [n];
	}
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			theDisplay[i][j] = 0;
		}
	}
}

TextDisplay::~TextDisplay() {
	for (int i = 0; i < gridSize; i++) {
		delete[] theDisplay[i];
	}
	delete[] theDisplay;
}

void TextDisplay::print(std::ostream &out) const {
	for (int i= 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			out << theDisplay[i][j];
		}
		out << endl;
	}
}

void TextDisplay::notify(int row, int column, int update) {
	if(row < gridSize && row >=0 && column < gridSize && column >=0 && update <=4 && update >=0){
		theDisplay[row][column] = update;
	}
}

