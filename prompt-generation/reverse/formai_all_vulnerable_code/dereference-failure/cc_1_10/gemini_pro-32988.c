//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The curious case of the lost data
int main(int argc, char *argv[]) {
  // Prepare for the journey into the depths of the hard drive
  FILE *disk = fopen("harddrive.dd", "rb");
  if (disk == NULL) {
    // Alas, the journey has come to an abrupt end before it began
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Cast our gaze upon the vast sea of bits and bytes
  fseek(disk, 0, SEEK_END);
  long disk_size = ftell(disk);
  rewind(disk);

  // Engage the enchanted magnifying glass to search for lost fragments
  char *buffer = malloc(disk_size);
  fread(buffer, disk_size, 1, disk);

  // Time to unleash the mystical algorithms of data recovery
  int found_count = 0;
  for (long i = 0; i < disk_size; i++) {
    // Behold, the magic of file signatures
    if (memcmp(buffer + i, "\x42\x4D", 2) == 0) {
      // A treasure has been unearthed! A rogue BMP file
      printf("Found BMP file at offset %ld\n", i);
      found_count++;
    } else if (memcmp(buffer + i, "\x50\x4B", 2) == 0) {
      // Another gem in the rough! A ZIP archive
      printf("Found ZIP archive at offset %ld\n", i);
      found_count++;
    } else if (memcmp(buffer + i, "\x7F\x45\x4C\x46", 4) == 0) {
      // Ho ho ho! An ELF executable
      printf("Found ELF executable at offset %ld\n", i);
      found_count++;
    }
  }

  // Ah, the journey has borne fruit!
  printf("\nRescued %d lost files from the digital abyss.\n", found_count);

  // Farewell, brave adventurer. May your data recovery expeditions always be fruitful.
  free(buffer);
  fclose(disk);
  return EXIT_SUCCESS;
}