//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// A kaleidoscope of colors to paint our checksums
char *colors[] = {
    "\033[0;31m", // Red
    "\033[0;32m", // Green
    "\033[0;33m", // Yellow
    "\033[0;34m", // Blue
    "\033[0;35m", // Magenta
    "\033[0;36m", // Cyan
    "\033[0;37m", // White
};

// A symphony of notes to harmonize our calculations
const char *notes[] = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};

// Our canvas for painting the checksums
char checksum[100];

// Calculate the checksum of a given string
uint16_t calculate_checksum(char *str) {
    uint16_t sum = 0;
    while (*str) {
        sum += *str++;
    }
    return sum;
}

// Paint the checksum in a vibrant palette
void paint_checksum(uint16_t checksum) {
    int index = checksum % 7;
    strcpy(checksum, colors[index]);
    strcat(checksum, "0x");
    char hex[5];
    sprintf(hex, "%04x", checksum);
    strcat(checksum, hex);
    strcat(checksum, "\033[0m");
}

// Play the checksum as a melodious tune
void play_checksum(uint16_t checksum) {
    int index = checksum % 12;
    printf("%s%s\n", notes[index], checksum);
}

int main() {
    // A tapestry of strings to calculate checksums for
    char *strings[] = {
        "Hello, world!",
        "Lorem ipsum dolor sit amet",
        "1234567890",
        "The quick brown fox jumps over the lazy dog"
    };

    // A canvas for our artistic display
    printf("Checksums:\n");
    for (int i = 0; i < 4; i++) {
        uint16_t checksum = calculate_checksum(strings[i]);
        paint_checksum(checksum);
        play_checksum(checksum);
        printf("\n");
    }

    return 0;
}