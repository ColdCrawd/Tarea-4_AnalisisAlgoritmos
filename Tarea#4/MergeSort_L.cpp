#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
using namespace chrono;

void setRandomArray(int arr[], int n, int minVal = 1) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = minVal + rand() % (n - minVal + 1);
    }
}

void merge(int arr[], int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;
  
  vector<int> L(n1);
  vector<int> M(n2);
  
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
    
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
    
  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    
    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 500000000;
    int* arr = new int[size];
    setRandomArray(arr, size, 1);

    //cout << "Array original: ";
    //printArray(arr, size);

    auto inicio = high_resolution_clock::now();
    mergeSort(arr, 0,size-1);
    auto fin = high_resolution_clock::now();

    //cout << "Array ordenado: ";
    //printArray(arr, size);

    duration<double> tiempo = fin - inicio;
    cout << fixed << setprecision(6);
    cout << "Tiempo transcurrido: " << tiempo.count() << " segundos" << endl;

    delete[] arr;
    return 0;
}
