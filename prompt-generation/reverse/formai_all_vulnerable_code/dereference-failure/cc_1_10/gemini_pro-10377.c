//GEMINI-pro DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to copy the contents of one file to another
void copyFile(FILE *src, FILE *dest) {
    char ch;
    while((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
}

// Function to reverse the contents of a file
void reverseFile(FILE *fp) {
    long fileLen;
    char *buffer;

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    fileLen = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the buffer
    buffer = (char *)malloc(fileLen + 1);

    // Read the file into the buffer
    fread(buffer, fileLen, 1, fp);

    // Reverse the buffer
    for (long i = 0, j = fileLen - 1; i < j; i++, j--) {
        char tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
    }

    // Write the buffer back to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer, fileLen, 1, fp);

    // Free the buffer
    free(buffer);
}

// Function to create a new file with the given name and contents
FILE *createNewFile(char *filename, char *contents) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error creating file");
        exit(1);
    }
    fprintf(fp, "%s", contents);
    fclose(fp);

    return fp;
}

// Function to open a file for reading
FILE *openFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    return fp;
}

// Function to count the number of lines in a file
int countLines(FILE *fp) {
    int lines = 0;
    char ch;

    while((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    return lines;
}

// Function to print the contents of a file
void printFile(FILE *fp) {
    char ch;

    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
}

int main() {
    // Open the source and destination files
    FILE *src = openFile("source.txt");
    FILE *dest = createNewFile("destination.txt", "");

    // Copy the contents of the source file to the destination file
    copyFile(src, dest);

    // Close the source and destination files
    fclose(src);
    fclose(dest);

    // Open the destination file for reading
    dest = openFile("destination.txt");

    // Reverse the contents of the destination file
    reverseFile(dest);

    // Print the contents of the destination file
    printFile(dest);

    // Close the destination file
    fclose(dest);

    return 0;
}