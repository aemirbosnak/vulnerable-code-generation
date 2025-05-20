//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *name;
    char *contents;
    size_t size;
    FILE *file;
} File;

int main() {
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char output_file_name[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *token;
    File input_file;
    File output_file;

    printf("Enter the name of the input file: ");
    fgets(input_file_name, MAX_FILE_NAME_LENGTH, stdin);
    input_file_name[strcspn(input_file_name, "\n")] = '\0';

    printf("Enter the name of the output file: ");
    fgets(output_file_name, MAX_FILE_NAME_LENGTH, stdin);
    output_file_name[strcspn(output_file_name, "\n")] = '\0';

    input_file.name = input_file_name;
    input_file.size = 0;
    input_file.file = fopen(input_file_name, "r");

    if (input_file.file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    output_file.name = output_file_name;
    output_file.size = 0;
    output_file.file = fopen(output_file_name, "w");

    if (output_file.file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file.file)!= NULL) {
        input_file.size += strlen(line);
        token = strtok(line, " ");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                fprintf(output_file.file, "%s ", token);
            }
            token = strtok(NULL, " ");
        }
        fprintf(output_file.file, "\n");
    }

    fclose(input_file.file);
    fclose(output_file.file);

    printf("File processed successfully.\n");

    return 0;
}