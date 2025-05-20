//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    FILE *input_file, *output_file;
    char filename[100];
    char input_buffer[1000];
    char output_buffer[1000];
    int i, j, k, n;
    int key;
    int option;

    printf("Enter filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter encryption key (0-25): ");
    scanf("%d", &key);

    printf("Enter output filename: ");
    scanf("%s", filename);

    output_file = fopen(filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(input_buffer, 1000, input_file)!= NULL) {
        n = strlen(input_buffer);
        for (i = 0; i < n; i++) {
            if (isalpha(input_buffer[i])) {
                if (isupper(input_buffer[i])) {
                    input_buffer[i] = 'A' + (input_buffer[i] - 'A' + key) % 26;
                } else {
                    input_buffer[i] = 'a' + (input_buffer[i] - 'a' + key) % 26;
                }
            }
        }
        fprintf(output_file, "%s", input_buffer);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}