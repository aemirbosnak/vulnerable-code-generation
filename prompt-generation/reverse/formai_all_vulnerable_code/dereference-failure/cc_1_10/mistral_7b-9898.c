//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to sanitize user input using filters
char* sanitize_input(char* input) {
    char* output = malloc(strlen(input) + 1);
    int i = 0;

    // Filter out funny characters
    while (input[i]) {
        if (input[i] == ':' || input[i] == ';' || input[i] == '\\' || input[i] == '/') {
            output[i] = '_';
        } else {
            output[i] = input[i];
        }
        i++;
    }

    output[i] = '\0';
    return output;
}

int main() {
    char user_input[100];
    char sanitized_input[100];

    printf("Hello there, kind traveler! Welcome to the Sanitarium!\n");
    printf("Please enter your input here: ");
    fgets(user_input, sizeof(user_input), stdin);

    // Remove newline character from user input
    user_input[strcspn(user_input, "\n")] = '\0';

    // Sanitize user input using our magical sanitize function
    strcpy(sanitized_input, sanitize_input(user_input));

    printf("You entered: %s\n", user_input);
    printf("But we don't want those naughty characters! So we sanitized it to: %s\n", sanitized_input);

    // Save sanitized input to a file named "sanitized_input.txt"
    int fd = open("sanitized_input.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(fd, sanitized_input, strlen(sanitized_input) + 1);
    close(fd);

    printf("Your sanitized input has been safely stored in the Sanitarium's vault!\n");

    return 0;
}