//Falcon-180B DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MESSAGES 100
#define MAX_ERROR_MESSAGE_LENGTH 100

typedef struct {
    char message[MAX_ERROR_MESSAGE_LENGTH];
    int line_number;
    int column_number;
} error_message_t;

int num_error_messages = 0;
error_message_t error_messages[MAX_ERROR_MESSAGES];

void add_error_message(const char* message, int line_number, int column_number) {
    if (num_error_messages >= MAX_ERROR_MESSAGES) {
        printf("Error: Too many errors!\n");
        exit(1);
    }

    strncpy(error_messages[num_error_messages].message, message, MAX_ERROR_MESSAGE_LENGTH - 1);
    error_messages[num_error_messages].message[MAX_ERROR_MESSAGE_LENGTH - 1] = '\0';
    error_messages[num_error_messages].line_number = line_number;
    error_messages[num_error_messages].column_number = column_number;

    num_error_messages++;
}

void print_error_messages() {
    if (num_error_messages == 0) {
        printf("No errors found.\n");
    } else {
        printf("Found %d errors:\n", num_error_messages);
        for (int i = 0; i < num_error_messages; i++) {
            printf("Line %d, column %d: %s\n", error_messages[i].line_number, error_messages[i].column_number, error_messages[i].message);
        }
    }
}

int main() {
    int x = 5;
    int y = 0;
    int z = x / y;

    if (num_error_messages == 0) {
        printf("Program completed without errors.\n");
    } else {
        printf("Program completed with %d errors.\n", num_error_messages);
    }

    return 0;
}