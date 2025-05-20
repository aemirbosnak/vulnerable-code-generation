//FormAI DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 500

struct Entry{
    char date[20];
    char time[15];
    char title[50];
    char content[MAX_ENTRY_LENGTH];
};

struct Diary{
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void addEntry(struct Diary* diary, char* title, char* content){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    snprintf(diary->entries[diary->num_entries].date, 20, "%d-%02d-%02d", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday);
    snprintf(diary->entries[diary->num_entries].time, 15, "%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
    snprintf(diary->entries[diary->num_entries].title, 50, "%s", title);
    snprintf(diary->entries[diary->num_entries].content, MAX_ENTRY_LENGTH, "%s", content);
    diary->num_entries++;
}

void displayEntries(struct Diary* diary){
    for(int i=0; i<diary->num_entries; i++){
        printf("Title: %s\n", diary->entries[i].title);
        printf("Date: %s\n", diary->entries[i].date);
        printf("Time: %s\n", diary->entries[i].time);
        printf("Content: %s\n", diary->entries[i].content);
        printf("\n");
    }
}

int main(){
    struct Diary diary = {0};

    //Adding a few entries
    addEntry(&diary, "My first entry", "This is my first entry in my digital diary.");
    addEntry(&diary, "Today's events", "Today was a busy day. I had meetings and ran errands.");
    addEntry(&diary, "Memorable Moment", "I had dinner with my family today. It was great to catch up with everyone.");

    //Displaying all entries
    printf("All diary entries:\n\n");
    displayEntries(&diary);

    return 0;
}