//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to print a belly laugh
void belly_laugh() {
    printf("__________\n");
    printf("| Q (O_o)\n");
    printf("|       |\n");
    printf("|      (_)\n");
    printf("|  ______\n");
    printf("|/\n");
}

// Function to check if a character is alphabetic
int is_alphabetic(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Function to print the reverse of a string followed by a belly laugh
void print_reverse_laugh(char *str) {
    reverse_string(str);
    printf("Reversed: ");
    puts(str);
    belly_laugh();
}

// Function to read a file and print its contents reversed followed by a belly laugh
void process_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        for (int i = bytes_read - 1; i >= 0; i--) {
            putchar(buffer[i]);
        }
    }

    close(fd);

    printf("\n");
    belly_laugh();
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    if (!is_alphabetic(filename[0])) {
        printf("Error: File name must start with a letter.\n");
        return 1;
    }

    process_file(filename);

    return 0;
}