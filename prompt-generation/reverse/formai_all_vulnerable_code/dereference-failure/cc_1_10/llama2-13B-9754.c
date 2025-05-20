//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PHONE_BOOK_SIZE (1024 * 1024 * 10)
#define NAME_LEN 256
#define PHONE_LEN 20

struct phone_book {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
};

int main() {
    struct phone_book *pb = malloc(PHONE_BOOK_SIZE);
    int i, j;
    char line[NAME_LEN + 1];

    // Load phone book from file
    FILE *fp = fopen("phone_book.txt", "r");
    if (fp == NULL) {
        perror("Failed to open phone book file");
        return 1;
    }
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        fgets(line, NAME_LEN + 1, fp);
        if (feof(fp)) break;
        // Parse line and store in phone book
        sscanf(line, "%255s %19s", pb[i].name, pb[i].phone);
    }
    fclose(fp);

    // Display phone book
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%s: %s\n", pb[i].name, pb[i].phone);
    }

    // Add new entry
    printf("Enter name: ");
    fgets(line, NAME_LEN + 1, stdin);
    sscanf(line, "%255s", pb[i].name);
    printf("Enter phone number: ");
    fgets(line, PHONE_LEN + 1, stdin);
    sscanf(line, "%19s", pb[i].phone);
    i++;

    // Update phone book
    mlock(pb, PHONE_BOOK_SIZE);
    memcpy(&pb[i], &pb[0], i * sizeof(struct phone_book));
    munlock(pb, PHONE_BOOK_SIZE);

    // Display updated phone book
    for (i = 0; i < PHONE_BOOK_SIZE; i++) {
        printf("%s: %s\n", pb[i].name, pb[i].phone);
    }

    return 0;
}