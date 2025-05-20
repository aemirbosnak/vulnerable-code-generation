//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <fcntl.h>

#define MAX_FILE_SIZE 1000000
#define MAX_FILENAME_SIZE 100
#define MAX_BUF_SIZE 2048

typedef struct {
  char filename[MAX_FILENAME_SIZE];
  long int last_modified;
  int num_bytes;
  char *data;
} file_data;

int get_file_data(char *filename, file_data *fd) {
  struct stat sb;
  int fd_file;

  if (stat(filename, &sb) < 0) {
    perror("stat");
    return -1;
  }

  fd_file = open(filename, O_RDONLY);
  if (fd_file < 0) {
    perror("open");
    return -1;
  }

  strcpy(fd->filename, filename);
  fd->last_modified = sb.st_mtim.tv_sec;
  fd->num_bytes = sb.st_size;

  fd->data = malloc(MAX_FILE_SIZE);
  if (fd->data == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
    return -1;
  }

  int num_read = read(fd_file, fd->data, MAX_FILE_SIZE);
  if (num_read < 0) {
    perror("read");
    return -1;
  }

  close(fd_file);

  return 0;
}

int sync_files(char *src_dir, char *dst_dir) {
  DIR *src_d, *dst_d;
  struct dirent *src_ent, *dst_ent;

  file_data src_fd, dst_fd;

  src_d = opendir(src_dir);
  if (src_d == NULL) {
    perror("opendir");
    return -1;
  }

  dst_d = opendir(dst_dir);
  if (dst_d == NULL) {
    perror("opendir");
    return -1;
  }

  while ((src_ent = readdir(src_d)) != NULL) {
    if (src_ent->d_name[0] == '.') continue;

    char src_filename[MAX_FILENAME_SIZE], dst_filename[MAX_FILENAME_SIZE];
    sprintf(src_filename, "%s/%s", src_dir, src_ent->d_name);
    sprintf(dst_filename, "%s/%s", dst_dir, src_ent->d_name);

    if (get_file_data(src_filename, &src_fd) < 0) {
      fprintf(stderr, "Error: could not get file data for %s\n", src_filename);
      continue;
    }

    while ((dst_ent = readdir(dst_d)) != NULL) {
      if (dst_ent->d_name[0] == '.') continue;

      if (strcmp(dst_ent->d_name, src_ent->d_name) == 0) {
        char dst_filename[MAX_FILENAME_SIZE];
        sprintf(dst_filename, "%s/%s", dst_dir, dst_ent->d_name);

        if (get_file_data(dst_filename, &dst_fd) < 0) {
          fprintf(stderr, "Error: could not get file data for %s\n", dst_filename);
          continue;
        }

        if (src_fd.last_modified > dst_fd.last_modified) {
          int fd_dst = open(dst_filename, O_WRONLY);
          if (fd_dst < 0) {
            perror("open");
            continue;
          }

          int num_written = write(fd_dst, src_fd.data, src_fd.num_bytes);
          if (num_written < 0) {
            perror("write");
            continue;
          }

          printf("Copied %d bytes from %s to %s\n", num_written, src_filename, dst_filename);

          close(fd_dst);
        }
      }
    }

    rewinddir(dst_d);
  }

  closedir(src_d);
  closedir(dst_d);

  return 0;
}

int main(int argc, char *argv[]) {
  sync_files(argv[1], argv[2]);
  return 0;
}