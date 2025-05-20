//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CHAR 50
#define MAX_PASS 20

char generate_char() {
  char c;
  int r = rand() % 94;
  c = (char)(r + 33);
  return c;
}

void generate_password(char* password, int length) {
  srand(time(0));
  for(int i = 0; i < length; i++)
    password[i] = generate_char();
  password[length] = '\0';
}

int is_valid(char c) {
  if(c >= 33 && c <= 47)
    return 1;
  if(c >= 58 && c <= 64)
    return 1;
  if(c >= 91 && c <= 96)
    return 1;
  if(c >= 123 && c <= 126)
    return 1;
  return 0;
}

void insert_numbers(char* password, int num_digits) {
  int i, r;
  for(i = 0; i < num_digits; ) {
    r = rand() % MAX_PASS;
    if(is_valid(password[r])) {
      password[r] = rand() % 10 + '0';
      i++;
    }
  }
}

void insert_symbols(char* password, int num_symbols) {
  int i, r;
  for(i = 0; i < num_symbols;) {
    r = rand() % MAX_PASS;
    if(is_valid(password[r])) {
      password[r] = generate_char();
      i++;
    }
  }
}

void encrypt_password(char* password) {
  int r = rand() % MAX_CHAR;
  char temp[MAX_PASS];
  strcpy(temp, password);
  for(int i = 0; i < strlen(password); i++) {
    password[(i + r) % strlen(password)] = temp[i];
  }
  password[strlen(password)] = '\0';
}

int main() {
  char password[MAX_PASS];
  int pass_length, num_digits, num_symbols;
  printf("Enter the length of the password: ");
  scanf("%d", &pass_length);
  printf("Enter the number of digits to be inserted: ");
  scanf("%d", &num_digits);
  printf("Enter the number of symbols to be inserted: ");
  scanf("%d", &num_symbols);
  generate_password(password, pass_length);
  insert_numbers(password, num_digits);
  insert_symbols(password, num_symbols);
  encrypt_password(password);
  printf("Your secure password is: %s\n", password);
  return 0;
}