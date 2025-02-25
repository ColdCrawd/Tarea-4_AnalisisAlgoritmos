#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;

void setRandomArray(int arr[], int n, int minVal = 1) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = minVal + rand() % (n - minVal + 1);
    }
}

void bubbleSort(int arr[]){
    for(int i= 5000 ; i>0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j]> arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[]) {
    for (int i = 0; i < 5000; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int* arr = new int[5000];
    setRandomArray(arr, 5000, 1);

    //cout << "Array original: ";
    //printArray(arr);

    auto inicio = high_resolution_clock::now();
    bubbleSort(arr);
    auto fin = high_resolution_clock::now();

    //cout << "Array ordenado: ";
    //printArray(arr);

    duration<double> tiempo = fin - inicio;
    cout << fixed << setprecision(6);
    cout << "Tiempo transcurrido: " << tiempo.count() << " segundos" << endl;

    delete[] arr;
    return 0;
}
