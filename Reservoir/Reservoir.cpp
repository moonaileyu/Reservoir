#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir()
{
	name = nullptr;
	width = 0;
	length = 0;
	depth = 0;
}

Reservoir::Reservoir(const char* n, double w, double l, double d)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);

	width = w;

	length = l;

	depth = d;
}

Reservoir::Reservoir(const Reservoir& other)
{
	if (other.name)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	else name = nullptr;

	width = other.width;

	length = other.length;

	depth = other.depth;
}

Reservoir::~Reservoir()
{
	delete[] name;
}

double Reservoir::GetVolume() const
{
	return width * length * depth;
}

double Reservoir::GetArea() const
{
	return width * length;
}

bool Reservoir::SameType(const Reservoir& other) const
{
	if (name && other.name)
	{
		return strcmp(name, other.name) == 0;
	}
		
	return false;
}

bool Reservoir::CompareArea(const Reservoir& other) const
{
	if (!SameType(other))
	{
		cout << "Comparison is impossible: different types of reservoirs" << endl;
		return false;
	}

	return GetArea() > other.GetArea();
}

const char* Reservoir::GetName() const
{
	return name;
}

double Reservoir::GetWidth() const
{ 
	return width;
}

double Reservoir::GetLength() const
{
	return length;
}

double Reservoir::GetDepth() const
{
	return depth;
}

void Reservoir::SetName(const char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

void Reservoir::SetWidth(double w)
{
	width = w;
}

void Reservoir::SetLength(double l)
{
	length = l;
}

void Reservoir::SetDepth(double d)
{
	depth = d;
}

Reservoir& Reservoir::operator=(const Reservoir& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] name;

	if (other.name)
	{
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
	}
	else name = nullptr;

	width = other.width;

	length = other.length;

	depth = other.depth;

	return *this;
}

void ReservoirArray::Resize(int NewCapacity)
{
	Reservoir* newArr = new Reservoir[NewCapacity];

	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;

	arr = newArr;
	capacity = NewCapacity;
}

ReservoirArray::ReservoirArray()
{
	size = 0;
	capacity = 2;
	arr = new Reservoir[capacity];
}

ReservoirArray::~ReservoirArray()
{
	delete[] arr;
}

void ReservoirArray::Add(const Reservoir& res)
{
	if (size >= capacity) 
	{
		Resize(capacity * 2);
	}

	arr[size++] = res;
}

void ReservoirArray::Remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	for (int i = index; i < size - 1; i++) 
	{
		arr[i] = arr[i + 1];
	}

	size--;
}

int ReservoirArray::GetSize() const
{
	return size;
}

Reservoir& ReservoirArray::operator[](int index)
{
	return arr[index];
}