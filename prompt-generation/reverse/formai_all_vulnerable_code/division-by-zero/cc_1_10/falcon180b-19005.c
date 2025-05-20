//Falcon-180B DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_ERRORS 100
#define MAX_ERROR_MSG_LEN 256

typedef struct {
    char msg[MAX_ERROR_MSG_LEN];
    int line_num;
    int col_num;
} error_t;

error_t errors[MAX_ERRORS];
int num_errors = 0;

void add_error(char *msg, int line_num, int col_num) {
    if (num_errors >= MAX_ERRORS) {
        printf("Too many errors.\n");
        exit(1);
    }
    strncpy(errors[num_errors].msg, msg, MAX_ERROR_MSG_LEN);
    errors[num_errors].line_num = line_num;
    errors[num_errors].col_num = col_num;
    num_errors++;
}

void print_errors() {
    printf("Found %d errors:\n", num_errors);
    for (int i = 0; i < num_errors; i++) {
        printf("%d:%d: %s\n", errors[i].line_num, errors[i].col_num, errors[i].msg);
    }
}

int main() {
    int x = 42;
    int y = 0;
    int z;

    z = x / y;

    if (num_errors > 0) {
        print_errors();
        return 1;
    }

    return 0;
}