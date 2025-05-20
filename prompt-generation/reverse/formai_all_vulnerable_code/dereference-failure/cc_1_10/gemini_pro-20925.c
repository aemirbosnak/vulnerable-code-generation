//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

void usage() {
  printf("Usage: %s [options]\n", "kwang");
  printf("Options:\n");
  printf("  -l <length>\tSpecify the length of the password to generate (default: 16)\n");
  printf("  -u\t\tUse uppercase letters in the password\n");
  printf("  -l\t\tUse lowercase letters in the password\n");
  printf("  -d\t\tUse digits in the password\n");
  printf("  -s\t\tUse symbols in the password\n");
  printf("  -h\t\tDisplay this help message\n");
}

char *generate_password(int length, int use_uppercase, int use_lowercase, int use_digits, int use_symbols) {
  char *password = malloc(length + 1);
  int i;
  char *characters;
  int characters_length;

  // Initialize the characters string based on the options
  characters = malloc(1);
  characters_length = 0;
  if (use_uppercase) {
    characters = realloc(characters, characters_length + 27);
    strcpy(characters + characters_length, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    characters_length += 26;
  }
  if (use_lowercase) {
    characters = realloc(characters, characters_length + 27);
    strcpy(characters + characters_length, "abcdefghijklmnopqrstuvwxyz");
    characters_length += 26;
  }
  if (use_digits) {
    characters = realloc(characters, characters_length + 11);
    strcpy(characters + characters_length, "0123456789");
    characters_length += 10;
  }
  if (use_symbols) {
    characters = realloc(characters, characters_length + 33);
    strcpy(characters + characters_length, "!@#$%^&*()_+=-`~");
    characters_length += 32;
  }

  // Generate the password
  srand(time(NULL));
  for (i = 0; i < length; i++) {
    password[i] = characters[rand() % characters_length];
  }
  password[length] = '\0';

  free(characters);

  return password;
}

int main(int argc, char *argv[]) {
  int length = 16;
  int use_uppercase = 1;
  int use_lowercase = 1;
  int use_digits = 1;
  int use_symbols = 1;
  int i;

  // Parse the command line options
  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-l") == 0) {
      if (i + 1 < argc) {
        length = atoi(argv[i + 1]);
        i++;
      } else {
        usage();
        return EXIT_FAILURE;
      }
    } else if (strcmp(argv[i], "-u") == 0) {
      use_uppercase = 1;
    } else if (strcmp(argv[i], "-l") == 0) {
      use_lowercase = 1;
    } else if (strcmp(argv[i], "-d") == 0) {
      use_digits = 1;
    } else if (strcmp(argv[i], "-s") == 0) {
      use_symbols = 1;
    } else if (strcmp(argv[i], "-h") == 0) {
      usage();
      return EXIT_FAILURE;
    } else {
      usage();
      return EXIT_FAILURE;
    }
  }

  // Generate the password
  char *password = generate_password(length, use_uppercase, use_lowercase, use_digits, use_symbols);

  // Print the password
  printf("%s\n", password);

  // Free the password
  free(password);

  return EXIT_SUCCESS;
}