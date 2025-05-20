//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ebook {
    char title[50];
    char author[50];
    char filename[50];
};

int main() {
    struct ebook books[100]; // Assume there are at most 100 books
    int num_books = 0;

    // Read ebooks from file into struct array
    FILE* fp = fopen("ebooks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open ebook file.\n");
        return 1;
    }
    char line[150];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* title = strtok(line, ",");
        char* author = strtok(NULL, ",");
        char* filename = strtok(NULL, ",");
        strcpy(books[num_books].title, title);
        strcpy(books[num_books].author, author);
        strcpy(books[num_books].filename, filename);
        num_books++;
    }
    fclose(fp);

    // Print ebooks to console
    printf("Welcome to My Ebook Reader!\n");
    printf("We have %d ebooks available.\n", num_books);
    printf("----------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s by %s\n", i+1, books[i].title, books[i].author);
    }

    // Prompt user for ebook selection
    int selection;
    char filename[50];
    printf("Enter the number of the ebook you want to read: ");
    scanf("%d", &selection);
    if (selection < 1 || selection > num_books) {
        printf("Error: invalid selection.\n");
        return 1;
    }
    strcpy(filename, books[selection-1].filename);

    // Read ebook file and print to console
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open ebook file.\n");
        return 1;
    }
    printf("----------------------\n");
    printf("%s by %s\n", books[selection-1].title, books[selection-1].author);
    printf("----------------------\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);

    return 0;
}