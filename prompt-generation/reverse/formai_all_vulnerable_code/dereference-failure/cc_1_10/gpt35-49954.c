//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_TEXT_LENGTH 1000

struct Page {
    char* text;
    int pageNumber;
};

struct Ebook {
    int numPages;
    struct Page pages[MAX_PAGES];
    int currentPage;
};

void displayPage(struct Ebook* ebook) {
    printf("Page %d/%d:\n", ebook->currentPage+1, ebook->numPages);
    printf("%s\n", ebook->pages[ebook->currentPage].text);
}

void turnPage(struct Ebook* ebook) {
    if (ebook->currentPage < ebook->numPages-1) {
        ebook->currentPage++;
        displayPage(ebook);
    } else {
        printf("You have reached the end of the ebook.\n");
    }
}

void goBack(struct Ebook* ebook) {
    if (ebook->currentPage > 0) {
        ebook->currentPage--;
        displayPage(ebook);
    } else {
        printf("You are already on the first page.\n");
    }
}

void loadEbook(struct Ebook* ebook, char* filename) {
    FILE* ebookFile = fopen(filename, "r");
    if (ebookFile == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    char text[MAX_TEXT_LENGTH];
    int pageItemCount = 0;
    int pageNumber = 0;
    while (fgets(text, MAX_TEXT_LENGTH, ebookFile)) {
        if (pageItemCount == 0) {
            ebook->pages[pageNumber].text = malloc(MAX_PAGES);
            ebook->pages[pageNumber].pageNumber = pageNumber;
        }
        ebook->pages[pageNumber].text = realloc(ebook->pages[pageNumber].text, strlen(ebook->pages[pageNumber].text) + strlen(text) + 1);
        strcat(ebook->pages[pageNumber].text, text);
        pageItemCount++;

        if (pageItemCount == 40) {
            pageNumber++;
            pageItemCount = 0;
        }
    }
    fclose(ebookFile);
    ebook->numPages = pageNumber;
    ebook->currentPage = 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ebookreader <filename>\n");
        exit(1);
    }

    struct Ebook ebook;
    loadEbook(&ebook, argv[1]);
    displayPage(&ebook);

    char input;
    while (1) {
        printf("Enter (n)ext, (p)revious, or (q)uit: ");
        scanf("%c", &input);
        while (getchar() != '\n');

        if (input == 'n') {
            turnPage(&ebook);
        } else if (input == 'p') {
            goBack(&ebook);
        } else if (input == 'q') {
            printf("Goodbye.\n");
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}