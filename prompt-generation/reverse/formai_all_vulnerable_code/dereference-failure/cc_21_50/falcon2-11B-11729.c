//Falcon2-11B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

void translate(char* sentence) {
    int i, j;
    char temp;
    char* result = (char*) malloc(strlen(sentence) + 1);

    for (i = 0, j = 0; sentence[i]; i++) {
        if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'y') {
            temp = 'c';
        } else if (sentence[i] == 'b' || sentence[i] == 'd' || sentence[i] == 'f' || sentence[i] == 'g' || sentence[i] == 'h' || sentence[i] == 'j' || sentence[i] == 'k' || sentence[i] == 'l' || sentence[i] =='m' || sentence[i] == 'n' || sentence[i] == 'p' || sentence[i] == 'q' || sentence[i] == 'r' || sentence[i] =='s' || sentence[i] == 't' || sentence[i] == 'v' || sentence[i] == 'w' || sentence[i] == 'x' || sentence[i] == 'z') {
            temp = 'f';
        } else if (sentence[i] == 'c' || sentence[i] == 'g' || sentence[i] == 'j' || sentence[i] == 'k' || sentence[i] == 'q' || sentence[i] == 'x') {
            temp = 'j';
        } else if (sentence[i] =='s' || sentence[i] == 'z') {
            temp ='s';
        } else if (sentence[i] == 't') {
            temp = 't';
        } else if (sentence[i] == 'l') {
            temp = 'l';
        } else if (sentence[i] =='m') {
            temp ='m';
        } else if (sentence[i] == 'n') {
            temp = 'n';
        } else if (sentence[i] == 'r') {
            temp = 'r';
        } else if (sentence[i] == 'd') {
            temp = 'd';
        } else if (sentence[i] == 'v') {
            temp = 'v';
        } else if (sentence[i] == 'w') {
            temp = 'w';
        } else if (sentence[i] == 'u') {
            temp = 'u';
        } else if (sentence[i] == 'y') {
            temp = 'y';
        } else if (sentence[i] == 'e') {
            temp = 'e';
        } else if (sentence[i] == 'i') {
            temp = 'i';
        } else if (sentence[i] == 'o') {
            temp = 'o';
        } else if (sentence[i] == 'p') {
            temp = 'p';
        } else if (sentence[i] == 'q') {
            temp = 'q';
        } else if (sentence[i] == 'r') {
            temp = 'r';
        } else if (sentence[i] == 't') {
            temp = 't';
        } else if (sentence[i] == 'v') {
            temp = 'v';
        } else if (sentence[i] == 'w') {
            temp = 'w';
        } else if (sentence[i] == 'x') {
            temp = 'x';
        } else if (sentence[i] == 'z') {
            temp = 'z';
        } else {
            temp = 'a';
        }
        result[j++] = temp;
    }
    result[j] = '\0';
    printf("The translated sentence is: %s\n", result);
    free(result);
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    translate(sentence);
    return 0;
}