//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 256

typedef struct {
    char* title;
    char* author;
    char* content;
    int content_size;
} Ebook;

Ebook* create_ebook(char* title, char* author) {
    Ebook* ebook = (Ebook*) malloc(sizeof(Ebook));
    ebook->title = title;
    ebook->author = author;
    ebook->content = NULL;
    ebook->content_size = 0;
    return ebook;
}

void add_content_to_ebook(Ebook* ebook, char* content) {
    int content_size = strlen(content);
    ebook->content = (char*) realloc(ebook->content, ebook->content_size + content_size + 1);
    strcat(ebook->content, content);
    ebook->content_size += content_size;
}

void print_ebook(Ebook* ebook) {
    printf("Title: %s\n", ebook->title);
    printf("Author: %s\n", ebook->author);
    printf("Content:\n%s\n", ebook->content);
}

int main() {
    Ebook* ebook = create_ebook("My Ebook", "John Doe");
    char input[MAX_LINE_SIZE];

    while(fgets(input, MAX_LINE_SIZE, stdin)) {
        if(strncmp(input, "Title: ", 7) == 0) {
            char* new_title = input + 7;
            while(isspace(*new_title)) new_title++;
            ebook->title = strdup(new_title);
        } else if(strncmp(input, "Author: ", 8) == 0) {
            char* new_author = input + 8;
            while(isspace(*new_author)) new_author++;
            ebook->author = strdup(new_author);
        } else if(strncmp(input, "Content: ", 9) == 0) {
            char* new_content = input + 9;
            while(isspace(*new_content)) new_content++;
            add_content_to_ebook(ebook, new_content);
        }
    }

    print_ebook(ebook);
    free(ebook->title);
    free(ebook->author);
    free(ebook->content);
    free(ebook);

    return 0;
}