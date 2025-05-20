//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 20

// ASCII art alphabet
const char* alphabet[26][HEIGHT] = {
    {
        " _____ ",
        "|   __|",
        "|__   |",
        "|_____|",
        "       "
    },
    {
        "  ___  ",
        " / _ \\ ",
        "| | | |",
        "| |_| |",
        " \\___/ "
    },
    {
        " ____  ",
        "|___ \\ ",
        "  __) |",
        " / __/ ",
        "|_____|"
    },
    {
        " _____ ",
        "|___ / ",
        "  |_ \\ ",
        " ___) |",
        "|____/ "
    },
    {
        " _  _  ",
        "| || | ",
        "| || |_",
        "|__   _|",
        "   |_| "
    },
    {
        " _____ ",
        "| ____|",
        "| |__  ",
        "|___ \\ ",
        "|____/ "
    },
    {
        "  ___  ",
        " / _ \\ ",
        "| (_) |",
        " \\__, |",
        "   /_/ "
    },
    {
        " _  __",
        "| |/ /",
        "| ' / ",
        "| . \\ ",
        "|_|\\_\\"
    },
    {
        "  ___  ",
        " / _ \\ ",
        "| (_) |",
        " \\__, |",
        "    /_/"
    },
    {
        "  ___  ",
        " / _ \\ ",
        "| (_) |",
        " \\__, |",
        "    / /"
    },
    {
        "       ",
        "       ",
        "       ",
        "       ",
        "       "
    },
    {
        "      ",
        "|____|",
        "|    |",
        "|    |",
        "|____|"
    },
    {
        "   __|",
        "  (   ",
        "  /   ",
        " /    ",
        "/___| "
    },
    {
        "|___ /",
        "  |_ \\",
        " ___) |",
        "|__ < ",
        "|___/ "
    },
    {
        "  __  ",
        " /  \\ ",
        "| () |",
        " \\__/ ",
        "      "
    },
    {
        "|___ \\ ",
        "  __) |",
        " |__ < ",
        " ___) |",
        "|____/ "
    },
    {
        "  ___  ",
        " / _ \\ ",
        "| | | |",
        "| |_| |",
        " \\__\\_\\"
    },
    {
        " ____  ",
        "| ___| ",
        "|___ \\ ",
        " ___) |",
        "|____/ "
    },
    {
        "  __ ",
        " / / ",
        "| |  ",
        "| |  ",
        "| |  "
    },
    {
        "    __",
        "   / /",
        "  / / ",
        "  > <  ",
        " /_/  "
    },
    {
        " _   _ ",
        "| | | |",
        "| |_| |",
        "|_  _|",
        "  |_| "
    },
    {
        " _    _ ",
        "| |  | |",
        "| |  | |",
        "| |/\\| |",
        "\\_/  \\_/ "
    },
    {
        " _   _ ",
        "| | / /",
        "| |/ / ",
        "|   <  ",
        "|_|\\_\\"
    },
    {
        " _     __",
        "| |   / /",
        "| |__/ / ",
        "|  __/  ",
        "|_|     "
    },
    {
        " _____ ",
        "|  ___|",
        "| |__  ",
        "|  __| ",
        "|_|    "
    }
};

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Please enter the input string!\n");
        return 1;
    }
    char* input_str = argv[1];
    printf("Input: %s\n", input_str);

    int input_str_len = strlen(input_str);
    char output_str[HEIGHT][WIDTH * input_str_len];

    for (int k = 0; k < HEIGHT; k++) {
        for (int i = 0; i < input_str_len; i++) {
            int alphabet_index = input_str[i] - 'A';
            if (alphabet_index < 0 || alphabet_index >= 26) {
                alphabet_index = 10; // character not in alphabet, use ' '
            }
            const char* row_str = alphabet[alphabet_index][k];
            int row_str_len = strlen(row_str);
            int start_index = i * WIDTH;
            int end_index = start_index + row_str_len;
            // pad the end of the row string with spaces
            for (int j = end_index; j < start_index + WIDTH; j++) {
                output_str[k][j] = ' ';
            }
            // copy the row string to the output array
            memcpy(&output_str[k][start_index], row_str, row_str_len);
        }
        // add a newline character to the end of each row
        output_str[k][WIDTH * input_str_len] = '\n';
    }

    // print the output string
    for (int i = 0; i < HEIGHT; i++) {
        printf("%s", output_str[i]);
    }

    return 0;
}