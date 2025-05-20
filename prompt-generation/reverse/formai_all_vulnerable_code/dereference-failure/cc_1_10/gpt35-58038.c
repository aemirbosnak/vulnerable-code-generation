//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_NAME_SIZE 256

char source_dir[MAX_FILE_NAME_SIZE], dest_dir[MAX_FILE_NAME_SIZE];

void copy_file(char *src, char *dst) {
  int src_fd, dst_fd, n;
  char buffer[1024];
  src_fd = open(src, O_RDONLY);
  dst_fd = open(dst, O_WRONLY | O_CREAT, 0666);

  while ((n = read(src_fd, buffer, sizeof(buffer))) > 0) {
    write(dst_fd, buffer, n);
  }
  close(src_fd);
  close(dst_fd);
}

void sync_files(char *src, char *dst) {
  struct dirent *entry;
  struct stat src_stat, dst_stat;
  DIR *dir;
  char src_path[MAX_FILE_NAME_SIZE], dst_path[MAX_FILE_NAME_SIZE];

  dir = opendir(src);
  while ((entry = readdir(dir)) != NULL) {
    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
      continue;

    sprintf(src_path, "%s/%s", src, entry->d_name);
    sprintf(dst_path, "%s/%s", dst, entry->d_name);

    if (stat(src_path, &src_stat) == -1) {
      perror(src_path);
      continue;
    }
    if (S_ISDIR(src_stat.st_mode)) {
      if (stat(dst_path, &dst_stat) == -1) {
        mkdir(dst_path, src_stat.st_mode);
      }
      sync_files(src_path, dst_path);
    } else {
      if (stat(dst_path, &dst_stat) == -1) {
        copy_file(src_path, dst_path);
      } else if (src_stat.st_mtime > dst_stat.st_mtime) {
        printf("Updating file %s\n", dst_path);
        copy_file(src_path, dst_path);
      }
    }
  }
  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
    exit(1);
  }

  strcpy(source_dir, argv[1]);
  strcpy(dest_dir, argv[2]);

  sync_files(source_dir, dest_dir);

  return 0;
}