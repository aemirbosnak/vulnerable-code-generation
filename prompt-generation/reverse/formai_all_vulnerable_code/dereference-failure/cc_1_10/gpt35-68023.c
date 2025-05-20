//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: modular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
bool isVirus(char*);
bool scanFile(char*);
void printResults(bool, char*);

int main() {
    char fileName[100];
    printf("Enter the file name: ");
    scanf("%s", fileName);

    bool isInfected = scanFile(fileName);
    printResults(isInfected, fileName);

    return 0;
}

// Function to check if a file contains virus
bool scanFile(char* fileName) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    bool isInfected = false;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file!\n");
        exit(EXIT_FAILURE);
    }

    // Read file line-by-line until end of file
    while ((read = getline(&line, &len, fp)) != -1) {
        if (isVirus(line)) {
            isInfected = true;
            break;
        }
    }

    fclose(fp);
    if (line) free(line);

    return isInfected;
}

// Function to check if a string contains virus
bool isVirus(char* str) {
    char arr[5][10] = {"virus", "malware", "trojan", "worm", "spyware"};

    for (int i = 0; i < 5; i++) {
        if (strstr(str, arr[i]) != NULL)
            return true;
    }

    return false;
}

// Function to print the results
void printResults(bool isInfected, char* fileName) {
    if (isInfected)
        printf("%s is infected with a virus!\n", fileName);
    else
        printf("%s is clean.\n", fileName);
}