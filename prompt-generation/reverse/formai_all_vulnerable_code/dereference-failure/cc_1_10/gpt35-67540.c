//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII art functions
void generateLine(char *line, int width, char char1, char char2){
    int i;
    for(i=0; i<width-1; i++){
        if(i%2 == 0) line[i] = char1;
        else line[i] = char2;
    }
    line[i] = '\n';
}

void generateTextArt(char *text, int width, int height){
    char **lines;
    int i, j, k, len = strlen(text);

    // initialize 2D array for lines of ASCII art
    lines = (char**) malloc(sizeof(char*) * height);
    for(i=0; i<height; i++) lines[i] = (char*) malloc(sizeof(char) * width);

    // generate each line of ASCII art
    for(i=0; i<height; i++){
        if(i == 0 || i == height-1) generateLine(lines[i], width, '+', '-');
        else generateLine(lines[i], width, '|', ' ');
    }

    // fill in text in the middle of ASCII art
    int textStartIndex = (width - len) / 2;
    i = height / 2;
    for(k=0; k<len; k++) lines[i][textStartIndex+k] = text[k];

    // print out ASCII art
    for(i=0; i<height; i++){
        for(j=0; j<width; j++){
            printf("%c", lines[i][j]);
        }
    }

    // free allocated memory
    for(i=0; i<height; i++) free(lines[i]);
    free(lines);
}

int main(){
    char text[] = "ASCII ART";
    int width = 60, height = 20;

    generateTextArt(text, width, height);

    return 0;
}