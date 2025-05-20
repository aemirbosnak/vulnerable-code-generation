//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ART_FILE "art.dict"
#define MAX_WORD_LEN 25
#define ART_LEN 10
#define ART_WIDTH (ART_LEN * 2 + 1)

typedef struct {
    char word[MAX_WORD_LEN];
    char art[ART_LEN][ART_WIDTH];
} art_t;

void load_dictionary(art_t *arts, int size);
int find_art_index(art_t *arts, int size, char *word);
void print_art(char *art);

int main() {
    art_t arts[100];
    int size = 0;

    load_dictionary(arts, 100);

    char word[MAX_WORD_LEN];
    while (1) {
        printf("Enter a word or type 'exit' to quit: ");
        scanf("%s", word);

        if (strcmp(word, "exit") == 0) {
            break;
        }

        int index = find_art_index(arts, size, word);
        if (index != -1) {
            print_art(arts[index].art[0]);
        } else {
            printf("Sorry, we don't have ASCII art for that word.\n");
        }
    }

    return 0;
}

void load_dictionary(art_t *arts, int size) {
    FILE *fp = fopen(ART_FILE, "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LEN + ART_LEN * ART_WIDTH + 2];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s", arts[size].word, arts[size].art[0]);
        for (int i = 1; i < ART_LEN; i++) {
            strcpy(arts[size].art[i], arts[size].art[i-1] + ART_WIDTH + 1);
        }
        size++;
    }

    fclose(fp);
}

int find_art_index(art_t *arts, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arts[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

void print_art(char *art) {
    for (int i = 0; i < ART_LEN; i++) {
        printf("\n%s", art + i * ART_WIDTH);
    }
}