//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "ROMEO"
#define VIRUS_SIZE 5

// Function to scan a file for viruses
int scan_file(FILE *file, char *filename) {
    char buffer[1024];
    int found_virus = 0;

    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        int i;
        for (i = 0; i < strlen(buffer) - VIRUS_SIZE + 1; i++) {
            if (strncmp(buffer + i, VIRUS_SIGNATURE, VIRUS_SIZE) == 0) {
                printf("Virus found in %s at offset %d\n", filename, i);
                found_virus = 1;
                break;
            }
        }
    }

    return found_virus;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    char filename[1024];
    strcpy(filename, argv[1]);

    int found_virus = scan_file(file, filename);

    fclose(file);

    if (!found_virus) {
        printf("%s is clean\n", filename);
    }

    return 0;
}