//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *title;
    char *body;
    time_t timestamp;
} Entry;

typedef struct {
    Entry *entries;
    int num_entries;
    int capacity;
} Diary;

Diary *diary_new() {
    Diary *diary = malloc(sizeof(Diary));
    if (diary == NULL) {
        return NULL;
    }

    diary->entries = NULL;
    diary->num_entries = 0;
    diary->capacity = 0;

    return diary;
}

void diary_free(Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        free(diary->entries[i].title);
        free(diary->entries[i].body);
    }
    free(diary->entries);
    free(diary);
}

int diary_add_entry(Diary *diary, char *title, char *body) {
    if (diary->num_entries == diary->capacity) {
        diary->capacity *= 2;
        diary->entries = realloc(diary->entries, diary->capacity * sizeof(Entry));
        if (diary->entries == NULL) {
            return -1;
        }
    }

    diary->entries[diary->num_entries].title = strdup(title);
    diary->entries[diary->num_entries].body = strdup(body);
    diary->entries[diary->num_entries].timestamp = time(NULL);
    diary->num_entries++;

    return 0;
}

int diary_save(Diary *diary, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return -1;
    }

    for (int i = 0; i < diary->num_entries; i++) {
        fprintf(file, "%s\n", diary->entries[i].title);
        fprintf(file, "%s\n", diary->entries[i].body);
        fprintf(file, "%ld\n", diary->entries[i].timestamp);
    }

    fclose(file);

    return 0;
}

int diary_load(Diary *diary, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        if (diary->num_entries == diary->capacity) {
            diary->capacity *= 2;
            diary->entries = realloc(diary->entries, diary->capacity * sizeof(Entry));
            if (diary->entries == NULL) {
                free(line);
                fclose(file);
                return -1;
            }
        }

        diary->entries[diary->num_entries].title = strdup(line);
        getline(&line, &len, file);
        diary->entries[diary->num_entries].body = strdup(line);
        getline(&line, &len, file);
        diary->entries[diary->num_entries].timestamp = atol(line);
        diary->num_entries++;
    }

    free(line);
    fclose(file);

    return 0;
}

int main() {
    Diary *diary = diary_new();

    diary_add_entry(diary, "My first entry", "This is my first entry in my digital diary.");
    diary_add_entry(diary, "My second entry", "This is my second entry in my digital diary.");
    diary_add_entry(diary, "My third entry", "This is my third entry in my digital diary.");

    diary_save(diary, "diary.txt");

    diary_free(diary);

    return 0;
}