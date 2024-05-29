#pragma once
#include <iostream>;
#include <chrono>;
#include <cstdlib>;
#include <ctime>;

using namespace std;
using namespace std::chrono;

void InsertionSort(int arr[], int n, int& iterations, int& comparisons, int& swaps)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
        iterations++;
    }
}

void FillArrayRandom(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % 10000;
    }
}

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

int InsertionTask()
{
    const int n = 10000;
    int arr[n];

    srand(time(0));

    FillArrayRandom(arr, n);

    int iterations = 0, comparisons = 0, swaps = 0;

    auto start = high_resolution_clock::now();
    InsertionSort(arr, n, iterations, comparisons, swaps);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Iterations: " << iterations << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Cast time (microseconds): " << duration.count() << endl;

    const int m = 100;
    int arr2[m];
    for (int i = 0; i < m; ++i)
    {
        arr2[i] = rand() % 300; // Випадкові числа від 0 до 9999
    }

    cout << "Array of 100 elements:\n";
    InsertionSort(arr2, m, iterations, comparisons, swaps);
    PrintArray(arr2, m);
}