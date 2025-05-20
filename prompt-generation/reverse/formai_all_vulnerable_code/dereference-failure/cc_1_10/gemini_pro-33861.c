//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// The plague of bytes
unsigned char plague[] = {
  0x55, 0x48, 0x89, 0xe5, 0x57, 0x56, 0x53, 0x48, 0x83, 0xec, 0x28, 0x48, 0x89, 0x7d, 0xf8, 0x48,
  0x89, 0x75, 0xf0, 0x48, 0x89, 0x55, 0xe8, 0x48, 0x83, 0xc4, 0x20, 0x5b, 0x5e, 0x5f, 0x5d, 0xc3
};

// The holy knights of signatures
char *signatures[] = {
  "\x55\x89\xe5\x83\xec\x28\x89\x7d\xf8\x89\x75\xf0\x89\x55\xe8\x83\xc4\x20\x5b",
  "\x89\xe5\x83\xec\x28\x89\x7d\xf8\x89\x75\xf0\x89\x55\xe8\x83\xc4\x20\x5b",
  "\x55\x89\xe5\x83\xec\x28\x89\x7d\xf8\x89\x75\xf0\x89\x55\xe8\x83\xc4\x20\x5b"
};

// The scroll of detection
void detect_plague(unsigned char *buffer, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < sizeof(signatures) / sizeof(char *); j++) {
      if (memcmp(buffer + i, signatures[j], strlen(signatures[j])) == 0) {
        printf("Plague detected at offset %d!\n", i);
      }
    }
  }
}

// The main quest
int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }

  // Open the file of suspected plague
  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    printf("Could not open file %s\n", argv[1]);
    return 1;
  }

  // Read the file into a buffer
  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  fseek(file, 0, SEEK_SET);
  unsigned char *buffer = malloc(size);
  fread(buffer, 1, size, file);
  fclose(file);

  // Scan the buffer for the plague
  detect_plague(buffer, size);

  // Free the buffer
  free(buffer);

  return 0;
}