//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Define virus signatures
#define VIRUS_1 "SurrealistVirus"
#define VIRUS_2 "DaliVirus"
#define VIRUS_3 "MagritteVirus"

void surrealistScan(char* fileName) {
    FILE* fp;
    char ch;
    int i = 0;
    int virusFound = 0;

    // Open the file for reading
    fp = fopen(fileName, "r");

    // Check if the file exists
    if (fp == NULL) {
        printf("File %s does not exist.\n", fileName);
        exit(1);
    }

    // Read the file character by character
    while ((ch = fgetc(fp))!= EOF) {
        // Check for virus signatures
        if (strcmp(&ch, VIRUS_1) == 0 || strcmp(&ch, VIRUS_2) == 0 || strcmp(&ch, VIRUS_3) == 0) {
            virusFound = 1;
            break;
        }

        // Count the number of characters read
        i++;
    }

    // Close the file
    fclose(fp);

    // Print the results
    if (virusFound) {
        printf("Virus found in file %s.\n", fileName);
    } else {
        printf("File %s is clean.\n", fileName);
    }

    // Exit the program
    exit(0);
}

int main(int argc, char* argv[]) {
    int i;

    // Check if the correct number of arguments are provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Loop through all the files provided as arguments
    for (i = 1; i < argc; i++) {
        // Call the surrealistScan function for each file
        surrealistScan(argv[i]);
    }

    // Exit the program
    return 0;
}