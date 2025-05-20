//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    
    char *str = argv[1];
    char *cat_str = "meow";
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            str[i] = 'a';
        } else if (str[i] == 'y') {
            str[i] = 'i';
        } else if (str[i] == 'Y') {
            str[i] = 'I';
        } else if (str[i] == 'H') {
            str[i] = 'A';
        } else if (str[i] == 'W') {
            str[i] = 'O';
        } else if (str[i] == 'B') {
            str[i] = 'I';
        } else if (str[i] == 'S') {
            str[i] = 'O';
        } else if (str[i] == 'T') {
            str[i] = 'A';
        } else if (str[i] == 'W') {
            str[i] = 'I';
        } else if (str[i] == 'C') {
            str[i] = 'O';
        } else if (str[i] == 'K') {
            str[i] = 'O';
        } else if (str[i] == 'D') {
            str[i] = 'O';
        } else if (str[i] == 'G') {
            str[i] = 'I';
        } else if (str[i] == 'J') {
            str[i] = 'O';
        } else if (str[i] == 'P') {
            str[i] = 'A';
        } else if (str[i] == 'Q') {
            str[i] = 'A';
        } else if (str[i] == 'X') {
            str[i] = 'I';
        } else if (str[i] == 'Z') {
            str[i] = 'I';
        }
    }
    
    strcat(str, cat_str);
    printf("Original string: %s\n", str);
    return 0;
}