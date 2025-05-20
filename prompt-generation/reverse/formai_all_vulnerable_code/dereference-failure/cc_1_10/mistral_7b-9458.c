//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 100
#define ENTRY_SIZE 256

struct DiaryEntry {
    char title[100];
    char content[ENTRY_SIZE];
    time_t timestamp;
};

void save_entry(struct DiaryEntry *diary, int index, const char *title, const char *content) {
    strcpy(diary[index].title, title);
    strcpy(diary[index].content, content);
    diary[index].timestamp = time(NULL);
}

struct DiaryEntry *get_latest_entry(struct DiaryEntry *diary) {
    int latest_index = 0;
    time_t latest_timestamp = diary[0].timestamp;

    for (int i = 1; i < DIARY_SIZE; ++i) {
        if (diary[i].timestamp > latest_timestamp) {
            latest_index = i;
            latest_timestamp = diary[i].timestamp;
        }
    }

    return &diary[latest_index];
}

int main(int argc, char **argv) {
    struct DiaryEntry diary[DIARY_SIZE];

    if (argc < 3) {
        printf("Usage: %s <title> <content>\n", argv[0]);
        return 1;
    }

    save_entry(diary, find_empty_slot(diary), argv[1], argv[2]);

    struct DiaryEntry *latest_entry = get_latest_entry(diary);

    printf("Entry saved.\n");
    printf("Title: %s\n", latest_entry->title);
    printf("Content:\n%s\n", latest_entry->content);
    printf("Timestamp: %s", ctime(&latest_entry->timestamp));

    return 0;
}

int find_empty_slot(struct DiaryEntry *diary) {
    for (int i = 0; i < DIARY_SIZE; ++i) {
        if (diary[i].title[0] == '\0') {
            return i;
        }
    }

    return -1;
}