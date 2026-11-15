/*
Write a C++ program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix
*/

#include <iostream>
using namespace std;

class MatrixOps
{
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

public:
    // Input matrices
    void input()
    {
        cout << "Enter rows and columns of first matrix: ";
        cin >> r1 >> c1;

        cout << "Enter first matrix:\n";
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                cin >> A[i][j];

        cout << "Enter rows and columns of second matrix: ";
        cin >> r2 >> c2;

        cout << "Enter second matrix:\n";
        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                cin >> B[i][j];
    }

    // Display matrix
    void display(int M[10][10], int r, int c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }

    // Addition
    void addition()
    {
        if (r1 != r2 || c1 != c2)
        {
            cout << "Addition not possible.\n";
            return;
        }

        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                C[i][j] = A[i][j] + B[i][j];

        display(C, r1, c1);
    }

    // Subtraction
    void subtraction()
    {
        if (r1 != r2 || c1 != c2)
        {
            cout << "Subtraction not possible.\n";
            return;
        }

        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                C[i][j] = A[i][j] - B[i][j];

        display(C, r1, c1);
    }

    // Multiplication
    void multiplication()
    {
        if (c1 != r2)
        {
            cout << "Multiplication not possible.\n";
            return;
        }

        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < c1; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }

        display(C, r1, c2);
    }

    // Transpose
    void transpose()
    {
        for (int i = 0; i < c1; i++)
        {
            for (int j = 0; j < r1; j++)
                cout << A[j][i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    MatrixOps m;
    m.input();

    cout << "\nAddition:\n";
    m.addition();

    cout << "\nSubtraction:\n";
    m.subtraction();

    cout << "\nMultiplication:\n";
    m.multiplication();

    cout << "\nTranspose:\n";
    m.transpose();

    return 0;
}
