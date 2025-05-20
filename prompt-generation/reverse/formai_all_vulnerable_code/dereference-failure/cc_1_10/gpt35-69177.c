//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_SIZE 1000

void scan_file(char *filename);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Error: No file provided\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        scan_file(argv[i]);
    }

    printf("Scan Complete. No viruses found.\n");

    return 0;
}

void scan_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char virus[MAX_VIRUS_SIZE];
    char line[MAX_VIRUS_SIZE];

    // Open virus database file
    FILE *database = fopen("virus_database.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open virus database file\n");
        return;
    }

    // Loop through virus database
    while (fgets(virus, MAX_VIRUS_SIZE, database) != NULL) {
        virus[strcspn(virus, "\n")] = '\0'; // remove newline character

        // Loop through file being scanned
        while (fgets(line, MAX_VIRUS_SIZE, file) != NULL) {
            if (strstr(line, virus) != NULL) {
                printf("Virus detected in file %s\n", filename);
                printf("Matching string: %s\n", line);
                exit(0);
            }
        }

        fseek(file, 0, SEEK_SET); // reset file pointer to beginning of file
    }

    fclose(database);
    fclose(file);
}