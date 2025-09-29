#pragma once
class Reservoir
{
private:
	char* name;
	double width, length, depth;

public:
	Reservoir();
	Reservoir(const char* n, double w, double l, double d);
	Reservoir(const Reservoir& other); 
	~Reservoir();

	double GetVolume() const;
	double GetArea() const;

	bool SameType(const Reservoir& other) const;
	bool CompareArea(const Reservoir& other) const;

	const char* GetName() const;
	double GetWidth() const;
	double GetLength() const;
	double GetDepth() const;

	void SetName(const char* n);;
	void SetWidth(double w);
	void SetLength(double l);
	void SetDepth(double d);
	
	Reservoir& operator=(const Reservoir& other);
};

class ReservoirArray 
{
private:
	Reservoir* arr;
	int size;
	int capacity;

	void Resize(int NewCapacity);

public:
	ReservoirArray();
	~ReservoirArray();

	void Add(const Reservoir& res);
	void Remove(int index);

	int GetSize() const;
	Reservoir& operator[](int index);
};