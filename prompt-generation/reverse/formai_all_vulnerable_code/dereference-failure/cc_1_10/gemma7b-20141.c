//Gemma-7B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileData {
  FILE* filePointer;
  char* buffer;
  int bufferSize;
  int readPos;
  int writePos;
} FileData;

void initializeFileData(FileData* fileData) {
  fileData->filePointer = NULL;
  fileData->buffer = NULL;
  fileData->bufferSize = MAX_BUFFER_SIZE;
  fileData->readPos = 0;
  fileData->writePos = 0;
}

int readData(FileData* fileData) {
  if (fileData->readPos >= fileData->bufferSize) {
    return -1;
  }

  int bytesRead = fread(fileData->buffer + fileData->readPos, 1, fileData->bufferSize - fileData->readPos, fileData->filePointer);

  fileData->readPos += bytesRead;

  return bytesRead;
}

int writeData(FileData* fileData, char* data, int dataLength) {
  if (fileData->writePos + dataLength >= fileData->bufferSize) {
    return -1;
  }

  int bytesWritten = fwrite(data, 1, dataLength, fileData->filePointer);

  fileData->writePos += bytesWritten;

  return bytesWritten;
}

int main() {
  FileData fileData;
  initializeFileData(&fileData);

  fileData.filePointer = fopen("my_file.txt", "w");
  writeData(&fileData, "Hello, world!", 13);

  fclose(fileData.filePointer);

  fileData.filePointer = fopen("my_file.txt", "r");
  char* data = readData(&fileData);

  printf("%s", data);

  fclose(fileData.filePointer);

  return 0;
}