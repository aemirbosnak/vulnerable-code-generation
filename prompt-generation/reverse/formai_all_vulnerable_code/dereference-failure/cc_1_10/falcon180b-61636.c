//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int key;
    int value;
} Pair;

Pair* hashtable;
int size;

void init_hashtable() {
    hashtable = (Pair*)malloc(MAX_SIZE * sizeof(Pair));
    if (hashtable == NULL) {
        printf("Error: Could not allocate memory for hashtable.\n");
        exit(1);
    }
    size = 0;
}

int hash(int key) {
    return key % MAX_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    int i = 0;
    while (hashtable[index].key!= -1 && i < MAX_SIZE) {
        if (hashtable[index].key == key) {
            hashtable[index].value = value;
            return;
        }
        index = (index + i) % MAX_SIZE;
        i++;
    }
    hashtable[index].key = key;
    hashtable[index].value = value;
    size++;
}

int search(int key) {
    int index = hash(key);
    int i = 0;
    while (hashtable[index].key!= -1 && i < MAX_SIZE) {
        if (hashtable[index].key == key) {
            return hashtable[index].value;
        }
        index = (index + i) % MAX_SIZE;
        i++;
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 1000000; i++) {
        int key = rand() % MAX_SIZE;
        int value = rand() % MAX_SIZE;
        insert(key, value);
    }
    for (i = 0; i < 1000000; i++) {
        int key = rand() % MAX_SIZE;
        int value = search(key);
        if (value!= -1) {
            printf("%d -> %d\n", key, value);
        }
    }
    return 0;
}