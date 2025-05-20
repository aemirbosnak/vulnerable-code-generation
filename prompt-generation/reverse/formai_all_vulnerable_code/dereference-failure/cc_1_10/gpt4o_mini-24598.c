//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdio.h>

void print_pattern(int n) {
    if (n <= 0) {
        fprintf(stderr, "Invalid input! The number of rows must be greater than 0.\n");
        return;
    }
    
    // Print Top Half
    for (int i = 1; i <= n; i++) {
        // Space before stars
        for (int j = i; j < n; j++) {
            putchar(' ');
        }
        // Stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            putchar('*');
        }
        putchar('\n');
    }

    // Print Bottom Half
    for (int i = n - 1; i >= 1; i--) {
        // Space before stars
        for (int j = n; j > i; j--) {
            putchar(' ');
        }
        // Stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int is_valid_number(const char *str) {
    int i = 0;
    if (str[0] == '\0') return 0; // Empty string

    // Check for negative sign
    if (str[0] == '-') {
        i++;
        if (str[1] == '\0') return 0; // Just a negative sign
    }

    // Check each character
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') return 0; // Not a digit
        i++;
    }
    return 1; // Valid number
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_rows>\n", argv[0]);
        return 1; 
    }

    // Check for valid number input
    if (!is_valid_number(argv[1])) {
        fprintf(stderr, "Error: Please enter a valid positive integer.\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n <= 0) {
        fprintf(stderr, "Error: The number of rows must be a positive integer.\n");
        return 1;
    }

    printf("Generating a pattern with %d rows...\n", n);
    print_pattern(n);
    
    printf("Pattern generated successfully.\n");
    return 0;
}