//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char *input, char *output) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0; i < strlen(input); i++) {
        output[i] = 'A';
        for (j = 0; j < strlen(key); j++) {
            k = (int)key[j] - 97;
            output[i] = output[i] + k;
        }
        output[i] = output[i] % 26 + 97;
    }
    output[strlen(input)] = '\0';
}

void decrypt(char *input, char *output) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0; i < strlen(input); i++) {
        output[i] = 'A';
        for (j = 0; j < strlen(key); j++) {
            k = (int)key[j] - 97;
            output[i] = output[i] - k;
        }
        output[i] = output[i] % 26 + 97;
    }
    output[strlen(input)] = '\0';
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char input_buffer[1000], output_buffer[1000];
    int i;

    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        encrypt(input_buffer, output_buffer);
        fputs(output_buffer, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");

    return 0;
}