//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

void print_usage() {
    printf("Usage: hex_converter [option] <value>\n");
    printf("Options:\n");
    printf("  -d  Convert decimal to hexadecimal\n");
    printf("  -h  Convert hexadecimal to decimal\n");
    printf("  -i  Interactive mode\n");
    printf("  -f  File mode, provide input through file\n");
}

void decimal_to_hexadecimal(int decimal) {
    printf("Decimal: %d -> Hexadecimal: %X\n", decimal, decimal);
}

void hexadecimal_to_decimal(const char *hexadecimal) {
    int decimal;
    sscanf(hexadecimal, "%x", &decimal);
    printf("Hexadecimal: %s -> Decimal: %d\n", hexadecimal, decimal);
}

void interactive_mode() {
    char input[MAX_INPUT_SIZE];
    int is_running = 1;

    while (is_running) {
        printf("Enter 'd' for Decimal to Hexadecimal or 'h' for Hexadecimal to Decimal (or 'q' to quit): ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strncmp(input, "q", 1) == 0) {
            is_running = 0;
            continue;
        }

        if (strncmp(input, "d", 1) == 0) {
            int decimal;
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            getchar(); // Clear newline from buffer
            decimal_to_hexadecimal(decimal);
        } else if (strncmp(input, "h", 1) == 0) {
            char hex[MAX_INPUT_SIZE];
            printf("Enter a hexadecimal number: ");
            fgets(hex, MAX_INPUT_SIZE, stdin);
            hex[strcspn(hex, "\n")] = 0; // Remove newline character
            hexadecimal_to_decimal(hex);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
}

void file_mode(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_INPUT_SIZE];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        if (line[0] == 'd') {
            int decimal = atoi(line + 2);
            decimal_to_hexadecimal(decimal);
        } else if (line[0] == 'h') {
            hexadecimal_to_decimal(line + 2);
        } else {
            printf("Invalid format in file: %s\n", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "-d") == 0) {
        if (argc != 3) {
            print_usage();
            return 1;
        }
        int decimal = atoi(argv[2]);
        decimal_to_hexadecimal(decimal);
    } else if (strcmp(argv[1], "-h") == 0) {
        if (argc != 3) {
            print_usage();
            return 1;
        }
        hexadecimal_to_decimal(argv[2]);
    } else if (strcmp(argv[1], "-i") == 0) {
        interactive_mode();
    } else if (strcmp(argv[1], "-f") == 0) {
        if (argc != 3) {
            print_usage();
            return 1;
        }
        file_mode(argv[2]);
    } else {
        print_usage();
        return 1;
    }

    return 0;
}