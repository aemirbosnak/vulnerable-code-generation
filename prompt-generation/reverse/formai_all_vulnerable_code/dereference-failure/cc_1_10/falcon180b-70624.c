//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

void display(int arr[], int n) {
    int i;
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void moveDisk(int arr[], int n, int from, int to, int aux) {
    int i;
    for(i=0; i<n-1; i++) {
        if(i == from) {
            printf("Move disk %d from rod %d to rod %d\n", arr[i], from, to);
            break;
        }
        else if(i == to) {
            printf("Move disk %d from rod %d to rod %d\n", arr[i], from, to);
            break;
        }
        else if(i == aux) {
            printf("Move disk %d from rod %d to rod %d\n", arr[i], from, to);
            break;
        }
    }
}

void towerOfHanoi(int arr[], int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    towerOfHanoi(arr, n-1, from, aux, to);
    moveDisk(arr, n, from, to, aux);
    towerOfHanoi(arr, n-1, aux, to, from);
}

int main() {
    int n, i;
    char from, to, aux;
    srand(time(0));
    n = rand() % MAX_DISKS + 1;
    int *arr = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        arr[i] = rand() % 100;

    printf("Tower of Hanoi problem with %d disks\n", n);
    printf("Initial configuration:\n");
    display(arr, n);

    printf("Enter the rod from which you want to start: ");
    scanf("%c", &from);
    printf("Enter the rod on which you want to place the disks: %c\n", from);
    scanf("%c", &to);
    printf("Enter the auxiliary rod: ");
    scanf("%c", &aux);

    towerOfHanoi(arr, n, from, to, aux);

    printf("\nFinal configuration:\n");
    display(arr, n);
    return 0;
}