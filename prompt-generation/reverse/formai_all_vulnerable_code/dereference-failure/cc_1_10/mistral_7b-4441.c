//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct error {
    int err_code;
    char err_msg[100];
} error_t;

void print_error(int err_code) {
    error_t err_msg[] = {
        {1, "Invalid argument"},
        {2, "Memory allocation failed"},
        {3, "File not found"},
        {4, "Permission denied"},
        {5, "Unknown error"}
    };

    for (int i = 0; i < 5; i++) {
        if (err_code == err_msg[i].err_code) {
            printf("Error: %s\n", err_msg[i].err_msg);
            break;
        }
    }

    if (err_code != err_msg[4].err_code) {
        sprintf(err_msg[5].err_msg, "Unknown error code %d", err_code);
        printf("Error: %s\n", err_msg[5].err_msg);
    }
}

void func_with_error(int arg) {
    int *ptr = malloc(arg * sizeof(int));

    if (ptr == NULL) {
        print_error(2);
        exit(1);
    }

    // Some error-prone code goes here

    free(ptr);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error(1);
        return 1;
    }

    int arg = atoi(argv[1]);
    func_with_error(arg);

    return 0;
}