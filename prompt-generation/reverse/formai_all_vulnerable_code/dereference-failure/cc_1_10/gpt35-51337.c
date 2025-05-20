//FormAI DATASET v1.0 Category: QR code reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* function to read QR code from file */
void read_qr(const char *filename) {

  /* open file for reading */
  FILE *file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    exit(1);
  }

  /* get file size */
  struct stat st;
  if (fstat(fileno(file), &st)) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    exit(1);
  }
  size_t size = st.st_size;

  /* allocate buffer for file contents */
  char *buffer = malloc(size + 1);
  if (!buffer) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    exit(1);
  }

  /* read file */
  if (!fread(buffer, size, 1, file)) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    exit(1);
  }

  /* close file */
  fclose(file);

  /* null-terminate buffer */
  buffer[size] = '\0';

  /* extract QR code data */
  const char *start = strstr(buffer, "QR-Code:");
  if (!start) {
    fprintf(stderr, "Error: QR code not found\n");
    exit(1);
  }
  start += strlen("QR-Code:");

  const char *end = strstr(start, "\n");
  if (!end) {
    fprintf(stderr, "Error: end of QR code not found\n");
    exit(1);
  }

  /* null-terminate QR code data */
  char qr_data[128];
  strncpy(qr_data, start, end - start);
  qr_data[end - start] = '\0';

  /* print QR code data */
  printf("%s\n", qr_data);

  /* free buffer */
  free(buffer);
}

int main(int argc, char *argv[]) {

  /* check arguments */
  if (argc != 2) {
    fprintf(stderr, "Usage: %s FILE\n", argv[0]);
    exit(1);
  }

  /* read QR code */
  read_qr(argv[1]);

  return 0;
}