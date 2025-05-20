//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
// Romeo and Juliet inspired C Antivirus scanner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if an input string contains a virus
bool contains_virus(char *str) {
    // List of virus signatures to check against
    char *virus_signatures[] = {"rm-rf", "trojan", "worm", "keylogger", "rootkit"};
    int num_signatures = sizeof(virus_signatures) / sizeof(char*);
    // Check if str contains any of the virus signatures
    for (int i = 0; i < num_signatures; i++) {
        if (strstr(str, virus_signatures[i])) {
            return true;
        }
    }
    // If none of the signatures match, return false
    return false;
}

int main() {
    // Declare variables
    char filename[50];
    char line[256];
    FILE *file_in, *file_out;
    bool virus_found = false;
    // Prompt user for input file name
    printf("O, virus scanner, what file shall we scan?\n");
    fgets(filename, 50, stdin);
    // Remove newline character from end of filename
    filename[strcspn(filename, "\n")] = 0;
    // Open input file
    file_in = fopen(filename, "r");
    if (file_in == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    // Open output file
    file_out = fopen("scan_results.txt", "w");
    if (file_out == NULL) {
        printf("Error: Could not create output file\n");
        exit(1);
    }
    // Read input file line by line and check for viruses
    while (fgets(line, sizeof(line), file_in)) {
        if (contains_virus(line)) {
            virus_found = true;
            fprintf(file_out, "Warning! A virus was detected in this line: %s\n", line);
        }
    }
    // Close input and output files
    fclose(file_in);
    fclose(file_out);
    // Print results
    if (virus_found) {
        printf("Alas, a virus has been found and recorded in 'scan_results.txt'.\n");
    } else {
        printf("Huzzah! No viruses were found in the file.\n");
    }
    // Exit program
    return 0;
}