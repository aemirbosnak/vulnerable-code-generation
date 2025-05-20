//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

// Our trusty magnifying glass to inspect metadata
typedef struct Metadata {
  time_t created;  // Time of creation, a crucial clue
  time_t modified; // Last modified, a trail to follow
  time_t accessed; // Snooping around, eh Watson?
  uid_t owner;     // The owner's mark, a valuable lead
  gid_t group;     // Group affiliation, a potential network
  mode_t mode;     // Permissions, revealing hidden secrets
  size_t size;     // Size of the file, a clue to its significance
} Metadata;

// Elementary, my dear Watson! Extracting metadata like a master
Metadata* extract_metadata(const char* filename) {
  Metadata* metadata = malloc(sizeof(Metadata));
  struct stat file_info;
  if (stat(filename, &file_info) == -1) {
    perror("Elementary, my dear Watson! Error in extracting metadata");
    return NULL;
  }
  metadata->created = file_info.st_ctime;
  metadata->modified = file_info.st_mtime;
  metadata->accessed = file_info.st_atime;
  metadata->owner = file_info.st_uid;
  metadata->group = file_info.st_gid;
  metadata->mode = file_info.st_mode;
  metadata->size = file_info.st_size;
  return metadata;
}

// The game is afoot, Watson! Printing metadata for analysis
void print_metadata(const char* filename, Metadata* metadata) {
  printf("--------------------Metadata Report--------------------\n");
  printf("Filename: %s\n", filename);
  printf("Created: %s", ctime(&(metadata->created)));
  printf("Modified: %s", ctime(&(metadata->modified)));
  printf("Accessed: %s", ctime(&(metadata->accessed)));
  printf("Owner ID: %u\n", metadata->owner);
  printf("Group ID: %u\n", metadata->group);
  printf("Permissions: %o\n", metadata->mode);
  printf("Size: %zu bytes\n", metadata->size);
  printf("-----------------------------------------------------\n");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Elementary, my dear Watson! Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  Metadata* metadata = extract_metadata(argv[1]);
  if (metadata == NULL) {
    return 1;
  }
  print_metadata(argv[1], metadata);
  free(metadata);
  return 0;
}