//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct summary {
  char *text;
  size_t len;
} summary_t;

summary_t *new_summary(const char *text) {
  summary_t *summary = malloc(sizeof(summary_t));
  if (!summary) {
    return NULL;
  }

  summary->text = strdup(text);
  if (!summary->text) {
    free(summary);
    return NULL;
  }

  summary->len = strlen(summary->text);

  return summary;
}

void free_summary(summary_t *summary) {
  free(summary->text);
  free(summary);
}

char *summarize_text(const summary_t *summary) {
  if (!summary) {
    return NULL;
  }

  if (summary->len <= 100) {
    return strdup(summary->text);
  }

  char *result = malloc(101);
  if (!result) {
    return NULL;
  }

  strncpy(result, summary->text, 100);
  result[100] = '\0';

  return result;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <text>\n", argv[0]);
    return EXIT_FAILURE;
  }

  const summary_t *summary = new_summary(argv[1]);
  if (!summary) {
    fprintf(stderr, "Failed to create summary\n");
    return EXIT_FAILURE;
  }

  char *result = summarize_text(summary);
  if (!result) {
    fprintf(stderr, "Failed to summarize text\n");
    return EXIT_FAILURE;
  }

  printf("Summary: %s\n", result);

  free(result);
  free_summary(summary);

  return EXIT_SUCCESS;
}