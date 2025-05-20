//Falcon-180B DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MSG_LEN 100

struct error {
    char msg[ERROR_MSG_LEN];
    int line;
    char file[ERROR_MSG_LEN];
};

static struct error errors[MAX_ERRORS];
static int num_errors = 0;

void add_error(const char* msg, int line, const char* file) {
    if (num_errors == MAX_ERRORS) {
        fprintf(stderr, "Error: too many errors\n");
        exit(1);
    }

    strncpy(errors[num_errors].msg, msg, ERROR_MSG_LEN - 1);
    errors[num_errors].msg[ERROR_MSG_LEN - 1] = '\0';

    errors[num_errors].line = line;
    strncpy(errors[num_errors].file, file, ERROR_MSG_LEN - 1);
    errors[num_errors].file[ERROR_MSG_LEN - 1] = '\0';

    num_errors++;
}

void print_errors() {
    fprintf(stderr, "Errors:\n");
    for (int i = 0; i < num_errors; i++) {
        fprintf(stderr, "%s:%d: %s\n", errors[i].file, errors[i].line, errors[i].msg);
    }
}

int main() {
    int x = 10;
    int y = 0;
    int z = x / y;

    add_error("Division by zero", __LINE__, __FILE__);

    printf("%d\n", z);

    print_errors();

    return 0;
}