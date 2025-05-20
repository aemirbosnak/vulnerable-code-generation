//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_INPUT_SIZE 100

void show_error(const char *message, const int code) {
    fprintf(stderr, "[ERROR]: %s. (Error Code: %d) - %s\n", message, code, strerror(code));
}

void handle_potato() {
    printf("Oh no! A potato error occurred! 🥔 Please reboot the potato...\n");
}

void handle_sasquatch() {
    printf("Sasquatch sighted! It might have stolen your data! 🦶 Run!\n");
}

int risky_operation(int simulated_error) {
    if (simulated_error == 1) {
        errno = ENOENT; // No such file or directory error
        return -1;
    }
    if (simulated_error == 2) {
        errno = EIO; // Input/output error
        return -1;
    }
    if (simulated_error == 3) {
        handle_potato();
        return -1;
    }
    if (simulated_error == 4) {
        handle_sasquatch();
        return -1;
    }
    return 0; // Success!
}

int main() {
    char user_input[MAX_INPUT_SIZE];
    int simulated_error;

    printf("Welcome to the Great C Error Adventure!\n");
    printf("Type a number between 1 and 4 to simulate different errors or 0 to exit: \n");

    while (1) {
        printf("Your choice: ");
        fgets(user_input, MAX_INPUT_SIZE, stdin);
        simulated_error = atoi(user_input);

        if (simulated_error == 0) {
            printf("Exiting with the grace of a thousand unicorns! 🦄\n");
            break;
        }

        // Simulate an operation
        if (risky_operation(simulated_error) < 0) {
            switch (errno) {
                case ENOENT:
                    show_error("File not found", errno);
                    break;
                case EIO:
                    show_error("I/O Error, check your sandwiches", errno);
                    break;
                default:
                    show_error("Unknown error, we are all confused", errno);
                    break;
            }
        } else {
            printf("Operation successful! 🎉 You are a champion of the universe! 🌌\n");
        }
    }

    return 0;
}