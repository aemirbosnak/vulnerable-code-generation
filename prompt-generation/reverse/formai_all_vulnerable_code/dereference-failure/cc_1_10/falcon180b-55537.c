//Falcon-180B DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ERRORS 10
#define MAX_ERROR_MSG_LEN 100

typedef struct {
    char msg[MAX_ERROR_MSG_LEN];
    time_t timestamp;
} Error;

Error errors[MAX_ERRORS];
int num_errors = 0;

void log_error(const char* msg) {
    if (num_errors >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors, cannot log more.\n");
        return;
    }
    strncpy(errors[num_errors].msg, msg, MAX_ERROR_MSG_LEN);
    errors[num_errors].timestamp = time(NULL);
    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors to print.\n");
        return;
    }
    printf("Last %d errors:\n", num_errors);
    for (int i = 0; i < num_errors; i++) {
        printf("%s (%ld)\n", errors[i].msg, errors[i].timestamp);
    }
}

int main() {
    const char* input = "This is a test. 12345";
    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            int num = atoi(token);
            if (num % 2 == 0) {
                printf("Even number: %s\n", token);
            } else {
                printf("Odd number: %s\n", token);
            }
        } else {
            printf("Non-numeric token: %s\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}