//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a diary entry
#define MAX_ENTRY_LENGTH 1024

// Define the maximum number of diary entries
#define MAX_ENTRIES 100

// Define the diary struct
typedef struct diary {
    char entries[MAX_ENTRIES][MAX_ENTRY_LENGTH];
    int num_entries;
} diary_t;

// Create a new diary
diary_t* create_diary() {
    diary_t* diary = malloc(sizeof(diary_t));
    diary->num_entries = 0;
    return diary;
}

// Add a new entry to the diary
void add_entry(diary_t* diary, char* entry) {
    if (diary->num_entries < MAX_ENTRIES) {
        strcpy(diary->entries[diary->num_entries], entry);
        diary->num_entries++;
    }
}

// Print the diary
void print_diary(diary_t* diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i]);
    }
}

// Get the current date and time
char* get_date() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char* date = malloc(sizeof(char) * 100);
    strftime(date, 100, "%Y-%m-%d %H:%M:%S", tm);
    return date;
}

// Main function
int main() {
    // Create a new diary
    diary_t* diary = create_diary();

    // Add some entries to the diary
    add_entry(diary, "Dear Diary,\nI had a great day today. I went to the park with my friends and we played frisbee. I also met a new friend and we talked for hours. I feel so happy and content.");
    add_entry(diary, "Dear Diary,\nI'm feeling a little down today. I had a fight with my friend and I don't know how to fix it. I feel like I'm always the one who has to apologize, even when it's not my fault.");
    add_entry(diary, "Dear Diary,\nI'm so excited! I got a new job and I start tomorrow. I'm nervous, but I'm also really excited to start a new chapter in my life.");

    // Print the diary
    print_diary(diary);

    // Free the diary
    free(diary);

    return 0;
}