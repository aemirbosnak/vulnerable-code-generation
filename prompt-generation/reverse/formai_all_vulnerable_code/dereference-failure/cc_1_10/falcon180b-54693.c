//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char buffer[1024];
    int position = 0;

    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] + position;
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = buffer[i] + position;
            } else if (buffer[i] >= '0' && buffer[i] <= '9') {
                buffer[i] = buffer[i] + position;
            } else {
                buffer[i] = buffer[i];
            }
        }

        fputs(buffer, output_file);
    }
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    char key[100];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");
    return 0;
}