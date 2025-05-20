//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096
#define MAX_PATH_LEN 256

typedef struct {
  char path[MAX_PATH_LEN];
  time_t timestamp;
} FileEntry;

typedef struct {
  FileEntry* files;
  int num_files;
  char* backup_dir;
} BackupSystem;

void add_file_to_backup(BackupSystem* bs, const char* path) {
  if (bs->num_files >= bs->num_files + 1) {
    bs->files = realloc(bs->files, (bs->num_files + 1) * sizeof(FileEntry));
  }

  bs->files[bs->num_files].timestamp = time(NULL);
  strcpy(bs->files[bs->num_files].path, path);
  bs->num_files++;
}

void backup_files(BackupSystem* bs) {
  for (int i = 0; i < bs->num_files; i++) {
    char backup_path[MAX_PATH_LEN];
    snprintf(backup_path, MAX_PATH_LEN, "%s/%s.%ld", bs->backup_dir, bs->files[i].path, bs->files[i].timestamp);

    int fd_in = open(bs->files[i].path, O_RDONLY);
    if (fd_in == -1) {
      perror("open");
      continue;
    }

    int fd_out = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_out == -1) {
      perror("open");
      close(fd_in);
      continue;
    }

    char buf[BUF_SIZE];
    ssize_t nread;
    while ((nread = read(fd_in, buf, BUF_SIZE)) > 0) {
      if (write(fd_out, buf, nread) != nread) {
        perror("write");
        break;
      }
    }

    if (nread == -1) {
      perror("read");
    }

    close(fd_in);
    close(fd_out);
  }
}

int main(int argc, char** argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s backup_dir file1 file2 ...\n", argv[0]);
    return 1;
  }

  BackupSystem bs;
  bs.files = NULL;
  bs.num_files = 0;
  bs.backup_dir = argv[1];

  for (int i = 2; i < argc; i++) {
    add_file_to_backup(&bs, argv[i]);
  }

  backup_files(&bs);

  free(bs.files);

  return 0;
}