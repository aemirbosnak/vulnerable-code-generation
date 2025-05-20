//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_book_entry {
    char *name;
    char *number;
};

struct phone_book {
    int num_entries;
    struct phone_book_entry *entries;
};

struct phone_book *create_phone_book(int num_entries) {
    struct phone_book *pb = malloc(sizeof(struct phone_book));
    pb->num_entries = num_entries;
    pb->entries = malloc(num_entries * sizeof(struct phone_book_entry));
    return pb;
}

void add_entry(struct phone_book *pb, char *name, char *number) {
    struct phone_book_entry *entry = &pb->entries[pb->num_entries++];
    entry->name = strdup(name);
    entry->number = strdup(number);
}

void print_phone_book(struct phone_book *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        struct phone_book_entry *entry = &pb->entries[i];
        printf("%s: %s\n", entry->name, entry->number);
    }
}

void free_phone_book(struct phone_book *pb) {
    for (int i = 0; i < pb->num_entries; i++) {
        struct phone_book_entry *entry = &pb->entries[i];
        free(entry->name);
        free(entry->number);
    }
    free(pb->entries);
    free(pb);
}

int main() {
    struct phone_book *pb = create_phone_book(10);
    add_entry(pb, "John Doe", "555-1212");
    add_entry(pb, "Jane Smith", "555-1213");
    add_entry(pb, "John Smith", "555-1214");
    add_entry(pb, "Jane Doe", "555-1215");
    add_entry(pb, "John Jones", "555-1216");
    add_entry(pb, "Jane Jones", "555-1217");
    add_entry(pb, "John Williams", "555-1218");
    add_entry(pb, "Jane Williams", "555-1219");
    add_entry(pb, "John Brown", "555-1220");
    add_entry(pb, "Jane Brown", "555-1221");

    print_phone_book(pb);

    free_phone_book(pb);

    return 0;
}