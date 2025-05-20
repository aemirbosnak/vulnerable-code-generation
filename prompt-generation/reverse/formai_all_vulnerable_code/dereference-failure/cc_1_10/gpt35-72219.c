//FormAI DATASET v1.0 Category: Ebook reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>

/* -- Ebook data structure -- */
struct Ebook {
    char title[50];
    char author[50];
    char isbn[20];
    int year;
    char publisher[50];
    char genre[20];
    int pageCount;
    int currentChapter;
    char *content;
};

/* -- Function to read an Ebook from file -- */
struct Ebook readEbook(char *filename) {
    FILE *fp = fopen(filename, "r");
    struct Ebook ebook;

    /* Read metadata from file */
    fscanf(fp, "Title: %[^\n]\n", ebook.title);
    fscanf(fp, "Author: %[^\n]\n", ebook.author);
    fscanf(fp, "ISBN: %[^\n]\n", ebook.isbn);
    fscanf(fp, "Year: %d\n", &ebook.year);
    fscanf(fp, "Publisher: %[^\n]\n", ebook.publisher);
    fscanf(fp, "Genre: %[^\n]\n", ebook.genre);
    fscanf(fp, "Page Count: %d\n", &ebook.pageCount);

    /* Read content from file */
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp) - ftell(fp) / 10;
    fseek(fp, 0, SEEK_SET);
    ebook.content = malloc(size);
    fread(ebook.content, 1, size, fp);
    fclose(fp);

    ebook.currentChapter = 0;

    return ebook;
}

/* -- Function to display Ebook metadata -- */
void displayMetadata(struct Ebook ebook) {
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("ISBN: %s\n", ebook.isbn);
    printf("Year: %d\n", ebook.year);
    printf("Publisher: %s\n", ebook.publisher);
    printf("Genre: %s\n", ebook.genre);
    printf("Page Count: %d\n", ebook.pageCount);
    printf("Current Chapter: %d\n\n", ebook.currentChapter + 1);
}

/* -- Function to display Ebook content -- */
void displayContent(struct Ebook ebook) {
    printf("%s\n", ebook.content);
}

/* -- Main function -- */
int main() {
    struct Ebook ebook = readEbook("book.epub");

    /* Display metadata and first chapter */
    displayMetadata(ebook);
    displayContent(ebook);

    /* Allow user to navigate through the chapters */
    char choice = ' ';
    while (choice != 'q') {
        printf("Press left or right arrow to navigate, or 'q' to quit.\n");
        choice = getchar();

        switch (choice) {
            case 'r':
                ebook.currentChapter++;
                if (ebook.currentChapter >= ebook.pageCount) {
                    ebook.currentChapter = ebook.pageCount - 1;
                }
                break;
            case 'l':
                ebook.currentChapter--;
                if (ebook.currentChapter < 0) {
                    ebook.currentChapter = 0;
                }
                break;
        }

        system("clear");
        displayMetadata(ebook);
        displayContent(ebook);
    }

    free(ebook.content);

    return 0;
}