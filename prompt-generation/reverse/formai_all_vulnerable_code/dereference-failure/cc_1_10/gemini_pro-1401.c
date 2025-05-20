//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Holy smokes! Time to scramble some files! Buckle up, kiddos!

// Our trusty encryption key
#define ENCRYPTION_KEY 0x5E

// Function to encrypt a file in one fell swoop
void encrypt_file(char *input_file, char *output_file) {
  // Open input file, ready to slurp up those bytes!
  FILE *input = fopen(input_file, "rb");
  
  if (input == NULL) {
    // Ouch! Couldn't open the input file. Cry me a river!
    printf("Omigawd! I can't find the input file: %s\n", input_file);
    exit(1);
  }

  // Ready the output file, where the magic will happen
  FILE *output = fopen(output_file, "wb");
  
  if (output == NULL) {
    // Oops! Output file won't budge. Time to throw a tantrum!
    printf("Blast! Can't create the output file: %s\n", output_file);
    exit(1);
  }

  // Now for the fun part! Let's go byte by byte and scramble 'em
  int ch;
  while ((ch = fgetc(input)) != EOF) {
    // XOR-ing the byte with our secret key. Watch the bits dance!
    ch ^= ENCRYPTION_KEY;
    fputc(ch, output);
  }

  // Tada! File encrypted, safe and sound. Go celebrate!
  fclose(input);
  fclose(output);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    // Whoops! You forgot to give me the files, buddy. Try again!
    printf("Hey, you didn't tell me what to encrypt! Syntax: %s input_file output_file\n", argv[0]);
    return 1;
  }

  // Let's get this party started! Encrypt the file!
  encrypt_file(argv[1], argv[2]);
  printf("Boom! '%s' is now encrypted as '%s'\n", argv[1], argv[2]);

  return 0;
}