//Falcon-180B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

#define ERR_INVALID_ARGUMENT 1
#define ERR_FILE_NOT_FOUND 2
#define ERR_FILE_READ_ERROR 3
#define ERR_MEMORY_ALLOCATION_ERROR 4
#define ERR_INVALID_CHARACTER 5
#define ERR_INVALID_FILE_FORMAT 6

void print_error_message(int error_code) {
    switch (error_code) {
        case ERR_INVALID_ARGUMENT:
            printf("Error: Invalid argument.\n");
            break;
        case ERR_FILE_NOT_FOUND:
            printf("Error: File not found.\n");
            break;
        case ERR_FILE_READ_ERROR:
            printf("Error: File read error.\n");
            break;
        case ERR_MEMORY_ALLOCATION_ERROR:
            printf("Error: Memory allocation error.\n");
            break;
        case ERR_INVALID_CHARACTER:
            printf("Error: Invalid character.\n");
            break;
        case ERR_INVALID_FILE_FORMAT:
            printf("Error: Invalid file format.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_error_message(ERR_INVALID_ARGUMENT);
        return ERR_INVALID_ARGUMENT;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        print_error_message(ERR_FILE_NOT_FOUND);
        return ERR_FILE_NOT_FOUND;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int length = strlen(line);
        if (line[length - 1]!= '\n') {
            print_error_message(ERR_INVALID_FILE_FORMAT);
            return ERR_INVALID_FILE_FORMAT;
        }
        line[length - 1] = '\0';
        for (int i = 0; i < length; i++) {
            if (!isprint(line[i])) {
                print_error_message(ERR_INVALID_CHARACTER);
                return ERR_INVALID_CHARACTER;
            }
        }
    }

    fclose(file);
    return 0;
}