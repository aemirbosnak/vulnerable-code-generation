//Falcon-180B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MESSAGES 100
#define MAX_ERROR_MESSAGE_LENGTH 256

typedef struct {
    char *message;
    int line_number;
} ErrorMessage;

static ErrorMessage error_messages[MAX_ERROR_MESSAGES];
static int num_error_messages = 0;

void add_error_message(char *message, int line_number) {
    if (num_error_messages >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error: Too many error messages\n");
        exit(1);
    }

    int message_length = strlen(message);
    if (message_length >= MAX_ERROR_MESSAGE_LENGTH) {
        fprintf(stderr, "Error: Error message is too long\n");
        exit(1);
    }

    error_messages[num_error_messages].message = malloc(message_length + 1);
    strncpy(error_messages[num_error_messages].message, message, message_length);
    error_messages[num_error_messages].message[message_length] = '\0';

    error_messages[num_error_messages].line_number = line_number;
    num_error_messages++;
}

void print_error_messages() {
    for (int i = 0; i < num_error_messages; i++) {
        fprintf(stderr, "Error on line %d: %s\n", error_messages[i].line_number, error_messages[i].message);
    }
}

int main() {
    int x = 10;
    int y = 0;

    int result = x / y;

    if (result == 0) {
        add_error_message("Division by zero", __LINE__);
    }

    return 0;
}