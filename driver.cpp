/*
 *	@Author:	Jeff Berube
 *	@Title:		driver.cpp
 *
 *	@Description:	Test unit for memory class with overloaded operators 
 *
 */

#include <cstdlib>

#include "cmemory"

using namespace std;

void test_equality(Memory& left_side, Memory& right_side) {

	if (left_side == right_side) printf("A is equal to B.\n\n");
	else printf("A is not equal to B.\n\n");

}

int main() {

	Memory A(100);
	Memory B, C;

	/* Populate B with 5 for the first 50 values */
	for (int i = 0; i < 50; i++)
		B[i] = 5;

	printf("\n*** Subscript Operator Test ***\n");
	printf("Object B populated using subscript operator\n\n");
	
	B.dump();

	A = B;

	printf("\n*** Equality Operator Test #1 ***\n");
	printf("Object B copied into A and then tested for equality.\n\n");

	test_equality(A, B);

	printf("\n*** Equality Operator Test #2 ***\n");
	printf("Object A modified and then tested for equality against object B.\n\n");

	A[3] = 4;

	test_equality(A, B);

	printf("\n*** Addition Operator Test ***\n");
	printf("Object C is equal to Object A plus Object B\n\n");
	
	C = A + B;

	C.dump();

	printf("\n*** Output Operator Test ***\n");
	printf("Object C dumped using << operator\n\n");

	cout << C;

	return 0;

}
