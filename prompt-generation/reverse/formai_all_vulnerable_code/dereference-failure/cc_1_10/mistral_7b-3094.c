//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void readFile(char *filename) {
    FILE *fp;
    char line[MAX_SIZE];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s.\n", filename);
        exit(1);
    }

    printf("Contents of %s:\n", filename);

    while (fgets(line, MAX_SIZE, fp) != NULL) {
        printf("%s", line);
        count++;
    }

    printf("\nNumber of lines read: %d\n", count);

    fclose(fp);
}

void writeFile(char *filename, char *data) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        exit(1);
    }

    fprintf(fp, "%s", data);

    printf("Data written to file %s successfully.\n", filename);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    char filename[MAX_SIZE];
    char data[MAX_SIZE] = "I am grateful for the opportunity to write this code.\n";

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    readFile(filename);

    printf("Writing data to file...\n");
    writeFile(filename, data);

    readFile(filename);

    printf("File handling completed.\n");

    return 0;
}