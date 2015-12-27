CXX = g++
CXXFLAGS = -g -Wall
OBJECTS = main.o cell.o controller.o game.o textdisplay.o view.o
EXEC = flood

${EXEC}:${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}
cell.o: cell.cc cell.h

controller.o: controller.cc controller.h

main.o: main.cc cell.h controller.h game.h view.h textdisplay.h

game.o: game.cc game.h

testdisplay.o: testplay.cc testdisplay.h

view.o: view.cc view.h

clean:
	rm ${OBJECTS} ${EXEC}

.PHONY: clean

