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

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
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
    quickSort(arr, 0, size-1);
    auto fin = high_resolution_clock::now();

    //cout << "Array ordenado: ";
    //printArray(arr, size);

    duration<double> tiempo = fin - inicio;
    cout << fixed << setprecision(6);
    cout << "Tiempo transcurrido: " << tiempo.count() << " segundos" << endl;

    delete[] arr;
    return 0;
}
