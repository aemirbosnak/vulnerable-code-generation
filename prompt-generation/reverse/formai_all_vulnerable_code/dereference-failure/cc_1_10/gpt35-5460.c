//FormAI DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int n, i, choice, val;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("Press 1 to add an element to the array.\n");
        printf("Press 2 to delete an element from the array.\n");
        printf("Press 3 to print the elements of the array.\n");
        printf("Press 4 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element you want to add: ");
                scanf("%d", &val);
                arr = (int*) realloc(arr, (n+1) * sizeof(int));
                arr[n] = val;
                n++;
                printf("Element added successfully.\n");
                break;

            case 2:
                if (n == 0) {
                    printf("Array is already empty.\n");
                } else {
                    printf("Enter the index of the element you want to delete: ");
                    scanf("%d", &val);
                    for (i = val; i < n-1; i++) {
                        arr[i] = arr[i+1];
                    }
                    arr = (int*) realloc(arr, (n-1) * sizeof(int));
                    n--;
                    printf("Element deleted successfully.\n");
                }
                break;

            case 3:
                printf("Elements of the array are:\n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                free(arr);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}