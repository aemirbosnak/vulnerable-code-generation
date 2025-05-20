//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct BabblingOracle {
  char oracle_message[MAX_BUFFER_SIZE];
  int oracle_length;
  int (*say_fortune)(struct BabblingOracle *);
} BabblingOracle;

BabblingOracle *create_oracle() {
  BabblingOracle *oracle = malloc(sizeof(BabblingOracle));
  oracle->oracle_length = 0;
  oracle->say_fortune = NULL;
  return oracle;
}

void append_oracle_message(BabblingOracle *oracle, char *message) {
  int message_length = strlen(message) + 1;
  if (oracle->oracle_length + message_length > MAX_BUFFER_SIZE) {
    return;
  }

  memcpy(oracle->oracle_message + oracle->oracle_length, message, message_length);
  oracle->oracle_length += message_length;
}

int fortune_of_the_cat(BabblingOracle *oracle) {
  if (oracle->oracle_length == 0) {
    return -1;
  }

  char *message = oracle->oracle_message;
  int i = 0;
  for (i = 0; message[i] != '\0'; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      return i;
    }
  }

  return -1;
}

int main() {
  BabblingOracle *oracle = create_oracle();
  append_oracle_message(oracle, "The cat sleeps on a moonstone, and dreams of purrs.");
  append_oracle_message(oracle, "The wind whispers secrets through the trees.");
  append_oracle_message(oracle, "The stars dance in the sky, a celestial ballet.");

  int fortune = fortune_of_the_cat(oracle);
  if (fortune != -1) {
    printf("Your fortune is: %c", oracle->oracle_message[fortune]);
  } else {
    printf("There is no fortune for you.");
  }

  return 0;
}