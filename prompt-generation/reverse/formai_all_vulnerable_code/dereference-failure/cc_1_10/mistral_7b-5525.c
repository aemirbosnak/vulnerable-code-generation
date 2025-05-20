//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Alan Turing
/*-------------------------------------------------------------
| Digital Diary by John Doe                                     |
| Inspired by the genius of Alan Turing                          |
|--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARY_SIZE 50

/*-------------------------------------------------------------
| Struct to represent an entry in the diary                     |
--------------------------------------------------------------*/
typedef struct {
    char date[11];
    char description[100];
} DiaryEntry;

/*-------------------------------------------------------------
| Initialize an empty diary                                     |
--------------------------------------------------------------*/
DiaryEntry diary[DIARY_SIZE];
int diary_index = 0;

/*-------------------------------------------------------------
| Add a new entry to the diary                                  |
--------------------------------------------------------------*/
void add_entry(char *date, char *description) {
    if (diary_index >= DIARY_SIZE) {
        printf("Diary is full.\n");
        return;
    }

    strcpy(diary[diary_index].date, date);
    strcpy(diary[diary_index].description, description);
    diary_index++;
}

/*-------------------------------------------------------------
| Print the diary entries                                       |
--------------------------------------------------------------*/
void print_diary() {
    for (int i = 0; i < diary_index; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].description);
    }
}

/*-------------------------------------------------------------
| Main program                                                 |
--------------------------------------------------------------*/
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <date> <description>\n", argv[0]);
        return 1;
    }

    add_entry(argv[1], argv[2]);
    print_diary();

    return 0;
}