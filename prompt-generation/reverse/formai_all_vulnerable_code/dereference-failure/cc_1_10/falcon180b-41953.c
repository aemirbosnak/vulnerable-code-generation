//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
} file_t;

int main() {
    FILE *input_file, *output_file;
    char line[MAX_FILE_NAME_LENGTH + 1];
    char *filename, *data;
    int file_count = 0;
    file_t files[100];

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Input file not found.\n");
        return 1;
    }

    while (fgets(line, MAX_FILE_NAME_LENGTH + 1, input_file)!= NULL) {
        filename = strtok(line, ":");
        data = strtok(NULL, ":");

        strcpy(files[file_count].filename, filename);
        strcpy(files[file_count].data, data);

        file_count++;
    }

    fclose(input_file);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Output file creation failed.\n");
        return 1;
    }

    for (int i = 0; i < file_count; i++) {
        fprintf(output_file, "%s:%s\n", files[i].filename, files[i].data);
    }

    fclose(output_file);

    printf("Data recovery successful.\n");

    return 0;
}