//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 260
#define MAX_SIG_LENGTH 100
#define MAX_SIGS 10

typedef struct {
    char signature[MAX_SIG_LENGTH];
} VirusSignature;

VirusSignature virusSignatures[MAX_SIGS] = {
    {"EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"}, // Common virus signature for testing
    {"This is another example signature."}, 
    {"A fake virus signature example."}, 
    {"Malware.Spyware.123456"}, 
    {"Trojan.Agent.Example"}
};

void scanFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        for (int i = 0; i < MAX_SIGS; i++) {
            if (strstr(buffer, virusSignatures[i].signature)) {
                printf("Virus detected in file: %s\n", filePath);
                fclose(file);
                return;
            }
        }
    }

    fclose(file);
}

void scanDirectory(const char *dirPath) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);
            struct stat pathStat;
            stat(fullPath, &pathStat);
            if (S_ISDIR(pathStat.st_mode)) {
                scanDirectory(fullPath); // Recur for directories
            } else {
                scanFile(fullPath); // Scan file for viruses
            }
        }
    }

    closedir(dp);
}

void displayHelp() {
    printf("Simple C Antivirus Scanner\n");
    printf("Usage: antivirus_scanner <directory>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        displayHelp();
        return EXIT_FAILURE;
    }

    const char *directoryPath = argv[1];
    
    printf("Scanning directory: %s\n", directoryPath);
    scanDirectory(directoryPath);
    
    printf("Scan complete.\n");
    return EXIT_SUCCESS;
}