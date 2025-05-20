//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

char *ascii_art[] = {
    "                                                                                                                                           ",
    "                                                                                                                           @-                .---.               ",
    "                                                                                                                         .-._:               /:.-. /              ",
    "                                                                                                                         :  : '              /:::-'.-'                ",
    "                                                                                                                         :  : /               '::.-'   _..._             ",
    "                                                                                                                         :  : :               /:.-'..'     `-.          ",
    "                                                                                                                         :   : :              /:.-'    '._     `.        ",
    "                                                                                                                         :   ;  :             /:.-' .-._  : _._  `.       ",
    "                                                                                                                         '   ;  :    .        /:.-' /   `.'-:   `. \       ",
    "                                                                                                                         :  ;   : . :  .     /:.-' /  _;-./\_   `. :       ",
    "                                                                                                                         :  :    :;_;' _---. /:.-'/   .'/  .--.;  :        ",
    "                                                                                                                         '. :  .:    /  .-'-;_:-' |  |  /   .-'-. :        ",
    "                                                                                                                       .-.:  :    :        (o)  | /   (o)   .'         ",
    "                                                                                                                       :    :    :        : :  | |    :..   .-'          ",
    "                                                                                                                       :    '    :     _.-'|_|  :.._.-:     .'            ",
    "                                                                                                                       :        .-:   /   /:..'    ;   \    :              ",
    "                                                                                                                       '    _.-:     ;    '     :   :     :          _   ",
    "                                                                                                                       .'   /:.     /:       :   :     :     _.-' '-.  ",
    "                                                                                                                       :    |:     :        :   :     : :_.-'     \.'  ",
    "                                                                                                                       :    | :   :         :   :    /    (o)     :    ",
    "                                                                                                                       :    : (O) :           :   :   :       .---.      ",
    "                                                                                                                       '.   :(_.-:            :   :  :       /.-.-. \     ",
    "                                                                                                                         '.-'  __...       _....'   :  :       //'-._.'\    ",
    "                                                                                                                           .-'.-'           / _.-'    :  :      /-.-`  _.-'   ",
    "                                                                                                                         :  /          _.-'          :  :     :  /  .-'      "
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    int width = strlen(argv[1]);
    int height = sizeof(ascii_art) / sizeof(ascii_art[0]);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Text is too long or too tall.\n");
        return 1;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}