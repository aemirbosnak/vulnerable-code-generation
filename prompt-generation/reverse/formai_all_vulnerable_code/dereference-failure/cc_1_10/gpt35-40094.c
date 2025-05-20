//FormAI DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

void process_text(char *text) {
    printf("Processing text asynchronously\n");
    // Simulating asynchronous text processing
    for (int i = 0; i < 5; i++) {
        printf("Processing text part %d\n", i+1);
        // Simulating some processing time
        sleep(1);
    }
    printf("Text processing complete!\n");
}

void read_text_file(char *filename) {
    printf("Reading text file...\n");
    // Opening file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    // Getting file size
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocating memory for text
    char *text = (char *) malloc(sizeof(char) * (size + 1));
    if (text == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    // Reading text from file
    fread(text, sizeof(char), size, fp);
    fclose(fp);

    // Add null character at the end of text
    text[size] = '\0';

    // Process text asynchronously
    process_text(text);

    // Free memory
    free(text);
}

int main() {
    char filename[] = "sample.txt";

    read_text_file(filename);

    printf("Exiting program...\n");
    return 0;
}