//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {

    FILE *fp;
    char filename[50];
    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nError: %s\n", strerror(errno));
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int num;
    printf("\nEnter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("\nError: Invalid input\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    int arr[5] = {1, 2, 3, 4, 5};
    int index;
    printf("\nEnter an index: ");
    if (scanf("%d", &index) != 1) {
        printf("\nError: Invalid input\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    } else if (index < 0 || index > 4) {
        printf("\nError: Index out of bounds\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    char str[50];
    printf("\nEnter a string: ");
    if (scanf("%s", str) != 1) {
        printf("\nError: Invalid input\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    printf("\nNumber: %d\n", num);
    printf("Array value at index %d: %d\n", index, arr[index]);
    printf("String: %s\n", str);

    fclose(fp);
    exit(EXIT_SUCCESS);
}