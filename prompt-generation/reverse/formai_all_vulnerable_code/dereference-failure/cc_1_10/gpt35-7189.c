//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void handleError(int error_code) {
    switch(error_code) {
        case 1:
            printf("Error: File could not be opened.\n");
            exit(1);
        case 2:
            printf("Error: Out of memory.\n");
            exit(1);
        case 3:
            printf("Error: Division by zero.\n");
            exit(1);
        default:
            printf("Unknown error occured.\n");
            exit(1);
    }
}

int main() {
    FILE *fp = fopen("file.txt", "r");
    int *arr;
    int num, denom;

    if(fp == NULL) {
        handleError(1);
    }

    arr = malloc(10 * sizeof(int));
    if(arr == NULL) {
        handleError(2);
    }

    printf("Enter a numerator: ");
    scanf("%d", &num);
    printf("Enter a denominator: ");
    scanf("%d", &denom);

    if(denom == 0) {
        handleError(3);
    }

    printf("%d / %d = %d\n", num, denom, num/denom);

    fclose(fp);
    free(arr);

    return 0;
}