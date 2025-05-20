//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 4096

typedef struct {
  int fd;
  char *buf;
  size_t buf_len;
  size_t buf_pos;
} file_t;

typedef struct {
  file_t *file1;
  file_t *file2;
  int pipe[2];
} sync_t;

void file_init(file_t *file, const char *path) {
  file->fd = open(path, O_RDONLY);
  if (file->fd == -1) {
    perror("open");
    exit(1);
  }
  file->buf = malloc(BUF_SIZE);
  if (file->buf == NULL) {
    perror("malloc");
    exit(1);
  }
  file->buf_len = 0;
  file->buf_pos = 0;
}

void file_deinit(file_t *file) {
  close(file->fd);
  free(file->buf);
}

int file_read(file_t *file) {
  if (file->buf_pos == file->buf_len) {
    file->buf_len = read(file->fd, file->buf, BUF_SIZE);
    if (file->buf_len == 0) {
      return 0;
    }
    file->buf_pos = 0;
  }
  return file->buf[file->buf_pos++];
}

void file_write(file_t *file, int c) {
  if (file->buf_pos == BUF_SIZE) {
    write(file->fd, file->buf, file->buf_len);
    file->buf_pos = 0;
  }
  file->buf[file->buf_pos++] = c;
}

void sync_init(sync_t *sync, file_t *file1, file_t *file2) {
  sync->file1 = file1;
  sync->file2 = file2;
  if (pipe(sync->pipe) == -1) {
    perror("pipe");
    exit(1);
  }
}

void sync_deinit(sync_t *sync) {
  close(sync->pipe[0]);
  close(sync->pipe[1]);
}

void sync_thread(sync_t *sync) {
  int c;
  while ((c = file_read(sync->file1)) != 0) {
    file_write(sync->file2, c);
  }
  close(sync->pipe[1]);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "usage: %s file1 file2\n", argv[0]);
    exit(1);
  }
  file_t file1, file2;
  file_init(&file1, argv[1]);
  file_init(&file2, argv[2]);
  sync_t sync;
  sync_init(&sync, &file1, &file2);
  pid_t pid = fork();
  if (pid == 0) {
    sync_thread(&sync);
  } else {
    close(sync.pipe[0]);
    waitpid(pid, NULL, 0);
    sync_deinit(&sync);
    file_deinit(&file1);
    file_deinit(&file2);
  }
  return 0;
}