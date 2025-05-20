//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void forsaken_knight_synchronize(char *path1, char *path2) {
  DIR *dir1, *dir2;
  struct dirent *ent1, *ent2;
  struct stat stat1, stat2;

  // Open directories
  dir1 = opendir(path1);
  dir2 = opendir(path2);
  if (!dir1 || !dir2) {
    printf("Fie! I cannot cross into these dark realms: %s or %s\n", path1, path2);
    return;
  }

  // Read and compare files
  while ((ent1 = readdir(dir1)) && (ent2 = readdir(dir2))) {
    if (!strcmp(ent1->d_name, ".") || !strcmp(ent1->d_name, "..") || !strcmp(ent2->d_name, ".") || !strcmp(ent2->d_name, ".."))
      continue;

    char path1_full[256], path2_full[256];
    sprintf(path1_full, "%s/%s", path1, ent1->d_name);
    sprintf(path2_full, "%s/%s", path2, ent2->d_name);

    if (stat(path1_full, &stat1) < 0 || stat(path2_full, &stat2) < 0) {
      printf("Hark! I cannot glean the secrets of these files: %s or %s\n", path1_full, path2_full);
      continue;
    }

    // If files are different, copy the newer one to the other directory
    if (stat1.st_mtime != stat2.st_mtime) {
      if (stat1.st_mtime > stat2.st_mtime) {
        printf("Lo! I shall vanquish the ancient version and bring forth the truth: %s -> %s\n", path1_full, path2_full);
        if (copy_file(path1_full, path2_full) < 0)
          printf("Alas! My blade is dull and I cannot transcribe the knowledge: %s\n", path2_full);
      } else {
        printf("Behold! I shall banish the foul copy and restore the original: %s -> %s\n", path2_full, path1_full);
        if (copy_file(path2_full, path1_full) < 0)
          printf("Woe! My shield is shattered and I cannot protect the wisdom: %s\n", path1_full);
      }
    }
  }

  // Close directories
  closedir(dir1);
  closedir(dir2);
}

int copy_file(char *source, char *dest) {
  // Open files
  FILE *src, *dst;
  src = fopen(source, "r");
  dst = fopen(dest, "w");
  if (!src || !dst) {
    printf("Pox! I cannot open these scrolls: %s or %s\n", source, dest);
    return -1;
  }

  // Read and write file contents
  int c;
  while ((c = fgetc(src)) != EOF) {
    fputc(c, dst);
  }

  // Close files
  fclose(src);
  fclose(dst);

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Hark! I am but a simple squire, and I require two paths to fulfil my duty.\n");
    return 1;
  }

  forsaken_knight_synchronize(argv[1], argv[2]);

  return 0;
}