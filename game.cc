#include "game.h"

Game::Game() {
	theGrid = NULL;
	gridSize = 0;
	for (int i = 0; i < 5; i++) {
		colours[i] = 0;
	}
}

Game::~Game() {
	for (int i = 0; i < gridSize; i++) {
		delete[] theGrid[i];
	}
	delete[] theGrid;
}

void Game::clearGame() {
	for (int i = 0; i < gridSize; i++) {
		delete[] theGrid[i];
	}
	delete[] theGrid;
	gridSize = 0;
	theGrid = NULL;
	for (unsigned int i = 0; i < 5; i++) {
		colours[i] = 0;
	}
}

void Game::init(int row, int column, int state) {
	if(row < gridSize && row >=0 && column < gridSize && column >=0 && state <=4 && state >=0){
		theGrid[row][column].setState(state);
	}
}

void Game::init(int n, GameNotification *gameNotification) {
	notification = gameNotification;
	if (theGrid != NULL) {
		for (int i = 0; i < gridSize; i++) {
			delete[] theGrid[i];
		}
		delete[] theGrid;
	}
	gridSize = n;
	theGrid = new Cell*[n];
	for (int i = 0; i < n; i++) {
		theGrid[i] = new Cell [n];
		for (int j = 0; j < n; j++) {
			theGrid[i][j].setCoords(i, j);
			theGrid[i][j].setGame(this);
		}
	}
	colours[0] = n*n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - 1); j++) {
			theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
			theGrid[i][j+1].addNeighbour(&theGrid[i][j]);
			//theGrid[i*n + j]->addNeighbour(theGrid[i*n + j + 1]);
			//theGrid[i*n + j + 1]->addNeighbour(theGrid[i*n + j]);// add left and right neighbours to every cell
		}
	}
	for (int i = 0; i < (n-1); i++) {
		for (int j = 0; j < n; j++) {
			theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
			theGrid[i+1][j].addNeighbour(&theGrid[i][j]);
			//theGrid[i*n + j]->setCoords(i, j);
			//theGrid[i*n + j]->addNeighbour(theGrid[(i+1)*n + j]);
			//theGrid[(i + 1)*n + j]->addNeighbour(theGrid[i*n + j]);// add top and bot neightbours to every cell
		}
	}

}
void Game::notify(int row, int column, int oldState, int newState) {
	colours[oldState]--;
	colours[newState]++;
	notification->notify(row, column, newState);
}
void Game::change(const int & state) {
	theGrid[0][0].notify(state);
	//theGrid[0]->notify(state);
}

bool Game::isWon() const {
	int all = gridSize * gridSize;
	for (int i = 0; i < 5; i++) {
		if (colours[i] == all) {
			return true;
		}
	}
	return false;
}

