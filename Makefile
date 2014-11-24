CC = g++
OBJ = driver.o memory.o 

memory: $(OBJ)
	$(CC) $(OBJ) -std=c++11 -g -o $@

.cpp.o:
	$(CC) -std=c++11 -g -c $<

clean:
	rm *.o memory
