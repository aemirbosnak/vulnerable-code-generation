//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int size = 0;
    int choice;

    while(1) {
        printf("\n");
        printf("1. Allocate memory\n");
        printf("2. Deallocate memory\n");
        printf("3. Display memory usage\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of memory to allocate: ");
                scanf("%d", &size);
                ptr = (int*) malloc(size * sizeof(int));
                if(ptr == NULL) {
                    printf("Memory allocation failed!\n");
                }
                else {
                    printf("Memory allocated successfully!\n");
                }
                break;

            case 2:
                if(ptr!= NULL) {
                    free(ptr);
                    ptr = NULL;
                    size = 0;
                    printf("Memory deallocated successfully!\n");
                }
                else {
                    printf("No memory allocated yet!\n");
                }
                break;

            case 3:
                system("free -m");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}