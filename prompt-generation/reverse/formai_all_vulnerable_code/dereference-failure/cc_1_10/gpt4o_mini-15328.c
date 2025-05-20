//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_FILE_SIZE 4096
#define MAX_VIRUSES 10

// Structure to store information about known viruses
typedef struct {
    char name[50];
    char signature[50];
} Virus;

// List of known viruses
Virus virusList[MAX_VIRUSES] = {
    {"HappyVirus", "HV123"},
    {"SadVirus", "SV456"},
    {"JoyfulMalware", "JM789"},
    {"BadData", "BD101"},
    {"SneakyTrojan", "ST112"},
    {"EvilRootkit", "ER113"},
    {"RogueBot", "RB114"},
    {"ZombieApp", "ZA115"},
    {"SpookyCrypt", "SC116"},
    {"CheerfulAdware", "CA117"}
};

// Function to read a file into a buffer
int readFile(const char *filePath, char *buffer) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    fread(buffer, sizeof(char), MAX_FILE_SIZE, file);
    fclose(file);
    return 1;
}

// Function to check if a file contains a virus signature
int containsVirusSignature(const char *buffer) {
    for (int i = 0; i < MAX_VIRUSES; i++) {
        if (strstr(buffer, virusList[i].signature) != NULL) {
            printf("Beware! Found %s in your file!\n", virusList[i].name);
            return 1;
        }
    }
    return 0;
}

// Function to scan a directory for files
void scanDirectory(const char *directoryPath) {
    DIR *dir = opendir(directoryPath);
    struct dirent *entry;

    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the '.' and '..' entries
        if (entry->d_name[0] == '.') {
            continue;
        }

        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", directoryPath, entry->d_name);

        if (entry->d_type == DT_REG) {
            printf("Scanning file: %s...\n", fullPath);
            char fileContent[MAX_FILE_SIZE];

            if (readFile(fullPath, fileContent) && containsVirusSignature(fileContent)) {
                printf("Warning! Possible virus detected in %s!\n", fullPath);
            } else {
                printf("All clear in %s! 🎉\n", fullPath);
            }
        } else if (entry->d_type == DT_DIR) {
            scanDirectory(fullPath);
        }
    }

    closedir(dir);
}

// Function to start the scanning process
void startScanning() {
    char directory[1024];

    printf("🎉 Welcome to the Cheery Antivirus Scanner! 🎉\n");
    printf("Please enter the directory to scan: ");
    scanf("%1023s", directory);

    scanDirectory(directory);
    printf("Scanning completed! Have a great day! 🌈✨\n");
}

// Main function
int main() {
    startScanning();
    return 0;
}