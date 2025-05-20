//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <assert.h>
#include <math.h>

#define CHUNK_SIZE 1024

typedef struct {
  int fd;
  char *buf;
  size_t buf_size;
  size_t buf_pos;
  size_t file_size;
  int eof;
} file_t;

void init_file(file_t *file, const char *path) {
  file->fd = open(path, O_RDONLY);
  if (file->fd == -1) {
    err(1, "open");
  }
  struct stat statbuf;
  if (fstat(file->fd, &statbuf) == -1) {
    err(1, "fstat");
  }
  file->file_size = statbuf.st_size;
  file->buf = malloc(CHUNK_SIZE);
  if (file->buf == NULL) {
    err(1, "malloc");
  }
  file->buf_size = CHUNK_SIZE;
  file->buf_pos = 0;
  file->eof = 0;
}

void read_file(file_t *file) {
  if (file->eof) {
    return;
  }
  ssize_t n = read(file->fd, file->buf + file->buf_pos, file->buf_size - file->buf_pos);
  if (n == -1) {
    err(1, "read");
  } else if (n == 0) {
    file->eof = 1;
    return;
  }
  file->buf_pos += n;
  if (file->buf_pos == file->buf_size) {
    file->buf = realloc(file->buf, file->buf_size * 2);
    if (file->buf == NULL) {
      err(1, "realloc");
    }
    file->buf_size *= 2;
  }
}

int get_bit(file_t *file) {
  while (file->buf_pos >= file->file_size) {
    read_file(file);
  }
  while (file->buf_pos % 8 != 0) {
    file->buf_pos++;
  }
  int bit = (file->buf[file->buf_pos / 8] >> (7 - (file->buf_pos % 8))) & 1;
  file->buf_pos++;
  return bit;
}

void close_file(file_t *file) {
  close(file->fd);
  free(file->buf);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s <file>\n", argv[0]);
    return 1;
  }
  file_t file;
  init_file(&file, argv[1]);
  for (size_t i = 0; i < file.file_size * 8; i++) {
    printf("%d", get_bit(&file));
  }
  close_file(&file);
  return 0;
}