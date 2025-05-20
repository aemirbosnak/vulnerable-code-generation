//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// **Malware Signatures**
#define VIRUS_SIGNATURE "I_AM_A_VIRUS"
#define KNOWN_VIRUS_1 "VIRUS_VARIANT_A"
#define KNOWN_VIRUS_2 "VIRUS_VARIANT_B"

// **Scanner Logic**
int scanFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, VIRUS_SIGNATURE) != NULL ||
            strstr(buffer, KNOWN_VIRUS_1) != NULL ||
            strstr(buffer, KNOWN_VIRUS_2) != NULL) {
            fclose(file);
            return 1;  // File Infected!
        }
    }
    fclose(file);
    return 0;  // File Clean!
}

// **Crawler and Scanner**
void scanDirectory(const char* dirPath) {
    DIR* dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
        if (entry->d_type == DT_DIR) {
            scanDirectory(filePath);
        } else if (entry->d_type == DT_REG) {
            int scanResult = scanFile(filePath);
            if (scanResult == 1) {
                printf("**ALERT!** Infected file found: %s\n", filePath);
            }
        }
    }
    closedir(dir);
}

// **Main Program**
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory to scan>\n", argv[0]);
        return -1;
    }
    const char* dirPath = argv[1];
    printf("**Scanning Directory: %s**\n", dirPath);
    scanDirectory(dirPath);
    printf("**Scan Complete!**\n");
    return 0;
}