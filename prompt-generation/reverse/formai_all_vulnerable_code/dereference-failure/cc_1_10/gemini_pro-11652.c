//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#ifdef WIN32
  #include <windows.h>
#else
  #include <sys/time.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define BUF_SIZE 4096
#define MAX_WORDS 10000

typedef struct {
  char *word;
  int count;
} word_t;

static long entropy = 0;
static int max_entropy = 0;
static int min_entropy = INT_MAX;
static int word_count = 0;
static long total_bits = 0;
static long total_words = 0;
static word_t *words = NULL;

#ifdef WIN32
  LARGE_INTEGER start, stop, frequency;
#else
  struct timeval start, stop;
#endif

static void start_timer() {
  #ifdef WIN32
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
  #else
    gettimeofday(&start, NULL);
  #endif
}

static long stop_timer() {
  #ifdef WIN32
    QueryPerformanceCounter(&stop);
    return (stop.QuadPart - start.QuadPart) * 1000000 / frequency.QuadPart;
  #else
    gettimeofday(&stop, NULL);
    return (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_usec);
  #endif
}

static void add_word(const char *word) {
  int i;

  for (i = 0; i < word_count; i++) {
    if (!strcmp(words[i].word, word)) {
      words[i].count++;
      return;
    }
  }

  if (word_count >= MAX_WORDS) {
    fprintf(stderr, "Error: too many words\n");
    exit(1);
  }

  words[word_count].word = strdup(word);
  words[word_count].count = 1;
  word_count++;
}

static void entropy_bits(int count) {
  long bits;

  if (count == 0) {
    return;
  }

  bits = log2(count) * count;
  total_bits += bits;
  total_words++;
  if (bits > max_entropy) {
    max_entropy = bits;
  }
  if (bits < min_entropy) {
    min_entropy = bits;
  }
  entropy += bits;
}

static void print_results() {
  int i;
  FILE *fp;

  fp = fopen("Shannon-style-word-distribution.txt", "w");
  if (!fp) {
    perror("fopen");
    exit(1);
  }

  fprintf(fp, "Total words: %ld\n", total_words);
  fprintf(fp, "Total bits: %ld\n", total_bits);
  fprintf(fp, "Entropy: %.2f bits/word\n", (double)entropy / total_words);
  fprintf(fp, "Max entropy: %d bits/word\n", max_entropy);
  fprintf(fp, "Min entropy: %d bits/word\n", min_entropy);

  fprintf(fp, "\nWord frequency distribution:\n");
  for (i = 0; i < word_count; i++) {
    fprintf(fp, "%s: %d\n", words[i].word, words[i].count);
  }

  fclose(fp);
}

int main(int argc, char **argv) {
  FILE *fp;
  char buf[BUF_SIZE];
  char *p, *q;
  long elapsed;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  fp = fopen(argv[1], "r");
  if (!fp) {
    perror("fopen");
    exit(1);
  }

  start_timer();

  while (fgets(buf, BUF_SIZE, fp)) {
    for (p = buf; *p; p++) {
      if (isalpha(*p)) {
        q = p + 1;
        while (isalpha(*q)) {
          q++;
        }
        add_word(p);
        p = q - 1;
      }
    }
  }

  fclose(fp);

  elapsed = stop_timer();

  printf("Elapsed time: %.2f seconds\n", (double)elapsed / 1000000);

  print_results();

  return 0;
}