//FormAI DATASET v1.0 Category: Ebook reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int page_count;
    float price;
    char* content;
};

void read_book(struct book* b) {
    printf("Title: ");
    fflush(stdin);
    fgets(b->title, 50, stdin);
    printf("Author: ");
    fflush(stdin);
    fgets(b->author, 50, stdin);
    printf("Page count: ");
    scanf("%d", &b->page_count);
    printf("Price: ");
    scanf("%f", &b->price);
    printf("Content file name: ");
    char content_file_name[50];
    fflush(stdin);
    fgets(content_file_name, 50, stdin);
    content_file_name[strcspn(content_file_name, "\n")] = 0;
    FILE* content_file = fopen(content_file_name, "r");
    if (content_file == NULL) {
        printf("Content file not found.\n");
        exit(1);
    }
    fseek(content_file, 0, SEEK_END);
    long content_size = ftell(content_file);
    rewind(content_file);
    b->content = malloc(content_size);
    fread(b->content, content_size, 1, content_file);
    fclose(content_file);
}

void display_book(struct book* b) {
    printf("Title: %s", b->title);
    printf("Author: %s", b->author);
    printf("Page count: %d\n", b->page_count);
    printf("Price: %.2f\n", b->price);
    printf("Content:\n");
    printf("%s\n", b->content);
}

int main() {
    struct book b;
    read_book(&b);
    display_book(&b);
    free(b.content);
    return 0;
}