// Excercise Variables
// Question 4 - Swapper Program

#include <iostream>

int main()
{
	int varA, varB, varSwap = 0;

	//printf("Var currently stores: %d \n", var);
	printf("Input two numbers: ");
	scanf_s("%d %d", &varA, &varB); // assign var a value from console
	getchar(); // inappropriate way to clear buffer

	printf("A: %d, B: %d \n", varA, varB);
	printf("Performing swap... press Enter\n");
	getchar();

	varSwap = varA; // varA value hold temporarily in varSwap
	varA = varB;
	varB = varSwap;

	printf("A is now: %d\n B is now: %d", varA, varB);

	getchar();
	
}