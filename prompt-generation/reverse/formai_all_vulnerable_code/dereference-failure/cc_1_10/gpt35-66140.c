//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char data[100];
  printf("Please enter metadata: ");
  fgets(data, 100, stdin);

  char* metadata = malloc(strlen(data) * sizeof(char) + 1);
  strcpy(metadata, data);

  printf("Your metadata is: \"%s\"\n", metadata);

  printf("Performing surrealist analysis of metadata...\n");

  int num_characters = strlen(metadata);
  int num_words = 0;
  int num_vowels = 0;
  int num_consonants = 0;

  char vowels[] = "aeiouAEIOU";
  char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

  for (int i = 0; i < num_characters; i++) {
    char character = metadata[i];

    if (character == ' ') {
      num_words++;
    } else if (strchr(vowels, character) != NULL) {
      num_vowels++;
    } else if (strchr(consonants, character) != NULL) {
      num_consonants++;
    }
  }

  num_words++;

  printf("Number of words: %d\n", num_words);
  printf("Number of vowels: %d\n", num_vowels);
  printf("Number of consonants: %d\n", num_consonants);

  printf("Creating surreal metadata visualization...\n");

  for (int i = 0; i < num_words; i++) {
    printf("\n");
    for (int j = 0; j < num_consonants; j++) {
      printf("!");
    }
    printf(" ");
    for (int j = 0; j < num_vowels; j++) {
      printf("*");
    }
    printf(" ");
    for (int j = 0; j < num_consonants; j++) {
      printf("?");
    }
    printf("\n");
  }

  printf("\n");

  free(metadata);

  return 0;
}