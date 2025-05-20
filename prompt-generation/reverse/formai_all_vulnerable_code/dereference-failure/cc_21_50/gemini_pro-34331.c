//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  int fd;
  char *buf;
  struct stat st;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  if (stat(argv[1], &st) == -1) {
    perror("stat");
    exit(1);
  }

  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    perror("open");
    exit(1);
  }

  if ((buf = malloc(st.st_size)) == NULL) {
    perror("malloc");
    exit(1);
  }

  if (read(fd, buf, st.st_size) != st.st_size) {
    perror("read");
    exit(1);
  }

  close(fd);

  for (int i = 0; i < st.st_size; i++) {
    if (buf[i] != 'a' && buf[i] != 'b' && buf[i] != 'c' && buf[i] != 'd' && buf[i] != 'e' && buf[i] != 'f' && buf[i] != 'g' && buf[i] != 'h' && buf[i] != 'i' && buf[i] != 'j' && buf[i] != 'k' && buf[i] != 'l' && buf[i] != 'm' && buf[i] != 'n' && buf[i] != 'o' && buf[i] != 'p' && buf[i] != 'q' && buf[i] != 'r' && buf[i] != 's' && buf[i] != 't' && buf[i] != 'u' && buf[i] != 'v' && buf[i] != 'w' && buf[i] != 'x' && buf[i] != 'y' && buf[i] != 'z') {
      printf("Suspicious character detected: %c\n", buf[i]);
    }
  }

  free(buf);

  return 0;
}