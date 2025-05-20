//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000
#define MAX_PARAGRAPH_LENGTH 10000
#define MAX_CHAPTER_LENGTH 100000
#define MAX_BOOK_LENGTH 1000000

typedef struct {
    char *title;
    char *author;
    int num_chapters;
    int *chapter_lengths;
} Book;

typedef struct {
    int num_sentences;
    int *sentence_lengths;
} Chapter;

typedef struct {
    int num_words;
    int *word_lengths;
} Sentence;

typedef struct {
    int num_paragraphs;
    int *paragraph_lengths;
} Ebook;

void init_book(Book *book, char *title, char *author, int num_chapters) {
    book->title = title;
    book->author = author;
    book->num_chapters = num_chapters;
    book->chapter_lengths = (int *) malloc(num_chapters * sizeof(int));
    for (int i = 0; i < num_chapters; i++) {
        book->chapter_lengths[i] = 0;
    }
}

void init_chapter(Chapter *chapter, int num_sentences) {
    chapter->num_sentences = num_sentences;
    chapter->sentence_lengths = (int *) malloc(num_sentences * sizeof(int));
    for (int i = 0; i < num_sentences; i++) {
        chapter->sentence_lengths[i] = 0;
    }
}

void init_sentence(Sentence *sentence, int num_words) {
    sentence->num_words = num_words;
    sentence->word_lengths = (int *) malloc(num_words * sizeof(int));
    for (int i = 0; i < num_words; i++) {
        sentence->word_lengths[i] = 0;
    }
}

void init_ebook(Ebook *ebook, int num_paragraphs) {
    ebook->num_paragraphs = num_paragraphs;
    ebook->paragraph_lengths = (int *) malloc(num_paragraphs * sizeof(int));
    for (int i = 0; i < num_paragraphs; i++) {
        ebook->paragraph_lengths[i] = 0;
    }
}

void free_book(Book *book) {
    free(book->title);
    free(book->author);
    free(book->chapter_lengths);
}

void free_chapter(Chapter *chapter) {
    free(chapter->sentence_lengths);
}

void free_sentence(Sentence *sentence) {
    free(sentence->word_lengths);
}

void free_ebook(Ebook *ebook) {
    free(ebook->paragraph_lengths);
}

int main() {
    Book book;
    init_book(&book, "A Mind-Bending Ebook Reader", "Anonymous", 3);

    Chapter chapter;
    init_chapter(&chapter, 5);

    Sentence sentence;
    init_sentence(&sentence, 15);

    Ebook ebook;
    init_ebook(&ebook, 10);

    int total_words = 0;
    for (int i = 0; i < 5; i++) {
        char *word = "ebook";
        int word_length = strlen(word);
        total_words += word_length;

        if (i == 3) {
            printf("The ebook is about %d words long.\n", total_words);
        }
    }

    return 0;
}