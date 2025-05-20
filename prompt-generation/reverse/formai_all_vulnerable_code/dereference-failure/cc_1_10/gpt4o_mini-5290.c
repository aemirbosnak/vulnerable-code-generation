//GPT-4o-mini DATASET v1.0 Category: Ebook reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_PAGES 100

typedef struct {
    char** pages;
    int total_pages;
    int current_page;
} eBook;

void initialize_book(eBook* book) {
    book->pages = (char**)malloc(MAX_PAGES * sizeof(char*));
    for (int i = 0; i < MAX_PAGES; i++) {
        book->pages[i] = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    book->total_pages = 0;
    book->current_page = 0;
}

void free_book(eBook* book) {
    for (int i = 0; i < MAX_PAGES; i++) {
        free(book->pages[i]);
    }
    free(book->pages);
}

void load_book(const char* filename, eBook* book) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
        
    while (fgets(book->pages[book->total_pages], MAX_LINE_LENGTH, file) && 
           book->total_pages < MAX_PAGES) {
        book->total_pages++;
    }
    
    fclose(file);
}

void display_page(eBook* book) {
    if (book->current_page < book->total_pages) {
        printf("Page %d of %d:\n", book->current_page + 1, book->total_pages);
        printf("%s\n", book->pages[book->current_page]);
    } else {
        printf("End of book.\n");
    }
}

void next_page(eBook* book) {
    if (book->current_page < book->total_pages - 1) {
        book->current_page++;
    } else {
        printf("You are already on the last page.\n");
    }
}

void previous_page(eBook* book) {
    if (book->current_page > 0) {
        book->current_page--;
    } else {
        printf("You are already on the first page.\n");
    }
}

void display_menu() {
    printf("eBook Reader:\n");
    printf("1. Next Page\n");
    printf("2. Previous Page\n");
    printf("3. Show Current Page\n");
    printf("4. Exit\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ebook_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    eBook book;
    initialize_book(&book);
    load_book(argv[1], &book);
    
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                next_page(&book);
                break;
            case 2:
                previous_page(&book);
                break;
            case 3:
                display_page(&book);
                break;
            case 4:
                free_book(&book);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice, please try again.\n");
        }
        display_page(&book);
    }

    free_book(&book);
    return EXIT_SUCCESS;
}