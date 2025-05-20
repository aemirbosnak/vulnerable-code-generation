//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void syncFiles(char file1[], char file2[]);

int main() {
  char file1[30], file2[30];

  printf("Welcome to the Surrealistic C File Synchronizer!\n");
  printf("Please enter the first file name: ");
  scanf("%s", file1);

  printf("Please enter the second file name: ");
  scanf("%s", file2);

  syncFiles(file1, file2);

  printf("File synchronization complete!\n");

  return 0;
}

void syncFiles(char file1[], char file2[]) {
  srand(time(NULL));
  int random = rand() % 10;

  FILE *fp1, *fp2;
  fp1 = fopen(file1, "r");
  fp2 = fopen(file2, "r+");

  if (fp1 == NULL) {
    printf("%s does not exist.\n", file1);
    return;
  }

  if (fp2 == NULL) {
    printf("%s does not exist.\n", file2);
    return;
  }

  char c1 = getc(fp1);
  int count = 1;

  while (c1 != EOF) {
    if (count % random == 0) {
      fprintf(fp2, "%c", c1 - random);
    } else {
      fprintf(fp2, "%c", c1);
    }
    c1 = getc(fp1);
    count++;
  }

  printf("File contents synchronized with a surrealistic twist!\n");

  fclose(fp1);
  fclose(fp2);
}