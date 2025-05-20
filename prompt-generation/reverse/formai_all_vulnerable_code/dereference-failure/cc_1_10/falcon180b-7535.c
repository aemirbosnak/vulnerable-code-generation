//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *binary;
    int decimal;
} binary_t;

binary_t *binary_table = NULL;
int table_size = 0;

void init_binary_table() {
    binary_table = (binary_t *) malloc(sizeof(binary_t));
    table_size = 1;
    strcpy(binary_table[0].binary, "0");
    binary_table[0].decimal = 0;
}

void add_binary_entry(char *binary, int decimal) {
    binary_t *new_table = (binary_t *) realloc(binary_table, sizeof(binary_t) * (table_size + 1));
    if (new_table == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    binary_table = new_table;
    strcpy(binary_table[table_size].binary, binary);
    binary_table[table_size].decimal = decimal;
    table_size++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <decimal_number>\n", argv[0]);
        exit(1);
    }

    int decimal = atoi(argv[1]);

    if (decimal < 0 || decimal > 255) {
        printf("Error: Input must be between 0 and 255.\n");
        exit(1);
    }

    init_binary_table();
    add_binary_entry("0", 0);
    add_binary_entry("1", 1);

    char binary[9];
    int i = 0;
    while (decimal > 0) {
        binary[i++] = '0' + decimal % 2;
        decimal /= 2;
    }

    printf("Decimal: %d\n", decimal);
    printf("Binary:  ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");

    return 0;
}