//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 256
#define MAX_MESSAGE_LENGTH 1024

// Define the file name and message
#define LOVE_LETTER "love-letter.txt"
#define MESSAGE "My dearest, every moment with you is a dream come true. You are the sun to my sky and the stars to my night. Forever yours, [Your Name]"

int main() {
    // Open the file in write mode
    FILE *file = fopen(LOVE_LETTER, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the message to the file
    fprintf(file, "%s", MESSAGE);
    if (ferror(file)) {
        perror("Error writing to file");
        return 1;
    }

    // Close the file
    fclose(file);

    // Open the file again in read mode
    file = fopen(LOVE_LETTER, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the message from the file
    char buffer[MAX_MESSAGE_LENGTH];
    fread(buffer, 1, MAX_MESSAGE_LENGTH, file);
    if (ferror(file)) {
        perror("Error reading from file");
        return 1;
    }

    // Print the message
    printf("%s", buffer);

    // Close the file
    fclose(file);

    return 0;
}