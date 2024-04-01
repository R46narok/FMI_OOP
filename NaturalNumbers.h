#pragma once

#include <iostream>

class NaturalNumbers
{
public:
	NaturalNumbers();
	NaturalNumbers(int* pElements, int size, const char* name);
	NaturalNumbers(const NaturalNumbers& other);
	NaturalNumbers(NaturalNumbers&& other);
	~NaturalNumbers();

	NaturalNumbers& operator=(const NaturalNumbers& other);

	bool isEmpty() const { return m_Size == 0; }
	
	friend std::ostream& operator<<(std::ostream& os, const NaturalNumbers& n);
	friend std::ostream& operator>>(std::ostream& os, const NaturalNumbers& n);

	bool operator[](int n) const;
	NaturalNumbers operator+(const NaturalNumbers& other);
	NaturalNumbers& operator+=(const NaturalNumbers& other);
private:
	int* _union(int* pLeft, int leftSize, int *pRight, int rightSize, int* pResultSize);
	int* fillUnique(int* pElements, int size, int* pResultSize);

	char* m_Name;
	int* m_pElements;
	int m_Size;

};

std::ostream& operator<<(std::ostream& os, const NaturalNumbers& n);
std::ostream& operator>>(std::ostream& os, const NaturalNumbers& n);