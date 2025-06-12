all:
	g++ -std=c++17 -Iengine main.cpp engine/*.cpp -o minidb

clean:
	rm -f minidb
	rm -f db/*.tbl
