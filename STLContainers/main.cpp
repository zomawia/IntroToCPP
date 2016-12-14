#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>


// Random number generator
float randomRange(int start, int end)
{
	return (rand() % (end - start + 1) + start);
}

int main(){
	srand(time(0)); // seeding
	
	std::vector<int> vectorOfInts;
	auto it = vectorOfInts.begin();
	vectorOfInts.resize(20);

	for (it = vectorOfInts.begin(); it != vectorOfInts.end(); ++it) {
		(*it) = rand();
		std::cout << (*it) << std::endl;
	}
	
	std::cout << std::endl << "// sorting" << std::endl << std::endl;

	std::sort(vectorOfInts.begin(), vectorOfInts.end());

	//print
	for (it = vectorOfInts.begin(); it != vectorOfInts.end(); ++it) {
		std::cout << (*it) << std::endl;
	}

	std::cout << std::endl << "// change every second value in the vector to 0" << std::endl << std::endl;
	
	//change every second value in the vector to 0
	
	for (it = vectorOfInts.begin(); it != vectorOfInts.end(); ) {
		it = it + 1;
		(*it) = 0;
		it = it + 1;
	}

	//print
	for (it = vectorOfInts.begin(); it != vectorOfInts.end(); ++it) {
		std::cout << (*it) << std::endl;
	}

	//std::vector<int> vectorOfRandomInts;

	//vectorOfInts.push_back(5);
	//vectorOfInts.push_back(2);
	//vectorOfInts.push_back(7);

	//int secondValue = vectorOfInts.at(1);
	//int thirdValue = vectorOfInts[2];

	//vectorOfInts[2] = 10;

	//if (vectorOfInts.size() > 2) {vectorOfInts[2] = 10;}

	//auto it = vectorOfInts.begin();

	////iValue will equal 5
	//int iValue = (*it);
	//(*it) = 12;

	//it = vectorOfInts.begin();
	//it = it + 2;

	//for (it = vectorOfInts.begin(); it != vectorOfInts.end(); ++it) {
	//	std::cout << (*it) << std::endl;
	//}









	system("pause");
	return 0;
}