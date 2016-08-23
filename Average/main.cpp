// Question 6. Ask the user for 5 while (sic) numbers. Output the average of these numbers

#include <iostream>

int main()
{
	int numOne, numTwo, numThree, numFour, numFive, iAverage = 0;
	float fAverage = 0.0;
	
	printf("Input 5 whole numbers.\n");
	scanf_s("%d %d %d %d %d", &numOne, &numTwo, &numThree, &numFour, &numFive);

	printf("Calculating Average...\n\n");

	fAverage = (numOne + numTwo + numThree + numFour + numFive) / 5.0f;
	iAverage = fAverage;


	printf("Rounded average is: %d\n", iAverage);
	//printf("Decimal average is: %f\n", fAverage);
	
	system("pause"); //pause

}