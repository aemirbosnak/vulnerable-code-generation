//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_SUSPECTS 5
#define SECRET_MESSAGE_LEN 1024

typedef struct suspect {
  char name[256];
  int age;
  double net_worth;
  struct suspect* next;
} suspect;

int main() {

  suspect* head = NULL;
  suspect* tail = NULL;

  // Create the suspects
  for (int i = 0; i < NUM_SUSPECTS; i++) {
    suspect* new_suspect = malloc(sizeof(suspect));
    new_suspect->name[0] = 'A' + i;
    new_suspect->age = rand() % 100;
    new_suspect->net_worth = rand() % 1000000;
    new_suspect->next = NULL;

    if (head == NULL) {
      head = new_suspect;
      tail = new_suspect;
    } else {
      tail->next = new_suspect;
      tail = new_suspect;
    }
  }

  // Generate a secret message
  char secret_message[SECRET_MESSAGE_LEN];
  for (int i = 0; i < SECRET_MESSAGE_LEN; i++) {
    secret_message[i] = (rand() % 26) + 'a';
  }

  // Encrypt the secret message
  for (suspect* suspect = head; suspect; suspect = suspect->next) {
    for (int i = 0; i < SECRET_MESSAGE_LEN; i++) {
      secret_message[i] ^= suspect->age;
    }
  }

  // Print the encrypted secret message
  for (int i = 0; i < SECRET_MESSAGE_LEN; i++) {
    printf("%c", secret_message[i]);
  }

  return 0;
}