#pragma once
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

void MergeSort(int arr[], int left, int right, int& comparisons, int& swaps, int& iterations)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // ���������� ������� ����� ��������
        MergeSort(arr, left, mid, comparisons, swaps, iterations);
        MergeSort(arr, mid + 1, right, comparisons, swaps, iterations);

        // ��'������ ���������� ��������
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // ��������� �������� ������
        int* L = new int[n1];
        int* R = new int[n2];

        // ��ﳺ�� � ��� ���
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[mid + 1 + j];
        }

        // ��'������ �������� ������ ����� � arr[left..right]
        int i = 0; // ���������� ������ ������� ��������
        int j = 0; // ���������� ������ ������� ��������
        int k = left; // ���������� ������ ������ ��������
        while (i < n1 && j < n2)
        {
            comparisons++;
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
            swaps++;
        }

        // ������� �������� �������� � L[], ���� ���� �
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
            swaps++;
        }

        // ������� �������� �������� � R[], ���� ���� �
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
            swaps++;
        }

        // ��������� �������� ������
        delete[] L;
        delete[] R;

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

void MergeTask()
{
    const int n = 10000;
    int arr[n];

    srand(time(0)); // ������������� ���������� ��������� �����

    FillArrayRandom(arr, n);

    int comparisons = 0, swaps = 0, iterations = 0;

    auto start = high_resolution_clock::now();
    MergeSort(arr, 0, n - 1, comparisons, swaps, iterations);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    //cout << "Sorted array: ";
    //PrintArray(arr, n);

    cout << "Iterations: " << iterations << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Cast time (microseconds): " << duration.count() << endl;
}