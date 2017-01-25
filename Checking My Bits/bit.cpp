#include <iostream>

//Returns `true` if the left most bit(MSB) of the `value` is set.
//Otherwise, this returns `false`.
bool IsLeftMostBitSet(unsigned int value) {
	return (int)value > 0;
}

//Returns `true` if the right most bit(LSB) of the `value` is set.
//Otherwise, this returns `false`.
bool IsRightMostBitSet(unsigned int value) {
	return value & 1;
}

//Returns `true` if the specified `bitToCheck` is set.The bits are
//zero indexed starting from the right most bit.
bool IsBitSet(unsigned int value, unsigned char bitToCheck) {


	return value & bitToCheck;
}

//Input | Output
//-------- - | ------ -
//00000001 | 0
//10011100 | 2
//01010000 | 4
//00000000 | -1
int GetRightMostSetBit(unsigned int value) {

	for (int i = 0; i < 8; ++i) {

	}
	return 0;
}

//Prints the `value` in binary.
void PrintBinary(unsigned char value) {
	int printCount = sizeof(unsigned char) * 8;

	char * bof = new char[printCount];

	for (int i = 0; i < printCount; ++i) {
		bof[printCount - i - 1] = ((value >> i) & 1) ? '1' : '0';
	}

	for (int i = 0; i < printCount; ++i) {
		std::cout << bof[i];
	}

	delete[] bof;

	std::cout << std::endl;
}

//Using only bitwise arithmetic operators, determine if the given `value` is
//a power of two.
bool IsPowerOf2(unsigned int value) {
	int qty = 0;

	const int bitCount = sizeof(unsigned int);

	for (int i = 0; i <= bitCount; ++i) {
		int shifted = value >> i;
		if (shifted & 1)
			qty++;
	}

	return qty % 2;
}