#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Find the middle index
        
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Return index of the target element
        }
        
        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }
    
    return -1;  // Return -1 if the target element is not found
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // Sorted array for binary search
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    // Display the original array
    printf("Array: ");
    printArray(arr, size);
    
    // Perform binary search
    int result = binarySearch(arr, size, target);
    
    // Display the result
    if (result != -1) {
        printf("Element %d is present at index %d.\n", target, result);
    } else {
        printf("Element %d is not present in the array.\n", target);
    }
    
    return 0;
}
