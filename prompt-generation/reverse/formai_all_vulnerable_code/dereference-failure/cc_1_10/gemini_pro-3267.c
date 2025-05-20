//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
// Power up your password with an electrifying generator!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Unleash the energy within the alphabet!
char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Electrify the digits with their magnetic charm!
char digits[] = "0123456789";

// Summon the power of special characters, like the mighty Gandalf!
char specials[] = "!@#$%^&*()-_=+[]{};:,<.>/?";

// Harness the force of randomness, like a cosmic storm!
void shuffle(char *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    size_t j = rand() % size;
    char temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

// Forge a password of legendary proportions!
char *generatePassword(int length) {

  // Cast a spell and conjure a password, character by character!
  char *password = malloc(length + 1);

  // Invoke the mystical power of the alphabet!
  for (int i = 0; i < length; i++) {
    ssize_t index = rand() % strlen(alphabet);
    password[i] = alphabet[index];
  }

  // Summon the enchanting lure of digits!
  for (int i = 0; i < length; i++) {
    if (rand() % 2 == 0) {
      ssize_t index = rand() % strlen(digits);
      password[i] = digits[index];
    }
  }

  // Unveil the enigmatic presence of special characters!
  for (int i = 0; i < length; i++) {
    if (rand() % 5 == 0) {
      ssize_t index = rand() % strlen(specials);
      password[i] = specials[index];
    }
  }

  // Sprinkle a touch of chaos with a cosmic shuffle!
  shuffle(password, length);

  // Seal the password with a magical terminator!
  password[length] = '\0';

  // Return the password, a testament to your unyielding pursuit of security!
  return password;
}

// Prepare for greatness and ignite the password generator!
int main() {

  // Set the stage for password generation!
  int length;
  printf("Behold, the Password Forge of Destiny!\n");
  printf("Command the length of your desired password: ");
  scanf("%d", &length);

  // Invoke the generator and witness the birth of a password!
  char *password = generatePassword(length);

  // Present the password, a crown jewel of security!
  printf("Behold, your password, forged in the fires of randomness: %s\n", password);

  // Unveil the unseen and reveal the secrets within the password!
  printf("Unveiling the password's essence: ");
  for (int i = 0; i < length; i++) {
    printf("%c", password[i]);
  }
  printf("\n");

  // Release the password from its digital cage!
  free(password);

  return 0;
}