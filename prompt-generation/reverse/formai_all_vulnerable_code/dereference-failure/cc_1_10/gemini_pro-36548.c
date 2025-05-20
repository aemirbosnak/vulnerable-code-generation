//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: imaginative
// Journey into the Depths of Digital Memoria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Tapestry of Lost Data
typedef struct LostData {
  char* filename;
  char* data;
  int size;
} LostData;

// The Archaeologist's Toolkit
LostData* recoverData(char* path) {
  FILE* file = fopen(path, "rb");
  if (file == NULL) {
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* data = malloc(size);
  fread(data, 1, size, file);
  fclose(file);

  LostData* lostData = malloc(sizeof(LostData));
  lostData->filename = path;
  lostData->data = data;
  lostData->size = size;

  return lostData;
}

void displayData(LostData* lostData) {
  printf("Recovered Data from %s:\n", lostData->filename);
  for (int i = 0; i < lostData->size; i++) {
    putchar(lostData->data[i]);
  }
  printf("\n");
}

int main() {
  // The Cave of Forgotten Files
  char* paths[] = {"ancient_scroll.txt", "forgotten_code.c", "haunted_diary.txt"};

  // The Archaeologist's Expedition
  printf("Embarking on a Data Recovery Journey...\n");
  for (int i = 0; i < 3; i++) {
    LostData* lostData = recoverData(paths[i]);
    if (lostData != NULL) {
      displayData(lostData);
    } else {
      printf("Data Recovery Failed for %s.\n", paths[i]);
    }
    free(lostData);
  }

  printf("Expedition Complete. Data Restored to the Realm of Memory.\n");

  return 0;
}