//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: unmistakable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entry structure
typedef struct Entry {
    char *title;
    char *content;
    time_t timestamp;
} Entry;

// Linked list node
typedef struct Node {
    Entry *entry;
    struct Node *next;
} Node;

// The digital diary
typedef struct Diary {
    Node *head;
    Node *tail;
    int num_entries;
} Diary;

// Function to create a new entry
Entry *new_entry(char *title, char *content) {
    Entry *entry = malloc(sizeof(Entry));
    entry->title = strdup(title);
    entry->content = strdup(content);
    entry->timestamp = time(NULL);
    return entry;
}

// Function to create a new node
Node *new_node(Entry *entry) {
    Node *node = malloc(sizeof(Node));
    node->entry = entry;
    node->next = NULL;
    return node;
}

// Function to initialize the diary
Diary *new_diary() {
    Diary *diary = malloc(sizeof(Diary));
    diary->head = NULL;
    diary->tail = NULL;
    diary->num_entries = 0;
    return diary;
}

// Function to add an entry to the diary
void add_entry(Diary *diary, Entry *entry) {
    Node *node = new_node(entry);
    if (diary->head == NULL) {
        diary->head = node;
        diary->tail = node;
    } else {
        diary->tail->next = node;
        diary->tail = node;
    }
    diary->num_entries++;
}

// Function to print an entry
void print_entry(Entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Content: %s\n", entry->content);
    printf("Timestamp: %s\n", ctime(&entry->timestamp));
}

// Function to print the diary
void print_diary(Diary *diary) {
    Node *node = diary->head;
    while (node != NULL) {
        print_entry(node->entry);
        node = node->next;
    }
}

// Function to get the number of entries in the diary
int get_num_entries(Diary *diary) {
    return diary->num_entries;
}

// Function to free the memory allocated for the diary
void free_diary(Diary *diary) {
    Node *node = diary->head;
    while (node != NULL) {
        Node *next = node->next;
        free(node->entry->title);
        free(node->entry->content);
        free(node->entry);
        free(node);
        node = next;
    }
    free(diary);
}

// Main function
int main() {
    // Create a new digital diary
    Diary *diary = new_diary();

    // Add some entries to the diary
    add_entry(diary, new_entry("My First Entry", "This is my first entry in my digital diary."));
    add_entry(diary, new_entry("My Second Entry", "This is my second entry in my digital diary."));
    add_entry(diary, new_entry("My Third Entry", "This is my third entry in my digital diary."));

    // Print the diary
    print_diary(diary);

    // Get the number of entries in the diary
    int num_entries = get_num_entries(diary);
    printf("The diary contains %d entries.\n", num_entries);

    // Free the memory allocated for the diary
    free_diary(diary);

    return 0;
}