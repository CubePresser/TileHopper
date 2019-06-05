LINK_TARGET = tilehopper.exe

OBJS = \
	game.o \
	board.o \
	main.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

all : $(LINK_TARGET)
	echo All done

clean :
	rm -f $(REBUILDABLES)
	echo Clean done

$(LINK_TARGET) : $(OBJS)
	g++ -o $@ $^

%.o : %.cpp
	g++ -o $@ -c $<

main.o : board.h game.h
game.o : board.h