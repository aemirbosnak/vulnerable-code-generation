//Gemma-7B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileHandle {
  FILE* filePtr;
  char* buffer;
  int bufferSize;
  int readPos;
  int writePos;
} FileHandle;

FileHandle* createFileHandle(char* filename) {
  FileHandle* handle = (FileHandle*)malloc(sizeof(FileHandle));
  handle->filePtr = fopen(filename, "r+b");
  handle->buffer = (char*)malloc(MAX_BUFFER_SIZE);
  handle->bufferSize = MAX_BUFFER_SIZE;
  handle->readPos = 0;
  handle->writePos = 0;

  return handle;
}

void writeFileHandle(FileHandle* handle, char* data, int dataSize) {
  if (handle->writePos + dataSize > handle->bufferSize) {
    handle->buffer = (char*)realloc(handle->buffer, handle->bufferSize * 2);
    handle->bufferSize *= 2;
  }

  memcpy(handle->buffer + handle->writePos, data, dataSize);
  handle->writePos += dataSize;
}

char* readFileHandle(FileHandle* handle, int* dataSize) {
  *dataSize = handle->readPos;

  if (handle->readPos > 0) {
    return handle->buffer;
  } else {
    return NULL;
  }
}

void closeFileHandle(FileHandle* handle) {
  fclose(handle->filePtr);
  free(handle->buffer);
  free(handle);
}

int main() {
  FileHandle* handle = createFileHandle("test.txt");

  writeFileHandle(handle, "Hello, world!", 13);

  char* data = readFileHandle(handle, NULL);

  if (data) {
    printf("%s", data);
  }

  closeFileHandle(handle);

  return 0;
}