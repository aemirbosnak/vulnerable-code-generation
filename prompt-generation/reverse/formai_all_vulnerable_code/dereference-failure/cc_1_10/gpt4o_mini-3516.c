//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void printBinary(int n) {
    if (n > 1) {
        printBinary(n >> 1);
    }
    printf("%d", n & 1);
}

char* intToBinary(int n) {
    int size = sizeof(n) * 8;
    char *binary = (char*)malloc(size + 1); // Allocate memory for binary string
    if (!binary) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    binary[size] = '\0'; // Null-terminate the string
    for (int i = size - 1; i >= 0; i--) {
        binary[i] = (n & 1) ? '1' : '0';
        n >>= 1;
    }
    return binary;
}

void convertAndPrint(int n) {
    printf("Decimal: %d\n", n);
    printf("Binary: ");
    printBinary(n);
    printf("\n");
}

void interactiveMode() {
    int number;
    while (1) {
        printf("Enter an integer (or type -1 to exit): ");
        scanf("%d", &number);
        if (number == -1) {
            printf("Exiting...\n");
            break;
        }
        convertAndPrint(number);
    }
}

void fileMode(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    int number;
    while (fscanf(file, "%d", &number) != EOF) {
        convertAndPrint(number);
    }
    fclose(file);
}

void usage() {
    printf("Usage:\n");
    printf("1. Enter 'interactive' for interactive mode\n");
    printf("2. Enter 'file [filename]' to read from a file\n");
    printf("3. Enter 'exit' to quit the program\n");
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        usage();
        interactiveMode();
    } else if (argc == 2 && strcmp(argv[1], "interactive") == 0) {
        interactiveMode();
    } else if (argc == 3 && strcmp(argv[1], "file") == 0) {
        fileMode(argv[2]);
    } else {
        printf("Invalid arguments, try again.\n");
        usage();
    }
    return 0;
}