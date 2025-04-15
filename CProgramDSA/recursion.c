#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n * factorial(n-1)
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;

    // Ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for negative numbers as factorial is not defined for them
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Call the factorial function and display the result
        printf("Factorial of %d is %d\n", num, factorial(num));
    }

    return 0;
}
