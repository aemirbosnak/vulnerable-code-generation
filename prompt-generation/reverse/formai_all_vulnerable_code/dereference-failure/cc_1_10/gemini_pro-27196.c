//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: artistic
// In an ethereal realm where bytes dance,
// Behold, a symphony of encryption's trance.

#include <stdio.h>
#include <stdlib.h>

// Where secrets are veiled, in twilight's embrace,
// A key, a cipher, a cryptic chase.
char key[] = "MysticalGates";
int cipher = 13;

// The chosen file, a canvas for our art,
// Its contents concealed, in code's smart start.
FILE *file;

void encryptFile(char *filename) {
  // Open the file, like a portal to secrets untold,
  // Where the cipher's dance will leave stories to unfold.
  file = fopen(filename, "rb+");
  if (file == NULL) {
    printf("File not found, the encryption dance cannot commence.\n");
    return;
  }

  // Read the file's contents, byte by byte,
  // A stream of data, where secrets might hide.
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);
  unsigned char *buffer = (unsigned char *)malloc(fileSize);
  fread(buffer, fileSize, 1, file);

  // With the key and cipher as our guiding light,
  // We shift each byte, obscuring it from sight.
  for (long i = 0; i < fileSize; i++) {
    buffer[i] = (buffer[i] + cipher) ^ key[i % strlen(key)];
  }

  // Back into the file, the encrypted bytes flow,
  // Secrets hidden, like whispers in the snow.
  fseek(file, 0, SEEK_SET);
  fwrite(buffer, fileSize, 1, file);
  free(buffer);

  // The encryption's dance complete, the file sealed,
  // Its contents concealed, a secret revealed.
  printf("File encrypted successfully, its secrets concealed within.\n");
  fclose(file);
}

int main(int argc, char **argv) {
  // If the key is lost, the dance cannot start,
  // Without the cipher, the secret remains apart.
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  // With the filename given, the journey begins,
  // The file's contents, soon to be twinned.
  encryptFile(argv[1]);

  // As the program ends, its task complete,
  // The file remains encrypted, its secrets discreet.
  return 0;
}