//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encrypt(char* input, char* output, int key_len) {
    int i = 0, j = 0;
    while (input[i]) {
        output[j] = input[i] ^ KEY[j % key_len];
        i++;
        j++;
    }
    output[i] = '\0';
}

void decrypt(char* input, char* output, int key_len) {
    int i = 0, j = 0;
    while (input[i]) {
        output[j] = input[i] ^ KEY[j % key_len];
        i++;
        j++;
    }
    output[i] = '\0';
}

int main() {
    char input_file[100], output_file[100];
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    char *buffer = (char*) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    fread(buffer, file_size, 1, input);
    fclose(input);

    encrypt(buffer, buffer, strlen(KEY));

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fwrite(buffer, file_size, 1, output);
    fclose(output);

    printf("File encrypted successfully.\n");
    return 0;
}