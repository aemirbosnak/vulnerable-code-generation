//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OBJS 10
#define OBJ_SIZE 100

typedef struct obj {
    char name[20];
    int age;
    void (*method)(struct obj *);
} obj;

obj *objects[MAX_OBJS];

void init_objects() {
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        objects[i] = malloc(OBJ_SIZE);
        objects[i]->name[0] = '\0';
        objects[i]->age = 0;
        objects[i]->method = NULL;
    }
}

void free_objects() {
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        if (objects[i]) {
            free(objects[i]);
            objects[i] = NULL;
        }
    }
}

void print_objects() {
    int i;
    for (i = 0; i < MAX_OBJS; i++) {
        if (objects[i]) {
            printf("%s %d\n", objects[i]->name, objects[i]->age);
        }
    }
}

void age_increaser(struct obj *obj) {
    obj->age++;
}

void name_changer(struct obj *obj) {
    obj->name[0] = obj->name[0] == 'A' ? 'B' : 'A';
}

int main() {
    srand(time(NULL));
    init_objects();

    obj *obj1 = malloc(OBJ_SIZE);
    obj1->name[0] = 'A';
    obj1->age = 10;
    obj1->method = age_increaser;

    obj *obj2 = malloc(OBJ_SIZE);
    obj2->name[0] = 'B';
    obj2->age = 20;
    obj2->method = name_changer;

    obj *obj3 = malloc(OBJ_SIZE);
    obj3->name[0] = 'C';
    obj3->age = 30;
    obj3->method = NULL;

    print_objects();

    age_increaser(obj1);
    print_objects();

    name_changer(obj2);
    print_objects();

    free_objects();

    return 0;
}