#include <iostream>
#include <assert.h>
#include "sstack.h"
#include <string>

void main() {

	//hashtable tb;
	//tb.set(1, 10);
	//tb.set(13, 11);
	//tb.set(157, 21);
	//tb.set(17, 441);

	//assert(tb.isSet(1));
	////assert(tb.count() == 3);

	//std::cout << "Count: " << tb.count() << std::endl;

	//std::cout << "tb.get = " << tb.get(157) << std::endl;

	//tb.clear();
	//
	//std::cout << "Count: " << tb.count() << std::endl;

	stack<std::string> S;

	S.reserve(50);

	S.push("hello");
	S.push("food");
	S.push("dinosaur");
	S.push("cat memes");
	
	
	std::cout << S.peek() << std::endl;

	S.pop();

	std::cout << S.peek() << std::endl;

	S.pop();

	std::cout << S.peek() << std::endl;

	S.pop();

	std::cout << S.peek() << std::endl;

	system("pause");
}