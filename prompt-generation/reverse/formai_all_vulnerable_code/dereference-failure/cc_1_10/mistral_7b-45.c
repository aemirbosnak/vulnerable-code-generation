//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: genius
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <signal.h>

#define BUFFER_SIZE 1024
#define SANITIZED_INPUT_SIZE 128

typedef struct InputData {
    char sanitized_input[SANITIZED_INPUT_SIZE];
    int length;
} InputData;

void handle_sigsegv(int sig) {
    printf("Error: Invalid input detected. Exiting...\n");
    exit(1);
}

void sanitize_input(char *input, InputData *input_data) {
    int i = 0;

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            if (input_data->length < SANITIZED_INPUT_SIZE) {
                input_data->sanitized_input[input_data->length] = tolower(input[i]);
                input_data->length++;
            }
        }
        i++;
    }

    input_data->sanitized_input[input_data->length] = '\0';
}

int main() {
    char input[BUFFER_SIZE];
    InputData input_data;
    int ch;

    signal(SIGSEGV, handle_sigsegv);

    printf("Genius User Input Sanitizer v1.0\n");
    printf("Enter your input: ");

    while (1) {
        fgets(input, BUFFER_SIZE, stdin);

        if (strlen(input) > BUFFER_SIZE - 1) {
            printf("Error: Input too long. Please enter a shorter input.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        sanitize_input(input, &input_data);
        printf("Sanitized Input: %s\n", input_data.sanitized_input);

        while ((ch = getchar()) != EOF) {
            if (ch == '\n') {
                break;
            }

            if (!isalnum(ch) && ch != ' ') {
                signal(SIGSEGV, handle_sigsegv);
                raise(SIGSEGV);
            }
        }

        printf("You have entered a valid input. Continuing...\n");
        break;
    }

    return 0;
}