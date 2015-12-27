#include "cell.h"
#include "game.h"
Cell::Cell() {
	state = 0;
	prevState = 0;
	numNeighbours = 0;
	for (int i = 0; i < 4; i++) {
		neighbours[i] = NULL;
	}
	row = -1;
	column = -1;
	game = NULL;
}

void Cell::notifyNeighbours() const {
	for (int i = 0; i < numNeighbours; i++) {
		neighbours[i]->notify(state, prevState);
	}
}
void Cell::notify(const int & current, const int & previous) {
	if (getState() == previous) {
		setState(current);
		notifyNeighbours();
	}
}
void Cell::notify(const int &change) {
	setState(change);
	notifyNeighbours();
}
void Cell::notifyGame() const {
	game->notify(row, column, prevState, state);
}
int Cell::getState() const {
	return state;
}
void Cell::setState(const int& change) {
	prevState = state;
	state = change;
	notifyGame();
}
void Cell::setCoords(const int new_row, const int new_column) {
	row = new_row;
	column = new_column;
}
void Cell::setGame(Game * my_game) {
	game = my_game;
}
void Cell::addNeighbour(Cell *new_neighbour) {
	neighbours[numNeighbours] = new_neighbour;
	numNeighbours++;
	if (numNeighbours > 4) {
		std::cerr << "too many neighbours !" << std::endl;
	}
}

