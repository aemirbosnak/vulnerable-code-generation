//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct score {
  int pos;
  int neg;
} score;

void help() {
  printf("Usage: sent [options] <text>\n");
  printf("Options:\n");
  printf("  -h|--help       Display this help message and exit\n");
  printf("  -t|--threshold  Set the threshold for sentiment analysis (default: 0.5)\n");
}

int main(int argc, char *argv[]) {
  double threshold = 0.5;
  if (argc < 2) {
    help();
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      help();
      return 0;
    } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--threshold") == 0) {
      if (i + 1 >= argc) {
        help();
        return 1;
      }
      threshold = atof(argv[i + 1]);
      i++;
    }
  }
  char *text = argv[argc - 1];
  score s;
  s.pos = 0;
  s.neg = 0;
  for (int i = 0; i < strlen(text); i++) {
    char c = text[i];
    if (isalpha(c)) {
      c = tolower(c);
      if (c >= 'a' && c <= 'z') {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
          s.pos++;
        } else {
          s.neg++;
        }
      }
    }
  }
  if ((double)s.pos / (s.pos + s.neg) >= threshold) {
    printf("Positive\n");
  } else {
    printf("Negative\n");
  }
  return 0;
}