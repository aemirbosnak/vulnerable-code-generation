//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct FileStats {
  char* name;
  int size;
};

int compareFiles(const void* a, const void* b) {
  const struct FileStats* file1 = (const struct FileStats*)a;
  const struct FileStats* file2 = (const struct FileStats*)b;
  return file2->size - file1->size;
}

int main() {
  DIR* dir = opendir(".");
  if (dir == NULL) {
    perror("Error opening current directory");
    return EXIT_FAILURE;
  }

  struct FileStats files[1024];
  int fileCount = 0;

  struct dirent* entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    struct stat fileStat;
    if (lstat(entry->d_name, &fileStat) == -1) {
      perror("Error getting file stats");
      continue;
    }

    files[fileCount].name = strdup(entry->d_name);
    files[fileCount].size = fileStat.st_size;
    fileCount++;
  }

  closedir(dir);

  qsort(files, fileCount, sizeof(struct FileStats), compareFiles);

  printf("\n**A Song of Bytes and Gigabytes**\n");
  for (int i = 0; i < fileCount; i++) {
    float sizeInMB = (float)files[i].size / 1024 / 1024;
    printf("%2d. %20s - %.2f MB\n", i + 1, files[i].name, sizeInMB);
  }

  int totalSize = 0;
  for (int i = 0; i < fileCount; i++) {
    totalSize += files[i].size;
  }

  float totalSizeInGB = (float)totalSize / 1024 / 1024 / 1024;
  printf("\nTotal Disk Space: %.2f GB\n", totalSizeInGB);

  for (int i = 0; i < fileCount; i++) {
    free(files[i].name);
  }

  return EXIT_SUCCESS;
}