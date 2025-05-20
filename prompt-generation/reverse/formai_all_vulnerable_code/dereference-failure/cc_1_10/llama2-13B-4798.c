//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define PHONEBOOK_SIZE 100
#define NAME_MAX_LEN 25
#define PHONE_MAX_LEN 20

struct phonebook {
    char name[NAME_MAX_LEN];
    char phone[PHONE_MAX_LEN];
};

typedef struct phonebook phonebook_t;

phonebook_t *phonebook_create(void) {
    phonebook_t *pb = malloc(sizeof(phonebook_t));
    pb->name[0] = '\0';
    pb->phone[0] = '\0';
    return pb;
}

void phonebook_add(phonebook_t *pb, const char *name, const char *phone) {
    strcpy(pb->name, name);
    strcpy(pb->phone, phone);
}

phonebook_t *phonebook_search(phonebook_t *pb, const char *name) {
    int i;
    for (i = 0; i < PHONEBOOK_SIZE; i++) {
        if (strcmp(pb->name, name) == 0) {
            return pb;
        }
        pb++;
    }
    return NULL;
}

void phonebook_delete(phonebook_t *pb, const char *name) {
    int i;
    for (i = 0; i < PHONEBOOK_SIZE; i++) {
        if (strcmp(pb->name, name) == 0) {
            break;
        }
        pb++;
    }
    if (i < PHONEBOOK_SIZE) {
        memset(pb->name, 0, NAME_MAX_LEN);
        memset(pb->phone, 0, PHONE_MAX_LEN);
    }
}

int main(void) {
    srand(time(NULL));
    phonebook_t *pb = phonebook_create();

    for (int i = 0; i < 10; i++) {
        char name[NAME_MAX_LEN];
        char phone[PHONE_MAX_LEN];
        int len;

        len = rand() % (NAME_MAX_LEN - 1) + 1;
        for (int j = 0; j < len; j++) {
            name[j] = 'a' + (rand() % 26);
        }
        name[len] = '\0';

        len = rand() % (PHONE_MAX_LEN - 1) + 1;
        for (int j = 0; j < len; j++) {
            phone[j] = 'a' + (rand() % 26);
        }
        phone[len] = '\0';

        phonebook_add(pb, name, phone);
    }

    for (int i = 0; i < 10; i++) {
        phonebook_t *found = phonebook_search(pb, "John Doe");
        if (found != NULL) {
            printf("Found phone number for John Doe: %s\n", found->phone);
        } else {
            printf("No phone number found for John Doe\n");
        }
    }

    return 0;
}