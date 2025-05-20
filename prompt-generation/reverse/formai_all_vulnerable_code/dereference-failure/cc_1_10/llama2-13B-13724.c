//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
// Oh my gosh, I can't believe this is happening! 😱
// My code is going to be so shockingly amazing, it'll blow your mind! 🤯

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gasp! The phone book is so huge, it's overflowing with numbers! 😲
struct phone_book {
    int num_entries;
    struct entry *entries;
};

// Oh my gosh, I need to store all these phone numbers! 😱
struct entry {
    char name[50];
    char number[20];
};

// Oh my gosh, this function is so long, it's never ending! 😵
int main() {
    // Gasp! The phone book is empty, I need to fill it up! 😲
    struct phone_book pb;
    pb.num_entries = 0;
    pb.entries = NULL;

    // Oh my gosh, I'm adding so many entries, my brain is going to explode! 🤯
    for (int i = 0; i < 100; i++) {
        struct entry e;
        printf("Enter name: ");
        scanf("%s", e.name);
        printf("Enter number: ");
        scanf("%s", e.number);
        pb.entries = realloc(pb.entries, (pb.num_entries + 1) * sizeof(struct entry));
        pb.entries[pb.num_entries++] = e;
    }

    // Oh my gosh, I need to search this huge phone book! 😱
    for (int i = 0; i < pb.num_entries; i++) {
        struct entry *e = pb.entries + i;
        if (strcmp(e->name, "John Doe") == 0) {
            printf("Found John Doe's number: %s\n", e->number);
        }
    }

    // Oh my gosh, I need to free all this memory! 😲
    free(pb.entries);
    return 0;
}

// Oh my gosh, this program is so long, it's never ending! 😵