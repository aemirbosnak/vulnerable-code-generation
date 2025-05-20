//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LEN 100
#define MAX_FILE_LEN 50

typedef struct {
    char entry[MAX_ENTRY_LEN];
    struct diary_entry *next;
} diary_entry;

diary_entry *head = NULL;

int main(void) {
    char buf[MAX_ENTRY_LEN];
    char fname[MAX_FILE_LEN];
    diary_entry *entry = NULL;

    while (1) {
        printf("Enter an entry (or type 'quit' to exit): ");
        if (fgets(buf, MAX_ENTRY_LEN, stdin) == NULL)
            break;
        if (strcmp(buf, "quit") == 0)
            break;

        entry = (diary_entry*)malloc(sizeof(diary_entry));
        if (entry == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            continue;
        }
        strcpy(entry->entry, buf);
        if (head == NULL) {
            head = entry;
        } else {
            entry->next = head;
            head = entry;
        }

        printf("Entry saved.\n");
    }

    printf("Writing diary entries to file %s...\n", fname);
    FILE *fptr = fopen(fname, "w");
    if (fptr == NULL) {
        fprintf(stderr, "Unable to open file '%s' for writing.\n", fname);
        return 1;
    }

    diary_entry *p = head;
    while (p!= NULL) {
        fputs(p->entry, fptr);
        fputs("\n", fptr);
        p = p->next;
    }
    fclose(fptr);

    printf("Diary entries written to file %s.\n", fname);

    return 0;
}