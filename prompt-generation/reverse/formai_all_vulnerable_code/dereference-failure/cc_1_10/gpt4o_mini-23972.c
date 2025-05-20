//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function prototypes
void scanDirectory(const char *dirName);
void recoverFile(const char *filePath, const char *destDir);
int isRecoverable(const char *filePath);
void logRecovery(const char *filePath, const char *destDir);
void displayHelp();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        displayHelp();
        return 1;
    }
    
    const char *sourceDir = argv[1];
    const char *destDir = argv[2];

    printf("Scanning directory: %s\n", sourceDir);
    scanDirectory(sourceDir);
    
    return 0;
}

void scanDirectory(const char *dirName) {
    struct dirent *entry;
    DIR *dp = opendir(dirName);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    
    while ((entry = readdir(dp))) {
        // Skip current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char fullPath[1024];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirName, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            // If it's a directory, scan recursively
            scanDirectory(fullPath);
        } else {
            // Check if it's recoverable
            if (isRecoverable(fullPath)) {
                printf("Recoverable file found: %s\n", fullPath);
                recoverFile(fullPath, dirName);
            }
        }
    }
    
    closedir(dp);
}

void recoverFile(const char *filePath, const char *destDir) {
    // Create destination path
    char recoveryPath[1024];
    snprintf(recoveryPath, sizeof(recoveryPath), "%s/recovered_%s", destDir, strrchr(filePath, '/') + 1);
    
    // Simulate file recovery
    FILE *srcFile = fopen(filePath, "rb");
    FILE *destFile = fopen(recoveryPath, "wb");
    
    if (srcFile && destFile) {
        char buffer[1024];
        size_t bytesRead;
        
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), srcFile)) > 0) {
            fwrite(buffer, 1, bytesRead, destFile);
        }
        
        fclose(srcFile);
        fclose(destFile);
        logRecovery(filePath, destDir);
        printf("Recovered file: %s -> %s\n", filePath, recoveryPath);
    } else {
        perror("File recovery error");
    }
}

int isRecoverable(const char *filePath) {
    // Simple check: simulate that all files with ".deleted" suffix are recoverable
    return strcasestr(filePath, ".deleted") != NULL;
}

void logRecovery(const char *filePath, const char *destDir) {
    FILE *logFile = fopen("recovery_log.txt", "a");
    if (logFile) {
        fprintf(logFile, "Recovered: %s to %s\n", filePath, destDir);
        fclose(logFile);
    }
}

void displayHelp() {
    printf("Usage: ./data_recovery_tool <source_directory> <destination_directory>\n");
    printf("Scans the source_directory for recoverable files and recovers them to destination_directory.\n");
}