//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printUsage() {
    printf("Usage: hex_converter [options] <number>\n");
    printf("Options:\n");
    printf("  -h, --help            Display this help message\n");
    printf("  -b, --binary          Convert to binary format\n");
    printf("  -d, --decimal         Convert to decimal format\n");
    printf("  -o, --octal           Convert to octal format\n");
    printf("  -x, --hexadecimal     Convert to hexadecimal format (default)\n");
}

void convertToHex(int number) {
    printf("Hexadecimal: %X\n", number);
}

void convertToBinary(int number) {
    if (number == 0) {
        printf("Binary: 0\n");
        return;
    }
    
    char binary[32];
    int idx = 0;
    
    while (number > 0) {
        binary[idx++] = (number % 2) + '0';
        number /= 2;
    }
    
    printf("Binary: ");
    for (int i = idx - 1; i >= 0; i--) {
        putchar(binary[i]);
    }
    putchar('\n');
}

void convertToDecimal(int number) {
    printf("Decimal: %d\n", number);
}

void convertToOctal(int number) {
    printf("Octal: %o\n", number);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: No number provided.\n");
        printUsage();
        return EXIT_FAILURE;
    }
    
    int number;
    
    // Check for help option
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printUsage();
        return EXIT_SUCCESS;
    }
    
    // Convert input to an integer
    number = atoi(argv[1]);
    if (number < 0) {
        fprintf(stderr, "Error: Please enter a non-negative integer.\n");
        return EXIT_FAILURE;
    }

    // Default to hexadecimal conversion
    if (argc == 2) {
        convertToHex(number);
    } else {
        // Loop through remaining arguments for conversion options
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-b") == 0 || strcmp(argv[i], "--binary") == 0) {
                convertToBinary(number);
            } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decimal") == 0) {
                convertToDecimal(number);
            } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--octal") == 0) {
                convertToOctal(number);
            } else if (strcmp(argv[i], "-x") == 0 || strcmp(argv[i], "--hexadecimal") == 0) {
                convertToHex(number);
            } else {
                fprintf(stderr, "Error: Unknown option '%s'\n", argv[i]);
                printUsage();
                return EXIT_FAILURE;
            }
        }
    }
    
    return EXIT_SUCCESS;
}