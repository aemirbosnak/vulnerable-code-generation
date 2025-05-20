//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii_art(char *text, int length);

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int length = strlen(text);

    print_ascii_art(text, length);

    return 0;
}

void print_ascii_art(char *text, int length) {
    FILE *ascii_art_file;
    char *file_name = "ascii_art.txt";

    // Open the ASCII art file for writing
    ascii_art_file = fopen(file_name, "w");

    // Write the ASCII art to the file
    fprintf(ascii_art_file, "        __  ___ ____   ____ ___ ____  _____\n");
    fprintf(ascii_art_file, "       /  |/  // __ \\ / __ `__ \\__ \\|__  /\n");
    fprintf(ascii_art_file, "      / /|_/ // / / // / / / / /__/ / /_ < \n");
    fprintf(ascii_art_file, "     / /  / // /_/ // / / / / / __/___/ / \n");
    fprintf(ascii_art_file, "    /_/  /_/ \\___\\_\\/_/ /_/ /_/ |____/ /_/\n");
    fprintf(ascii_art_file, "\n");
    fprintf(ascii_art_file, "Text: %.*s\n", length, text);
    fprintf(ascii_art_file, "\n");
    fprintf(ascii_art_file, "               ,#####,\n");
    fprintf(ascii_art_file, "           ,,,#####/####**,\n");
    fprintf(ascii_art_file, "        .,%%/(###/(##/(###((##((/%%,.\n");
    fprintf(ascii_art_file, "           .((##((##(###%#####(###. \n");
    fprintf(ascii_art_file, "      /((((((((((#/######/((#####(((((/\n");
    fprintf(ascii_art_file, "   ,((#(#(((((((((((((((###(######/((###,\n");
    fprintf(ascii_art_file, "   (##%&%((((((((((((((((((#######(#((##(#\n");
    fprintf(ascii_art_file, "  ((######(((((((((((((((((((####(#((((#%##\n");
    fprintf(ascii_art_file, "  ((######((((((((((((((((##%#/((((((#%##\n");
    fprintf(ascii_art_file, "   ((%######(((((((((((((%%%#((((((####,\n");
    fprintf(ascii_art_file, "  .,/#((###(((((((((((((##%(((((#####*,.\n");
    fprintf(ascii_art_file, "        .*((((##(((((((((((#((((((/.\n");
    fprintf(ascii_art_file, "              (((((((((((((((((((,\n");
    fprintf(ascii_art_file, "\n");

    // Close the ASCII art file
    fclose(ascii_art_file);

    // Print the ASCII art to the terminal
    system("cat ascii_art.txt");
}