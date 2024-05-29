#pragma once
#include <iostream>;
#include <chrono>;

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

void BubbleSort(int arr[], int n, int& iterations, int& comparisons, int& swaps)
{
    int i, j; bool swapped;
    do
    {
        iterations++; swapped = false;
        for (j = 0; j < n - iterations; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                swaps++;
            }
        }
    } while (swapped);
}

void BubbleTask()
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

    int iterations = 0, comparisons = 0, swaps = 0;

    // Сортування і замір часу
    auto start = high_resolution_clock::now();
    BubbleSort(arr, n, iterations, comparisons, swaps);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //cout << "\nSorted array 3: \n"; PrintArray(arr, n);
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
    BubbleSort(arr2, m, iterations, comparisons, swaps);
    PrintArray(arr2, m);
}
