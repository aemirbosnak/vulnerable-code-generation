//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Music_Record {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music_Record* next;
} Music_Record;

Music_Record* insert_record(Music_Record* head, char* title, char* artist, char* genre, int year) {
    Music_Record* new_record = (Music_Record*)malloc(sizeof(Music_Record));
    strcpy(new_record->title, title);
    strcpy(new_record->artist, artist);
    strcpy(new_record->genre, genre);
    new_record->year = year;
    new_record->next = NULL;

    if (head == NULL) {
        head = new_record;
    } else {
        head->next = new_record;
    }

    return head;
}

void display_records(Music_Record* head) {
    Music_Record* current_record = head;
    while (current_record) {
        printf("Title: %s\n", current_record->title);
        printf("Artist: %s\n", current_record->artist);
        printf("Genre: %s\n", current_record->genre);
        printf("Year: %d\n", current_record->year);
        printf("\n");
        current_record = current_record->next;
    }
}

int main() {
    Music_Record* head = NULL;

    insert_record(head, "The Dark Side of the Moon", "Pink Floyd", "Rock", 1973);
    insert_record(head, "Thriller", "Michael Jackson", "Pop", 1987);
    insert_record(head, "Abbey Road", "The Beatles", "Rock", 1969);

    display_records(head);

    return 0;
}