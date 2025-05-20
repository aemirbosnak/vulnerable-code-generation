//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define KEY "mysecretkey"
#define KEY_LENGTH 12

void encrypt(char *input, char *output) {
    int i, j, k;
    char key[KEY_LENGTH];
    strcpy(key, KEY);
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = ((input[i] - 65) + (key[i % KEY_LENGTH] - 65)) % 26 + 65;
            } else {
                output[i] = ((input[i] - 97) + (key[i % KEY_LENGTH] - 97)) % 26 + 97;
            }
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    FILE *input_file, *output_file;
    char input[MAX_LINE_LENGTH], output[MAX_LINE_LENGTH];
    int i, j, k;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while (fgets(input, MAX_LINE_LENGTH, input_file)!= NULL) {
        encrypt(input, output);
        fputs(output, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encryption successful!\n");
    return 0;
}