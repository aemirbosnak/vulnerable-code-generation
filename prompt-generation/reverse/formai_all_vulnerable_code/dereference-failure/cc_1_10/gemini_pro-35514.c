//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct hanoi {
  int *tower;
  int size;
};

struct hanoi *create_hanoi(int size) {
  struct hanoi *h = malloc(sizeof(struct hanoi));
  h->size = size;
  h->tower = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    h->tower[i] = i + 1;
  }
  return h;
}

void free_hanoi(struct hanoi *h) {
  free(h->tower);
  free(h);
}

void print_hanoi(struct hanoi *h) {
  for (int i = 0; i < h->size; i++) {
    printf("%d ", h->tower[i]);
  }
  printf("\n");
}

void move_disk(struct hanoi *h, int from, int to) {
  int disk = h->tower[from];
  h->tower[from] = 0;
  h->tower[to] = disk;
}

int main() {
  int size;
  printf("Enter the number of disks: ");
  scanf("%d", &size);
  struct hanoi *h = create_hanoi(size);
  printf("Initial state of the Hanoi tower:\n");
  print_hanoi(h);
  printf("\n");
  int from, to;
  while (1) {
    printf("Enter the source tower (1-%d): ", h->size);
    scanf("%d", &from);
    if (from < 1 || from > h->size) {
      printf("Invalid source tower\n");
      continue;
    }
    from--;
    printf("Enter the destination tower (1-%d): ", h->size);
    scanf("%d", &to);
    if (to < 1 || to > h->size) {
      printf("Invalid destination tower\n");
      continue;
    }
    to--;
    if (h->tower[from] == 0) {
      printf("There is no disk on the source tower\n");
      continue;
    }
    if (h->tower[to] != 0 && h->tower[to] < h->tower[from]) {
      printf("Cannot move a larger disk onto a smaller disk\n");
      continue;
    }
    move_disk(h, from, to);
    printf("New state of the Hanoi tower:\n");
    print_hanoi(h);
    printf("\n");
    int complete = 1;
    for (int i = 0; i < h->size; i++) {
      if (h->tower[i] != h->size - i) {
        complete = 0;
        break;
      }
    }
    if (complete) {
      break;
    }
  }
  free_hanoi(h);
  return 0;
}