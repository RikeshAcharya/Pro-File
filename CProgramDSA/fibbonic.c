#include <stdio.h>

// Function to print Fibonacci sequence up to nth term
void fibonacciSequence(int n) {
    int first = 0, second = 1, next;

    // Special case for n = 0
    if (n == 0) {
        printf("Fibonacci sequence up to %d term: %d\n", n, first);
        return;
    }

    printf("Fibonacci sequence up to %d terms: ", n);

    // Print the first two terms of the Fibonacci sequence
    printf("%d %d ", first, second);

    // Loop to calculate and print the rest of the terms
    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    printf("\n");
}

int main() {
    int num;

    // Ask the user for the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    // Check for non-negative terms
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        fibonacciSequence(num);
    }

    return 0;
}
