//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 1024

typedef struct {
  char *data;
  size_t size;
  size_t len;
} buffer;

static buffer *buf_new(void) {
  buffer *b = malloc(sizeof(buffer));
  b->data = malloc(CHUNK);
  b->size = CHUNK;
  b->len = 0;
  return b;
}

static void buf_free(buffer *b) {
  free(b->data);
  free(b);
}

static void buf_append(buffer *b, const char *data, size_t len) {
  if (b->len + len > b->size) {
    b->size *= 2;
    b->data = realloc(b->data, b->size);
  }
  memcpy(b->data + b->len, data, len);
  b->len += len;
}

static void buf_print(buffer *b) {
  fwrite(b->data, 1, b->len, stdout);
}

static void parse_xml(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    perror("fopen");
    exit(1);
  }

  buffer *b = buf_new();

  char buf[CHUNK];
  size_t n;
  while ((n = fread(buf, 1, CHUNK, fp)) > 0) {
    buf_append(b, buf, n);
  }

  fclose(fp);

  const char *start = b->data;
  const char *end = b->data + b->len;

  while (start < end) {
    while (start < end && *start != '<') {
      start++;
    }
    if (start < end) {
      buf_print(b);
      putchar('\n');
      start++;
    }
  }

  buf_free(b);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  parse_xml(argv[1]);

  return 0;
}