//GEMINI-pro DATASET v1.0 Category: Password management ; Style: post-apocalyptic
// In the desolate wasteland, where data is currency...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The vault to secure our precious passwords
typedef struct PasswordVault {
  char **accounts;
  char **passwords;
  int num_entries;
} PasswordVault;

// The wasteland's encryption oracle
char *encrypt(char *plaintext) {
  // Replace with your custom encryption algorithm, if it survives the apocalypse
  char *ciphertext = malloc(strlen(plaintext) + 1);
  for (int i = 0; i < strlen(plaintext); i++) {
    ciphertext[i] = plaintext[i] + 1;
  }
  ciphertext[strlen(plaintext)] = '\0';
  return ciphertext;
}

// The wasteland's decryption oracle
char *decrypt(char *ciphertext) {
  // Replace with your custom decryption algorithm, if it survives the apocalypse
  char *plaintext = malloc(strlen(ciphertext) + 1);
  for (int i = 0; i < strlen(ciphertext); i++) {
    plaintext[i] = ciphertext[i] - 1;
  }
  plaintext[strlen(ciphertext)] = '\0';
  return plaintext;
}

// Opens the vault, initializing its secrets
PasswordVault *open_vault() {
  PasswordVault *vault = malloc(sizeof(PasswordVault));
  vault->accounts = malloc(sizeof(char *) * 10);
  vault->passwords = malloc(sizeof(char *) * 10);
  vault->num_entries = 0;
  return vault;
}

// Adds a new secret to the vault
void add_secret(PasswordVault *vault, char *account, char *password) {
  vault->accounts[vault->num_entries] = malloc(strlen(account) + 1);
  strcpy(vault->accounts[vault->num_entries], account);
  char *encrypted_password = encrypt(password);
  vault->passwords[vault->num_entries] = malloc(strlen(encrypted_password) + 1);
  strcpy(vault->passwords[vault->num_entries], encrypted_password);
  free(encrypted_password);
  vault->num_entries++;
}

// Retrieves a secret from the vault
char *get_secret(PasswordVault *vault, char *account) {
  for (int i = 0; i < vault->num_entries; i++) {
    if (strcmp(vault->accounts[i], account) == 0) {
      char *decrypted_password = decrypt(vault->passwords[i]);
      return decrypted_password;
    }
  }
  return NULL;
}

// In the end, the wasteland consumes all...
void close_vault(PasswordVault *vault) {
  for (int i = 0; i < vault->num_entries; i++) {
    free(vault->accounts[i]);
    free(vault->passwords[i]);
  }
  free(vault->accounts);
  free(vault->passwords);
  free(vault);
}

int main() {
  PasswordVault *vault = open_vault();

  // Add a couple of survivors to the vault
  add_secret(vault, "Water Purifier", "H20_filter-123");
  add_secret(vault, "Radiation Suit", "Hazmat-567");

  // Retrieve a secret from the wasteland
  char *water_purifier_password = get_secret(vault, "Water Purifier");
  if (water_purifier_password == NULL) {
    printf("No water for you, wanderer!\n");
  } else {
    printf("Drink up, survivor: %s\n", water_purifier_password);
  }

  // The wasteland claims its due
  close_vault(vault);

  return 0;
}