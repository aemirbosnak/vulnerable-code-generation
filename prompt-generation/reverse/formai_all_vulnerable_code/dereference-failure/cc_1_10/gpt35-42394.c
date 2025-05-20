//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20
#define MAX_SIZE MAX_WIDTH * MAX_HEIGHT

const char *alphabet[] = {
    " ____  _     _        _  _____ ",
    "|  _ \\(_)___| |_ __ _| |/ /_ _|",
    "| |_) | / __| __/ _` | ' / | |",
    "|  __/| \\__ \\ || (_| | . \\ | |",
    "|_|   |_|___/\\__\\__,_|_|\\_\\___|"
};

void printArt(char *text) {
    int len = strlen(text);
    int row = 0;
    while (row < MAX_HEIGHT) {
        int col = 0, k = 0;
        while (col < MAX_WIDTH) {
            if (text[k] == '\0')
                break;

            char c = text[k];
            int index = (int)c - 32;

            for (int i = 0; i < 7; i++) {
                if (alphabet[index][i] == '_')
                    printf("_");
                else if (alphabet[index][i] == '|')
                    printf("|");
                else if (alphabet[index][i] == ' ')
                    printf(" ");
            }

            col += 7;
            k++;
        }
        printf("\n");
        row++;
    }
}

int main() {
    char input[MAX_SIZE] = { 0 };

    printf("Enter text to convert to ASCII art (max %d characters):\n", MAX_SIZE);
    fgets(input, MAX_SIZE, stdin);

    printArt(input);

    return 0;
}