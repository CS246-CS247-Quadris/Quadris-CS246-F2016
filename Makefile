CXX=g++ 
XXFLAGS=-Wall -MMD 
EXEC=quadris 
LIBS=-lX11 -L/opt/X11/lib
OBJECTS=main.o cell.o board.o block.o window.o Iblock.o Jblock.o Lblock.o Oblock.o Sblock.o Tblock.o Zblock.o level.o level1.o level2.o level3.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${XXFLAGS} ${OBJECTS} -o ${EXEC} ${LIBS}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}
