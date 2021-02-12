NAME=graph

all: graph  

run: graph 
	./$(NAME).exe > 3d-graph-1000-4.txt

graph:
	g++ *.cpp -o $(NAME).exe

gdb:
	g++ -g *.cpp -o $(NAME).exe

clean:
	rm *.o *.exe