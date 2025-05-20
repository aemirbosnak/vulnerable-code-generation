//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int num_words;
} WordFrequencyList;

void generate_random_theory(WordFrequencyList *list) {
    char theory[MAX_WORD_LENGTH * 10]; // Assuming a maximum of 10 words in the theory
    int num_words = rand() % (list->num_words + 1);
    int i;
    for (i = 0; i < num_words; i++) {
        strcat(theory, list->words[rand() % list->num_words].word);
        strcat(theory, " ");
    }
    printf("Random Conspiracy Theory: %s\n", theory);
}

void load_words(WordFrequencyList *list) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        exit(1);
    }
    char line[MAX_WORD_LENGTH + 1];
    int i = 0;
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        if (i >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        list->words[i].word = strdup(line);
        list->words[i].frequency = 0;
        i++;
    }
    fclose(file);
    list->num_words = i;
}

int main() {
    srand(time(NULL));
    WordFrequencyList list;
    load_words(&list);
    int choice;
    do {
        printf("1. Generate random theory\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                generate_random_theory(&list);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 2);
    return 0;
}