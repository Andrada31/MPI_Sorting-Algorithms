#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;

void swap(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
        }
    }
}

void selectionSort(int array[], int n)
{
    int i, j, min_i;
    for (i = 0; i < n - 1; i++)
    {
        min_i = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_i])
                min_i = j;
        swap(&array[min_i], &array[i]);
    }
}

void insertionSort(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}



void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void countingSort(int array[], int n, int k)
{
    int* A = new int[1000000];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(array[i] / k) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        A[count[(array[i] / k) % 10] - 1] = array[i];
        count[(array[i] / k) % 10]--;
    }
    for (i = 0; i < n; i++)
        array[i] = A[i];
}

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int i = 1; m / i > 0; i *= 10)
        countingSort(arr, n, i);
}


int partition(int array[], int l, int r)
{
    int pivot = array[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[r]);
    return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

void merge(int array[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[500000];
    int* R = new int[500000];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i = 0;

    int j = 0;

    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
    delete L;
    delete R;
}

void mergeSort(int array[], int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(array, l, m);
    mergeSort(array, m + 1, r);
    merge(array, l, m, r);
}


int main()
{
    ifstream input;
    ofstream fout1("C:\\Documents\\C_C++\\MPI\\data_in.txt");
    ofstream fout2("C:\\Documents\\C_C++\\MPI\\data_out.txt");
    //choose x var type:
    int x;
    //chose array size:
    int size = 1000000;
    cout<<"Array size: "<<size;

    //Generator 1 -> random x
    for(long i=0;i<size;i++)
    {
        x = rand();
        fout1<<x<<" ";
    }

    //Generator 2 -> reversed array
//    for(int i=size;i>0;i--)
//    {
//        fout1<<i<<" ";
//    }

    //Generator 3 -> sorted array
//    for(int i=0;i<size;i++)
//    {
//        fout1<<i<<" ";
//    }


    input.open("C:\\Documents\\C_C++\\MPI\\data_in.txt"); //read the generated numbers from data_in
    int* array = new int[size];
    int i = 0;
    while (!input.eof())
    {
        input >> array[i++];
    }

    clock_t clkStart;
    clock_t clkFinish;

    auto startTime = chrono::high_resolution_clock::now(); //start the clock
    cout<<"\nSorting algorithm: ";

//    cout<<"BubbleSort\n";
//    bubbleSort(array, size);

//    cout<<"SelectionSort\n";
//    selectionSort(array, size);

//    cout<<"InsertionSort\n";
//    insertionSort(array, size);

//    cout<<"HeapSort\n";
//    heapSort(array, size);

//    cout<<"MergeSort\n";
//    mergeSort(array, 0, size - 1);

//    cout<<"QuickSort\n";
//    quickSort(array, 0, size - 1);

//    cout<<"BucketSort\n";
//    bucketSort(array,size);

//    cout<<"RadixSort\n";
//    radixsort(array, size);

    cout<<"CountingSort\n";
    countingSort(array, size, 1);

    auto endTime = chrono::high_resolution_clock::now(); // Stop the clock
    auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    for (long i = 0; i < size; i++)
        fout2 << array[i] << " ";

    cout << fixed << setprecision(4); // Set output formatting for milliseconds
    cout << "Sorting completed in: " << elapsedTime.count() / 1000.0 << " milliseconds.\n";
    input.close();
    fout1.close();
    fout2.close();
    delete[] array;
    return 0;
}