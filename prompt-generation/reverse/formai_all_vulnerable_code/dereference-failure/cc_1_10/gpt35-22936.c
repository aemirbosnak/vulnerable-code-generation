//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Define the size of metadata to extract
#define MAX_METADATA_SIZE 512

// Define the maximum size of file path
#define MAX_FILE_PATH 256

// Structure for storing metadata information
typedef struct {
    uint32_t fileSize;
    uint32_t creationDate;
    char authorName[64];
    char title[128];
} MetadataInfo;

// Function to extract metadata from file
int extract_metadata(const char* filePath, MetadataInfo* metadata)
{
    // Open file in binary mode
    FILE* fp = fopen(filePath, "rb");
    if(!fp)
    {
        printf("Unable to open file: %s\n", filePath);
        return -1;
    }
    
    // Seek to the end of file
    fseek(fp, 0, SEEK_END);
    
    // Get the file size
    metadata->fileSize = ftell(fp);
    
    // Seek back to the beginning of file
    fseek(fp, 0, SEEK_SET);
    
    // Allocate memory to store file data
    uint8_t* fileData = (uint8_t*)malloc(metadata->fileSize);
    if(!fileData)
    {
        printf("Failed to allocate memory for file data\n");
        fclose(fp);
        return -1;
    }
    
    // Read file data
    if(fread(fileData, metadata->fileSize, 1, fp) != 1)
    {
        printf("Failed to read file data\n");
        free(fileData);
        fclose(fp);
        return -1;
    }
    
    // Close the file
    fclose(fp);
    
    // Extract metadata information
    uint8_t* ptr = fileData;
    uint32_t remainingBytes = metadata->fileSize;
    while(remainingBytes >= 4)
    {
        uint32_t tag = *(uint32_t*)ptr;
        ptr += 4;
        remainingBytes -= 4;
        
        uint32_t size = *(uint32_t*)ptr;
        ptr += 4;
        remainingBytes -= 4;
        
        switch(tag)
        {
            case 0x43524541: // "AREA" tag
                printf("AREA tag found: %d\n", size);
                break;
            case 0x504f5454: // "POTT" tag
                printf("POTT tag found: %d\n", size);
                break;
            case 0x414d4f42: // "AMOB" tag
                memcpy(metadata->authorName, ptr, size);
                metadata->authorName[size] = '\0';
                printf("AMOB tag found: %d, Author Name: %s\n", size, metadata->authorName);
                break;
            case 0x5449544c: // "TITL" tag
                memcpy(metadata->title, ptr, size);
                metadata->title[size] = '\0';
                printf("TITL tag found: %d, Title: %s\n", size, metadata->title);
                break;
            case 0x43524554: // "CRET" tag
                metadata->creationDate = *(uint32_t*)ptr;
                printf("CRET tag found: %d, Creation Date: %d\n", size, metadata->creationDate);
                break;
            default:
                printf("Unknown tag found: %d, size: %d\n", tag, size);
                break;
        }
        
        ptr += size;
        remainingBytes -= size;
    }
    
    // Free allocated memory
    free(fileData);
    
    return 0;
}

int main()
{
    MetadataInfo metadata = {0};
    
    // Get file path from user input
    char filePath[MAX_FILE_PATH];
    printf("Enter the file path: ");
    fgets(filePath, sizeof(filePath), stdin);
    filePath[strcspn(filePath, "\n")] = '\0'; // remove newline character if present
    
    // Extract metadata from file
    if(extract_metadata(filePath, &metadata) == 0)
    {
        // Display metadata information
        printf("\nMetadata Information:\n");
        printf("File Size: %d\n", metadata.fileSize);
        printf("Author Name: %s\n", metadata.authorName);
        printf("Title: %s\n", metadata.title);
        printf("Creation Date: %d\n", metadata.creationDate);
    }
    
    return 0;
}