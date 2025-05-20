//LLAMA2-13B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WORDS_PER_LINE 20
#define LINES_PER_PARAGRAPH 5
#define PARAGRAPHS_PER_PAGE 10
#define PAGES_TO_PRINT 5

// Function to generate a random word
void generate_word(char *word) {
    int i;
    for (i = 0; i < 20; i++) {
        word[i] = 'a' + (rand() % 26);
    }
}

// Function to print a paragraph
void print_paragraph(char *paragraph) {
    int i;
    for (i = 0; i < LINES_PER_PARAGRAPH; i++) {
        printf("%s\n", paragraph + i * WORDS_PER_LINE);
    }
}

// Function to print a page
void print_page(char *page) {
    int i;
    for (i = 0; i < PARAGRAPHS_PER_PAGE; i++) {
        print_paragraph(page + i * LINES_PER_PARAGRAPH * WORDS_PER_LINE);
    }
}

int main() {
    char *words[PARAGRAPHS_PER_PAGE][LINES_PER_PARAGRAPH];
    char *pages[PAGES_TO_PRINT];
    int i, j;

    // Initialize words and pages arrays
    for (i = 0; i < PARAGRAPHS_PER_PAGE; i++) {
        for (j = 0; j < LINES_PER_PARAGRAPH; j++) {
            words[i][j] = malloc(WORDS_PER_LINE * sizeof(char));
            generate_word(words[i][j]);
        }
    }

    // Generate pages
    for (i = 0; i < PAGES_TO_PRINT; i++) {
        pages[i] = malloc(PARAGRAPHS_PER_PAGE * LINES_PER_PARAGRAPH * WORDS_PER_LINE * sizeof(char));
        for (j = 0; j < PARAGRAPHS_PER_PAGE; j++) {
            print_paragraph(pages[i] + j * LINES_PER_PARAGRAPH * WORDS_PER_LINE);
        }
    }

    // Print pages
    for (i = 0; i < PAGES_TO_PRINT; i++) {
        printf("Page %d:\n", i + 1);
        print_page(pages[i]);
    }

    // Free memory
    for (i = 0; i < PARAGRAPHS_PER_PAGE; i++) {
        for (j = 0; j < LINES_PER_PARAGRAPH; j++) {
            free(words[i][j]);
        }
    }
    for (i = 0; i < PAGES_TO_PRINT; i++) {
        free(pages[i]);
    }

    return 0;
}