//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the CSV Reader, where we make sense of your jumbled data!\n");
  printf("Please enter the name of the file you wish to read (Don't worry, we won't judge):\n");
  
  char* file_name = malloc(100);
  scanf("%s", file_name);
  
  FILE* fp = fopen(file_name, "r");

  if (fp == NULL) {
    printf("We couldn't find your file. Please try entering the name again.\n");
    return 1;
  }

  printf("Great! We found your file.\n");
  printf("Reading your CSV data:\n");

  char buffer[1024];
  int rows = 0, cols = 0;

  while (fgets(buffer, 1024, fp)) {
    int col_count = 0;
    char* value = strtok(buffer, ",");

    while (value) {
      printf("%s ", value);
      value = strtok(NULL, ",");
      col_count++;
    }

    if (col_count > cols) {
      cols = col_count;
    }

    rows++;
    printf("\n");
  }

  printf("\nTotal rows: %d\n", rows);
  printf("Total columns: %d\n", cols);

  fclose(fp);
  free(file_name);

  printf("Thank you for using our CSV Reader! We hope your data makes more sense now.\n");

  return 0;
}