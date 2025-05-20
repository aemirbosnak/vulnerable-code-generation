//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
  int fd, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
  char buf[BUFSIZE], *ptr;
  struct stat st;
  unsigned long long int size;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (stat(argv[1], &st) == -1) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  size = st.st_size;

  if ((fd = open(argv[1], O_RDONLY)) == -1) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  while ((i = read(fd, buf, BUFSIZE)) > 0) {
    for (j = 0; j < i; j++) {
      for (k = 0; k < j; k++) {
        for (l = 0; l < k; l++) {
          for (m = 0; m < l; m++) {
            for (n = 0; n < m; n++) {
              for (o = 0; o < n; o++) {
                for (p = 0; p < o; p++) {
                  for (q = 0; q < p; q++) {
                    for (r = 0; r < q; r++) {
                      for (s = 0; s < r; s++) {
                        for (t = 0; t < s; t++) {
                          for (u = 0; u < t; u++) {
                            for (v = 0; v < u; v++) {
                              for (w = 0; w < v; w++) {
                                for (x = 0; x < w; x++) {
                                  for (y = 0; y < x; y++) {
                                    for (z = 0; z < y; z++) {
                                      if (buf[j] == buf[k] && buf[k] == buf[l] && buf[l] == buf[m] && buf[m] == buf[n] && buf[n] == buf[o] && buf[o] == buf[p] && buf[p] == buf[q] && buf[q] == buf[r] && buf[r] == buf[s] && buf[s] == buf[t] && buf[t] == buf[u] && buf[u] == buf[v] && buf[v] == buf[w] && buf[w] == buf[x] && buf[x] == buf[y] && buf[y] == buf[z]) {
                                        printf("Possible virus detected at offset %d\n", j);
                                        break;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  close(fd);

  return EXIT_SUCCESS;
}