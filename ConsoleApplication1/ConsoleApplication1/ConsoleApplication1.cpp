#include "pch.h"

using namespace System;

void CalculateDiameter() {
    Console::WriteLine(L"Завдання 1: Обчислення дiаметра вала");

    double T = 1800.0;  // Обертовий момент, кгс·см
    array<double>^ tau_values = gcnew array<double>{100, 120, 150, 170, 200, 250};

    for (int i = 0; i < tau_values->Length; i++) {
        double d = Math::Sqrt(T / (0.2 * tau_values[i]));  // Обчислення діаметра
        Console::WriteLine(L"d = {0:F2} при t = {1}", d, tau_values[i]);
    }
}

void TransformMatrix() {
    Console::WriteLine(L"\nЗавдання 2: Перетворення матрицi");

    array<int, 2>^ matrix = gcnew array<int, 2>(3, 3) {
        { 3, 5, 9 },
        { 7, 1, 6 },
        { 4, 8, 2 }
    };

    int minVal = Int32::MaxValue;
    int minRow = -1, minCol = -1;

    // Знаходимо найменший елемент і його позицію
    for (int i = 0; i < matrix->GetLength(0); i++) {
        for (int j = 0; j < matrix->GetLength(1); j++) {
            if (matrix[i, j] < minVal) {
                minVal = matrix[i, j];
                minRow = i;
                minCol = j;
            }
        }
    }

    // Замінюємо рядок і стовпець на нулі
    for (int j = 0; j < matrix->GetLength(1); j++) {
        matrix[minRow, j] = 0;
    }
    for (int i = 0; i < matrix->GetLength(0); i++) {
        matrix[i, minCol] = 0;
    }

    Console::WriteLine(L"Матриця пiсля перетворення:");
    for (int i = 0; i < matrix->GetLength(0); i++) {
        for (int j = 0; j < matrix->GetLength(1); j++) {
            Console::Write(matrix[i, j] + L"\t");
        }
        Console::WriteLine();
    }
}

int main(array<System::String^>^ args) {
    CalculateDiameter();
    TransformMatrix();
    return 0;
}
