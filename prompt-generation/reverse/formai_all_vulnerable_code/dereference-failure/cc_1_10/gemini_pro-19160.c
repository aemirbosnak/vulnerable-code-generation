//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char *text;
    struct entry *next;
};

struct diary {
    struct entry *head;
};

struct diary *create_diary() {
    struct diary *d = malloc(sizeof(struct diary));
    d->head = NULL;
    return d;
}

void add_entry(struct diary *d, char *text) {
    struct entry *e = malloc(sizeof(struct entry));
    e->text = text;
    e->next = d->head;
    d->head = e;
}

void print_diary(struct diary *d) {
    struct entry *e = d->head;
    while (e) {
        printf("%s\n", e->text);
        e = e->next;
    }
}

void free_diary(struct diary *d) {
    struct entry *e = d->head;
    while (e) {
        struct entry *next = e->next;
        free(e->text);
        free(e);
        e = next;
    }
    free(d);
}

int main() {
    struct diary *d = create_diary();
    char *text = "Dear diary, today was a beautiful day. I woke up to the sound of birds singing and the sun shining through my window. I went for a walk in the park and saw all the flowers in bloom. The world is such a beautiful place.";
    add_entry(d, text);
    print_diary(d);
    free_diary(d);
    return 0;
}