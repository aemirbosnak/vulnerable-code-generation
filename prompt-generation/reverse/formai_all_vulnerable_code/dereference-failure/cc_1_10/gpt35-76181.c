//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Date{
    int day;
    int month;
    int year;
};

struct Watermark {
    char author[50];
    char title[100];
    struct Date date_created;
};

void create_watermark(struct Watermark *wm, char *auth, char *title, struct Date date) {
    strcpy(wm->author, auth);
    strcpy(wm->title, title);
    wm->date_created = date;
}

void print_watermark(struct Watermark wm) {
    printf("Watermark Information:\n");
    printf("Author: %s\n", wm.author);
    printf("Title: %s\n", wm.title);
    printf("Date Created: %d/%d/%d\n", wm.date_created.day, wm.date_created.month, wm.date_created.year);
}

int main() {
    char author[50], title[100];
    struct Date date;
    struct Watermark wm;
    
    /* Get author and title from user */
    printf("Enter author name: ");
    fgets(author, 50, stdin);
    author[strcspn(author, "\n")] = 0;
    printf("Enter title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;
    
    /* Get date from system */
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    date.day = tm.tm_mday;
    date.month = tm.tm_mon + 1;
    date.year = tm.tm_year + 1900;
    
    /* Create watermark */
    create_watermark(&wm, author, title, date);
    print_watermark(wm);
    
    return 0;
}