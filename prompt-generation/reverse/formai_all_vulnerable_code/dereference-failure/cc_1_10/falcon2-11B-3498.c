//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to recover data from corrupted file
void recoverData(char* filename) {
    // Check if file exists
    if (access(filename, F_OK)!= 0) {
        printf("File does not exist.\n");
        return;
    }

    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }

    // Read the contents of the file
    char buffer[10000];
    int numBytes = fread(buffer, sizeof(char), 10000, file);
    if (numBytes <= 0) {
        printf("Failed to read file contents.\n");
        return;
    }

    // Close the file
    fclose(file);

    // Display the recovered data
    printf("%s\n", buffer);
}

// Function to detect and repair file corruption
void repairCorruption(char* filename) {
    // Check if file exists
    if (access(filename, F_OK)!= 0) {
        printf("File does not exist.\n");
        return;
    }

    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for reading.\n");
        return;
    }

    // Read the contents of the file
    char buffer[10000];
    int numBytes = fread(buffer, sizeof(char), 10000, file);
    if (numBytes <= 0) {
        printf("Failed to read file contents.\n");
        return;
    }

    // Close the file
    fclose(file);

    // Detect file corruption
    int corruptedBytes = 0;
    for (int i = 0; i < numBytes; i++) {
        if (buffer[i]!= (i % 10) + '0') {
            corruptedBytes++;
        }
    }
    if (corruptedBytes > 0) {
        printf("File corruption detected. Repairing...\n");

        // Repair the file corruption
        char* repairedBuffer = malloc(numBytes);
        for (int i = 0; i < numBytes; i++) {
            if (buffer[i]!= (i % 10) + '0') {
                repairedBuffer[i] = (i % 10) + '0';
            }
        }

        // Open the file for writing
        FILE* file = fopen(filename, "w");
        if (file == NULL) {
            printf("Failed to open file for writing.\n");
            return;
        }

        // Write the repaired data to the file
        fwrite(repairedBuffer, sizeof(char), numBytes, file);

        // Close the file
        fclose(file);

        // Display success message
        printf("File corruption repaired successfully.\n");
    } else {
        printf("File is not corrupted.\n");
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline

    // Recover data from the file
    recoverData(filename);

    // Repair file corruption
    repairCorruption(filename);

    return 0;
}