//Falcon-180B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MSGS 10
#define ERR_MSG_LEN 80

typedef struct {
    char *msg;
    int code;
} ErrorMsg;

int num_errors = 0;
ErrorMsg errors[MAX_ERROR_MSGS];

void add_error(char *msg, int code) {
    if (num_errors >= MAX_ERROR_MSGS) {
        printf("Error: Too many errors\n");
        exit(1);
    }

    errors[num_errors].msg = strdup(msg);
    errors[num_errors].code = code;

    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors\n");
        return;
    }

    printf("Errors:\n");
    for (int i = 0; i < num_errors; i++) {
        printf("%d: %s\n", errors[i].code, errors[i].msg);
    }
}

int main() {
    add_error("Invalid input", 1);
    add_error("File not found", 2);

    if (num_errors == 0) {
        printf("Success\n");
        return 0;
    } else {
        print_errors();
        return 1;
    }
}