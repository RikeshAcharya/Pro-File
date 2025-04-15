#include <stdio.h>

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort helper functions
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
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
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort helper functions
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Arrays for different sorting algorithms
    int arr1[] = {12, 11, 13, 5, 6, 64, 100};
    int arr2[] = {12, 11, 13, 5, 6, 7, 8};
    int arr3[] = {4, 3, 1, 2, 5, 9, 7, 10, 6};
    int arr4[] = {12, 34, 54, 2, 3, 6, 7};
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    int arr6[] = {64, 25, 12, 22, 11, 10, 1};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int n6 = sizeof(arr6) / sizeof(arr6[0]);

    // Insertion Sort
    printf("\nInsertion Sort:\n");
    printf("Original data: ");
    printArray(arr1, n1);
    insertionSort(arr1, n1);
    printf("Sorted data: ");
    printArray(arr1, n1);

    // Merge Sort
    printf("\nMerge Sort:\n");
    printf("Original data: ");
    printArray(arr2, n2);
    mergeSort(arr2, 0, n2 - 1);
    printf("Sorted data: ");
    printArray(arr2, n2);

    // Quick Sort
    printf("\nQuick Sort:\n");
    printf("Original data: ");
    printArray(arr3, n3);
    quickSort(arr3, 0, n3 - 1);
    printf("Sorted data: ");
    printArray(arr3, n3);

    // Shell Sort
    printf("\nShell Sort:\n");
    printf("Original data: ");
    printArray(arr4, n4);
    shellSort(arr4, n4);
    printf("Sorted data: ");
    printArray(arr4, n4);

    // Bubble Sort
    printf("\nBubble Sort:\n");
    printf("Original data: ");
    printArray(arr5, n5);
    bubbleSort(arr5, n5);
    printf("Sorted data: ");
    printArray(arr5, n5);

    // Selection Sort
    printf("\nSelection Sort:\n");
    printf("Original data: ");
    printArray(arr6, n6);
    selectionSort(arr6, n6);
    printf("Sorted data: ");
    printArray(arr6, n6);

    return 0;
}
