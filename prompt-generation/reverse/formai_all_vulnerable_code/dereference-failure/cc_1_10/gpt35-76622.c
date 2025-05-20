//FormAI DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(int err_code)
{
    switch (err_code) {
        case 1:
            printf("Error: File not found!\n");
            exit(1);
        case 2:
            printf("Error: Memory allocation failed!\n");
            exit(1);
        case 3:
            printf("Error: Divide by zero detected!\n");
            exit(1);
        default:
            printf("Error: Unknown error occurred!\n");
            exit(1);
    }
}

int main(int argc, char* argv[])
{
    FILE* fp;

    if (argc != 2) {
        error(1);
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        error(1);
    }

    char* buffer = (char*) malloc(sizeof(char) * 100);
    if (!buffer) {
        error(2);
    }

    int num, denom, result;

    printf("Enter numerator: ");
    scanf("%d", &num);
    printf("Enter denominator: ");
    scanf("%d", &denom);

    if (denom == 0) {
        error(3);
    }

    result = num / denom;
    printf("Result: %d\n", result);

    fclose(fp);
    free(buffer);

    return 0;
}