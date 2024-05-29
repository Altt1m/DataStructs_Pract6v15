#pragma once
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void ShellSort(int arr[], int n, int& iterations, int& comparisons, int& swaps)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                comparisons++;
                arr[j] = arr[j - gap];
                swaps++;
            }
            arr[j] = temp;
            iterations++;
        }
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

void ShellTask()
{
    const int n = 10000;
    int arr[n];

    srand(time(0));

    FillArrayRandom(arr, n);

    int iterations = 0, comparisons = 0, swaps = 0;

    auto start = high_resolution_clock::now();
    ShellSort(arr, n, iterations, comparisons, swaps);
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
    ShellSort(arr2, m, iterations, comparisons, swaps);
    PrintArray(arr2, m);
}