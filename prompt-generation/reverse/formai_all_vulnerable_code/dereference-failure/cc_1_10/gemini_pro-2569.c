//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static const char *words_ = "Words";
static const char *chars_ = "Chars";
static const char *lines_ = "Lines";
static const char *bytes_ = "Bytes";
#define COUNT_MAX 10

typedef struct {
  size_t words;
  size_t chars;
  size_t lines;
  size_t bytes;
} count_t;

typedef struct {
  char *path;
  count_t *count;
} job_t;

static count_t sum_counts(count_t *a, count_t *b) {
  count_t r;
  r.words = a->words + b->words;
  r.chars = a->chars + b->chars;
  r.lines = a->lines + b->lines;
  r.bytes = a->bytes + b->bytes;
  return r;
}

static void print_count(const char *type, count_t *count) {
  switch (type[0]) {
    case 'w':
      printf("%zu %s\n", count->words, words_);
      break;
    case 'c':
      printf("%zu %s\n", count->chars, chars_);
      break;
    case 'l':
      printf("%zu %s\n", count->lines, lines_);
      break;
    case 'b':
      printf("%zu %s\n", count->bytes, bytes_);
      break;
    default:
      break;
  }
}

static void print_counts(count_t *count) {
  print_count("words", count);
  print_count("chars", count);
  print_count("lines", count);
  print_count("bytes", count);
}

static void count_file(job_t *job) {
  count_t *count = job->count;
  FILE *fp = fopen(job->path, "r");
  if (!fp) {
    return;
  }

  int c;
  int wc = 0;
  int lc = 0;
  while ((c = getc(fp)) != EOF) {
    if (!isspace(c)) {
      wc++;
    }
    if (c == '\n') {
      lc++;
    }
    count->chars++;
    count->bytes++;
  }

  count->words = wc;
  count->lines = lc;

  fclose(fp);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <files>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int jobs_count = argc - 1;
  job_t *jobs = malloc(sizeof(job_t) * jobs_count);
  count_t *counts = malloc(sizeof(count_t) * jobs_count);
  for (int i = 1; i < argc; i++) {
    jobs[i - 1].path = argv[i];
    jobs[i - 1].count = &counts[i - 1];
  }

  for (int i = 0; i < jobs_count; i++) {
    count_file(&jobs[i]);
  }

  count_t total_count = {0};
  for (int i = 0; i < jobs_count; i++) {
    total_count = sum_counts(&total_count, &counts[i]);
  }

  print_counts(&total_count);

  free(jobs);
  free(counts);

  return EXIT_SUCCESS;
}