//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: medieval
// Upon yon fair realm of disks,
// Where bytes and kilobytes do dwell,
// A minstrel bold did venture forth,
// To sing a tale of space to tell.

#include <stdio.h>
#include <stdlib.h>

// Fair maiden, list thy grand design,
// Where data doth reside and shine.
typedef struct Disk {
  char *path;
  long size;
} Disk;

// A humble bard, with skill profound,
// To traverse disks with nary a sound.
void DiskAnalyzer(Disk *disk) {
  // With humble grace, we seek thy size,
  // The weight of data in disguise.
  disk->size = 0;

  // Through realms of bytes, we wander deep,
  // Counting every bit that we may reap.
  FILE *file = fopen(disk->path, "rb");
  if (file) {
    fseek(file, 0, SEEK_END);
    disk->size = ftell(file);
    fclose(file);
  }
}

// A knight of old, with armor bright,
// To sort the disks, both day and night.
void SortDisks(Disk *disks, int count) {
  // With swift exchange, we order true,
  // From smallest size to largest due.
  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      if (disks[j].size > disks[j + 1].size) {
        Disk temp = disks[j];
        disks[j] = disks[j + 1];
        disks[j + 1] = temp;
      }
    }
  }
}

// A herald fair, with voice so clear,
// To sing the tales of disks so dear.
void PrintDisks(Disk *disks, int count) {
  // With eloquence, we shall proclaim,
  // The size of each, a noble aim.
  printf("Disks of Yore:\n\n");
  for (int i = 0; i < count; i++) {
    printf("Path: %s\n", disks[i].path);
    printf("Size: %ld bytes\n\n", disks[i].size);
  }
}

// A lord of realms, with power grand,
// To free the disks from mortal hand.
void FreeDisks(Disk *disks, int count) {
  // With care we tend, we set them free,
  // To roam the realm of memory.
  for (int i = 0; i < count; i++) {
    free(disks[i].path);
  }
  free(disks);
}

// The minstrel's quest, a noble deed,
// To analyze the disks, a valiant creed.
int main(int argc, char *argv[]) {
  // With gentle touch, we gather disks,
  // To weave their tale with tuneful tricks.
  int diskCount = argc - 1;
  Disk *disks = malloc(sizeof(Disk) * diskCount);

  for (int i = 0; i < diskCount; i++) {
    disks[i].path = argv[i + 1];
  }

  // The bard embarks on his grand task,
  // With nimble fingers, he'll unveil the mask.
  for (int i = 0; i < diskCount; i++) {
    DiskAnalyzer(&disks[i]);
  }

  // The knights assemble, fierce and strong,
  // To sort the disks, both right and wrong.
  SortDisks(disks, diskCount);

  // The herald steps forth, with voice so clear,
  // To share the tale of disks so dear.
  PrintDisks(disks, diskCount);

  // The lord, with wisdom, sets them free,
  // To reclaim their realms in liberty.
  FreeDisks(disks, diskCount);

  // The minstrel's song, forever true,
  // Of disks analyzed, a tale anew.
  return 0;
}