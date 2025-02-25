#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
using namespace chrono;

void setRandomArray(int arr[], int n, int minVal = 1)
{
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        arr[i] = minVal + rand() % (n - minVal + 1);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 500000;
    int *arr = new int[size];
    setRandomArray(arr, size, 1);

    //cout << "Array original: ";
    //printArray(arr, size);

    auto inicio = high_resolution_clock::now();
    heapSort(arr, size);
    auto fin = high_resolution_clock::now();

    //cout << "Array ordenado: ";
    //printArray(arr, size);

    duration<double> tiempo = fin - inicio;
    cout << fixed << setprecision(6);
    cout << "Tiempo transcurrido: " << tiempo.count() << " segundos" << endl;

    delete[] arr;
    return 0;
}
