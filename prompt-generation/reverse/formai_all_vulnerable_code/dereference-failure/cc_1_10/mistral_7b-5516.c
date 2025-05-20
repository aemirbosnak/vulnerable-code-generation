//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void main(void) {
  int i, j, k, l, m, n;
  char str[100], *p, *q, ch;
  FILE *fp;

  // Randomly seed for srand()
  time_t t;
  t = time(NULL);
  srand(t);

  printf("Welcome to the magical world of C! \n");

  // Generate a random string
  for (i = 0; i < 10; i++) {
    str[i] = rand() % 26 + 'A';
  }
  str[10] = '\0';
  printf("Random String: %s \n", str);

  // Copy the random string to another string
  strcpy(p, str);

  // Reverse the second string using pointers
  for (i = 0, q = p + strlen(p) - 1; i < strlen(p) / 2; i++) {
    ch = p[i];
    p[i] = q[i];
    q[i] = ch;
  }

  printf("Reversed String: %s \n", p);

  // Create a file with the random string
  fp = fopen("random_file.txt", "w");
  fprintf(fp, "%s", str);
  fclose(fp);

  // Check if the file was created
  struct stat st;
  if (stat("random_file.txt", &st) == -1) {
    perror("Error creating file");
    exit(1);
  }

  printf("File Size: %ld bytes \n", st.st_size);

  // Read the file and print its contents
  fp = fopen("random_file.txt", "r");
  fscanf(fp, "%s", str);
  printf("File Contents: %s \n", str);
  fclose(fp);

  // Remove the file
  unlink("random_file.txt");

  // Exit the program
  printf("Thank you for visiting the magical world of C! \n");
  exit(0);
}