//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_BUFFER 100

// Function to clear the buffer
void clear_buffer(char *buffer) {
    memset(buffer, '\0', MAX_BUFFER);
}

// Function to print the buffer
void print_buffer(char *buffer) {
    printf("%s\n", buffer);
}

// Function to add a character to the buffer
void add_character(char *buffer, char c) {
    if (strlen(buffer) >= MAX_BUFFER - 1) {
        printf("Error: Buffer overflow.\n");
        return;
    }

    strcat(buffer, &c);
}

// Function to delete the last character from the buffer
void delete_character(char *buffer) {
    if (strlen(buffer) <= 0) {
        printf("Error: Buffer underflow.\n");
        return;
    }

    strcpy(buffer + strlen(buffer) - 1, "");
}

// Function to perform the calculation
void calculate(char *buffer) {
    char *endptr;
    double result = strtod(buffer, &endptr);

    if (endptr == buffer) {
        printf("Error: Invalid input.\n");
        return;
    }

    printf("Result: %f\n", result);
}

// Function to handle user input
void handle_input(char *buffer) {
    char c;

    while ((c = getchar())!= '\n') {
        if (isdigit(c) || c == '.' || c == '-') {
            add_character(buffer, c);
        } else if (c == 'C') {
            clear_buffer(buffer);
        } else if (c == 'D') {
            delete_character(buffer);
        } else if (c == '=') {
            calculate(buffer);
        } else {
            printf("Error: Invalid input.\n");
        }
    }

    add_character(buffer, '\n');
}

int main() {
    char buffer[MAX_BUFFER];

    clear_buffer(buffer);

    printf("Cyberpunk Scientific Calculator\n");

    while (1) {
        handle_input(buffer);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }

    return 0;
}