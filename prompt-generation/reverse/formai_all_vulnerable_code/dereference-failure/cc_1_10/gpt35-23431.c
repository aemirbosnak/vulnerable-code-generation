//FormAI DATASET v1.0 Category: File Backup System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void backupFile(char *srcPath, char *destPath, char *filename);
void backupDir(char *srcPath, char *destPath);
void removeDir(char *path);

int main(int argc, char *argv[])
{
    // Check command line argument count.
    if (argc != 3)
    {
        printf("Usage: backup [source directory] [destination directory]\n");
        exit(1);
    }

    // Get source and destination paths from command line arguments.
    char *srcPath = argv[1], *destPath = argv[2];

    // Check if source path is a directory.
    DIR *srcDir = opendir(srcPath);
    if (srcDir == NULL)
    {
        printf("Error: Source path is not a directory.\n");
        exit(1);
    }
    closedir(srcDir);

    // Check if destination path is a directory.
    DIR *destDir = opendir(destPath);
    if (destDir == NULL)
    {
        printf("Destination directory does not exist. Creating...\n");
        mkdir(destPath, 0777);
    }
    closedir(destDir);

    // Backup directory recursively.
    backupDir(srcPath, destPath);

    printf("Backup complete!\n");

    return 0;
}

void backupDir(char *srcPath, char *destPath)
{
    // Create destination directory.
    char destDir[BUFFER_SIZE];
    sprintf(destDir, "%s/%s", destPath, basename(srcPath));
    mkdir(destDir, 0777);

    // Open source directory.
    DIR *dir = opendir(srcPath);

    if (dir != NULL)
    {
        // Iterate over directory contents.
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            // Create source and destination paths.
            char path[BUFFER_SIZE], dest[BUFFER_SIZE];
            sprintf(path, "%s/%s", srcPath, entry->d_name);
            sprintf(dest, "%s/%s", destDir, entry->d_name);

            if (entry->d_type == DT_DIR)
            {
                // Backup subdirectory recursively.
                backupDir(path, dest);
            }
            else
            {
                // Backup file.
                backupFile(path, destDir, entry->d_name);
            }
        }
        closedir(dir);
    }
}

void backupFile(char *srcPath, char *destPath, char *filename)
{
    // Open source file.
    FILE *srcFile = fopen(srcPath, "rb");
    if (srcFile == NULL)
    {
        printf("Error: Failed to open %s!\n", srcPath);
        return;
    }

    // Create destination file.
    char destFile[BUFFER_SIZE];
    sprintf(destFile, "%s/%s", destPath, filename);
    FILE *destFilePtr = fopen(destFile, "wb");
    if (destFilePtr == NULL)
    {
        printf("Error: Failed to create %s!\n", destFile);
        fclose(srcFile);
        return;
    }

    // Copy file contents.
    char buffer[BUFFER_SIZE];
    size_t size;
    while ((size = fread(buffer, 1, BUFFER_SIZE, srcFile)) > 0)
    {
        fwrite(buffer, 1, size, destFilePtr);
    }

    // Close files.
    fclose(destFilePtr);
    fclose(srcFile);

    printf("Backed up %s\n", srcPath);
}

void removeDir(char *path)
{
    // Open directory.
    DIR *dir = opendir(path);

    if (dir != NULL)
    {
        // Iterate over directory contents.
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            {
                continue;
            }

            // Create path to file.
            char filePath[BUFFER_SIZE];
            sprintf(filePath, "%s/%s", path, entry->d_name);

            if (entry->d_type == DT_DIR)
            {
                // Delete subdirectory recursively.
                removeDir(filePath);
            }
            else
            {
                // Delete file.
                remove(filePath);
            }
        }
        closedir(dir);
    }

    // Delete directory.
    rmdir(path);
}