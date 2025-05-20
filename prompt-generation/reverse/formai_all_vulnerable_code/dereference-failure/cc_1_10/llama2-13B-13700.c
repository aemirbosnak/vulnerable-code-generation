//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 256

typedef struct {
    char date[20];
    char entry[ENTRY_SIZE];
} diary_entry_t;

typedef struct {
    diary_entry_t entries[DIARY_SIZE];
    int current_entry;
} diary_t;

void init_diary(diary_t *d) {
    for (int i = 0; i < DIARY_SIZE; i++) {
        strcpy(d->entries[i].date, "");
        strcpy(d->entries[i].entry, "");
    }
    d->current_entry = 0;
}

void add_entry(diary_t *d, char *date, char *entry) {
    strcpy(d->entries[d->current_entry].date, date);
    strcpy(d->entries[d->current_entry].entry, entry);
    d->current_entry++;
    if (d->current_entry >= DIARY_SIZE) {
        d->current_entry = 0;
    }
}

void print_diary(diary_t *d) {
    for (int i = 0; i < DIARY_SIZE; i++) {
        printf("%s: %s\n", d->entries[i].date, d->entries[i].entry);
    }
}

int main() {
    diary_t *d = (diary_t *)malloc(sizeof(diary_t));
    init_diary(d);

    char date[20];
    char entry[ENTRY_SIZE];

    printf("Welcome to thy digital diary, fair knight!\n");

    while (1) {
        printf("Enter date (mm/dd/yy): ");
        fgets(date, 20, stdin);
        printf("Enter entry: ");
        fgets(entry, ENTRY_SIZE, stdin);

        add_entry(d, date, entry);

        printf("Thy diary doth now contain: \n");
        print_diary(d);

        printf("Wilt thou continue? (y/n): ");
        char cont = getchar();
        if (cont == 'n') {
            break;
        }
    }

    free(d);
    return 0;
}