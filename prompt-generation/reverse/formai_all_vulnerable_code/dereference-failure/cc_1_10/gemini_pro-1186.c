//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

unsigned char key[KEY_SIZE] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F};

void encrypt_file(char *input_file, char *output_file)
{
  FILE *in, *out;
  unsigned char buffer[1024];
  unsigned char encrypted_buffer[1024];
  int bytes_read, i;

  in = fopen(input_file, "rb");
  if (in == NULL)
  {
    fprintf(stderr, "Error opening input file: %s\n", input_file);
    exit(1);
  }

  out = fopen(output_file, "wb");
  if (out == NULL)
  {
    fprintf(stderr, "Error opening output file: %s\n", output_file);
    exit(1);
  }

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0)
  {
    for (i = 0; i < bytes_read; i++)
    {
      encrypted_buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
    }

    fwrite(encrypted_buffer, 1, bytes_read, out);
  }

  fclose(in);
  fclose(out);
}

void decrypt_file(char *input_file, char *output_file)
{
  FILE *in, *out;
  unsigned char buffer[1024];
  unsigned char decrypted_buffer[1024];
  int bytes_read, i;

  in = fopen(input_file, "rb");
  if (in == NULL)
  {
    fprintf(stderr, "Error opening input file: %s\n", input_file);
    exit(1);
  }

  out = fopen(output_file, "wb");
  if (out == NULL)
  {
    fprintf(stderr, "Error opening output file: %s\n", output_file);
    exit(1);
  }

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), in)) > 0)
  {
    for (i = 0; i < bytes_read; i++)
    {
      decrypted_buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
    }

    fwrite(decrypted_buffer, 1, bytes_read, out);
  }

  fclose(in);
  fclose(out);
}

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    fprintf(stderr, "Usage: %s <mode> <input_file> <output_file> <key>\n", argv[0]);
    fprintf(stderr, "Mode can be either 'encrypt' or 'decrypt'\n");
    fprintf(stderr, "Key must be a 16-byte hexadecimal string\n");
    exit(1);
  }

  if (strcmp(argv[1], "encrypt") == 0)
  {
    int i;

    for (i = 0; i < KEY_SIZE; i++)
    {
      key[i] = (unsigned char)strtol(argv[4] + 2 * i, NULL, 16);
    }

    encrypt_file(argv[2], argv[3]);
  }
  else if (strcmp(argv[1], "decrypt") == 0)
  {
    int i;

    for (i = 0; i < KEY_SIZE; i++)
    {
      key[i] = (unsigned char)strtol(argv[4] + 2 * i, NULL, 16);
    }

    decrypt_file(argv[2], argv[3]);
  }

  return 0;
}