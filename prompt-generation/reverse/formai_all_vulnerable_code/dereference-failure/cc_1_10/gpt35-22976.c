//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_dir(char *path, int depth, long long *total_size) {
  DIR *dir = opendir(path);

  if (dir == NULL)
    return;

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;

    char new_path[1024];
    snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

    struct stat st;
    if (stat(new_path, &st) == -1)
      continue;

    if (S_ISDIR(st.st_mode)) {
      printf("%*s[DIR] %s\n", depth*2, "", entry->d_name);
      analyze_dir(new_path, depth+1, total_size);
    }
    else {
      printf("%*s[FILE] %s (%lld bytes)\n", depth*2, "", entry->d_name, st.st_size);
      *total_size += st.st_size;
    }
  }

  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "USAGE: %s [path]\n", argv[0]);
    exit(1);
  }

  long long total_size = 0;

  analyze_dir(argv[1], 0, &total_size);

  printf("Total size: %lld bytes\n", total_size);

  return 0;
}