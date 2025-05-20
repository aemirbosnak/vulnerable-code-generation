//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_METADATA_LENGTH 256
#define MAX_FILES 100

typedef struct {
    char fileName[256];
    char fileType[50];
    long fileSize; // in bytes
} FileMetadata;

void extractMetadata(const char *directory, FileMetadata *metadataArray, int *count) {
    struct dirent *entry;
    DIR *dp = opendir(directory);
    
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // If it's a regular file
            // Store metadata
            snprintf(metadataArray[*count].fileName, sizeof(metadataArray[*count].fileName), "%s/%s", directory, entry->d_name);
            snprintf(metadataArray[*count].fileType, sizeof(metadataArray[*count].fileType), "Regular File");
            
            FILE *file = fopen(metadataArray[*count].fileName, "rb");
            if (file) {
                fseek(file, 0, SEEK_END); // Move to the end of the file
                metadataArray[*count].fileSize = ftell(file); // Get file size
                fclose(file);
            } else {
                metadataArray[*count].fileSize = -1; // Indicate error
            }
            
            (*count)++;
        }
    }
    
    closedir(dp);
}

void printMetadata(const FileMetadata *metadataArray, int count) {
    printf("Extracted File Metadata:\n");
    printf("%-40s %-20s %-10s\n", "File Name", "File Type", "File Size (bytes)");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-40s %-20s %-10ld\n", metadataArray[i].fileName, metadataArray[i].fileType, metadataArray[i].fileSize);
    }
}

void saveMetadataToFile(const FileMetadata *metadataArray, int count, const char *outputFileName) {
    FILE *outfile = fopen(outputFileName, "w");
    if (outfile == NULL) {
        perror("fopen");
        return;
    }
    
    fprintf(outfile, "File Name,File Type,File Size (bytes)\n");
    for (int i = 0; i < count; i++) {
        fprintf(outfile, "%s,%s,%ld\n", metadataArray[i].fileName, metadataArray[i].fileType, metadataArray[i].fileSize);
    }
    
    fclose(outfile);
    printf("Metadata saved to %s\n", outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_path> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *directory = argv[1];
    const char *outputFileName = argv[2];
    
    FileMetadata metadataArray[MAX_FILES];
    int count = 0;
    
    extractMetadata(directory, metadataArray, &count);
    printMetadata(metadataArray, count);
    saveMetadataToFile(metadataArray, count, outputFileName);
    
    return EXIT_SUCCESS;
}