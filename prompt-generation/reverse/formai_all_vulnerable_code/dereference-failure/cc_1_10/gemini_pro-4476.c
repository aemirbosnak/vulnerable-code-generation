//GEMINI-pro DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function to generate a random string of length n
char *generate_random_string(int n) {
  char *str = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    str[i] = 'a' + rand() % 26;
  }
  str[n] = '\0';
  return str;
}

// A function to write a random string to a file
void write_random_string_to_file(char *filename, int n) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    return;
  }

  char *str = generate_random_string(n);
  fprintf(file, "%s", str);
  free(str);

  fclose(file);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random number of strings to write to the file
  int num_strings = rand() % 100 + 1;

  // Generate a random length for each string
  int *lengths = malloc(num_strings * sizeof(int));
  for (int i = 0; i < num_strings; i++) {
    lengths[i] = rand() % 100 + 1;
  }

  // Write the random strings to the file
  for (int i = 0; i < num_strings; i++) {
    char filename[20];
    sprintf(filename, "file%d.txt", i);
    write_random_string_to_file(filename, lengths[i]);
  }

  free(lengths);

  return 0;
}