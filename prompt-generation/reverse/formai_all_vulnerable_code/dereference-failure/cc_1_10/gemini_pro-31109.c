//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

typedef struct _diary_entry {
    time_t timestamp;
    char *text;
} diary_entry;

typedef struct _diary {
    int num_entries;
    diary_entry *entries;
} diary;

diary *diary_new() {
    diary *d = malloc(sizeof(diary));
    d->num_entries = 0;
    d->entries = NULL;
    return d;
}

void diary_free(diary *d) {
    for (int i = 0; i < d->num_entries; i++) {
        free(d->entries[i].text);
    }
    free(d->entries);
    free(d);
}

void diary_add_entry(diary *d, const char *text) {
    d->entries = realloc(d->entries, (d->num_entries + 1) * sizeof(diary_entry));
    d->entries[d->num_entries].timestamp = time(NULL);
    d->entries[d->num_entries].text = strdup(text);
    d->num_entries++;
}

void diary_print(diary *d) {
    for (int i = 0; i < d->num_entries; i++) {
        printf("{%s} ", ctime(&d->entries[i].timestamp));
        printf("%s", d->entries[i].text);
    }
}

int main() {
    diary *d = diary_new();
    diary_add_entry(d, "Today was a good day.");
    diary_add_entry(d, "I met a new friend.");
    diary_add_entry(d, "I learned something new.");
    diary_print(d);
    diary_free(d);
    return 0;
}