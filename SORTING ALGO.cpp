#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

// ---------------- Selection Sort ----------------
void selectionSort(vector<int> arr)
{
    int n = arr.size();
    int swaps = 0;
    int comparisons = 0;

    for(int i = 0; i < n; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            comparisons++;

            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
        swaps++;
    }
}

// ---------------- Bubble Sort ----------------
void bubbleSort(vector<int> arr)
{
    int n = arr.size();
    int swaps = 0;
    int comparisons = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

// ---------------- Quick Sort ----------------
int partition(vector<int>& arr, int low, int high, int& comparisons)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        comparisons++;

        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, int& comparisons)
{
    if(low < high)
    {
        int pi = partition(arr, low, high, comparisons);

        quickSortHelper(arr, low, pi - 1, comparisons);
        quickSortHelper(arr, pi + 1, high, comparisons);
    }
}

void quickSort(vector<int> arr)
{
    int comparisons = 0;

    quickSortHelper(arr, 0, arr.size() - 1, comparisons);
}

// ---------------- Merge Sort ----------------
void merge(vector<int>& arr, int left, int mid, int right, int& comparisons)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        comparisons++;

        if(L[i] <= R[j])
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
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int>& arr, int left, int right, int& comparisons)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSortHelper(arr, left, mid, comparisons);
        mergeSortHelper(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

void mergeSort(vector<int> arr)
{
    int comparisons = 0;

    mergeSortHelper(arr, 0, arr.size() - 1, comparisons);
}

// ---------------- Main Function ----------------
int main()
{
    vector<int> sorted5 = {1, 2, 3, 4, 5};
    vector<int> reverse5 = {5, 4, 3, 2, 1};

    vector<int> sorted100;
    vector<int> reverse100;

    for(int i = 1; i <= 100; i++)
    {
        sorted100.push_back(i);
    }

    for(int i = 100; i >= 1; i--)
    {
        reverse100.push_back(i);
    }

    cout << fixed << setprecision(8);

    // ---------------- Selection Sort ----------------
    cout << "\n=====================================\n";
    cout << "Selection Sort";
    cout << "\n=====================================\n";

    clock_t start, end;
    double totalTime;

    // 5 Sorted
    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        selectionSort(sorted5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Sorted: " << totalTime / 3 << " seconds\n";

    // 5 Reverse
    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        selectionSort(reverse5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Reverse: " << totalTime / 3 << " seconds\n";

    // 100 Sorted
    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        selectionSort(sorted100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Sorted: " << totalTime / 3 << " seconds\n";

    // 100 Reverse
    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        selectionSort(reverse100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Reverse: " << totalTime / 3 << " seconds\n";

    // ---------------- Bubble Sort ----------------
    cout << "\n=====================================\n";
    cout << "Bubble Sort";
    cout << "\n=====================================\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        bubbleSort(sorted5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        bubbleSort(reverse5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Reverse: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        bubbleSort(sorted100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        bubbleSort(reverse100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Reverse: " << totalTime / 3 << " seconds\n";

    // ---------------- Quick Sort ----------------
    cout << "\n=====================================\n";
    cout << "Quick Sort";
    cout << "\n=====================================\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        quickSort(sorted5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        quickSort(reverse5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Reverse: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        quickSort(sorted100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        quickSort(reverse100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Reverse: " << totalTime / 3 << " seconds\n";

    // ---------------- Merge Sort ----------------
    cout << "\n=====================================\n";
    cout << "Merge Sort";
    cout << "\n=====================================\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        mergeSort(sorted5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        mergeSort(reverse5);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "5 Reverse: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        mergeSort(sorted100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Sorted: " << totalTime / 3 << " seconds\n";

    totalTime = 0;

    for(int i = 0; i < 3; i++)
    {
        start = clock();
        mergeSort(reverse100);
        end = clock();

        totalTime += double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "100 Reverse: " << totalTime / 3 << " seconds\n";
system("pause");
return 0;
}