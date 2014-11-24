/*
 *	@Author:	Jeff Berube
 *	@Title:		memory.cpp
 *
 *	@Description: Memory class implementation
 *
 */

#include "cmemory"

void Memory::store(int index, int value) {

	data[index] = value;

}

int Memory::retrieve(int index) {

	return data[index];

}

void Memory::copy_block(int source_index, int length, int destination_index) {

	vector<int> tmp;

	printf("BLOCK COPY | SOURCE INDEX: %d \t LENGTH: %d \t DESTINATION INDEX: %d\n\n",
			source_index, length, destination_index);

	/* Save data to temporary vector */
	for (int i = 0; i < length; i++)	
		tmp.push_back(data[source_index + i]);

	/* Copy data to destination */
	for (int i = 0; i < length && i + destination_index < MAX_SIZE; i++)
		data[destination_index + i] = tmp[i];
}

void Memory::dump(int start, int length) {

	/* Output header for memory dump */
	printf("  Memory Dump\t\tStart: %3d\tLength: %3d\n");
	printf("  ----------------------------------------------------\n");

	/* Set color to green and output column labels */
	printf("\033[32m     %4d %4d %4d %4d %4d %4d %4d %4d %4d %4d", 
				0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	int i;

	/* Generate empty space for first row if necessary in partial dump */
	for (i = 0; i < start % 10; i++) {
	
		/* Set color to green and output row label if at start of row */
		if (i % 10 == 0) printf("\n\033[32m%4d\033[m ", start - (start % 10));

		/* Output blank space in case of partial dump */
		printf("     ");

	}

	/* Dump content of memory */
	for (i = start; i < start + length; i++) {
	
		/* Set color to green and output row label if at start of row */
		if (i % 10 == 0) printf("\n\033[32m%4d\033[m ", i);

		/* Print data */
		printf("%4d ", data[i]);

	}
	
	printf("\n\n\n");	

}

void Memory::dump(int start) {

	dump(start, MAX_SIZE - start);

}

void Memory::dump() {

	dump(0, MAX_SIZE);

}

int& Memory::operator[](int value) {

	return data[value];

}

bool operator==(Memory& left_side, Memory& right_side) {

	int i = 0;

	while (i < left_side.MAX_SIZE) {
	
		if (left_side[i] != right_side[i]) return false;
		i++;

	}

	return true;

}

ostream& operator<<(ostream& os, Memory& mem) {

	mem.dump();

	return os;
}

Memory& operator+(Memory& left_side, Memory& right_side) {

	Memory* tmp = new Memory(left_side.MAX_SIZE);

	int i = 0;

	while (i < left_side.MAX_SIZE) {
	
		(*tmp)[i] = left_side[i] + right_side[i];
		i++;

	}

	return *tmp;

}

