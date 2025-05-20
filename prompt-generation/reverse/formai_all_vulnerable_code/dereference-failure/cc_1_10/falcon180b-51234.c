//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CODE_LEN 7
#define HEX_CHARS "0123456789ABCDEF"

void print_usage() {
    printf("Usage:./program <input_file> <output_file>\n");
}

int is_valid_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
}

int hex_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    } else {
        return c - 'a' + 10;
    }
}

void rgb_to_hex(int r, int g, int b, char* hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

void hex_to_rgb(char* hex, int* r, int* g, int* b) {
    int len = strlen(hex);
    if (len!= MAX_CODE_LEN) {
        printf("Invalid hex code length.\n");
        exit(1);
    }
    if (hex[0]!= '#') {
        printf("Hex code must start with #.\n");
        exit(1);
    }
    *r = hex_to_int(hex[1]) * 16 + hex_to_int(hex[2]);
    *g = hex_to_int(hex[3]) * 16 + hex_to_int(hex[4]);
    *b = hex_to_int(hex[5]) * 16 + hex_to_int(hex[6]);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        int pos = 0;
        while ((pos = strcspn(line + pos, ","))!= strlen(line)) {
            char* rgb_str = line + pos + 1;
            pos += strlen(rgb_str) + 1;
            int r, g, b;
            hex_to_rgb(rgb_str, &r, &g, &b);
            rgb_to_hex(r, g, b, line + pos - strlen(rgb_str) - 1);
            pos += MAX_CODE_LEN - 1;
        }
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}