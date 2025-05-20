//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>

#define Kb(x) ((x) * 1024)
#define Mb(x) (Kb(x) * 1024)
#define Gb(x) (Mb(x) * 1024)

typedef struct {
  size_t bytes;
  clock_t start;
} Sample;

Sample samples[1000];
size_t sample_count = 0;

void sigint_handler(int sig) {
  printf("\n");
  for (size_t i = 0; i < sample_count; i++) {
    printf("%4lu: %7zu bytes in %5ld seconds (%.2f MB/s)\n", i + 1, samples[i].bytes, (clock() - samples[i].start) / CLOCKS_PER_SEC, samples[i].bytes / (1024.0 * 1024.0) / ((clock() - samples[i].start) / CLOCKS_PER_SEC));
  }
  exit(0);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interval (seconds)>\n", argv[0]);
    return 1;
  }
  int interval = atoi(argv[1]);
  if (interval <= 0) {
    fprintf(stderr, "Interval must be a positive integer.\n");
    return 1;
  }

  signal(SIGINT, sigint_handler);

  while (1) {
    samples[sample_count].bytes = 0;
    samples[sample_count].start = clock();
    for (size_t i = 0; i < 10000; i++) {
      char *buf = malloc(Mb(1));
      samples[sample_count].bytes += Mb(1);
      if (buf == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
      }
      free(buf);
    }
    sample_count++;
    sleep(interval);
  }

  return 0;
}