//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000
#define ROWS 8
#define COLS 8

void drawLine() {
    printf("+");
    for (int i = 0; i < COLS; ++i) {
        printf("-");
    }
    printf("+\n");
}

void clearBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    drawLine();
    for (int i = 0; i < ROWS; ++i) {
        printf("|");
        for (int j = 0; j < COLS; ++j) {
            printf("%c", board[i][j]);
        }
        printf("|\n");
    }
    drawLine();
}

void addChar(char board[ROWS][COLS], char c) {
    int row = ROWS / 2;
    int col = COLS / 2;
    
    if (isalnum(c)) {
        int index = toupper(c) - 'A';
        const char* letters[] = {
            "  ###  \n #   # \n#     #\n#     #\n#     #\n #   # \n  ###  \n",
            " ##### \n#     #\n#      \n#      \n###### \n#     #\n#     #\n",
            " ####  \n#    # \n     # \n    #  \n   #   \n  #    \n ######\n",
            " ##### \n#     #\n#     #\n###### \n#     #\n#     #\n ##### \n",
            "###### \n#      \n#      \n#####  \n#      \n#      \n###### \n",
            "###### \n#      \n#      \n#####  \n#      \n#      \n#      \n",
            " ######\n#      \n#      \n#  ####\n#     #\n#     #\n ##### \n",
            "#     #\n#     #\n#     #\n#######\n      #\n      #\n      #\n",
            "#######\n#     #\n#     #\n###### \n#     #\n#     #\n#######\n",
            "#######\n#     #\n#     #\n###### \n#     #\n#     #\n#     #\n",
            "#     #\n#    # \n#   #  \n#####  \n#   #  \n#    # \n#     #\n",
            "#      \n#      \n#      \n#      \n#      \n#      \n###### \n",
            "#     #\n##    #\n# #   #\n#  #  #\n#   # #\n#    ##\n#     #\n",
            "#     #\n##    #\n# #   #\n#  #  #\n#   # #\n#    # \n#     #\n",
            " ######\n#     #\n#     #\n#     #\n#     #\n#     #\n ###### \n",
            "###### \n#     #\n#     #\n###### \n#      \n#      \n#      \n",
            " ######\n#     #\n#     #\n#  #  #\n#   # #\n#    ##\n #### #\n",
            "###### \n#     #\n#     #\n###### \n#   #  \n#    # \n#     #\n",
            " ##### \n#     #\n#      \n ##### \n     # \n#     #\n ##### \n",
            "#######\n   #   \n   #   \n   #   \n   #   \n   #   \n#######\n",
            "#      \n #     \n  #    \n   #   \n    #  \n     # \n      #\n",
            "#     #\n# #   #\n#  #  #\n#   # #\n#    ##\n#     #\n#     #\n",
            "#     #\n##    #\n# #   #\n#  #  #\n#   # #\n#    # \n#    # \n",
            " #   # \n #   # \n# # # #\n # # # \n  # #  \n   #   \n   #   \n",
            "#     #\n#     #\n#     #\n#     #\n#     #\n#     #\n ######\n",
            "#     #\n#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n",
            "#     #\n#     #\n#     #\n#  #  #\n# # # #\n##   ##\n#     #\n",
            "#     #\n#     #\n #   # \n  # #  \n   #   \n  # #  \n #   # \n",
            "#     #\n #   # \n  # #  \n   #   \n  # #  \n #   # \n#     #\n",
            "#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n   #   \n",
            "#######\n     # \n    #  \n   #   \n  #    \n #     \n#######\n",
            "  ###  \n #   # \n#     #\n#     #\n#     #\n #   # \n  # #  \n",
            "#######\n     # \n     # \n     # \n     # \n     # \n#######\n",
            "   ### \n  #   #\n#      \n#      \n#      \n  #   #\n   ### \n",
            "      #\n      #\n      #\n      #\n      #\n      #\n ######\n",
            "#     #\n##   ##\n# # # #\n#  #  #\n#     #\n#     #\n#     #\n",
            " #   # \n# # # #\n#  #  #\n#     #\n#     #\n#     #\n #   # \n",
            "#     #\n##    #\n# #   #\n#   # #\n#    ##\n#     #\n#     #\n",
            " ######\n     # \n     # \n     # \n     # \n     # \n     # \n",
            "#     #\n#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n",
            "#     #\n#     #\n#     #\n#  #  #\n# # # #\n##   ##\n#     #\n",
            "#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n   #   \n",
            "#     #\n#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n",
            "#######\n     # \n    #  \n   #   \n  #    \n #     \n#      \n",
            "  ###  \n #   # \n#     #\n#     #\n# # # #\n #   # \n  # #  \n",
            "#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n",
            " ######\n#    # \n    #  \n   #   \n  #    \n #     \n###### \n",
            "###### \n#     #\n      #\n ##### \n#      \n#      \n#######\n",
            "#######\n     # \n    #  \n   #   \n  #    \n #     \n#      \n",
            "###### \n#     #\n      #\n ##### \n#      \n#      \n#      \n",
            " ######\n#     #\n     # \n   #   \n #     \n#      \n###### \n",
            "#######\n#     #\n#     #\n#     #\n#     #\n#     #\n#######\n",
            "   #   \n  ##   \n # #   \n   #   \n   #   \n   #   \n ##### \n",
            "#      \n#      \n#      \n#      \n#      \n#      \n#######\n",
            "##   ##\n##   ##\n##   ##\n  ## # \n  ## # \n #   # \n #   # \n",
            "#     #\n#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n",
            "#     #\n#     #\n#     #\n#  #  #\n # #   \n  #    \n  #    \n",
            "#     #\n#     #\n#     #\n#     #\n #   # \n  # #  \n   #   \n",
            "#     #\n#     #\n #   # \n  # #  \n   #   \n  # #  \n #   # \n",
            "#     #\n#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n",
            "#######\n#    # \n  # #  \n   #   \n  # #  \n#    # \n#######\n",
            "  ###  \n #   # \n#     #\n     # \n    #  \n   #   \n #     \n",
            "#######\n     # \n    #  \n   #   \n  #    \n #     \n#######\n",
            "   ### \n  #   #\n#      \n ##    \n#      \n  #   #\n   ### \n",
            " #   # \n# #  # \n # # # \n  # #  \n # # # \n#  # # \n#   #  \n",
            "#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n   #   \n",
            "#     #\n##    #\n# #   #\n#  #  #\n#   # #\n##   ##\n#     #\n",
            "      #\n      #\n      #\n      #\n#     #\n#     #\n ######\n",
            "###### \n#     #\n#      \n#####  \n     # \n#     #\n###### \n",
            "     # \n    ## \n   # # \n   #   \n # # # \n#     #\n #### #\n",
            "###### \n    #  \n   #   \n  #    \n #     \n#     #\n#######\n",
            "   ### \n  #   #\n#      \n ##    \n#      \n#      \n#      \n",
            "#     #\n #   # \n  # #  \n   #   \n  # #  \n #   # \n#     #\n",
            "#     #\n #   # \n  # #  \n   #   \n   #   \n   #   \n   #   \n",
            "#     #\n #   # \n  # #  \n   #   \n   #   \n#     #\n #   # \n",
        };
        if (index >= 0 && index < sizeof(letters) / sizeof(letters[0])) {
            const char* letter = letters[index];
            while (*letter) {
                if (*letter == '\n') {
                    ++row;
                    col = COLS / 2 - 4;
                } else if (*letter == '#') {
                    board[row][col] = '#';
                    ++col;
                } else if (*letter == ' ') {
                    ++col;
                }
                ++letter;
            }
        }
    }
}

int main() {
    char board[ROWS][COLS];
    clearBoard(board);
    
    char input[MAX_LENGTH];
    printf("Please enter text to convert to ASCII art:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    for (int i = 0; i < strlen(input); ++i) {
        addChar(board, input[i]);
    }
    
    printBoard(board);
    
    return 0;
}