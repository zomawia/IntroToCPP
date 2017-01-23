#include <iostream>
#include <random>

void printData(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		printf("%i ", data[i]);
	}
	printf("\n\n");
}

void randFill(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		data[i] = rand();
	}
}

void bubbleSort(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (data[j] < data[j - 1]) {
				int temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;					
			}
		}

	}

}

void insertionSort(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		int j = i;
		int temp;
		while(j > 0 && data[j-1] > data[j]){
			std::swap(data[j], data[j - 1]);
			j--;
		}
	}
}

void mergeSortR(int *data, size_t L, size_t R) {
	printData(data + L, R + 1 - L);
	if (L < R) {		
		size_t middle = (L + R) / 2;
		mergeSortR(data, L, middle);
		mergeSortR(data, middle + 1, R);		
		
	}
	
}

void mergeSort(int *data, size_t length) {
	mergeSortR(data, 0, length - 1);
}

void merge(int *data, size_t L, size_t M, size_t R) {
	size_t s = R - L;
	int *A = new int[s+1];
	size_t l = L, r = M + 1;

	for (int i = 0; i < s; ++i) {
		if (l <= M && r <= R) {
			if (data[l] < data[r]) A[i] = data[l++];
			else A[i] = data[r++];
		}
		
		if (l == M)	A[i] = data[r++];
		else A[i] = data[l++];
	}

	for (int i = 0; i < s; ++i)
		data[L + i] = A[i];

	delete[] A;
}

void gnomeSort(int *data, int length) {
	int index = 0;

	while (index < length) {
		if (index == 0) index++;
		if (data[index] >= data[index - 1]) index++;
		else {
			std::swap(data[index], data[index - 1]);
			index--;
		}
	}
}

void main() {
	const size_t length = 8;
	int data[length];
	randFill(data, length);
	printData(data, length);
	//bubbleSort(data, length);
	//insertionSort(data, length);
	//mergeSort(data, length);
	gnomeSort(data, length);
	printData(data, length);
	system("pause");
}
