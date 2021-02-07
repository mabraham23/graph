NAME=graph

all: graph  

run: graph 
	./$(NAME).exe

graph:
	g++ *.cpp -o $(NAME).exe

gdb:
	g++ -g *.cpp -o $(NAME).exe

clean:
	rm *.o *.exe