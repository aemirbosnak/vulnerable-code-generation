//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan a file for viruses
int scan_file(char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* buffer = malloc(fsize + 1);
    fread(buffer, fsize, 1, fp);
    buffer[fsize] = '\0';
    fclose(fp);

    // Scan the buffer for viruses
    int found_virus = 0;
    char* virus_signatures[] = {
        "EICAR_TEST_STRING",
        "W32.Stuxnet.A",
        "W32.Conficker.C",
        "W32.Sality.AE",
        "W32.Zeus.A"
    };
    int num_signatures = sizeof(virus_signatures) / sizeof(char*);
    for (int i = 0; i < num_signatures; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            found_virus = 1;
            break;
        }
    }

    // Free the buffer
    free(buffer);

    // Return the result
    return found_virus;
}

// Main function
int main(int argc, char* argv[]) {
    // Check if a filename was provided
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Scan the file
    int found_virus = scan_file(argv[1]);

    // Print the result
    if (found_virus) {
        printf("Virus found in file %s\n", argv[1]);
    } else {
        printf("No virus found in file %s\n", argv[1]);
    }

    return 0;
}