//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_ART_LENGTH 100

typedef struct art {
    char* text;
    char* art;
} art_t;

art_t generate_art(char* text) {
    art_t art;
    int i, j;
    int n = strlen(text);

    art.text = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    art.art = (char*)malloc(MAX_ART_LENGTH * sizeof(char));

    for (i = 0; i < n; i++) {
        art.text[i] = text[i];
    }

    for (i = 0; i < MAX_ART_LENGTH; i++) {
        art.art[i] = '\0';
    }

    for (i = 0; i < MAX_ART_LENGTH; i++) {
        for (j = 0; j < n; j++) {
            art.art[i] += text[j];
        }
    }

    return art;
}

void print_art(art_t art) {
    int i, j;

    printf("Text: %s\n", art.text);
    printf("Art: ");
    for (i = 0; i < MAX_ART_LENGTH; i++) {
        for (j = 0; j < MAX_ART_LENGTH; j++) {
            printf("%c", art.art[i*MAX_ART_LENGTH+j]);
        }
        printf("\n");
    }
}

int main() {
    char* text = "Hello, World!";
    art_t art = generate_art(text);
    print_art(art);
    free(art.text);
    free(art.art);
    return 0;
}