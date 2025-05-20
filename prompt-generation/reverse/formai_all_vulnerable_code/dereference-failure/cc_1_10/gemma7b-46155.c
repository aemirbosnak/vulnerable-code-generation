//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void convert_hex(char **buffer, int *length) {
  int i = 0;
  char tmp[MAX_BUFFER_SIZE];
  char *p = *buffer;
  *length = 0;

  while (p[i] && i < MAX_BUFFER_SIZE) {
    int n = 0;
    char nibble1 = p[i] & 0xf0;
    char nibble2 = p[i] & 0x0f;

    sprintf(tmp, "%x", nibble1);
    n = strlen(tmp);
    if (*length + n > MAX_BUFFER_SIZE) {
      return;
    }
    *buffer = realloc(*buffer, (*length) * sizeof(char) + n);
    memcpy((*buffer) + *length, tmp, n);
    *length += n;

    sprintf(tmp, "%x", nibble2);
    n = strlen(tmp);
    if (*length + n > MAX_BUFFER_SIZE) {
      return;
    }
    *buffer = realloc(*buffer, (*length) * sizeof(char) + n);
    memcpy((*buffer) + *length, tmp, n);
    *length += n;

    i++;
  }

  return;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int length = 0;

  convert_hex(buffer, &length);

  printf("Converted hex: ");
  for (int i = 0; i < length; i++) {
    printf("%x ", buffer[i]);
  }

  printf("\n");

  return 0;
}