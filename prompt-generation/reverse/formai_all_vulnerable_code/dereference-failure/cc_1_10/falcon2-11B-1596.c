//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct diary {
    char title[100];
    char content[1000];
    int date;
    struct diary *next;
} diary;

diary *root;

void add_diary(diary *root, char *title, char *content, int date) {
    diary *new_diary = (diary *) malloc(sizeof(diary));
    strcpy(new_diary->title, title);
    strcpy(new_diary->content, content);
    new_diary->date = date;
    new_diary->next = NULL;

    if (root == NULL) {
        root = new_diary;
    } else {
        diary *curr = root;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_diary;
    }
}

void print_diary(diary *root) {
    diary *curr = root;
    while (curr!= NULL) {
        printf("Title: %s\n", curr->title);
        printf("Content: %s\n", curr->content);
        printf("Date: %d\n", curr->date);
        curr = curr->next;
    }
}

int main() {
    diary *new_diary = (diary *) malloc(sizeof(diary));
    strcpy(new_diary->title, "My First Diary");
    strcpy(new_diary->content, "Today is a great day. The sun is shining, the birds are singing, and I feel happy.");
    new_diary->date = 12345;

    add_diary(root, new_diary->title, new_diary->content, new_diary->date);

    print_diary(root);

    return 0;
}