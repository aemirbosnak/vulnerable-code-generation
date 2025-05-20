//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  // Create an array of suspects.
  char **suspects = malloc(sizeof(char *) * 5);
  suspects[0] = "Mr. Bartholomew P. Finch";
  suspects[1] = "Mrs. Amelia F. Jenkins";
  suspects[2] = "Mr. Alfred C. Hardy";
  suspects[3] = "Mr. Sidney L. Green";
  suspects[4] = "Miss Judith H. Sparrow";

  // Create a list of possible motives.
  char **motives = malloc(sizeof(char *) * 3);
  motives[0] = "Jealousy";
  motives[1] = "Revenge";
  motives[2] = "Financial gain";

  // Generate a random conspiracy theory.
  int theory_number = rand() % 3;
  char *theory = malloc(sizeof(char) * 200);

  switch (theory_number)
  {
    case 0:
      strcpy(theory, "Mr. Finch, driven by jealousy, plotted to frame Mr. Hardy for the crime.");
      break;
    case 1:
      strcpy(theory, "Mrs. Jenkins, seeking revenge for a broken marriage, devised a scheme to implicate Mr. Green.");
      break;
    case 2:
      strcpy(theory, "Miss Sparrow, motivated by financial greed, falsely accused Mr. Hardy of the crime.");
      break;
  }

  // Print the conspiracy theory.
  printf("The mystery has been unraveled! The conspiracy theory is:\n\n");
  printf("%s\n", theory);

  // Free the memory allocated for the suspects and motives arrays.
  free(suspects);
  free(motives);

  // Free the memory allocated for the conspiracy theory.
  free(theory);

  return 0;
}