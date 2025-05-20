//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <key> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[3], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char key[strlen(argv[2])];
    strcpy(key, argv[2]);

    int i = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        for (int j = 0; j < strlen(buffer); j++) {
            char c = tolower(buffer[j]);
            if (isalpha(c)) {
                int k = c - 97;
                k = (k + i) % 26;
                if (isupper(c)) {
                    c = (char) (k + 65);
                } else {
                    c = (char) (k + 97);
                }
            }
            fprintf(output_file, "%c", c);
        }
        fprintf(output_file, "\n");
        i++;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}