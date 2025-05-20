//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    unsigned int size;
    unsigned char *data;
} file_t;

int main() {
    // Define the virus signatures
    const char *virus_signatures[] = {
        // Signature 1: EICAR test virus
        "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*",
        // Signature 2: Melissa virus
        "This document was created with Microsoft Word 97 Macintosh Edition.",
        // Signature 3: ILOVEYOU virus
        "kindly check the attached LOVELETTER coming from me.",
    };

    // Prompt the user for the file to scan
    char filename[256];
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return 1;
    }

    // Get the file size
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Read the file into memory
    file_t file_data;
    file_data.name = filename;
    file_data.size = size;
    file_data.data = malloc(size);
    fread(file_data.data, 1, size, file);

    // Close the file
    fclose(file);

    // Scan the file for viruses
    int found_virus = 0;
    for (int i = 0; i < 3; i++) {
        if (strstr(file_data.data, virus_signatures[i]) != NULL) {
            found_virus = 1;
            break;
        }
    }

    // Print the results
    if (found_virus) {
        printf("File %s is infected with a virus.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    // Free the memory
    free(file_data.data);

    return 0;
}