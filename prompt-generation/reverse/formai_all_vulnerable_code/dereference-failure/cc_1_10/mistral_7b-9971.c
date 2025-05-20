//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ELF_SIZE 100
#define KEY_SIZE 20
#define TABLE_SIZE 10001

typedef struct Elf {
    char name[KEY_SIZE];
    int strength;
} Elf;

void print_elf(Elf elf) {
    printf("Name: %s\nStrength: %d\n-------------------\n", elf.name, elf.strength);
}

Elf create_elf(char* name) {
    Elf elf = {0};
    strcpy(elf.name, name);
    return elf;
}

int binary_search(Elf table[], int left, int right, Elf elf) {
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(table[mid].name, elf.name) == 0) {
            return mid;
        }
        if (strcmp(table[mid].name, elf.name) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

Elf find_elf(Elf table[], int size, Elf elf) {
    int index = binary_search(table, 0, size - 1, elf);
    if (index != -1) {
        return table[index];
    }
    return (Elf){0};
}

Elf search_elf(Elf elves[], int elves_size, char* name) {
    Elf elf = create_elf(name);
    Elf found_elf = find_elf(elves, elves_size, elf);
    free(elf.name);
    return found_elf;
}

void print_elves(Elf elves[], int size) {
    printf("The elves in the forest:\n");
    for (int i = 0; i < size; ++i) {
        print_elf(elves[i]);
    }
}

Elf* generate_elves(int size) {
    Elf* elves = malloc(size * sizeof(Elf));
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        char name[KEY_SIZE];
        snprintf(name, KEY_SIZE, "Elf %d", i + 1);
        Elf elf = create_elf(name);
        elf.strength = rand() % 100 + 1;
        elves[i] = elf;
    }
    return elves;
}

int main() {
    Elf* elves = generate_elves(ELF_SIZE);
    print_elves(elves, ELF_SIZE);

    char name[KEY_SIZE];
    printf("Enter the name of the elf you want to search for: ");
    scanf("%s", name);

    Elf searched_elf = search_elf(elves, ELF_SIZE, name);
    if (searched_elf.strength > 0) {
        printf("Elf %s found! His strength is %d.\n", searched_elf.name, searched_elf.strength);
    } else {
        printf("Elf %s not found :(\n", name);
    }

    free(elves);
    return 0;
}