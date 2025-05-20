//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to synchronize files
void file_sync(char* source_file, char* target_file) {
    // Open source and target files
    FILE* source = fopen(source_file, "r");
    FILE* target = fopen(target_file, "w");

    // Check if files were opened successfully
    if (source == NULL || target == NULL) {
        printf("Error opening file(s).\n");
        exit(1);
    }

    // Read source file line by line
    char line[256];
    while (fgets(line, sizeof(line), source)!= NULL) {
        // Convert line to uppercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = toupper(line[i]);
        }
        // Write line to target file
        fprintf(target, "%s", line);
    }

    // Close files
    fclose(source);
    fclose(target);
}

int main() {
    // Declare variables
    char source_file[256], target_file[256];

    // Get source and target file names from user
    printf("Enter source file name: ");
    scanf("%s", source_file);
    printf("Enter target file name: ");
    scanf("%s", target_file);

    // Synchronize files
    file_sync(source_file, target_file);

    // Print success message
    printf("Files synchronized successfully.\n");

    return 0;
}