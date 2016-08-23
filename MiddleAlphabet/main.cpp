/*	7. Write a program that determines the letter that lies halfway between two letters of the
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
	char chA, chB;
	int iA,	iB,	iDiff;
	
	//input 2 char
	printf("Enter letter: ");
	scanf_s(" %c", &chA);

	printf("Enter another letter: ");
	scanf_s(" %c", &chB);
	
	printf("First letter ASCII: %d\n", chA);
	printf("2nd  letter ASCII: %d\n", chB);

	//calculate letter difference
	iA = chA;
	iB = chB;
	iDiff = (iB + iA) / 2;

	//output difference
	printf("Difference letter: %c\n", iDiff);
	printf("Difference letter ASCII: %d\n", iDiff);

	//	Do you know how to deal with upper vs.lower case letters ?
	//
	//	Does it matter if the letters are input in reverse order ?
	//


	system("pause");

}