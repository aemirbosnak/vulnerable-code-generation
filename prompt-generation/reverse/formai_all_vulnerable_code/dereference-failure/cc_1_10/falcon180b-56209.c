//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

struct color_code {
    char *hex;
    int r, g, b;
};

static struct color_code codes[] = {
    {"#000000", 0, 0, 0},
    {"#800000", 128, 0, 0},
    {"#008000", 0, 128, 0},
    {"#808000", 128, 128, 0},
    {"#000080", 0, 0, 128},
    {"#800080", 128, 0, 128},
    {"#008080", 0, 128, 128},
    {"#c0c0c0", 192, 192, 192},
    {"#ff0000", 255, 0, 0},
    {"#00ff00", 0, 255, 0},
    {"#ffff00", 255, 255, 0},
    {"#0000ff", 0, 0, 255},
    {"#ff00ff", 255, 0, 255},
    {"#00ffff", 0, 255, 255},
    {"#ffffff", 255, 255, 255}
};

int main(int argc, char **argv) {
    FILE *in_file, *out_file;
    char line[MAX_LINE_LEN];
    char *hex_code;
    int i;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, in_file)!= NULL) {
        hex_code = strstr(line, "#");
        if (hex_code!= NULL) {
            for (i = 0; i < sizeof(codes) / sizeof(codes[0]); i++) {
                if (strcmp(codes[i].hex, hex_code) == 0) {
                    fprintf(out_file, "%s", codes[i].hex);
                    break;
                }
            }
        } else {
            fprintf(out_file, "%s", line);
        }
    }

    fclose(in_file);
    fclose(out_file);

    return 0;
}