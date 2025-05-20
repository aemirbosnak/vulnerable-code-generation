//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Romeo and Juliet
// A Romeo and Juliet-inspired File Backup System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The two lovers, represented as file paths
char romeo[256];
char juliet[256];

// Write a sonnet to the console
void writeSonnet() {
    printf("From forth the fatal loins of these two foes\nA pair of star-cross'd lovers take their life;\nTheir hands have exchanged vows, their lips have sworn\nTo eternal love, though fortune frowns on strife.\n\n"
           "But fate, as in Verona's tragic tale,\nDoth force their paths to separate and divide;\nAnd thus, to save their love from bitter wail,\nRomeo and Juliet must their files confide.\n\n"
           "A backup system, they shall now create,\nTo guard their precious data, safe and sound;\nWith every change and update, they shall mate,\nTheir files entwined, on sacred ground.\n\n"
           "So, let us sing the tale of Romeo and Jules,\nWhose love defies the boundaries of rules.");
}

// Perform the file backup
void backupFiles() {
    // Copy Romeo's file to Juliet's
    FILE *romeoFile = fopen(romeo, "r");
    FILE *julietFile = fopen(juliet, "w");

    if (romeoFile == NULL || julietFile == NULL) {
        perror("Error opening files");
        exit(1);
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), romeoFile) != NULL) {
        fputs(buffer, julietFile);
    }

    // Close the files
    fclose(romeoFile);
    fclose(julietFile);
}

// Ask the user for input
void getInput() {
    printf("Enter the path to Romeo's file: ");
    scanf("%s", romeo);

    printf("Enter the path to Juliet's file: ");
    scanf("%s", juliet);
}

// The main function
int main() {
    // Write the sonnet
    writeSonnet();

    // Get input from the user
    getInput();

    // Perform the file backup
    backupFiles();

    // Confirm the backup
    printf("Backup complete! Romeo and Juliet's files are now entwined.\n");

    return 0;
}