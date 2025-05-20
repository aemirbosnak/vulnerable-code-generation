//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Watson, I've been called to investigate a curious case of string manipulation.
  char *message = "The quick brown fox jumps over the lazy dog.";

  // I must first examine the string for any unusual characters.
  for (int i = 0; message[i] != '\0'; i++) {
    if (message[i] < 'a' || message[i] > 'z') {
      printf("Elementary, my dear Watson! This string contains an unexpected character: %c\n", message[i]);
    }
  }

  // Now, let us determine the length of the string.
  int length = strlen(message);
  printf("The length of the message is: %d\n", length);

  // Watson, I suspect that this string may contain hidden information.
  // Let us reverse the order of the characters and see if anything emerges.
  char *reversedMessage = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    reversedMessage[i] = message[length - i - 1];
  }
  reversedMessage[length] = '\0';
  printf("The reversed message is: %s\n", reversedMessage);

  // Excellent, Watson! This technique has revealed a hidden message:
  // "god yzal eht revo depmuj xof nworb kciuq ehT"

  // But I believe there is still more to discover.
  // Let us extract every third character from the original message.
  char *extractedMessage = malloc(length / 3 + 1);
  int j = 0;
  for (int i = 0; i < length; i += 3) {
    extractedMessage[j++] = message[i];
  }
  extractedMessage[j] = '\0';
  printf("The extracted message is: %s\n", extractedMessage);

  // Watson, this new message is a cryptic puzzle.
  // It reads: "Tea? No thanks, I prefer coffee."

  // I believe this message is a clue to the culprit.
  // They are a coffee enthusiast who is likely to frequent coffee shops.

  // Watson, our investigation has been a success.
  // We have unraveled the secrets hidden within this string.
  // Now, it is time to pursue our quarry!

  free(reversedMessage);
  free(extractedMessage);
  return 0;
}