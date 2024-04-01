#include "NaturalNumbers.h"

#include <cstring>

NaturalNumbers::NaturalNumbers()
	: m_Size(0), m_pElements(nullptr)
{
	m_Name = new char[sizeof("Empty set")];
	strcpy(m_Name, "Empty set");
}

NaturalNumbers::NaturalNumbers(int* pElements, int size, const char* name)
	: m_pElements(nullptr), m_Name(nullptr)
{
	int n = strlen(name);
	m_Name = new char[n + 1];
	memcpy(m_Name, name, n + 1);

	m_pElements = fillUnique(pElements, size, &m_Size);
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& other)
	: m_Size(other.m_Size)
{
	delete m_Name;
	delete m_pElements;

	m_Name = new char[strlen(other.m_Name)];
	strcpy(m_Name, other.m_Name);

	if (!other.isEmpty())
	{
		m_pElements = new int[other.m_Size];
		memcpy(m_pElements, other.m_pElements, other.m_Size);
	}
}

NaturalNumbers::NaturalNumbers(NaturalNumbers&& other)
{
	this->m_Name = other.m_Name;
	this->m_pElements = other.m_pElements;
	this->m_Size = other.m_Size;

	other.m_Name = nullptr;
	other.m_pElements = nullptr;
}

NaturalNumbers::~NaturalNumbers()
{
	delete[] m_pElements;
	delete[] m_Name;
}

NaturalNumbers& NaturalNumbers::operator=(const NaturalNumbers& other)
{
	delete m_Name;
	delete m_pElements;

	m_Name = new char[strlen(other.m_Name)];
	strcpy(m_Name, other.m_Name);

	if (!other.isEmpty())
	{
		m_pElements = new int[other.m_Size];
		memcpy(m_pElements, other.m_pElements, other.m_Size);
	}
	return *this;
}

bool NaturalNumbers::operator[](int n) const
{
	for (int i = 0; i < m_Size; ++i)
	{
		if (m_pElements[i] == n) return true;
	}

	return false;
}

NaturalNumbers NaturalNumbers::operator+(const NaturalNumbers& other)
{
	NaturalNumbers n;
	n.m_Name = new char[sizeof("Union")];
	memcpy(n.m_Name, "Union", 6);
	n.m_pElements = _union(other.m_pElements, other.m_Size, m_pElements, m_Size, &n.m_Size);

	return n;
}

NaturalNumbers& NaturalNumbers::operator+=(const NaturalNumbers& other)
{
	m_Name = new char[sizeof("Union")];
	memcpy(m_Name, "Union", 6);
	m_pElements = _union(other.m_pElements, other.m_Size, m_pElements, m_Size, &m_Size);

	return *this;
}

int* NaturalNumbers::_union(int* pLeft, int leftSize, int* pRight, int rightSize, int* pResultSize)
{
	int* temp = new int[leftSize + rightSize];
	for (int i = 0; i < leftSize; ++i)
	{
		temp[i] = pLeft[i];
	}
	for (int i = 0; i < rightSize; ++i)
	{
		temp[i + leftSize] = pRight[i];
	}
	

	int* pResult = fillUnique(temp, leftSize + rightSize, pResultSize);

	delete[] temp;

	return pResult;
}

int* NaturalNumbers::fillUnique(int* pElements, int size, int *pResultSize)
{
	int* unique = new int[size];
	int uniqueCount = 0;
	for (int i = 0; i < size; ++i)
	{
		bool isUnique = true;
		for (int j = 0; j < uniqueCount; ++j)
		{
			if (pElements[i] == unique[j])
			{
				isUnique = false;
				break;
			}
		}

		if (!isUnique) continue;

		unique[uniqueCount++] = pElements[i];
	}

	int* pResult = new int[uniqueCount];
	*pResultSize = uniqueCount;
	for (int i = 0; i < uniqueCount; ++i)
	{
		pResult[i] = unique[i];
	}

	delete[] unique;

	return pResult;
}

std::ostream& operator<<(std::ostream& os, const NaturalNumbers& n)
{
	std::cout << "[" << n.m_Name << "]" << std::endl;
	for (int i = 0; i < n.m_Size; ++i)
		std::cout << n.m_pElements[i] << " ";
	std::cout << std::endl;
	return os;
}

std::ostream& operator>>(std::ostream& os, const NaturalNumbers& n)
{
	std::cout << "[" << n.m_Name << "]" << std::endl;
	for (int i = 0; i < n.m_Size; ++i)
		std::cout << n.m_pElements[i] << " ";
	std::cout << std::endl;
	return os;
}

