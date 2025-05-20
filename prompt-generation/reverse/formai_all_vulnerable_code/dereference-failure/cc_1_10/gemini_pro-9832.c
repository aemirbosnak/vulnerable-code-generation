//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// A fair Verona, where our lovers reside
char *path;

// The Montagues of memory
#define PAGESIZE 4096
unsigned long long int *pages;
unsigned long long int npages;

// The Capulets of memory
#define BLOCKSIZE 512
unsigned long long int *blocks;
unsigned long long int nblocks;

// The tragic tale of disk space
void analyze() {
  FILE *f = fopen(path, "rb");
  if (!f) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  fseek(f, 0, SEEK_END);
  unsigned long long int fsize = ftell(f);
  rewind(f);

  npages = fsize / PAGESIZE + (fsize % PAGESIZE != 0);
  pages = malloc(sizeof(unsigned long long int) * npages);
  if (!pages) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  nblocks = fsize / BLOCKSIZE + (fsize % BLOCKSIZE != 0);
  blocks = malloc(sizeof(unsigned long long int) * nblocks);
  if (!blocks) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  for (unsigned long long int i = 0; i < npages; i++) {
    fread(&pages[i], sizeof(unsigned long long int), 1, f);
  }

  for (unsigned long long int i = 0; i < nblocks; i++) {
    fread(&blocks[i], sizeof(unsigned long long int), 1, f);
  }

  fclose(f);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  path = argv[1];

  analyze();

  // The tragic end
  printf("In fair Verona, where we lay our scene,\n");
  printf("From ancient grudge break to new mutiny,\n");
  printf("Where civil blood makes civil hands unclean.\n");
  printf("\n");
  printf("From forth the fatal loins of these two foes\n");
  printf("A pair of star-cross'd lovers take their life;\n");
  printf("Whose misadventur'd piteous overthrows\n");
  printf("Do with their death bury their parents' strife.\n");
  printf("\n");

  for (unsigned long long int i = 0; i < npages; i++) {
    printf("%llu: %llu\n", i * PAGESIZE, pages[i]);
  }

  for (unsigned long long int i = 0; i < nblocks; i++) {
    printf("%llu: %llu\n", i * BLOCKSIZE, blocks[i]);
  }

  return EXIT_SUCCESS;
}