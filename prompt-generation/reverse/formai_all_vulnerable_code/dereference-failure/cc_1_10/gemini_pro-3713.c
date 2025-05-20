//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet, a tragic love story of memory management

// Romeo, the young lover, seeking Juliet's affection
int *romeo_love(int *juliet) {
  if (!juliet) {
    printf("Alas, my Juliet, I cannot find thee!\n");
    exit(1);
  }
  printf("Oh, my Juliet, my heart beats for thee!\n");
  return juliet;
}

// Juliet, the fair maiden, testing Romeo's devotion
int *juliet_test(int *romeo) {
  if (!romeo) {
    printf("Romeo, where art thou? My heart yearns for thee!\n");
    exit(1);
  }
  printf("Romeo, thou art a true lover, my heart's desire!\n");
  free(romeo);
  return NULL;
}

int main(void) {
  int *romeo = malloc(sizeof(int));
  int *juliet = malloc(sizeof(int));

  *romeo = 1;
  *juliet = 2;

  printf("Prologue:\n");
  printf("Romeo: Oh, how I love thee, Juliet!\n");
  printf("Juliet: But seekest thou my love, Romeo?\n");

  // Romeo expresses his love, but Juliet tests his devotion
  int *romeo_returned = romeo_love(juliet);
  printf("Romeo: I do, my Juliet, with all my heart!\n");
  int *juliet_returned = juliet_test(romeo_returned);

  // Juliet reciprocates Romeo's love, freeing his memory
  if (!juliet_returned) {
    printf("Juliet: Mine heart is thine, Romeo!\n");
  }

  // Epilogue: both Romeo and Juliet are remembered
  printf("Epilogue:\n");
  printf("Narrator: Thus, the tragedy of Romeo and Juliet unfolds, a tale of love and memory.\n");
  return 0;
}