//FormAI DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// function to get the last modified time of a file
void getLastModifiedTime(char *filePath, char *lastModifiedTime)
{
    struct stat attrib;
    stat(filePath, &attrib);
    strftime(lastModifiedTime, 20, "%d-%m-%Y %H:%M:%S", localtime(&(attrib.st_mtime)));
}

int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }
    char sourceDir[256];
    char destDir[256];
    DIR* dir;
    DIR* dir2;
    strcpy(sourceDir, argv[1]);
    strcpy(destDir, argv[2]);
    struct dirent *ent;
    char lastModifiedSource[20];
    char lastModifiedDest[20];

    if ((dir = opendir (sourceDir)) != NULL) 
    {
        // loop through all the files in the source directory
        while ((ent = readdir (dir)) != NULL) 
        {
            // ignore directories and hidden files
            if (ent->d_type != DT_DIR && ent->d_name[0] != '.') 
            {
                char sourcePath[256];
                char destPath[256];
                sprintf(sourcePath, "%s/%s", sourceDir, ent->d_name);
                sprintf(destPath, "%s/%s", destDir, ent->d_name);

                // check if the file exists in the destination directory
                if ((dir2 = opendir(destDir)) != NULL)
                {
                    struct dirent *ent2;
                    int found = 0;
                    while ((ent2 = readdir(dir2)) != NULL)
                    {
                        if (strcmp(ent2->d_name, ent->d_name) == 0)
                        {
                            found = 1;
                            char destFilePath[256];
                            sprintf(destFilePath, "%s/%s", destDir, ent2->d_name);
                            // get last modified time of source and destination files
                            getLastModifiedTime(sourcePath, lastModifiedSource);
                            getLastModifiedTime(destFilePath, lastModifiedDest);
                            // compare last modified times
                            if (strcmp(lastModifiedSource, lastModifiedDest) > 0)
                            {
                                // source file is newer, copy it over
                                FILE *sourceFile, *destFile;
                                char ch;
                                sourceFile = fopen(sourcePath, "r");
                                destFile = fopen(destFilePath, "w");
                                while ((ch = fgetc(sourceFile)) != EOF)
                                    fputc(ch, destFile);
                                printf("Updated %s in %s\n", ent->d_name, destDir);
                                fclose(sourceFile);
                                fclose(destFile);
                                break;
                            }
                        } 
                    }
                    if (!found)
                    {
                        // file does not exist in destination directory, copy it over
                        FILE *sourceFile, *destFile;
                        char ch;
                        sourceFile = fopen(sourcePath, "r");
                        destFile = fopen(destPath, "w");
                        while ((ch = fgetc(sourceFile)) != EOF)
                            fputc(ch, destFile);
                        printf("Copied %s to %s\n", ent->d_name, destDir);
                        fclose(sourceFile);
                        fclose(destFile);
                    }
                }
                else 
                {
                    // destination directory does not exist, create it and copy over the file
                    mkdir(destDir, 0777);
                    FILE *sourceFile, *destFile;
                    char ch;
                    sourceFile = fopen(sourcePath, "r");
                    destFile = fopen(destPath, "w");
                    while ((ch = fgetc(sourceFile)) != EOF)
                        fputc(ch, destFile);
                    printf("Created %s in %s\n", ent->d_name, destDir);
                    fclose(sourceFile);
                    fclose(destFile);
                }
            }
        }
        closedir (dir);
    } 
    else 
    {
        // source directory does not exist
        printf("Source directory does not exist.\n");
        exit(1);
    }
    return 0;
}