//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>

int main() {
  /* Introducing our imaginary world */
  printf("Welcome to the land of the unicorns, where rainbows are formed by the wind!\n");

  /* Creating a file for unicorns */
  FILE *myfile = fopen("unicorns.txt", "w");

  /* Writing names of unicorns to the file */
  fprintf(myfile, "Sparkles\n");
  fprintf(myfile, "Rainbow\n");
  fprintf(myfile, "Flutter\n");
  fprintf(myfile, "Glitter\n");

  /* Closing the file */
  fclose(myfile);

  /* Opening the file in read mode */
  myfile = fopen("unicorns.txt", "r");

  /* Reading the names of unicorns line by line */
  printf("\nHere are the unicorns in our land:\n");
  char unicornname[50];
  while(fgets(unicornname, sizeof(unicornname), myfile)) {
    printf("- %s", unicornname);
  }

  /* Closing the file */
  fclose(myfile);

  /* Adding a new unicorn to the file */
  myfile = fopen("unicorns.txt", "a");
  fprintf(myfile, "Twinkle\n");
  fclose(myfile);

  /* Re-opening the file in read mode */
  myfile = fopen("unicorns.txt", "r");

  /* Reading the names of unicorns again */
  printf("\nAfter the birth of Twinkle, the unicorns in our land are now:\n");
  while(fgets(unicornname, sizeof(unicornname), myfile)) {
    printf("- %s", unicornname);
  }

  /* Closing the file */
  fclose(myfile);

  return 0;
}