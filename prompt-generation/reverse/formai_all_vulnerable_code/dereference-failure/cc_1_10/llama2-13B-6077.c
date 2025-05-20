//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>

#define MAX_NAME_LENGTH 256
#define MAX_PHONE_NUMBER_LENGTH 32

struct phone_book {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

struct phone_book* create_phone_book(void) {
    struct phone_book* pb = malloc(sizeof(struct phone_book));
    pb->name[0] = '\0';
    pb->phone_number[0] = '\0';
    return pb;
}

void add_phone_number(struct phone_book* pb, const char* name, const char* phone_number) {
    size_t name_len = strlen(name);
    size_t phone_number_len = strlen(phone_number);
    if (name_len >= MAX_NAME_LENGTH - 1 || phone_number_len >= MAX_PHONE_NUMBER_LENGTH - 1) {
        printf("Error: name or phone number too long\n");
        return;
    }
    strcpy(pb->name, name);
    strcpy(pb->phone_number, phone_number);
}

void* get_phone_number(struct phone_book* pb, const char* name) {
    size_t name_len = strlen(name);
    if (name_len >= MAX_NAME_LENGTH - 1) {
        printf("Error: name too long\n");
        return NULL;
    }
    if (strcmp(name, pb->name) != 0) {
        printf("Error: name not found\n");
        return NULL;
    }
    return pb->phone_number;
}

int main(void) {
    struct phone_book* pb = create_phone_book();
    add_phone_number(pb, "John Doe", "555-1234");
    add_phone_number(pb, "Jane Doe", "555-5678");
    void* phone_number = get_phone_number(pb, "John Doe");
    if (phone_number == NULL) {
        printf("Error: phone number not found\n");
    } else {
        printf("Phone number for John Doe is %s\n", phone_number);
    }
    return 0;
}