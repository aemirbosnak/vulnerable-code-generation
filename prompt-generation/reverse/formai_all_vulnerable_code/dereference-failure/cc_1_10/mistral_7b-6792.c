//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Dennis Ritchie
#define MAX_SIZE 10
#define ELEMENT_SIZE 20

typedef struct ArrayList {
    int size;
    int capacity;
    void *elements;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->elements = malloc(MAX_SIZE * ELEMENT_SIZE);
    list->size = 0;
    list->capacity = MAX_SIZE;
}

int isFull(ArrayList *list) {
    return list->size == list->capacity;
}

int addElement(ArrayList *list, int index, void *element) {
    if (isFull(list)) {
        list->capacity *= 2;
        list->elements = realloc(list->elements, list->capacity * ELEMENT_SIZE);
    }

    if (index < 0 || index > list->size) {
        return -1;
    }

    memmove((char *)list->elements + index * ELEMENT_SIZE, (char *)list->elements + index * ELEMENT_SIZE + ELEMENT_SIZE, (list->size - index) * ELEMENT_SIZE);
    memcpy((char *)list->elements + index * ELEMENT_SIZE, element, ELEMENT_SIZE);

    list->size++;

    return 0;
}

void removeElement(ArrayList *list, int index) {
    if (index < 0 || index >= list->size) {
        return;
    }

    memmove((char *)list->elements + index * ELEMENT_SIZE, (char *)list->elements + (index + 1) * ELEMENT_SIZE, ((list->size - (index + 1)) * ELEMENT_SIZE));

    list->size--;
}

void printArrayList(ArrayList *list) {
    for (int i = 0; i < list->size; ++i) {
        printf("%.*s\n", ELEMENT_SIZE, (char *)list->elements + i * ELEMENT_SIZE);
    }
}

int main() {
    ArrayList myList;
    initArrayList(&myList);

    addElement(&myList, 0, "Hello");
    addElement(&myList, 1, "World");
    addElement(&myList, 2, "Dennis");
    addElement(&myList, 3, "Ritchie");

    printArrayList(&myList);

    removeElement(&myList, 1);

    printArrayList(&myList);

    return 0;
}