//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

typedef struct disk_usage {
  long long total_size;
  long long used_size;
  long long free_size;
} disk_usage;

disk_usage get_disk_usage(const char *path) {
  disk_usage usage = {0, 0, 0};
  DIR *dir = opendir(path);
  if (dir == NULL) {
    perror("opendir");
    return usage;
  }
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
      continue;
    }
    char full_path[strlen(path) + strlen(entry->d_name) + 2];
    sprintf(full_path, "%s/%s", path, entry->d_name);
    struct stat statbuf;
    if (stat(full_path, &statbuf) == -1) {
      perror("stat");
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      disk_usage sub_usage = get_disk_usage(full_path);
      usage.total_size += sub_usage.total_size;
      usage.used_size += sub_usage.used_size;
      usage.free_size += sub_usage.free_size;
    } else {
      usage.total_size += statbuf.st_size;
      usage.used_size += statbuf.st_size;
    }
  }
  closedir(dir);
  return usage;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }
  disk_usage usage = get_disk_usage(argv[1]);
  printf("Total size: %lld bytes\n", usage.total_size);
  printf("Used size: %lld bytes\n", usage.used_size);
  printf("Free size: %lld bytes\n", usage.free_size);
  return EXIT_SUCCESS;
}