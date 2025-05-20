//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int size;
} File;

int compare(const void *a, const void *b) {
    File *fileA = (File *)a;
    File *fileB = (File *)b;
    return fileB->size - fileA->size;
}

void printSize(long long size) {
    if (size < 1024) {
        printf("%lld B", size);
    } else if (size < 1048576) {
        printf("%lld KB", size / 1024);
    } else if (size < 1073741824) {
        printf("%lld MB", size / 1048576);
    } else {
        printf("%lld GB", size / 1073741824);
    }
}

void analyze(char* filePath) {
    FILE *file = fopen(filePath, "rb");
    if (!file) {
        printf("File cannot be opened.");
        return;
    }
    
    fseek(file, 0L, SEEK_END);
    long long fileSize = ftell(file);
    rewind(file);
    
    printf("Total Disk Space: ");
    printSize(fileSize);
    
    char* str = malloc(fileSize + 1);
    fread(str, fileSize, 1, file);
    fclose(file);
    
    str[fileSize] = '\0';
    
    char* token = strtok(str, " \n\r\t");
    File* fileList = malloc(sizeof(File));
    int count = 0;
    while (token) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(fileList[i].name, token) == 0) {
                found = 1;
                fileList[i].size++;
                break;
            }
        }

        if (!found) {
            count++;
            fileList = realloc(fileList, count * sizeof(File));
            fileList[count - 1].name = token;
            fileList[count - 1].size = 1;
        }
        
        token = strtok(NULL, " \n\r\t");
    }
    
    qsort(fileList, count, sizeof(File), compare);
    
    printf("\n\nFile Sizes: \n");
    for (int i = 0; i < count; i++) {
        printf("\"%s\": ", fileList[i].name);
        printSize((long long)fileList[i].size);
        printf("\n");
    }
    
    free(fileList);
    free(str);
}

int main() {
    char filePath[100];
    printf("Enter file path to analyze: ");
    scanf("%s", filePath);
    printf("\nAnalyzing %s...\n\n", filePath);
    analyze(filePath);
    printf("\nDone analyzing %s.", filePath);

    return 0;
}