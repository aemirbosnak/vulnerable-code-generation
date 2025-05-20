//FormAI DATASET v1.0 Category: QR code reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CODE_LENGTH 100

bool is_qr_code(char* str);
char* read_qr_code();

int main() {
  printf("Welcome to the QR Code Reader\n");

  char* code = read_qr_code();
  if (is_qr_code(code)) {
    printf("Success! QR Code read: %s\n", code);
  } else {
    printf("Invalid QR Code: %s\n", code);
  }

  free(code);

  return 0;
}

bool is_qr_code(char* str) {
  if (strlen(str) >= MAX_CODE_LENGTH) {
    return false;
  }

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != 'Q' && str[i] != 'R') {
      return false;
    }

    if (i % 2 == 0 && str[i] != 'Q') {
      return false;
    }

    if (i % 2 == 1 && str[i] != 'R') {
      return false;
    }
  }

  return true;
}

char* read_qr_code() {
  char* code = (char*)malloc(MAX_CODE_LENGTH * sizeof(char));
  memset(code, 0, MAX_CODE_LENGTH);

  printf("Please enter the QR Code:\n");
  fgets(code, MAX_CODE_LENGTH, stdin);

  // Remove trailing newline character
  code[strcspn(code, "\n")] = '\0';

  return code;
}