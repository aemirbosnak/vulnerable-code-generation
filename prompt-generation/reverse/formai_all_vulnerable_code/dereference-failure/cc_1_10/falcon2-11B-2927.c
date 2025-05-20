//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MAX_CAPACITY 1000

typedef struct {
    char key[MAX_LENGTH];
    int value;
} Word;

typedef struct {
    Word* array;
    int capacity;
    int length;
} HashMap;

void initialize_map(HashMap* map, int capacity) {
    map->capacity = capacity;
    map->length = 0;
    map->array = (Word*)malloc(capacity * sizeof(Word));
    for (int i = 0; i < capacity; i++) {
        map->array[i].key[0] = '\0';
        map->array[i].value = 0;
    }
}

void print_map(HashMap* map) {
    for (int i = 0; i < map->length; i++) {
        printf("%s: %d\n", map->array[i].key, map->array[i].value);
    }
}

void insert_word(HashMap* map, char* key) {
    int i;
    for (i = 0; i < map->length; i++) {
        if (strcmp(map->array[i].key, key) == 0) {
            map->array[i].value++;
            return;
        }
    }
    if (map->length >= map->capacity) {
        Word* new_array = (Word*)realloc(map->array, (map->capacity + MAX_CAPACITY) * sizeof(Word));
        for (int j = 0; j < map->capacity; j++) {
            new_array[j] = map->array[j];
        }
        free(map->array);
        map->array = new_array;
        map->capacity += MAX_CAPACITY;
    }
    strcpy(map->array[map->length].key, key);
    map->array[map->length].value = 1;
    map->length++;
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline character

    HashMap map;
    initialize_map(&map, MAX_CAPACITY);
    for (int i = 0; text[i]!= '\0'; i++) {
        char c = tolower(text[i]);
        insert_word(&map, &c);
    }
    print_map(&map);
    return 0;
}