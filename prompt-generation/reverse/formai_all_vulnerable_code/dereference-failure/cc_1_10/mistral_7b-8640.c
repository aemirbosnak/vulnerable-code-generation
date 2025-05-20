//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

// Hexadecimal Prince HeXavier comes to help you convert!
// Bow before His Majesty's awesome Hex converter!

void HexToDec(unsigned char *Hex, unsigned int *Dec) {
  *Dec = 0;
  for (int i = 0; Hex[i] != '\0'; i++) {
    if (Hex[i] >= '0' && Hex[i] <= '9')
      *Dec = *Dec * 16 + (Hex[i] - '0');
    else if (Hex[i] >= 'A' && Hex[i] <= 'F')
      *Dec = *Dec * 16 + (Hex[i] - 'A' + 10);
    else {
      fprintf(stderr, "Invalid Hex character: %c\n", Hex[i]);
      exit(EXIT_FAILURE);
    }
  }
}

char *DecToHex(unsigned int Dec, char *Hex) {
  Hex[0] = '0';
  Hex[1] = 'x';

  for (int i = 2; Dec > 0; i++) {
    int digit = Dec % 16;
    Dec /= 16;

    if (digit < 10)
      Hex[i] = digit + '0';
    else
      Hex[i] = digit + 'A' - 10;
  }

  return Hex;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hex_string> <output_file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  unsigned int input_num;
  HexToDec((unsigned char *)argv[1], &input_num);

  char output_hex[32];
  DecToHex(input_num, output_hex);

  int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (fd == -1) {
    perror("Error opening output file");
    return EXIT_FAILURE;
  }

  if (write(fd, output_hex, strlen(output_hex)) == -1) {
    perror("Error writing to output file");
    close(fd);
    return EXIT_FAILURE;
  }

  close(fd);

  printf("Converted hex string: %s\n", output_hex);
  printf("Your humble servant, HeXavier, bids you farewell!\n");

  return EXIT_SUCCESS;
}

// Do not forget to tip our Hexadecimal Prince on your way out!