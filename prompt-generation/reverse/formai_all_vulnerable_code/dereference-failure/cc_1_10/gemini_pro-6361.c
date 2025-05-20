//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {
  // Set up the wasteland directory structure
  DIR *wasteland = opendir("wasteland");
  if (wasteland == NULL) {
    fprintf(stderr, "Error: Unable to open wasteland directory.\n");
    return EXIT_FAILURE;
  }

  // Initialize the survivor's stash
  DIR *stash = opendir("stash");
  if (stash == NULL) {
    fprintf(stderr, "Error: Unable to open stash directory.\n");
    return EXIT_FAILURE;
  }

  // Scavenge the wasteland for valuable loot
  struct dirent *entry;
  while ((entry = readdir(wasteland)) != NULL) {
    // Skip any hidden files or directories
    if (entry->d_name[0] == '.') {
      continue;
    }

    // Check if the item is already in the stash
    struct stat buf;
    char *path = malloc(strlen("stash/") + strlen(entry->d_name) + 1);
    sprintf(path, "stash/%s", entry->d_name);
    if (stat(path, &buf) == 0) {
      // Item is already in the stash, skip it
      free(path);
      continue;
    }

    // Add the item to the stash
    printf("Found %s in the wasteland! Adding to stash...\n", entry->d_name);
    rename(entry->d_name, path);
    free(path);
  }

  // Close up shop
  closedir(wasteland);
  closedir(stash);

  printf("Synchronization complete. May the wasteland be kind to you.\n");
  return EXIT_SUCCESS;
}