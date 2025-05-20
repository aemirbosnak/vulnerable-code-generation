//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <utime.h>

#define MAX_SURPRISE 1024

// Global variables
char *surprise_message = NULL;
int surprise_level = 0;

// Function to generate a surprise message
void surprise(const char *message) {
    // Calculate the surprise level based on the message length
    surprise_level = strlen(message) * 2;

    // Allocate memory for the surprise message
    surprise_message = malloc(surprise_level + 1);

    // Copy the message into the surprise message
    strcpy(surprise_message, message);
}

int main() {
    // Initialize the surprise level to 0
    surprise_level = 0;

    // Read input from the user
    char user_input[1024];
    printf("Enter a command: ");
    fgets(user_input, 1024, stdin);

    // Parse the input and execute the appropriate action
    if (strcmp(user_input, "surprise") == 0) {
        // Generate a surprise message
        surprise("You just won a prize!");
    } else if (strcmp(user_input, "more") == 0) {
        // Increase the surprise level
        surprise_level++;
    } else if (strcmp(user_input, "less") == 0) {
        // Decrease the surprise level
        surprise_level--;
    } else {
        // Default action: print the surprise message
        printf("%s\n", surprise_message);
    }

    // Clean up and exit
    free(surprise_message);
    return 0;
}

// Function to print the surprise message with a twist
void print_surprise() {
    // Open the /dev/urandom device
    int fd = open("/dev/urandom", O_RDONLY);

    // Read random bytes from the device
    char random_bytes[1024];
    read(fd, random_bytes, 1024);

    // Print the surprise message with the random bytes inserted
    printf("%s%s%s\n", surprise_message, random_bytes, "!");

    // Close the device
    close(fd);
}