//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_ENTRIES 10
#define MAX_LENGTH 256

struct entry {
    char date[20];
    char thoughts[MAX_LENGTH];
};

bool stop = false;
struct entry entries[MAX_ENTRIES];
int curr_entry = 0;

void sig_handler(int sig) {
    stop = true;
}

void add_entry(char *date, char *thoughts) {
    struct entry *new_entry = malloc(sizeof(struct entry));
    strcpy(new_entry->date, date);
    strcpy(new_entry->thoughts, thoughts);
    entries[curr_entry++] = *new_entry;
    if (curr_entry >= MAX_ENTRIES) {
        // Remove the oldest entry to make room for the new one
        entries[0] = entries[MAX_ENTRIES - 1];
        curr_entry--;
    }
}

void display_entry() {
    printf("--- %s ---\n", entries[curr_entry - 1].date);
    printf("%s\n", entries[curr_entry - 1].thoughts);
}

void random_entry() {
    int rnd = rand() % curr_entry;
    display_entry();
    curr_entry = rnd;
}

int main() {
    signal(SIGINT, sig_handler);

    while (true) {
        char date[20];
        char thoughts[MAX_LENGTH];

        printf("Enter date: ");
        fgets(date, 20, stdin);
        printf("Enter thoughts: ");
        fgets(thoughts, MAX_LENGTH, stdin);

        add_entry(date, thoughts);

        // Give the user a chance to see the latest entry
        display_entry();

        // Randomly select a previous entry to display
        random_entry();

        usleep(100000);
    }

    return 0;
}