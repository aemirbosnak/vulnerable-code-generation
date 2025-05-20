//FormAI DATASET v1.0 Category: Email Client ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFFER_SIZE 512

int main() {
  char input[BUFFER_SIZE];
  char password[BUFFER_SIZE];
  char message[BUFFER_SIZE];
  char encrypted[BUFFER_SIZE];

  printf("Enter email address:");
  fgets(input, BUFFER_SIZE, stdin);
  input[strcspn(input, "\n")] = '\0';

  printf("Enter password:");
  fgets(password, BUFFER_SIZE, stdin);
  password[strcspn(password, "\n")] = '\0';

  printf("Enter message:");
  fgets(message, BUFFER_SIZE, stdin);
  message[strcspn(message, "\n")] = '\0';

  int input_len = strlen(input);
  int password_len = strlen(password);
  int message_len = strlen(message);

  // Encryption
  for (int i = 0; i < message_len; i++) {
    encrypted[i] = (message[i] + password[i % password_len]) % 256;
  }

  // Decryption
  char decrypted[BUFFER_SIZE];
  for (int i = 0; i < message_len; i++) {
    decrypted[i] = (encrypted[i] - password[i % password_len] + 256) % 256;
  }

  printf("\nEmail sent to %s\n", input);
  printf("Encrypted message: ");

  for (int i = 0; i < message_len; i++) {
    printf("%02x", encrypted[i]);
  }

  printf("\nDecrypted message: %s\n", decrypted);

  return 0;
}