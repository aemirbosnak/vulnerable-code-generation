//MISTRAL-7B DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MY_MAGIC_NUMBER 0xDEADBEEF

typedef struct {
    int x, y;
} point;

typedef struct {
    char name[20];
    int age;
    point pos;
} person;

void init_person(person *p, char *n, int a, int b, int c) {
    strcpy(p->name, n);
    p->age = a;
    p->pos.x = b;
    p->pos.y = c;
}

void print_person(person p) {
    printf("%s is %d years old and is at (%d, %d)\n", p.name, p.age, p.pos.x, p.pos.y);
}

int main(void) {
    int i;
    person ppl[5];

    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        char name[20];
        int age, x, y;

        sprintf(name, "Person%d", i + 1);
        age = rand() % 100;
        x = rand() % 10;
        y = rand() % 10;

        init_person(&ppl[i], name, age, x, y);
    }

    for (i = 0; i < 5; i++) {
        printf("%s\n", ppl[i].name);
        print_person(ppl[i]);
    }

    for (i = 0; i < 5; i++) {
        person temp = ppl[i];
        int j;

        for (j = i + 1; j < 5; j++) {
            if (ppl[j].age < temp.age) {
                temp = ppl[j];
            }
        }

        person t = ppl[i];
        ppl[i] = temp;
        ppl[j] = t;
    }

    for (i = 0; i < 5; i++) {
        print_person(ppl[i]);
    }

    for (i = 0; i < 5; i++) {
        free(ppl[i].name);
    }

    return EXIT_SUCCESS;
}