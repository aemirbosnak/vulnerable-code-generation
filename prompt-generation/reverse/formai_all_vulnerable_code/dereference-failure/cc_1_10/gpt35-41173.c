//FormAI DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    char fileName[100];
    int fileSize;
    char* fileData;
} RecoveredFile;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    char* imageFileName = argv[1];
    FILE* imageFile = fopen(imageFileName, "rb");
    if(imageFile == NULL) {
        printf("Could not open %s\n", imageFileName);
        return 2;
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    rewind(imageFile);

    unsigned char rawBytes[BLOCK_SIZE];
    RecoveredFile recoveredFiles[10];
    int fileCount = 0;

    while(ftell(imageFile) < imageSize) {
        fread(rawBytes, BLOCK_SIZE, 1, imageFile);

        if(rawBytes[0] == 0xff && rawBytes[1] == 0xd8 && rawBytes[2] == 0xff) {
            // This is the start of a new JPEG file
            RecoveredFile newFile;
            sprintf(newFile.fileName, "recovered_file_%d.jpg", fileCount + 1);
            newFile.fileSize = 0;
            newFile.fileData = malloc(BLOCK_SIZE);
            memcpy(newFile.fileData, rawBytes, BLOCK_SIZE);
            newFile.fileSize += BLOCK_SIZE;
            recoveredFiles[fileCount] = newFile;
            fileCount++;
        } else if(fileCount > 0 && rawBytes[0] != 0xff) {
            // We are continuing a JPEG file
            RecoveredFile* currentFile = &recoveredFiles[fileCount - 1];
            currentFile->fileData = realloc(currentFile->fileData, currentFile->fileSize + BLOCK_SIZE);
            memcpy(currentFile->fileData + currentFile->fileSize, rawBytes, BLOCK_SIZE);
            currentFile->fileSize += BLOCK_SIZE;
        }
    }

    printf("%d files recovered!\n", fileCount);

    for(int i = 0; i < fileCount; i++) {
        RecoveredFile* currentFile = &recoveredFiles[i];
        FILE* recoveredFile = fopen(currentFile->fileName, "wb");
        fwrite(currentFile->fileData, currentFile->fileSize, 1, recoveredFile);
        fclose(recoveredFile);
    }

    fclose(imageFile);
    return 0;
}