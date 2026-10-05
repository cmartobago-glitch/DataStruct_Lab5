#include <iostream>
#include "DynamicArray.h"

using namespace std;

void processMatrix()
{
    const int rows = 3;
    const int columns = 3;

    int matrix[rows][columns] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transpose[columns][rows];

    // Create the transpose of the matrix.
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;

    for (int i = 0; i < columns; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cout << transpose[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    cout << "--- STARTING REFACTORED SUBSYSTEM ---" << endl;

    DynamicArray list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60);

    cout << "Size: " << list.getSize() << endl;
    cout << "Capacity: " << list.getCapacity() << endl;

    list.print();

    cout << "Found 30 at index: "
         << list.find(30) << endl;

    list.removeAt(2);

    list.print();

    cout << "Testing invalid index:" << endl;
    list.removeAt(99);

    list.print();

    processMatrix();

    return 0;
}