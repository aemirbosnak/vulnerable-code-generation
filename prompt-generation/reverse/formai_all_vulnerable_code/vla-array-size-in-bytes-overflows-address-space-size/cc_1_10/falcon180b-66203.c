//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entry {
    char date[11];
    char time[9];
    char mood[7];
    char text[1000];
};

void write_entry(FILE* diary, char* date, char* time, char* mood, char* text) {
    struct entry entry = {date, time, mood, text};
    fwrite(&entry, sizeof(struct entry), 1, diary);
}

void read_entries(FILE* diary, int num_entries) {
    struct entry entries[num_entries];
    rewind(diary);
    fread(entries, sizeof(struct entry), num_entries, diary);
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s: %s\n", entries[i].date, entries[i].time, entries[i].mood, entries[i].text);
    }
}

int main() {
    FILE* diary = fopen("diary.bin", "a+b");
    if (diary == NULL) {
        fprintf(stderr, "Error opening diary.\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char date[11];
    strftime(date, 11, "%Y-%m-%d", tm);
    char time[9];
    strftime(time, 9, "%H:%M:%S", tm);

    int num_entries;
    fseek(diary, 0, SEEK_END);
    num_entries = ftell(diary) / sizeof(struct entry);
    rewind(diary);

    char mood[7];
    printf("Enter your current mood (max 6 characters): ");
    scanf("%6s", mood);

    char text[1000];
    printf("What's on your mind today?\n");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';

    write_entry(diary, date, time, mood, text);

    read_entries(diary, num_entries);

    fclose(diary);

    return 0;
}