//Falcon-180B DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_ERRORS 10
#define ERROR_BUFFER_SIZE 100

// Struct to hold error information
typedef struct {
    char *error_message;
    int error_code;
} Error;

void add_error(Error *error_list, int error_code, char *error_message) {
    if (error_list->error_code == 0) {
        error_list->error_code = error_code;
        strcpy(error_list->error_message, error_message);
    }
}

void print_errors(Error *error_list) {
    printf("Errors:\n");
    for (int i = 0; i < MAX_ERRORS && error_list[i].error_code!= 0; i++) {
        printf("%d: %s\n", error_list[i].error_code, error_list[i].error_message);
    }
}

int main() {
    int result;
    char *input_string = "This is a test string";
    char *token;

    // Initialize error list
    Error error_list[MAX_ERRORS] = {{0, ""}};

    // Example 1: strtok_r usage
    token = strtok_r(input_string, " ", &result);
    if (token == NULL) {
        add_error(error_list, errno, strerror(errno));
    } else {
        printf("Token 1: %s\n", token);
    }

    // Example 2: fopen usage
    FILE *file = fopen("nonexistent_file.txt", "r");
    if (file == NULL) {
        add_error(error_list, errno, strerror(errno));
    } else {
        fclose(file);
        printf("File opened successfully\n");
    }

    // Example 3: malloc usage
    char *buffer = (char *) malloc(10);
    if (buffer == NULL) {
        add_error(error_list, errno, strerror(errno));
    } else {
        strcpy(buffer, "Test string");
        printf("Malloc successful: %s\n", buffer);
        free(buffer);
    }

    // Print errors
    print_errors(error_list);

    return 0;
}