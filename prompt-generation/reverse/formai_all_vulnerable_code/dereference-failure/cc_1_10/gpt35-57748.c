//FormAI DATASET v1.0 Category: Digital Diary ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Record {
    int year;
    int month;
    int day;
    char* entry;
};

struct Diary {
    struct Record* records;
    int numRecords;
};

struct Diary* createDiary() {
    struct Diary* diary = malloc(sizeof(struct Diary));
    diary->records = malloc(sizeof(struct Record) * 10);
    diary->numRecords = 0;
    return diary;
}

void addRecord(struct Diary* diary, int year, int month, int day, char* entry) {
    if(diary->numRecords == 10) {
        printf("Diary is full, cannot add more records.\n");
        return;
    }
    struct Record record;
    record.year = year;
    record.month = month;
    record.day = day;
    record.entry = entry;
    diary->records[diary->numRecords] = record;
    diary->numRecords++;
    printf("Record added successfully.\n");
}

void printDiary(struct Diary* diary) {
    if(diary->numRecords == 0) {
        printf("Diary is empty.\n");
        return;
    }
    printf("Diary Entries:\n");
    for(int i=0; i<diary->numRecords; i++) {
        printf("Date: %d/%d/%d\n", diary->records[i].day, diary->records[i].month, diary->records[i].year);
        printf("Entry: %s\n", diary->records[i].entry);
    }
}

int main() {
    struct Diary* diary = createDiary();
    addRecord(diary, 2021, 10, 1, "Today was a good day.");
    addRecord(diary, 2021, 10, 2, "I learned a new programming concept today.");
    printDiary(diary);

    return 0;
}