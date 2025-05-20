//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LENGTH 100

// Custom error structure
typedef struct {
    int error_code;
    char message[MAX_LENGTH];
} CustomError;

// Function to print custom error message and exit
void custom_error(int error_code, char *function_name) {
    CustomError error;

    error.error_code = error_code;
    strcpy(error.message, function_name);
    strcat(error.message, ": ");

    switch (error_code) {
        case 1:
            strcat(error.message, "Invalid argument.");
            break;
        case 2:
            strcat(error.message, "Memory allocation failed.");
            break;
        case 3:
            strcat(error.message, "File not found.");
            break;
        case 4:
            strcat(error.message, "Permission denied.");
            break;
        case 5:
            strcat(error.message, "Internal error.");
            break;
        default:
            strcpy(error.message, "Unknown error.");
    }

    fprintf(stderr, "%s\n", error.message);
    exit(error_code);
}

// Function to check if a given string is a valid file path
int is_valid_path(char *path) {
    struct stat info;

    if (stat(path, &info) < 0) {
        custom_error(3, __func__);
    }

    if (!S_ISREG(info.st_mode)) {
        custom_error(3, __func__);
    }

    return 1;
}

// Function to read a file and return its content as a string
char *read_file(char *path) {
    FILE *file;
    char *content = NULL;
    long file_size;

    if (!is_valid_path(path)) {
        return NULL;
    }

    file = fopen(path, "r");

    if (file == NULL) {
        custom_error(3, __func__);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    content = (char *)malloc((size_t)file_size + 1);

    if (content == NULL) {
        custom_error(2, __func__);
    }

    fread(content, file_size, 1, file);
    fclose(file);

    content[file_size] = '\0';

    return content;
}

int main(int argc, char **argv) {
    char *file_content;

    if (argc != 2) {
        custom_error(1, __func__);
    }

    file_content = read_file(argv[1]);

    if (file_content == NULL) {
        custom_error(5, __func__);
    }

    printf("File content:\n%s\n", file_content);

    free(file_content);

    return 0;
}