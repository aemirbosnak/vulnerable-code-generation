//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 1024
#define EXCITING_MESSAGE "Welcome, adventurer! Let's dive into the magical world of file exploration!\n"
#define FILE_NOT_FOUND_MESSAGE "Oops! It seems the file you're looking for does not exist. Please try again.\n"

int main(int argc, char *argv[]) {
    int fd;
    char file_path[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Greet the user with an exciting message
    printf("%s", EXCITING_MESSAGE);

    // Check if a command-line argument is provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Set the file path
    strcpy(file_path, argv[1]);

    // Open the file for reading
    fd = open(file_path, O_RDONLY);

    // Check if the file exists and is readable
    if (fd < 0) {
        printf("%s", FILE_NOT_FOUND_MESSAGE);
        return 1;
    }

    // Loop to read lines from the file and print them out with some formatting
    while (fgets(line, sizeof(line), fd) != NULL) {
        printf("%d: %s", ++line_number, line);
    }

    // Close the file
    close(fd);

    // Goodbye message at the end
    printf("\nThank you for using our file exploration tool! Have a wonderful day!\n");

    return 0;
}