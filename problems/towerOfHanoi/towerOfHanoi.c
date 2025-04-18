#include <stdio.h>

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("Move disk %d from %c to %c\n", n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n = 4;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
