//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_PATH_LENGTH 512
#define KNOWN_VIRUS_COUNT 5

// List of known viruses (in a medieval context, these are like dark artifacts)
const char *known_viruses[KNOWN_VIRUS_COUNT] = {
    "DarkGlyph",
    "ShadowHex",
    "RavenBane",
    "CursedSilver",
    "WickedCharm"
};

// Function to proclaim any found virus
void proclaim_virus(const char *file_path, const char *virus_name) {
    printf("Alas! A dark artifact, '%s', found within the realm: '%s'.\n", virus_name, file_path);
}

// Function to search for viruses in a given file
void scan_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    char line[MAX_FILENAME_LENGTH];

    if (file != NULL) {
        while (fgets(line, sizeof(line), file) != NULL) {
            for (int i = 0; i < KNOWN_VIRUS_COUNT; i++) {
                if (strstr(line, known_viruses[i]) != NULL) {
                    proclaim_virus(file_path, known_viruses[i]);
                }
            }
        }
        fclose(file);
    } else {
        printf("The tome '%s' could not be opened.\n", file_path);
    }
}

// Function to traverse the domain (directory) for tomes (files)
void traverse_domain(const char *directory_path) {
    struct dirent *entry;
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        printf("The realm of '%s' is shrouded in mystery; cannot be traversed.\n", directory_path);
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        // Skip the hidden tomes (.)
        if (entry->d_name[0] == '.') {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // If it is a directory, continue the quest
            printf("Entering the mystical realm: '%s'.\n", full_path);
            traverse_domain(full_path);
        } else {
            // If it is a file, commence the scanning
            printf("Scouting the tome: '%s'.\n", full_path);
            scan_file(full_path);
        }
    }
    closedir(directory);
}

// The main function to commence scanning the kingdom
int main(int argc, char *argv[]) {
    printf("~~~~~~ Welcome to the Medieval Antivirus Scanner ~~~~~~\n");
    if (argc < 2) {
        printf("Alas, please provide the path to the realm you wish to scan. Usage: ./antivirus <directory_path>\n");
        return 1;
    }

    const char *directory_path = argv[1];
    printf("Preparing to traverse the realm: '%s'.\n", directory_path);
    traverse_domain(directory_path);

    printf("~~~~~~ The scanning quest is complete! ~~~~~~\n");
    return 0;
}