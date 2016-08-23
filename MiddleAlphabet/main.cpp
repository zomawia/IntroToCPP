/*	Zomawia Sailo
	zomawia@gmail.com

7. Write a program that determines the letter that lies halfway between two letters of the
		alphabet as input by the user.For example, if the user inputs ‘A’ and ‘Z’, the output should
		be ‘M’.
		
		Do you know how to deal with upper vs.lower case letters ? 
		Does it matter if the letters are input in reverse order ?

	Note : Each character is assigned a value defined by the ASCII(American Standard Code for
			Information Interchange) character table.

 A = 65
 Z = 90

 a = 97
 z = 122

 */

#include <iostream>

int main()
{
	char chA = 0, chB = 0;
	//int iA,	iB;
	int	iDiff = 0;
	
	//input 2 char
	printf("Enter a letter: ");
	scanf_s(" %c", &chA);

	printf("Enter another letter: ");
	scanf_s(" %c", &chB);
	
	printf("\n\nFirst letter ASCII dec.: %d\n", chA);
	printf("2nd  letter ASCII dec.: %d\n", chB);

	//calculate letter difference using if statements
	//if (chA >= 97)
	//{
	//	chA -= 32;
	//}
	//if (chB >= 97)
	//{
	//	chB -= 32;
	//}

	// calculate using modulus/normalization
	chA = (chA - 65) % 32;
	chB = (chB - 65) % 32;
	
	iDiff = (chB + chA) / 2 + 65;

	//output difference
	printf("\n\nDifference letter: %c\n", iDiff);
	printf("Difference letter ASCII dec.: %d\n", iDiff);

	//	Do you know how to deal with upper vs.lower case letters ?
	// **yes**
	//	Does it matter if the letters are input in reverse order ?
	// **no it doesn't matter**


	system("pause");

}