//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: imaginative
// A Tale of Ones and Zeros: A Binary Converter Odyssey

#include <stdio.h>
#include <stdlib.h>

// The Oracle of Digits, interpreter of the binary realm
int bin_to_dec(char *bin) {
  int n = 0, pow = 1;

  while (*bin) {
    // Decipher the binary oracle's cryptic digits
    n += (*bin - '0') * pow;
    pow *= 2;
    bin++;
  }

  return n;
}

// The Weaver of Codes, transforming numbers into binary whispers
char *dec_to_bin(int n) {
  char *bin = malloc(33); // Allocate a spacious tapestry for the binary code
  int i = 0;

  while (n) {
    // Unravel the numerical enigma, weaving threads of ones and zeros
    bin[i++] = (n % 2) + '0';
    n /= 2;
  }

  bin[i] = '\0'; // Mark the end of the binary tapestry

  return bin;
}

// The Alchemist of Codes, transforming binary into hexadecimal alchemy
char *bin_to_hex(char *bin) {
  char *hex = malloc(17); // A mystical vessel to hold the hexadecimal elixir
  int i, j = 0;

  // Partition the binary stream into groups of four
  for (i = 0; i < strlen(bin); i += 4) {
    char nibble[5];
    strncpy(nibble, bin + i, 4);
    nibble[4] = '\0';

    // Transmute binary bits into hexadecimal digits
    switch (bin_to_dec(nibble)) {
      case 10:
        hex[j++] = 'A';
        break;
      case 11:
        hex[j++] = 'B';
        break;
      case 12:
        hex[j++] = 'C';
        break;
      case 13:
        hex[j++] = 'D';
        break;
      case 14:
        hex[j++] = 'E';
        break;
      case 15:
        hex[j++] = 'F';
        break;
      default:
        hex[j++] = bin_to_dec(nibble) + '0';
        break;
    }
  }

  hex[j] = '\0'; // Seal the hexadecimal elixir

  return hex;
}

int main() {
  // A portal to the realm of binary, where ones and zeros dance
  char *binary = "10101101";

  // Enter the binary labyrinth, decoding its secrets
  int decimal = bin_to_dec(binary);
  printf("Binary (%s): %d (Decimal)\n", binary, decimal);

  // Weave the decimal code into a binary tapestry
  char *new_binary = dec_to_bin(decimal);
  printf("Decimal (%d): %s (Binary)\n", decimal, new_binary);

  // Transmute the binary code into hexadecimal alchemy
  char *hexadecimal = bin_to_hex(binary);
  printf("Binary (%s): %s (Hexadecimal)\n", binary, hexadecimal);

  // Free the memory allocated for the binary and hexadecimal codes
  free(new_binary);
  free(hexadecimal);

  return 0;
}