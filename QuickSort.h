#pragma once
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void QuickSort(int arr[], int left, int right, int& comparisons, int& swaps, int& iterations)
{
    if (left < right)
    {
        int pivot = arr[right];
        int i = (left - 1);

        for (int j = left; j <= right - 1; j++)
        {
            comparisons++;
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
        swap(arr[i + 1], arr[right]);
        swaps++;
        int pivotIndex = i + 1;

        iterations++;
        QuickSort(arr, left, pivotIndex - 1, comparisons, swaps, iterations);
        QuickSort(arr, pivotIndex + 1, right, comparisons, swaps, iterations);
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

void QuickTask()
{
    const int n = 10000;
    int arr[n];

    srand(time(0)); // »нициализаци€ генератора случайных чисел

    FillArrayRandom(arr, n);

    int comparisons = 0, swaps = 0, iterations = 0;

    auto start = high_resolution_clock::now();
    QuickSort(arr, 0, n - 1, comparisons, swaps, iterations);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //cout << "Sorted array: ";
    //PrintArray(arr, n);

    cout << "Iterations: " << iterations << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Cast time (microseconds): " << duration.count() << endl;
}