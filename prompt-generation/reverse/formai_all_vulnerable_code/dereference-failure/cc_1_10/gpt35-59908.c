//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>

// Structure for storing information about an ebook
struct Ebook {
    char title[50];
    char author[50];
    int pageCount;
    float price;
    char filePath[100];
};

// Function to display ebook information
void displayEbookInfo(struct Ebook ebook) {
    printf("\nTitle: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Page count: %d\n", ebook.pageCount);
    printf("Price: $%.2f\n", ebook.price);
}

int main() {
    // Create an example Ebook and display its information
    struct Ebook myEbook = {"The Art of Programming", "John Smith", 300, 9.99, "/home/user/ebooks/art-of-programming.pdf"};
    displayEbookInfo(myEbook);

    // Open the ebook file and display the first 10 pages
    FILE *filePointer;
    filePointer = fopen(myEbook.filePath, "r");

    if (filePointer != NULL) {
        printf("\nDisplaying first 10 pages:\n");
        char currentLine[100];
        int pageCounter = 0;

        while (fgets(currentLine, sizeof(currentLine), filePointer)) {
            printf("%s", currentLine);

            if (currentLine[0] == '\f') { // Check for form feed character indicating new page
                pageCounter++;

                if (pageCounter >= 10) { // Stop after displaying 10 pages
                    break;
                }
            }
        }
    } else {
        printf("\nError: Failed to open ebook file.");
    }

    return 0;
}