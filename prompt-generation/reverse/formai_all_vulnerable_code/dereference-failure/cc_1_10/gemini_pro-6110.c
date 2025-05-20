//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

void copy_file(const char *src, const char *dst) {
  FILE *fin = fopen(src, "rb");
  FILE *fout = fopen(dst, "wb");

  if (fin == NULL || fout == NULL) {
    perror("Error opening files");
    return;
  }

  char buf[BUF_SIZE];
  size_t nread;

  while ((nread = fread(buf, 1, BUF_SIZE, fin)) > 0) {
    fwrite(buf, 1, nread, fout);
  }

  fclose(fin);
  fclose(fout);
}

void delete_file(const char *file) {
  if (remove(file) != 0) {
    perror("Error deleting file");
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
    return 1;
  }

  const char *src_dir = argv[1];
  const char *dst_dir = argv[2];

  DIR *src_dirp = opendir(src_dir);
  if (src_dirp == NULL) {
    perror("Error opening source directory");
    return 1;
  }

  DIR *dst_dirp = opendir(dst_dir);
  if (dst_dirp == NULL) {
    if (mkdir(dst_dir, 0755) != 0) {
      perror("Error creating destination directory");
      return 1;
    }

    dst_dirp = opendir(dst_dir);
    if (dst_dirp == NULL) {
      perror("Error opening destination directory");
      return 1;
    }
  }

  struct dirent *src_ent;
  while ((src_ent = readdir(src_dirp)) != NULL) {
    if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0) {
      continue;
    }

    char src_file[PATH_MAX];
    snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, src_ent->d_name);

    char dst_file[PATH_MAX];
    snprintf(dst_file, sizeof(dst_file), "%s/%s", dst_dir, src_ent->d_name);

    struct stat src_stat;
    if (stat(src_file, &src_stat) != 0) {
      perror("Error getting source file stats");
      continue;
    }

    struct stat dst_stat;
    if (stat(dst_file, &dst_stat) == 0) {
      if (src_stat.st_mtime > dst_stat.st_mtime) {
        copy_file(src_file, dst_file);
      }
    } else {
      copy_file(src_file, dst_file);
    }
  }

  struct dirent *dst_ent;
  while ((dst_ent = readdir(dst_dirp)) != NULL) {
    if (strcmp(dst_ent->d_name, ".") == 0 || strcmp(dst_ent->d_name, "..") == 0) {
      continue;
    }

    char dst_file[PATH_MAX];
    snprintf(dst_file, sizeof(dst_file), "%s/%s", dst_dir, dst_ent->d_name);

    struct stat dst_stat;
    if (stat(dst_file, &dst_stat) != 0) {
      perror("Error getting destination file stats");
      continue;
    }

    int found = 0;
    rewinddir(src_dirp);
    while ((src_ent = readdir(src_dirp)) != NULL) {
      if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0) {
        continue;
      }

      char src_file[PATH_MAX];
      snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, src_ent->d_name);

      struct stat src_stat;
      if (stat(src_file, &src_stat) != 0) {
        perror("Error getting source file stats");
        continue;
      }

      if (src_stat.st_ino == dst_stat.st_ino) {
        found = 1;
        break;
      }
    }

    if (!found) {
      delete_file(dst_file);
    }
  }

  closedir(src_dirp);
  closedir(dst_dirp);

  return 0;
}