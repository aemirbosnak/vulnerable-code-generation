//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 10000

typedef struct ebook {
    char title[20];
    char author[20];
    char text[MAX_TEXT_SIZE];
    int text_size;
} ebook;

ebook* openEbook(const char* filename) {
    ebook* ebook_ptr;
    FILE* ebook_file;

    ebook_ptr = (ebook*)malloc(sizeof(ebook));
    ebook_ptr->text_size = 0;

    ebook_file = fopen(filename, "r");
    if (ebook_file == NULL) {
        printf("Error opening ebook file.\n");
        return NULL;
    }

    while (fgets(ebook_ptr->text, MAX_TEXT_SIZE, ebook_file)!= NULL) {
        ebook_ptr->text_size++;
    }

    fclose(ebook_file);

    return ebook_ptr;
}

void printTitle(ebook* ebook_ptr) {
    printf("%s by %s\n", ebook_ptr->title, ebook_ptr->author);
}

void printText(ebook* ebook_ptr) {
    int i;

    printf("Reading...\n");

    for (i = 0; i < ebook_ptr->text_size; i++) {
        printf("%s\n", ebook_ptr->text);
    }
}

void printEnd(void) {
    printf("Press any key to exit.\n");
    getchar();
}

void ebookReader(ebook* ebook_ptr) {
    printTitle(ebook_ptr);
    printText(ebook_ptr);
    printEnd();
}

int main(int argc, char* argv[]) {
    ebook* ebook_ptr;

    ebook_ptr = openEbook(argv[1]);
    if (ebook_ptr == NULL) {
        return 1;
    }

    ebookReader(ebook_ptr);

    free(ebook_ptr);

    return 0;
}