//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("clear");
    char **a = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        a[i] = malloc(20 * sizeof(char));
    }
    a[0][0] = 'A';
    a[0][1] = 'B';
    a[0][2] = 'C';
    a[0][3] = 'D';
    a[0][4] = 'E';
    a[0][5] = 'F';
    a[0][6] = 'G';
    a[0][7] = 'H';
    a[0][8] = 'I';
    a[0][9] = 'J';
    a[1][0] = 'K';
    a[1][1] = 'L';
    a[1][2] = 'M';
    a[1][3] = 'N';
    a[1][4] = 'O';
    a[1][5] = 'P';
    a[1][6] = 'Q';
    a[1][7] = 'R';
    a[1][8] = 'S';
    a[1][9] = 'T';
    a[2][0] = 'U';
    a[2][1] = 'V';
    a[2][2] = 'W';
    a[2][3] = 'X';
    a[2][4] = 'Y';
    a[2][5] = 'Z';
    a[2][6] = 'a';
    a[2][7] = 'b';
    a[2][8] = 'c';
    a[2][9] = 'd';
    a[3][0] = 'e';
    a[3][1] = 'f';
    a[3][2] = 'g';
    a[3][3] = 'h';
    a[3][4] = 'i';
    a[3][5] = 'j';
    a[3][6] = 'k';
    a[3][7] = 'l';
    a[3][8] = 'm';
    a[3][9] = 'n';
    a[4][0] = 'o';
    a[4][1] = 'p';
    a[4][2] = 'q';
    a[4][3] = 'r';
    a[4][4] = 's';
    a[4][5] = 't';
    a[4][6] = 'u';
    a[4][7] = 'v';
    a[4][8] = 'w';
    a[4][9] = 'x';
    a[5][0] = 'y';
    a[5][1] = 'z';
    a[5][2] = '_';
    a[5][3] = '=';
    a[5][4] = '\\';
    a[5][5] = '/';
    a[5][6] = '>';
    a[5][7] = '<';
    a[5][8] = 'O';
    a[5][9] = 'P';
    for (int i = 0; i < 10; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}