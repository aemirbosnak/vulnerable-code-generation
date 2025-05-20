//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIRUS_LEN 100

// Function to check if a file is infected with a virus
int is_virus(char *filename) {
    FILE *file;
    char line[MAX_VIRUS_LEN];
    char *viruses[] = {"virus1", "virus2", "virus3"};
    int i, found = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    // Read the file line by line and check for viruses
    while (fgets(line, MAX_VIRUS_LEN, file)!= NULL) {
        for (i = 0; i < sizeof(viruses) / sizeof(char *); i++) {
            if (strstr(line, viruses[i])!= NULL) {
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // Close the file and return the result
    fclose(file);
    return found;
}

int main(int argc, char *argv[]) {
    int i, num_files = 0, infected_files = 0;
    char **files;

    // Check if the user provided any filenames
    if (argc < 2) {
        printf("Usage: %s <filename> [<filename>...]\n", argv[0]);
        return 1;
    }

    // Allocate memory for the filenames
    files = (char **)malloc(argc - 1 * sizeof(char *));
    if (files == NULL) {
        printf("Error: Out of memory.\n");
        return 1;
    }

    // Copy the filenames into the array
    for (i = 1; i < argc; i++) {
        files[num_files] = argv[i];
        num_files++;
    }

    // Scan the files for viruses
    for (i = 0; i < num_files; i++) {
        if (is_virus(files[i])) {
            infected_files++;
            printf("%s is infected with a virus.\n", files[i]);
        }
    }

    // Free the memory allocated for the filenames
    for (i = 0; i < num_files; i++) {
        free(files[i]);
    }
    free(files);

    // Print the summary
    if (infected_files == 0) {
        printf("No viruses found.\n");
    } else {
        printf("%d virus%s found.\n", infected_files, infected_files == 1? "" : "es");
    }

    return 0;
}