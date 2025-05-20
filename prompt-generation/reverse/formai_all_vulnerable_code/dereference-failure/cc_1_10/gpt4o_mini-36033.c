//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH 1024
#define MAX_VIRUSES 100

typedef struct {
    char name[50];
    char signature[50];
} Virus;

typedef struct {
    char path[MAX_PATH];
    time_t lastScan;
} Directory;

Virus virusDB[MAX_VIRUSES] = {
    {"EvilVirus", "123abc"},
    {"TrojanHorse", "456def"},
    {"Worm", "789ghi"},
    {"Spyware", "abc123"},
    {"Ransomware", "def456"}
};

int virusCount = 5;
Directory currentDirectory;
int flaggedFiles = 0;

void initDirectory(char *path) {
    strncpy(currentDirectory.path, path, MAX_PATH);
    currentDirectory.lastScan = time(NULL);
}

void scanFile(char *filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        perror("File open error");
        return;
    }

    char buffer[256];
    while (fread(buffer, 1, sizeof(buffer), file)) {
        for (int i = 0; i < virusCount; i++) {
            if (strstr(buffer, virusDB[i].signature) != NULL) {
                printf("Virus detected! %s in file: %s\n", virusDB[i].name, filePath);
                flaggedFiles++;
                break;
            }
        }
    }
    fclose(file);
}

void scanDirectory() {
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;

    if ((dir = opendir(currentDirectory.path)) == NULL) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char filePath[MAX_PATH];
            snprintf(filePath, sizeof(filePath), "%s/%s", currentDirectory.path, entry->d_name);
            if (stat(filePath, &filestat) == 0) {
                if (S_ISREG(filestat.st_mode)) {
                    scanFile(filePath);
                }
            }
        }
    }

    closedir(dir);
}

void reportResults() {
    printf("\nScan Complete! Total flagged files: %d\n", flaggedFiles);
    if (flaggedFiles > 0) {
        printf("Important: Please take action on the flagged files!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_to_scan>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Initializing the futuristic antivirus scanner...\n");
    initDirectory(argv[1]);
    
    printf("Scanning directory: %s\n", currentDirectory.path);
    scanDirectory();
    reportResults();

    return EXIT_SUCCESS;
}