DEPS := cube.cpp graph.cpp node.cpp
NAME := rubiksSolver.o
DEBUG := debugRubiks.o

default: $(NAME)

debug: $(DEBUG)

$(NAME): main.cpp $(DEPS)
	g++ -o $@ $^ 

$(DEBUG): main.cpp $(DEPS)
	g++ -g -o $@ $^ 
