//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define MAX_LINE_SIZE 256
#define DELIMITER "|"

typedef struct {
    char name[MAX_LINE_SIZE];
    char content[MAX_FILE_SIZE];
} FileData;

void loadFile(FileData *file, FILE *fp) {
    fseek(fp, 0L, SEEK_SET);
    fgets(file->name, MAX_LINE_SIZE, fp);
    fgets(file->content, MAX_FILE_SIZE, fp);
}

void saveFile(FILE *fp, FileData *file) {
    fprintf(fp, "%s%s", file->name, DELIMITER);
    fprintf(fp, "%s", file->content);
}

int compareFiles(FileData *file1, FileData *file2) {
    if (strcmp(file1->name, file2->name)!= 0) {
        return 1;
    }

    if (strcmp(file1->content, file2->content)!= 0) {
        return 1;
    }

    return 0;
}

void synchronizeFiles(FILE *file1, FILE *file2) {
    FileData fileData1, fileData2;

    while (fgets(fileData1.name, MAX_LINE_SIZE, file1)!= NULL) {
        loadFile(&fileData1, file1);

        while (fgets(fileData2.name, MAX_LINE_SIZE, file2)!= NULL) {
            loadFile(&fileData2, file2);

            if (compareFiles(&fileData1, &fileData2) == 0) {
                fprintf(stdout, "Files are synchronized.\n");
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r+");
    FILE *file2 = fopen(argv[2], "r+");

    if (file1 == NULL || file2 == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    synchronizeFiles(file1, file2);

    fclose(file1);
    fclose(file2);

    return 0;
}