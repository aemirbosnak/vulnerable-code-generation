//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure for the ebook data
typedef struct {
    char title[50]; // Book title
    char author[50]; // Author name
    int num_chapters; // Number of chapters in the book
    int current_chapter; // Current chapter number
    char *chapters[50]; // Array of chapter names
} ebook_data_t;

// Define the function to create a new ebook data structure
ebook_data_t *create_ebook(char *title, char *author, int num_chapters) {
    ebook_data_t *data = (ebook_data_t *)malloc(sizeof(ebook_data_t));
    strcpy(data->title, title);
    strcpy(data->author, author);
    data->num_chapters = num_chapters;
    data->current_chapter = 0;
    for (int i = 0; i < num_chapters; i++) {
        data->chapters[i] = (char *)malloc(50 * sizeof(char));
    }
    return data;
}

// Define the function to add a new chapter to an ebook
void add_chapter(ebook_data_t *data, char *chapter_name) {
    data->chapters[data->num_chapters] = chapter_name;
    data->num_chapters++;
}

// Define the function to display the ebook's contents
void display_ebook(ebook_data_t *data) {
    printf("Book Title: %s\nAuthor: %s\n", data->title, data->author);
    for (int i = 0; i < data->num_chapters; i++) {
        printf("Chapter %d: %s\n", i + 1, data->chapters[i]);
    }
}

// Define the function to navigate to the next chapter
void next_chapter(ebook_data_t *data) {
    data->current_chapter++;
    if (data->current_chapter >= data->num_chapters) {
        data->current_chapter = 0;
    }
}

// Define the function to navigate to the previous chapter
void prev_chapter(ebook_data_t *data) {
    data->current_chapter--;
    if (data->current_chapter < 0) {
        data->current_chapter = data->num_chapters - 1;
    }
}

// Define the main function
int main() {
    ebook_data_t *data = create_ebook("The Great Gatsby", "F. Scott Fitzgerald", 5);
    add_chapter(data, "Introduction");
    add_chapter(data, "Chapter 1");
    add_chapter(data, "Chapter 2");
    add_chapter(data, "Chapter 3");
    display_ebook(data);
    next_chapter(data);
    display_ebook(data);
    prev_chapter(data);
    display_ebook(data);
    return 0;
}