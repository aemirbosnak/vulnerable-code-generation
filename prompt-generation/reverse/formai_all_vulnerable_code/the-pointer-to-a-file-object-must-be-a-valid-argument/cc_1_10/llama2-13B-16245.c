//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Function to read a file and print its contents
void printFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];
    while (fgets(buffer, 1024, file) != NULL) {
        printf("%s\n", buffer);
    }
    fclose(file);
}

// Function to write a file and print its contents
void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    char buffer[1024];
    gets(buffer); // Read a line from the user
    fputs(buffer, file);
    fclose(file);
}

// Function to append to a file and print its contents
void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    char buffer[1024];
    gets(buffer); // Read a line from the user
    fputs(buffer, file);
    fclose(file);
}

int main() {
    // Open a file and print its contents
    printFile("example.txt");

    // Write a new file and print its contents
    writeFile("new_file.txt");

    // Append to an existing file and print its contents
    appendFile("existing_file.txt");

    // Create a new file and print its contents
    FILE *file = fopen("new_file.txt", "w");
    char buffer[1024];
    for (int i = 0; i < 10; i++) {
        sprintf(buffer, "Line %d\n", i);
        fputs(buffer, file);
    }
    fclose(file);

    // Read a file and print its contents, but with a twist!
    printFile("twist.txt");

    // Write a file with a random line length
    for (int i = 0; i < 10; i++) {
        char buffer[1024];
        int lineLength = rand() % 10 + 1;
        sprintf(buffer, "Line %d (%d characters)\n", i, lineLength);
        writeFile("random_lines.txt");
    }

    // Append to a file with a random line length
    for (int i = 0; i < 10; i++) {
        char buffer[1024];
        int lineLength = rand() % 10 + 1;
        sprintf(buffer, "Line %d (%d characters)\n", i, lineLength);
        appendFile("random_lines.txt");
    }

    return 0;
}