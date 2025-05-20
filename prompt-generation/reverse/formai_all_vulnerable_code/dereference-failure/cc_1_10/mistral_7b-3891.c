//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function to print a funny message when file is opened successfully
void file_opened(char *filename) {
    printf("\n%s, the %s file, has been opened with joy!\n", filename, filename);
}

// Function to print a funny message when file is opened unsuccessfully
void file_not_opened(char *filename) {
    printf("\nOh dear! %s, the %s file, refuses to open! Maybe it's playing hide and seek with us?\n", filename, filename);
}

int main(int argC, char *argV[]) {
    int fileDescriptor;
    char filename[50];
    char readBuffer[100];

    if (argC != 2) {
        printf("\n%s, the program that opens files, needs exactly one argument!\n", argV[0]);
        return 1;
    }

    strcpy(filename, argV[1]);

    // Open the file with a funny message
    file_opened(filename);
    fileDescriptor = open(filename, O_RDONLY);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        file_not_opened(filename);
        return 1;
    }

    // Read the file and print its content with a funny message
    while (read(fileDescriptor, readBuffer, sizeof(readBuffer)) > 0) {
        printf("\n%s, the file muse, whispers to us:\n", filename);
        printf("%s", readBuffer);
    }

    // Close the file with a funny message
    close(fileDescriptor);
    printf("\n%s, the file, has been closed with a sigh of contentment.\n", filename);

    return 0;
}