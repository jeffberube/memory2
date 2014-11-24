/*
 *	@Author:	Jeff Berube
 *	@Title:		driver.cpp
 *
 *	@Description:	Test unit for memory class
 *
 */

#include <cstdlib>

#include "cmemory"

using namespace std;

int main() {

	Memory mem;

	/* Randomly populate memory with ints */
	for (int i = 0; i < 100; i++)
		mem.store(i, rand() % 100 + 1);

	printf("\n\nMemory after being randomly populated.\n\n");

	mem.dump();

	mem.copy_block(0, 20, 83);

	printf("Memory after block copy.\n\n");

	mem.dump();

	printf("Partial memory dump using only start index\n\n");

	mem.dump(21);

	printf("Partial memory dump using start index and length.\n\n");

	mem.dump(21, 20);

	return 0;

}
