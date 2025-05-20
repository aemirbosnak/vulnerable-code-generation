//GEMINI-pro DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define PAGE_SIZE 4096

struct ebook {
  char *data;
  size_t size;
};

struct ebook *ebook_new(const char *filename) {
  struct ebook *book = malloc(sizeof(struct ebook));
  if (!book)
    return NULL;

  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    free(book);
    return NULL;
  }

  struct stat st;
  if (fstat(fd, &st) == -1) {
    close(fd);
    free(book);
    return NULL;
  }

  book->size = st.st_size;
  book->data = mmap(NULL, book->size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (book->data == MAP_FAILED) {
    close(fd);
    free(book);
    return NULL;
  }

  close(fd);
  return book;
}

void ebook_free(struct ebook *book) {
  if (!book)
    return;

  munmap(book->data, book->size);
  free(book);
}

int ebook_read(struct ebook *book, size_t offset, size_t len, char *buf) {
  if (!book || offset + len > book->size)
    return -1;

  memcpy(buf, book->data + offset, len);
  return 0;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <ebook.txt>\n", argv[0]);
    return EXIT_FAILURE;
  }

  struct ebook *book = ebook_new(argv[1]);
  if (!book) {
    fprintf(stderr, "Failed to open ebook\n");
    return EXIT_FAILURE;
  }

  char buf[PAGE_SIZE];
  size_t offset = 0;
  while (offset < book->size) {
    ssize_t n = ebook_read(book, offset, sizeof(buf), buf);
    if (n < 0) {
      fprintf(stderr, "Failed to read ebook\n");
      break;
    }

    fwrite(buf, 1, n, stdout);
    offset += n;
  }

  ebook_free(book);
  return EXIT_SUCCESS;
}