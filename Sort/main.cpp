#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

void printData(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		printf("%i ", data[i]);
	}
	printf("\n\n");
}

void randFill(int *data, size_t length) {
	for (int i = 0; i < length; ++i) {
		data[i] = rand() % 100;
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
	//printData(data + L, R + 1 - L);
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

int getMax(int *data, int length) {
	int mx = data[0];
	for (int i = 1; i < length; i++)
		if (data[i] > mx)
			mx = data[i];
	return mx;
}

void countSort(int *data, int length, int exp) {
	int *output = new int[length];
	int i, count[10] = {0};

	for (i = 0; i < length; i++)
		count[(data[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = length - 1; i >= 0; i--) {
		output[count[(data[i] / exp) % 10] - 1] = data[i];
		count[(data[i] / exp) % 10]--;
	}

	for (i = 0; i < length; i++)
		data[i] = output[i];
}

void radishSort(int *data, int length){
	int m = getMax(data, length);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(data, length, exp);
}

int *linearSearch(int *data, size_t length, int key) {

	for (int i = 0; i < length; ++i)
		if (data[i] == key)
			return &data[i];

	return nullptr;
}

int *binarySearch(int *data, size_t length, int key) {
	size_t	min = 0, 
			max = length - 1, 
			mid;

	while (min != max) {
		mid = (min + max) / 2;
		if (key == data[mid]) return &data[mid];
		else if (key > data[mid]) min = mid + 1;
		else if (key < data[mid]) max = mid - 1;
	}
	return NULL;
}

using namespace std::chrono;

void main() {
	
	srand(time(0));

	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	
	const size_t length = 10240;
	int data[length];

	randFill(data, length);

	t1 = high_resolution_clock::now();
	bubbleSort(data, length);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Bubble Time: " << duration << std::endl;

	randFill(data, length);

	t1 = high_resolution_clock::now();
	gnomeSort(data, length);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Gnome Time: " << duration << std::endl;

	randFill(data, length);

	t1 = high_resolution_clock::now();
	radishSort(data, length);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Radish Time: " << duration << std::endl;

	randFill(data, length);

	t1 = high_resolution_clock::now();
	mergeSort(data, length);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Merge Time: " << duration << std::endl;

	randFill(data, length);

	t1 = high_resolution_clock::now();
	insertionSort(data, length);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Insertion Time: " << duration << std::endl;

	system("pause");



}
