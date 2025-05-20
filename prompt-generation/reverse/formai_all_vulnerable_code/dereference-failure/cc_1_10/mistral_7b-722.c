//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <time.h>

#define HAUNTED_HOUSE_SIZE 1024
#define SHAPE_SHIFT_MAGIC 0xdeadbeef

typedef struct HauntedHouse {
    int magic;
    char name[32];
    int length;
    char *data;
} HauntedHouse;

HauntedHouse *create_haunted_house() {
    HauntedHouse *hh = mmap(NULL, HAUNTED_HOUSE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (hh == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    hh->magic = SHAPE_SHIFT_MAGIC;
    strcpy(hh->name, "Haunted House");
    hh->length = 0;
    hh->data = NULL;
    return hh;
}

void destroy_haunted_house(HauntedHouse *hh) {
    munmap(hh, HAUNTED_HOUSE_SIZE);
}

void add_to_haunted_house(HauntedHouse *hh, const char *str) {
    size_t len = strlen(str) + 1;
    if (hh->length + len > HAUNTED_HOUSE_SIZE - sizeof(HauntedHouse) - 16) {
        fprintf(stderr, "Haunted house is too small\n");
        return;
    }

    hh->length += len;

    char *new_data = hh->data + hh->length - len;
    memcpy(new_data, str, len);
}

void print_haunted_house(const HauntedHouse *hh) {
    printf("Name: %s\n", hh->name);
    printf("Length: %d\n", hh->length);
    printf("Data:\n");
    const char *data = hh->data;
    for (int i = 0; i < hh->length; ++i) {
        putchar(data[i]);
    }
    putchar('\n');
}

int main() {
    HauntedHouse *hh = create_haunted_house();

    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        int len = 1 + rand() % 20;
        char str[len];
        for (int j = 0; j < len; ++j) {
            str[j] = 'A' + rand() % 26;
        }
        add_to_haunted_house(hh, str);
    }

    print_haunted_house(hh);

    destroy_haunted_house(hh);

    return EXIT_SUCCESS;
}