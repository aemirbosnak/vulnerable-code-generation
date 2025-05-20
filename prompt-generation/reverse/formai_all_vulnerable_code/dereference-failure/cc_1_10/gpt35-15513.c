//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char hexTable[] = "0123456789abcdef";

char *int2hex(int value) {
  int index = 0;
  char *hex = malloc(sizeof(char) * 16);
  int i;

  if (value == 0) {
    hex[0] = '0';
    hex[1] = '\0';
    return hex;
  }

  while (value != 0) {
    hex[index] = hexTable[value % 16];
    value = value / 16;
    index++;
  }

  hex[index] = '\0';

  int length = strlen(hex);
  for (i = 0; i < length / 2; i++) {
    char temp = hex[i];
    hex[i] = hex[length - i - 1];
    hex[length - i - 1] = temp;
  }
  
  return hex;
}

int hex2int(char *hex) {
  int value = 0;
  int length = strlen(hex);
  int i;

  for (i = 0; i < length; i++) {
    int integer;
    if (hex[i] >= '0' && hex[i] <= '9') {
      integer = hex[i] - '0';
    } else if (hex[i] >= 'a' && hex[i] <= 'f') {
      integer = hex[i] - 'a' + 10;
    } else if (hex[i] >= 'A' && hex[i] <= 'F') {
      integer = hex[i] - 'A' + 10;
    } else {
      printf("Invalid hexadecimal string.\n");
      exit(1);
    }

    value = value * 16 + integer;
  }

  return value;
}

int main() {
  int inputInt = 65535;
  char *inputHex = "ffff";

  printf("Convert integer %d to hexadecimal: %s\n", inputInt, int2hex(inputInt));
  printf("Convert hexadecimal %s to integer: %d\n", inputHex, hex2int(inputHex));

  return 0;
}