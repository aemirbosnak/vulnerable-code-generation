//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRATITUDE_STRING "Gratitude is the memory of the heart."
#define MAX_LENGTH 1024

void print_gratitude(void);
void print_message(const char *message);

int main(void) {
  char *gratitude = malloc(strlen(GRATITUDE_STRING) + 1);
  char *message = malloc(MAX_LENGTH + 1);

  printf("Welcome to the Gratitude Program!\n");

  // Print the gratitude message with some flair
  print_gratitude();

  printf("Now, let's hear your message of gratitude:\n");
  fgets(message, MAX_LENGTH, stdin);

  // Print the message with some extra formatting
  print_message(message);

  free(gratitude);
  free(message);

  return 0;
}

void print_gratitude(void) {
  printf("Gratitude is the memory of the heart. Let us remember "
         "the kindness and love that surrounds us every day. "
         "May our hearts be filled with gratitude and our lives "
         "be filled with joy and purpose.\n");

  // Print some inspirational quotes
  printf("Here are some quotes to inspire your gratitude:\n");
  printf("  'Gratitude unlocks the fullness of life.' - "
          "Melody Beattie\n");
  printf("  'Gratitude is not only the greatest of virtues, "
          "but the parent of all the others.' - "
          "Marcus Tullius Cicero\n");
  printf("  'Gratitude turns negatives into positives.' - "
          "Bernard Berenson\n");
}

void print_message(const char *message) {
  printf("Your message of gratitude: %s\n", message);

  // Add some formatting to make it look pretty
  printf("  %s\n", message);
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] == ' ' || message[i] == '\n') {
      printf("  %c", message[i]);
    } else {
      printf("  %c%s", message[i], message[i + 1] == '\0' ? "" : " ");
      i++;
    }
  }
  printf("\n");
}