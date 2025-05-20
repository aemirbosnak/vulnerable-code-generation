//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  F2C,
  C2F,
} ConvertDir;

struct ConvArgs {
  char *from;
  char *to;
  char *s;
};

int to_f(char *s) {
  return atoi(s) * 9 / 5 + 32;
}

int to_c(char *s) {
  return (atoi(s) - 32) * 5 / 9;
}

int process(struct ConvArgs *args) {
  int v;
  char buf[10];
  switch (*args->from) {
  case 'f':
    v = to_c(args->s);
    sprintf(buf, "%dC", v);
    printf("%s\n", buf);
    break;
  case 'c':
    v = to_f(args->s);
    sprintf(buf, "%dF", v);
    printf("%s\n", buf);
    break;
  default:
    printf("Invalid input\n");
    exit(1);
  }
  return 0;
}

void usage(char *prog_name) {
  printf("Usage: %s <from> <to> <value>\n", prog_name);
  printf("Example: %s f c 32\n", prog_name);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    usage(argv[0]);
    exit(1);
  }
  struct ConvArgs args = {
      .from = argv[1],
      .to = argv[2],
      .s = argv[3],
  };
  return process(&args);
}