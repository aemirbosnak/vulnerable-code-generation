//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1024

typedef struct {
    char title[MAX_ENTRY_LENGTH];
    char content[MAX_ENTRY_LENGTH];
    time_t timestamp;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(const char* title, const char* content) {
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);
    char date_str[32];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", &tm);

    printf("New entry added on %s:\n", date_str);
    printf("Title: %s\n", title);
    printf("Content:\n%s\n", content);

    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].content, content);
    entries[num_entries].timestamp = now;

    num_entries++;
}

void view_entries() {
    printf("Digital Diary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d (added on %s):\n", i+1, ctime(&entries[i].timestamp));
        printf("Title: %s\n", entries[i].title);
        printf("Content:\n%s\n", entries[i].content);
        printf("\n");
    }
}

void search_entries(const char* keyword) {
    printf("Search results for '%s':\n", keyword);
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].content, keyword)) {
            printf("Entry %d (added on %s):\n", i+1, ctime(&entries[i].timestamp));
            printf("Title: %s\n", entries[i].title);
            printf("Content:\n%s\n", entries[i].content);
            printf("\n");
        }
    }
}

int main() {
    add_entry("My First Entry", "Hello, world!");
    add_entry("My Second Entry", "This is my second entry.");
    view_entries();
    search_entries("world");

    return 0;
}