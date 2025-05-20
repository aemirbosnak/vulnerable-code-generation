//FormAI DATASET v1.0 Category: Data recovery tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int size;
} FileData;

typedef struct {
    int sector;
    int nFiles;
    FileData* files;
} DriveSector;

typedef struct {
    int nSectors;
    DriveSector* sectors;
} Drive;

Drive* createDrive(int nSectors) {
    Drive* d = (Drive*)malloc(sizeof(Drive));
    d->nSectors = nSectors;
    d->sectors = (DriveSector*)malloc(nSectors * sizeof(DriveSector));
    for (int i = 0; i < nSectors; i++) {
        d->sectors[i].sector = i;
        d->sectors[i].nFiles = 0;
        d->sectors[i].files = NULL;
    }
    return d;
}

void deleteDrive(Drive* d) {
    for (int i = 0; i < d->nSectors; i++) {
        for (int j = 0; j < d->sectors[i].nFiles; j++) {
            free(d->sectors[i].files[j].data);
        }
        free(d->sectors[i].files);
    }
    free(d->sectors);
    free(d);
}

void addFile(DriveSector* s, char* data, int size) {
    s->nFiles++;
    s->files = (FileData*)realloc(s->files, s->nFiles * sizeof(FileData));
    s->files[s->nFiles-1].data = (char*)malloc(size * sizeof(char));
    memcpy(s->files[s->nFiles-1].data, data, size);
    s->files[s->nFiles-1].size = size;
}

void writeFile(Drive* d, int sector, int fileIndex, char* filename) {
    if (sector < 0 || sector >= d->nSectors ||
        fileIndex < 0 || fileIndex >= d->sectors[sector].nFiles) {
        printf("Invalid sector and/or file index\n");
        return;
    }
    FileData file = d->sectors[sector].files[fileIndex];
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }
    fwrite(file.data, sizeof(char), file.size, fp);
    fclose(fp);
}

int main() {
    Drive* d = createDrive(10);
    char* data1 = "Hello World!";
    char* data2 = "This is a test file.";
    addFile(&d->sectors[0], data1, strlen(data1));
    addFile(&d->sectors[1], data2, strlen(data2));
    writeFile(d, 0, 0, "file1.txt");
    writeFile(d, 1, 0, "file2.txt");
    deleteDrive(d);
    return 0;
}