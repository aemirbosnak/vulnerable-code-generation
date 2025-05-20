//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define DAY_SIZE 32

typedef struct {
    char date[DAY_SIZE];
    char entry[DIARY_SIZE];
} diary_t;

diary_t* create_diary() {
    diary_t* d = malloc(sizeof(diary_t));
    strcpy(d->date, "");
    strcpy(d->entry, "");
    return d;
}

void add_entry(diary_t* d, char* entry) {
    strcat(d->entry, entry);
}

void view_entry(diary_t* d) {
    printf("Date: %s\n", d->date);
    printf("Entry: %s\n", d->entry);
}

void delete_entry(diary_t* d, int index) {
    if (index < strlen(d->entry)) {
        d->entry[index] = '\0';
    }
}

int main() {
    srand(time(NULL));

    diary_t* d = create_diary();

    while (1) {
        printf("Enter a date (format: mm/dd/yyyy): ");
        char date[DAY_SIZE];
        scanf("%3s%2s%4s", date, date, date);

        add_entry(d, date);

        view_entry(d);

        printf("Delete an entry (index: 0-9): ");
        int index = rand() % strlen(d->entry);
        delete_entry(d, index);
    }

    free(d);
    return 0;
}