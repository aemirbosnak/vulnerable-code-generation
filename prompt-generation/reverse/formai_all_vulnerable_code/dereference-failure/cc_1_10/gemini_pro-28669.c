//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
// Amidst the desolate ruins, where remnants of civilization cling to the edge of oblivion, a desperate soul seeks solace in preserving precious memories.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our scavenged encryption key, a relic of a bygone era.
char key[] = "!&_n3p$%13t";

// The key to our sanctuary, where memories find refuge.
char target[1000] = "vault.bin";

// A function to encrypt a single byte, echoing the whispers of a lost code.
char encrypt(char c) {
  return c ^ key[rand() % strlen(key)];
}

// Our journey begins, traversing the treacherous wastelands of files.
int main(int argc, char** argv) {
  if (argc < 2) {
    printf("[radio crackles] Incoming scavenger report, do you copy? Unknown files detected. Awaiting backup instructions.\n");
    return 1;
  }

  // A bunker at the end of the world, where data finds sanctuary.
  FILE* fp = fopen(target, "wb");
  if (!fp) {
    printf("[radio crackles] Distress signal received. Vault door malfunction. Unable to secure memories!\n");
    return 1;
  }

  // For each file in the desolate landscape, we encrypt and store its secrets.
  for (int i = 1; i < argc; i++) {
    // Uncover the secrets hidden within these scavenged files.
    FILE* input = fopen(argv[i], "rb");
    if (!input) {
      printf("[radio crackles] File access denied. Target corrupted or vanished into the void.\n");
      continue;
    }

    // Prepare for transmission, encrypting each byte as it whispers past.
    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    rewind(input);
    char* buffer = malloc(size);
    fread(buffer, 1, size, input);
    fclose(input);

    for (int j = 0; j < size; j++) {
      buffer[j] = encrypt(buffer[j]);
    }

    // Transmit the encrypted data to our sanctuary, preserving it for a future unknown.
    fwrite(buffer, 1, size, fp);
    free(buffer);
  }

  // Mission accomplished, memories secured amidst the chaos.
  fclose(fp);
  printf("[radio crackles] Backup complete. Hope flickers in the darkness.\n");

  return 0;
}