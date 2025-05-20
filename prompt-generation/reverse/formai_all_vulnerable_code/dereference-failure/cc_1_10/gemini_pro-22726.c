//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char *date;
    char *text;
};

struct diary {
    int num_entries;
    struct entry *entries;
};

struct diary *diary_new() {
    struct diary *d = malloc(sizeof(struct diary));
    d->num_entries = 0;
    d->entries = NULL;
    return d;
}

void diary_free(struct diary *d) {
    for (int i = 0; i < d->num_entries; i++) {
        free(d->entries[i].date);
        free(d->entries[i].text);
    }
    free(d->entries);
    free(d);
}

void diary_add_entry(struct diary *d, char *date, char *text) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    new_entry->date = malloc(strlen(date) + 1);
    strcpy(new_entry->date, date);
    new_entry->text = malloc(strlen(text) + 1);
    strcpy(new_entry->text, text);
    d->entries = realloc(d->entries, (d->num_entries + 1) * sizeof(struct entry));
    d->entries[d->num_entries++] = *new_entry;
    free(new_entry);
}

void diary_print(struct diary *d) {
    for (int i = 0; i < d->num_entries; i++) {
        printf("%s\n%s\n\n", d->entries[i].date, d->entries[i].text);
    }
}

int main() {
    struct diary *d = diary_new();
    diary_add_entry(d, "2023-01-01", "Dear Diary,\n\nI'm so excited to start writing in you! I'm hoping to use you to document my thoughts and feelings, and to keep track of all the important things that happen in my life.\n\nI'm not sure what to write about today, but I'll just start with whatever comes to mind.\n\nI'm feeling really happy and grateful right now. I have a great job, a loving family, and amazing friends. I'm so lucky to have all of them in my life.\n\nI'm also really excited about the future. I have so many goals and dreams, and I can't wait to see what the future holds.\n\nI know that there will be challenges along the way, but I'm confident that I can overcome them. I'm strong and determined, and I'm not afraid to work hard.\n\nI'm so grateful for this opportunity to write in you, Diary. I can't wait to see what the future holds.");
    diary_print(d);
    diary_free(d);
    return 0;
}