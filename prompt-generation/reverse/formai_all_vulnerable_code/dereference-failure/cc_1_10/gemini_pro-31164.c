//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int size;
  char *data;
} File;

typedef struct {
  File *file1;
  File *file2;
} FilePair;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s file1 file2\n", argv[0]);
    return 1;
  }

  File file1, file2;
  if (!readFile(&file1, argv[1])) {
    return 2;
  }
  if (!readFile(&file2, argv[2])) {
    return 2;
  }

  FilePair fp;
  fp.file1 = &file1;
  fp.file2 = &file2;

  if (equalFiles(&fp)) {
    printf("The files are the same. No need to synchronize.\n");
    return 0;
  }

  printf("The files are different. Synchronizing...\n");

  int numDiffs = 0;
  for (int i = 0; i < file1.size; i++) {
    if (file1.data[i] != file2.data[i]) {
      numDiffs++;
    }
  }

  printf("Found %d differences. Applying changes...\n", numDiffs);

  for (int i = 0; i < file1.size; i++) {
    if (file1.data[i] != file2.data[i]) {
      file1.data[i] = file2.data[i];
    }
  }

  printf("Changes applied. Writing the synchronized file...\n");

  if (!writeFile(&file1, argv[1])) {
    return 3;
  }

  printf("File synchronized successfully.\n");

  return 0;
}

int readFile(File *file, char *filename) {
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    return 0;
  }

  fseek(fp, 0, SEEK_END);
  file->size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  file->data = malloc(file->size);
  if (file->data == NULL) {
    fclose(fp);
    return 0;
  }

  fread(file->data, 1, file->size, fp);
  fclose(fp);

  file->name = strdup(filename);

  return 1;
}

int writeFile(File *file, char *filename) {
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    return 0;
  }

  fwrite(file->data, 1, file->size, fp);
  fclose(fp);

  return 1;
}

int equalFiles(FilePair *fp) {
  if (fp->file1->size != fp->file2->size) {
    return 0;
  }

  for (int i = 0; i < fp->file1->size; i++) {
    if (fp->file1->data[i] != fp->file2->data[i]) {
      return 0;
    }
  }

  return 1;
}