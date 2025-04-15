#include <stdio.h>

// Function to solve Tower of Hanoi problem
// n: number of disks, source: source rod, target: target rod, auxiliary: auxiliary rod
void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        // Base case: Move a single disk from source to target
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    
    // Move n-1 disks from source to auxiliary rod, using target as auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);
    
    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);
    
    // Move the n-1 disks from auxiliary to target rod, using source as auxiliary
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int num;

    // Ask the user for the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    // Call the function to solve the Tower of Hanoi problem
    printf("Solution to Tower of Hanoi for %d disks:\n", num);
    towerOfHanoi(num, 'A', 'C', 'B');  // A is source, C is target, B is auxiliary

    return 0;
}
