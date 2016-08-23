/*	7. Write a program that determines the letter that lies halfway between two letters of the
		alphabet as input by the user.For example, if the user inputs ‘A’ and ‘Z’, the output should
		be ‘M’.Do you know how to deal with upper vs.lower case letters ? Does it matter if the
		letters are input in reverse order ?

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
	char cFirstChar = 0, cSecondChar = 0;
	
	//input 2 char
	printf("Input two letters: ");
	scanf_s("%d %d", &cFirstChar, &cSecondChar);

	//calculate letter difference
	printf("%d", cFirstChar);

	//output difference
	system("pause");

}