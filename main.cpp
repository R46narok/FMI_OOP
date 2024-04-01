#include <iostream>

#include "NaturalNumbers.h"

int main()
{
	int arr[] = {1, 2, 3, 3, 3, 4, 5, 5, 6, 8, 8, 9};
	int *arrp = &(arr[0]);
	int size = sizeof(arr) / sizeof(int);

	NaturalNumbers n1 = NaturalNumbers(arrp, size, "My set1");

	int arr1[] = { 10, 5, 5, 5, 3, 4, 4, 8, 11, 144, 23 };
	int* arrp1 = &(arr1[0]);
	int size1 = sizeof(arr1) / sizeof(int);
	NaturalNumbers n2 = NaturalNumbers(arrp1, size1, "My set2");

	n1 += n2;
	std::cout << n1 << std::endl;
}