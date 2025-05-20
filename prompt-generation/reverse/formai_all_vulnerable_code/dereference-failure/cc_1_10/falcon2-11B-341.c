//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 256

int main()
{
    char buff[BUFF_SIZE];
    FILE *fp;

    printf("Enter the path of the file you want to scan: ");
    fgets(buff, BUFF_SIZE, stdin);
    buff[strcspn(buff, "\n")] = '\0';  // Remove the newline character

    fp = fopen(buff, "rb");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* fileName = (char*) malloc(fileSize + 1);
    fread(fileName, 1, fileSize, fp);
    fileName[fileSize] = '\0';  // Remove the newline character

    printf("Scanning file: %s\n", fileName);

    char* virusName = (char*) malloc(256);
    char* virusFile = (char*) malloc(256);

    char* fileType = strrchr(fileName, '.');
    if (fileType == NULL) {
        sprintf(virusName, "Virus found in file: %s", fileName);
        sprintf(virusFile, "%s.exe", fileName);
    }
    else {
        sprintf(virusName, "Virus found in file: %s", fileName);
        sprintf(virusFile, "%s.exe", fileType);
    }

    printf("%s\n", virusName);
    printf("%s\n", virusFile);

    free(fileName);
    free(virusName);
    free(virusFile);
    fclose(fp);

    return 0;
}