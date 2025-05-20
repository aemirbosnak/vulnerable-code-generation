//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 24
#define MAX_INPUT_CHARS 100

char ascii_art[ASCII_HEIGHT*MAX_INPUT_CHARS];

void generate_ascii_art(char* input_text){

    int input_length = strlen(input_text);

    // Define all possible ASCII character rows
    char ascii_rows[95][8] = {
        "  ##   ",
        " ####  ",
        "##  ## ",
        "     ##",
        " ######",
        "##    #",
        " ######",
        "  #####",
        "#     #",
        "#     #",
        "#######",
        "#     #",
        "#######",
        "#######",
        "#     #",
        "#######",
        "#######",
        "#      ",
        "#      ",
        "###### ",
        " ##  ##",
        "  ## ##",
        "   ### ",
        "  ## ##",
        " ##  ##",
        "  #### ",
        "###### ",
        "     ##",
        "    ## ",
        "   ##  ",
        "  ##   ",
        " ##    ",
        "##     ",
        " ######",
        "#     #",
        "      #",
        "     # ",
        "    #  ",
        "   #   ",
        "  #    ",
        "#      ",
        " ######",
        "#     #",
        "      #",
        " ######",
        "      #",
        "#     #",
        " ######",
        "#######",
        "##     ",
        "##     ",
        "##     ",
        "#######",
        "##     ",
        "##     ",
        " ######",
        "##     ",
        "##     ",
        " ######",
        "      #",
        "      #",
        "###### ",
        "##     ",
        "##  ## ",
        " ######",
        "##   ##",
        "##   ##",
        " ######",
        "##   ##",
        "##   ##",
        " ######",
        "#######",
        "#     #",
        "#     #",
        "#     #",
        "#######",
        "#      ",
        "#      ",
        "#      ",
        "#######",
        "##   ##",
        "##   ##",
        " ## ## ",
        "  ###  ",
        " #   # ",
        "#     #",
        "#     #",
        " #   # ",
        "  ###  ",
        " #   # ",
        "#     #",
        "#     #",
        "#     #",
        " #### ",
        "#    #",
        "#",
        " #",
        "  ",
        "#",
        "#",
        "#",
        "#",
        "  #",
        " # ",
        "#  ",
        "## ",
        "# #",
        "#  ",
        "#  ",
        "###",
        " ##",
        " # ",
        "# #",
        "###",
        " # ",
        "  #",
        "   ",
        "#  ",
        "###",
        "#  ",
        "#  ",
        "###",
        "#  ",
        "###",
        " # ",
        "# #",
        "## ",
        "# #",
        "## ",
        "#  ",
        " ##",
        "#  ",
        "# #",
        "## ",
        "# #",
        "###"
    };

    // Loop through each row of ASCII characters 
    for (int i = 0; i < ASCII_HEIGHT; i++) {
        int ascii_index = (int)input_text[i%input_length]-32;
        char* row = ascii_rows[ascii_index];
        strcat(&ascii_art[i*MAX_INPUT_CHARS], row);
    }
}

int main(){

    printf("Please enter your text: ");
    char input_text[MAX_INPUT_CHARS];
    fgets(input_text, MAX_INPUT_CHARS, stdin);

    // Remove newline character from input_text
    input_text[strcspn(input_text, "\n")] = 0;

    // Generate the ASCII art
    generate_ascii_art(input_text);

    // Print the ASCII art
    for (int i = 0; i < ASCII_HEIGHT; i++){
        for (int j = 0; j < ASCII_WIDTH; j++){
            printf("%c", ascii_art[i*MAX_INPUT_CHARS+j]);
        }
        printf("\n");
    }

    return 0;
}