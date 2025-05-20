//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGS 100
#define MAX_SIG 100

char *sigs[MAX_SIGS];
int sig_lens[MAX_SIGS];
int num_sigs;

int load_sigs(char *filename) {
  FILE *fp;
  char buf[MAX_SIG + 1];
  int i = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return -1;
  }

  while (fgets(buf, MAX_SIG + 1, fp) != NULL) {
    sigs[i] = malloc(strlen(buf) + 1);
    strcpy(sigs[i], buf);
    sig_lens[i] = strlen(buf);
    i++;
  }

  fclose(fp);

  num_sigs = i;

  return 0;
}

int scan_file(char *filename) {
  FILE *fp;
  char buf[1024];
  int i, j;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    return -1;
  }

  while (fread(buf, 1024, 1, fp) == 1) {
    for (i = 0; i < num_sigs; i++) {
      for (j = 0; j < sig_lens[i]; j++) {
        if (buf[j] != sigs[i][j]) {
          break;
        }
      }

      if (j == sig_lens[i]) {
        fclose(fp);
        return 1;
      }
    }
  }

  fclose(fp);

  return 0;
}

int main(int argc, char *argv[]) {
  int i;

  if (argc < 3) {
    printf("Usage: %s <signature file> <files to scan>\n", argv[0]);
    return 1;
  }

  if (load_sigs(argv[1]) != 0) {
    printf("Error loading signatures\n");
    return 1;
  }

  for (i = 2; i < argc; i++) {
    if (scan_file(argv[i]) == 1) {
      printf("File %s is infected\n", argv[i]);
    } else {
      printf("File %s is clean\n", argv[i]);
    }
  }

  return 0;
}