//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUFFSIZE 4096

void sync_file(char *src, char *dest) {
  int src_fd, dest_fd;
  struct stat src_stat, dest_stat;

  if (stat(src, &src_stat) == -1) {
    perror("stat");
    return;
  }

  if (stat(dest, &dest_stat) == -1) {
    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
      perror("open");
      return;
    }
  } else {
    if (src_stat.st_mtime <= dest_stat.st_mtime) {
      return;
    }

    dest_fd = open(dest, O_WRONLY | O_TRUNC);
    if (dest_fd == -1) {
      perror("open");
      return;
    }
  }

  src_fd = open(src, O_RDONLY);
  if (src_fd == -1) {
    perror("open");
    return;
  }

  char buff[BUFFSIZE];
  int n;
  while ((n = read(src_fd, buff, BUFFSIZE)) > 0) {
    if (write(dest_fd, buff, n) == -1) {
      perror("write");
      break;
    }
  }

  close(src_fd);
  close(dest_fd);
}

void sync_dir(char *src_dir, char *dest_dir) {
  DIR *src_dirp, *dest_dirp;
  struct dirent *src_dirent, *dest_dirent;

  src_dirp = opendir(src_dir);
  if (src_dirp == NULL) {
    perror("opendir");
    return;
  }

  dest_dirp = opendir(dest_dir);
  if (dest_dirp == NULL) {
    mkdir(dest_dir, 0755);
    dest_dirp = opendir(dest_dir);
    if (dest_dirp == NULL) {
      perror("opendir");
      closedir(src_dirp);
      return;
    }
  }

  while ((src_dirent = readdir(src_dirp)) != NULL) {
    if (strcmp(src_dirent->d_name, ".") == 0 || strcmp(src_dirent->d_name, "..") == 0) {
      continue;
    }

    char src_path[PATH_MAX];
    char dest_path[PATH_MAX];

    snprintf(src_path, PATH_MAX, "%s/%s", src_dir, src_dirent->d_name);
    snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, src_dirent->d_name);

    struct stat src_stat, dest_stat;

    if (stat(src_path, &src_stat) == -1) {
      perror("stat");
      continue;
    }

    if (stat(dest_path, &dest_stat) == -1) {
      if (S_ISDIR(src_stat.st_mode)) {
        mkdir(dest_path, 0755);
        sync_dir(src_path, dest_path);
      } else {
        sync_file(src_path, dest_path);
      }
    } else {
      if (S_ISDIR(src_stat.st_mode)) {
        sync_dir(src_path, dest_path);
      } else if (src_stat.st_mtime > dest_stat.st_mtime) {
        sync_file(src_path, dest_path);
      }
    }
  }

  closedir(src_dirp);
  closedir(dest_dirp);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s src_dir dest_dir\n", argv[0]);
    return 1;
  }

  sync_dir(argv[1], argv[2]);

  return 0;
}