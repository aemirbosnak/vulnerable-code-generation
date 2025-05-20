//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan the given file and check for virus strings
void scanFile(char* filePath) {
    // Open the file in read mode
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    // Read the contents of file into buffer
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = malloc(fsize + 1);
    fread(buffer, fsize, 1, fp);
    fclose(fp);
    buffer[fsize] = 0;

    // List of virus strings to search for
    char* viruses[] = {"malware", "trojan", "worm", "virus", "ransomware"};

    // Check if virus string is present in file
    int i;
    for (i = 0; i < 5; i++) {
        if (strstr(buffer, viruses[i])) {
            printf("Virus Found: %s\n", viruses[i]);
            break;
        }
    }

    if (i == 5) {
        printf("No viruses found.\n");
    }

    free(buffer);
}

int main() {
    // Get the file path from user
    char filePath[100];
    printf("Enter file path: ");
    scanf("%s", filePath);

    // Scan the file for viruses
    scanFile(filePath);

    return 0;
}