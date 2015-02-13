CC=g++
winCC=x86_64-w64-mingw32-g++
winCFLAGS=-static
CFLAGS=-Wall
A=CycleComputer
default:
	$(CC) -o $(A) main.cpp $(A).cpp $(CFLAGS)
windows:
	$(winCC) -o $(A).exe main.cpp $(A).cpp $(winCFLAGS)
run:
	$(CC) -o $(A) main.cpp $(A).cpp $(CFLAGS) && ./$(A)
clean:
	rm -fv $(A) *~
