//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A mighty castle holds the structure of the kingdom's scrolls
#define MAX_SCROLL_SIZE 1024

// A token to represent the result known as the checksum
unsigned long calculate_checksum(const char *scroll) {
    unsigned long checksum = 0;
    for (size_t i = 0; i < strlen(scroll); i++) {
        checksum += (unsigned char)scroll[i]; // Adding the power of each character's might
    }
    return checksum;
}

// A hero noble enough to seek and decipher the scrolls
void seek_and_read_scroll(const char *filename) {
    FILE *scroll_file = fopen(filename, "r");
    if (scroll_file == NULL) {
        printf("Alas! The scroll of '%s' could not be found in the castle's treasury!\n", filename);
        return;
    }

    char scroll[MAX_SCROLL_SIZE];
    fread(scroll, sizeof(char), MAX_SCROLL_SIZE, scroll_file);
    fclose(scroll_file);

    // Declare the valor of the checksum
    unsigned long checksum = calculate_checksum(scroll);
    printf("The mighty checksum of '%s' is: %lu\n", filename, checksum);
}

// A noble function to foretell the future by creating a new scroll
void create_new_scroll(const char *filename, const char *content) {
    FILE *new_scroll = fopen(filename, "w");
    if (new_scroll == NULL) {
        printf("Alas! The creation of the scroll '%s' has met with misfortune!\n", filename);
        return;
    }

    fprintf(new_scroll, "%s", content);
    fclose(new_scroll);
    
    printf("The scroll '%s' hath been inscribed with noble content.\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hark! Thou must provide the name of the scroll to seek!\n");
        return 1; // A warning to the unprepared
    }

    if (strcmp(argv[1], "create") == 0 && argc == 4) {
        create_new_scroll(argv[2], argv[3]);
    } else {
        seek_and_read_scroll(argv[1]);
    }

    return 0; // The hero returns after performing the noble deed
}