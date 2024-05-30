#pragma once
#include <iostream>;
#include <chrono>;
#include <cstdlib>;
#include <ctime>;

using namespace std;
using namespace std::chrono;

void PrintArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}

void SelectionSort(int arr[], int n, int& iterations, int& comparisons, int& swaps)
{
    for (int i = 0; i < n - 1; ++i)
    {
        // Шукаємо найменший елемент
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            comparisons++;
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Свапаємо знайдений елемент з першим
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
        iterations++;
    }
}

void SelectionTask()
{
    const int n = 10000; // Розмір масиву
    int arr[n];

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    // Заповнення масиву випадковими числами
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 10000; // Випадкові числа від 0 до 9999
    }

    //int arr[] = { 64, 25, 12, 22, 11 };
    //int n = sizeof(arr) / sizeof(arr[0]);

    int iterations = 0, comparisons = 0, swaps = 0;

    //std::cout << "Original array: ";
    //PrintArray(arr, n);

    // Сортування і замір часу
    auto start = high_resolution_clock::now();
    SelectionSort(arr, n, iterations, comparisons, swaps);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //std::cout << "Sorted array: ";
    //PrintArray(arr, n);

    cout << "Array of 100,000 elements" << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Cast time (microseconds): " << duration.count() << endl;

    iterations = 0, comparisons = 0, swaps = 0;
    const int m = 100;
    int arr2[m];
    for (int i = 0; i < m; ++i)
    {
        arr2[i] = rand() % 300; // Випадкові числа від 0 до 9999
    }

    cout << "\nArray of 100 elements:" << endl;
    SelectionSort(arr2, m, iterations, comparisons, swaps);
    PrintArray(arr2, m);
    cout << "Iterations: " << iterations << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}