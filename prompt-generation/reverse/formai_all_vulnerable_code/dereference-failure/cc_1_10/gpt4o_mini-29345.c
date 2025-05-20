//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LINE_LENGTH 2048

void extractMetadataFromFile(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Cannot open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    printf("Extracting from file: %s\n", filePath);
    
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Extract comments
        if (strstr(line, "//") != NULL) {
            printf("\tComment on Line %d: %s", lineNumber, line);
        }
        
        // Extract includes
        if (strstr(line, "#include") != NULL) {
            printf("\tInclude on Line %d: %s", lineNumber, line);
        }
        
        // Extract function declarations (basic)
        if (strchr(line, '(') && strchr(line, ')')) {
            char *functionName = strtok(line, " ");
            while (functionName != NULL) {
                if (strchr(functionName, '(')) {
                    printf("\tFunction Declaration on Line %d: %s", lineNumber, functionName);
                    break;
                }
                functionName = strtok(NULL, " ");
            }
        }
    }
    
    fclose(file);
}

void exploreDirectory(const char *dirPath) {
    struct dirent *entry;
    DIR *dp = opendir(dirPath);

    if (dp == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Skip "." and ".."
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char newDirPath[MAX_PATH];
                snprintf(newDirPath, sizeof(newDirPath), "%s/%s", dirPath, entry->d_name);
                exploreDirectory(newDirPath);
            }
        } else if (entry->d_type == DT_REG) {
            // Check for C files
            if (strstr(entry->d_name, ".c") != NULL) {
                char filePath[MAX_PATH];
                snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);
                extractMetadataFromFile(filePath);
            }
        }
    }
    
    closedir(dp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *baseDir = argv[1];
    printf("Starting metadata extraction in directory: %s\n", baseDir);
    exploreDirectory(baseDir);

    return EXIT_SUCCESS;
}