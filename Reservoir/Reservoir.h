#pragma once
class Reservoir
{
private:
	char* name;
	double width, length, depth;

public:
	Reservoir();
	Reservoir(const char* n, double w, double l, double d);
	~Reservoir();

	double GetVolume();
	double GetArea();

	bool SameType(const Reservoir& other);
	bool CompareArea(const Reservoir& other);

	const char* GetName();
	double GetWidth();
	double GetLength();
	double GetDepth();

	void SetName(const char* n);;
	void SetWidth(double w);
	void SetLength(double l);
	void SetDepth(double d);
	
	Reservoir& operator=(const Reservoir& other);
};