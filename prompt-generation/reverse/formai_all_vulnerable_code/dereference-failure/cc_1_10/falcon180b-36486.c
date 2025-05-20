//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256
#define MAX_CODE_LENGTH 12

typedef struct {
    char symbol;
    int code;
    int length;
} Code;

void buildTable(char *input, Code *table) {
    int i, j, count[MAX_SYMBOLS];
    memset(count, 0, sizeof(count));

    for (i = 0; input[i]; i++) {
        count[input[i]]++;
    }

    for (i = 0; i < MAX_SYMBOLS; i++) {
        if (count[i]) {
            table[i].symbol = i;
            table[i].length = 1;
            table[i].code = 0;
            for (j = 0; j < MAX_SYMBOLS - 1; j++) {
                if (count[j] > count[i]) {
                    break;
                }
            }
            table[i].code = (1 << j);
            count[i] = 0;
        }
    }
}

void encode(char *input, Code *table, FILE *output) {
    int i, code, length;
    char buffer[MAX_CODE_LENGTH];

    memset(buffer, 0, sizeof(buffer));

    for (i = 0; input[i]; i++) {
        code = table[input[i]].code;
        length = table[input[i]].length;

        while (length > 0) {
            buffer[--length] = code & 0x7f;
            code >>= 7;
        }

        fwrite(buffer, length + 1, 1, output);
    }
}

void decode(FILE *input, Code *table, FILE *output) {
    int i, code, length;
    char buffer[MAX_CODE_LENGTH];

    memset(buffer, 0, sizeof(buffer));

    while (fread(buffer, 1, MAX_CODE_LENGTH, input) > 0) {
        code = 0;
        length = 0;

        while (buffer[length] & 0x80) {
            code |= (buffer[length] & 0x7f) << (length * 7);
            length++;
        }

        fputc(table[code].symbol, output);
    }
}

int main(int argc, char *argv[]) {
    FILE *input, *output;
    Code table[MAX_SYMBOLS];

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "rb");
    output = fopen(argv[2], "wb");

    if (!input ||!output) {
        printf("Error opening files.\n");
        return 1;
    }

    buildTable(argv[1], table);
    encode(argv[1], table, output);
    fclose(input);
    fclose(output);

    printf("Compression complete.\n");

    return 0;
}