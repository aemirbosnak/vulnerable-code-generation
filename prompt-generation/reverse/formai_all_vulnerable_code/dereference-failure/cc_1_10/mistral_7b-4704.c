//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIARY_SIZE 1000
#define ENTRY_SIZE 200
#define DATE_SIZE 11
#define MONTH_SIZE 4
#define YEAR_SIZE 4
#define TITLE_SIZE 80
#define CONTENT_SIZE 500

typedef struct DiaryEntry {
    char date[DATE_SIZE];
    char month[MONTH_SIZE];
    char year[YEAR_SIZE];
    char title[TITLE_SIZE];
    char content[CONTENT_SIZE];
} DiaryEntry;

void formatDate(char date[DATE_SIZE], int day, int month, int year) {
    sprintf(date, "%d/%02d/%d", year, month, day);
}

int isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}

void writeEntry(DiaryEntry *diary, int index, char *date, char *title, char *content) {
    strcpy(diary[index].date, date);
    strcpy(diary[index].month, date + 0);
    strcpy(diary[index].year, date + 3);
    strcpy(diary[index].title, title);
    strcpy(diary[index].content, content);
}

void readEntry(DiaryEntry *diary, int index, char *date, char *title, char *content) {
    strcpy(date, diary[index].date);
    strcpy(title, diary[index].title);
    strcpy(content, diary[index].content);
}

int main() {
    srand(time(NULL));

    DiaryEntry *diary = malloc(DIARY_SIZE * sizeof(DiaryEntry));
    int currentIndex = 0;

    while (currentIndex < DIARY_SIZE) {
        int day, month, year;
        time_t currentTime = time(NULL);
        struct tm *currentTm = localtime(&currentTime);

        day = currentTm->tm_mday;
        month = currentTm->tm_mon + 1;
        year = currentTm->tm_year + 1900;

        char date[DATE_SIZE];
        formatDate(date, day, month, year);

        char title[TITLE_SIZE];
        sprintf(title, "Entry %d - %s", currentIndex + 1, date);

        char content[CONTENT_SIZE];
        sprintf(content, "Today I %d some %s.", rand() % 100, rand() < 50 ? "ate" : "wrote");

        writeEntry(diary, currentIndex, date, title, content);
        currentIndex++;
    }

    int index = rand() % currentIndex;

    char date[DATE_SIZE];
    char title[TITLE_SIZE];
    char content[CONTENT_SIZE];

    readEntry(diary, index, date, title, content);
    printf("Entry:\nDate: %s\nTitle: %s\nContent:\n%s\n", date, title, content);

    free(diary);

    return 0;
}