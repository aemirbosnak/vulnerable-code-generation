//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Book struct
typedef struct {
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    int num_pages;
} Book;

// Word struct
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} Word;

// Function to compare words based on frequency
int compare_words(const void *a, const void *b) {
    const Word *word1 = a;
    const Word *word2 = b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

// Function to read a book from a file
Book read_book(FILE *fp) {
    Book book;

    fscanf(fp, "%s %s %d\n", book.title, book.author, &book.num_pages);

    return book;
}

// Function to read a word from a line
void read_word(const char *line, Word *word) {
    char *token = strtok(line, ",.?!;:");
    strncpy(word->word, token, MAX_WORD_LENGTH);
    word->frequency = 1;
}

// Function to update a word frequency
void update_word_frequency(Word *word) {
    word->frequency++;
}

// Function to print a word
void print_word(const Word *word) {
    printf("%s: %d\n", word->word, word->frequency);
}

// Function to print the top N words
void print_top_words(Word *words, int num_words, int n) {
    qsort(words, num_words, sizeof(Word), compare_words);

    printf("Top %d words:\n", n);

    for (int i = 0; i < n && i < num_words; i++) {
        print_word(&words[i]);
    }
}

// Function to count words in a book
int count_words(const Book *book, Word *words) {
    FILE *fp = fopen(book->title, "r");
    int num_words = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",.?!;:");

        while (token!= NULL) {
            read_word(token, &words[num_words]);
            num_words++;

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(fp);

    return num_words;
}

int main() {
    Book book;
    Word words[1000];
    int num_words;

    // Read book from file
    FILE *fp = fopen("book.txt", "r");
    book = read_book(fp);
    fclose(fp);

    // Count words in book
    num_words = count_words(&book, words);

    // Print top N words
    print_top_words(words, num_words, 10);

    return 0;
}