//GPT-4o-mini DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 7
#define NUM_ASCII 256

// Define ASCII Art Representation for A-Z, a-z, and space
const char *asciiArt[NUM_ASCII] = {
    [65] = "  A  \n A A \nAAAAA\nA   A\nA   A\n",   // A
    [66] = "BBBB \nB   B\nBBBB \nB   B\nBBBB \n",   // B
    [67] = " CCC \nC   C\nC    \nC   C\n CCC \n",   // C
    [68] = "DDDD \nD   D\nD   D\nD   D\nDDDD \n",   // D
    [69] = "EEEEE\nE    \nEEEEE\nE    \nEEEEE\n",   // E
    [70] = "EEEEE\nE    \nEEEEE\nE    \nE    \n",   // F
    [71] = " GGG \nG   G\nG  GG\nG   G\n GGG \n",   // G
    [72] = "H   H\nH   H\nHHHHH\nH   H\nH   H\n",   // H
    [73] = "IIIII\n  I  \n  I  \n  I  \nIIIII\n",   // I
    [74] = "  JJJ\n    J\n    J\nJ   J\n JJJ \n",   // J
    [75] = "K   K\nK  K \nKKK  \nK  K \nK   K\n",   // K
    [76] = "L    \nL    \nL    \nL    \nLLLLL\n",   // L
    [77] = "M     M\nMM   MM\nM M M M\nM     M\nM     M\n", // M
    [78] = "N   N\nNN  N\nN N N\nN  NN\nN   N\n",   // N
    [79] = " OOO \nO   O\nO   O\nO   O\n OOO \n",   // O
    [80] = "PPPP \nP   P\nPPPP \nP    \nP    \n",   // P
    [81] = " QQQ \nQ   Q\nQ   Q\nQ  QQ\n QQQ \n",   // Q
    [82] = "PPPP \nP   P\nPPPP \nP  P \nP   P\n",   // R
    [83] = " SSS \nS   S\n SSS \n    S\n SSS \n",   // S
    [84] = "TTTTT\n  T  \n  T  \n  T  \n  T  \n",   // T
    [85] = "U   U\nU   U\nU   U\nU   U\n UUU \n",   // U
    [86] = "V   V\nV   V\nV   V\n V V \n  V  \n",   // V
    [87] = "W     W\nW     W\nW  W  W\nW W W W\n W   W\n", // W
    [88] = "X   X\n X X \n  X  \n X X \nX   X\n",   // X
    [89] = "Y   Y\n Y Y \n  Y  \n  Y  \n  Y  \n",   // Y
    [90] = "ZZZZZ\n   Z \n  Z  \n Z   \nZZZZZ\n",   // Z
    [32] = "     \n     \n     \n     \n     \n"    // Space
};

// Function to print ASCII art
void printAsciiArt(const char *input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] < 0 || input[i] >= NUM_ASCII) {
            printf("Unsupported character: %c\n", input[i]);
            continue;
        }
        printf("%s", asciiArt[(unsigned char)input[i]]);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert input to uppercase to standardize ASCII art output
    char input[256];
    strncpy(input, argv[1], 255);
    input[255] = '\0';

    for (int i = 0; input[i]; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] -= ('a' - 'A');
        }
    }

    // Print ASCII art of the input string
    printAsciiArt(input);

    return EXIT_SUCCESS;
}