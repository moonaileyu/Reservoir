#include "Reservoir.h"
#include <iostream>
using namespace std;

int main()
{
    Reservoir Lake("Lake", 200, 300, 50);
    Reservoir Sea("Sea", 1000, 2000, 150);
    Reservoir Ocean("Ocean", 5000, 8000, 3000);

    ReservoirArray arr;
    arr.Add(Lake);
    arr.Add(Sea);
    arr.Add(Ocean);

    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << "Reservoir type: " << arr[i].GetName() << endl;
        cout << "Width: " << arr[i].GetWidth() << endl;
        cout << "Length: " << arr[i].GetLength() << endl;
        cout << "Depth: " << arr[i].GetDepth() << endl;
        cout << "Area: " << arr[i].GetArea() << endl;
        cout << "Volume: " << arr[i].GetVolume() << endl;
    }

    cout << "Compare area of Lake and Sea: " << (Lake.CompareArea(Sea) ? "Lake is bigger" : "Sea is bigger or different type") << endl;

    cout << "Lake and Sea same type? " << (Lake.SameType(Sea) ? "Yes" : "No") << endl;

    return 0;
}