//FormAI DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size (in bytes)
#define MAX_FILENAME_LENGTH 50 // Maximum length of a file name (excluding file extension)

// Function prototypes
int fileExists(const char* fileName);
void backupFile(const char* fileName);
void copyFile(const char* source, const char* destination);
char* getCurrentTime();

int main()
{
    char fileName[MAX_FILENAME_LENGTH];
    
    // Prompt user for file name
    printf("Enter the name of the file you want to backup: ");
    scanf("%s", fileName);
    
    // Check if file exists
    if (fileExists(fileName))
    {
        backupFile(fileName);
        printf("Backup successful!\n");
    }
    else
    {
        printf("File does not exist.\n");
    }
    
    return 0;
}

int fileExists(const char* fileName)
{
    FILE* file = fopen(fileName, "r");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}

void backupFile(const char* fileName)
{
    char backupFileName[MAX_FILENAME_LENGTH + 30]; // Add extra space for timestamp and file extension
    
    // Generate backup file name with timestamp
    sprintf(backupFileName, "backup_%s_%s", getCurrentTime(), fileName);
    
    // Copy file to backup file
    copyFile(fileName, backupFileName);
}

void copyFile(const char* source, const char* destination)
{
    FILE* inFile = fopen(source, "rb");
    FILE* outFile = fopen(destination, "wb");
    
    if (!inFile)
    {
        printf("Error: Could not open source file.\n");
        return;
    }
    if (!outFile)
    {
        printf("Error: Could not create destination file.\n");
        return;
    }
    
    // Copy file byte-by-byte
    int byte;
    while ((byte = getc(inFile)) != EOF)
    {
        putc(byte, outFile);
    }
    
    // Close files
    fclose(inFile);
    fclose(outFile);
}

char* getCurrentTime()
{
    time_t rawTime;
    struct tm* timeInfo;
    char* buffer = (char*)malloc(sizeof(char) * 30);
    
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    
    strftime(buffer, 30, "%Y%m%d_%H%M%S", timeInfo);
    
    return buffer;
}