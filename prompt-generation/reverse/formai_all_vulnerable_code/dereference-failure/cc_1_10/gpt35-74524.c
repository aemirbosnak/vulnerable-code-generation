//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    char* data;
} AsciiArt;

void printAsciiArt(AsciiArt* art) {
    char* ptr = art->data;
    for (int i=0; i<art->height; i++) {
        for (int j=0; j<art->width; j++) {
            printf("%c", *ptr++);
        }
        printf("\n");
    }
}

AsciiArt* textToAsciiArt(char* text) {
    int width = 50;
    int height = 10;
    char* data = (char*) malloc(width * height * sizeof(char));
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            data[i*width+j] = ' ';
        }
    }
    
    int len = strlen(text);
    int start = (width - len) / 2;
    for (int i=0; i<len; i++) {
        data[start+i] = text[i];
    }
    
    AsciiArt* art = (AsciiArt*) malloc(sizeof(AsciiArt));
    art->width = width;
    art->height = height;
    art->data = data;
    
    return art;
}

int main() {
    char* text = "ASCII ART GENERATOR";
    AsciiArt* art = textToAsciiArt(text);
    printAsciiArt(art);
    free(art->data);
    free(art);

    return 0;
}