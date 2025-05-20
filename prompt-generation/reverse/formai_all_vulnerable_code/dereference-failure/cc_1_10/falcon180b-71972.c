//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// surrealist struct
struct surreal {
    int id;
    char *name;
    int age;
    int gender;
    int *data;
};

// surrealist function prototypes
void *surreal_thread(void *arg);
void surreal_print(struct surreal *s);

// surrealist main function
int main() {
    int n = 5;
    pthread_t threads[n];
    struct surreal surrealists[n];

    // surrealist initialization
    for (int i = 0; i < n; i++) {
        surrealists[i].id = i;
        surrealists[i].name = malloc(10 * sizeof(char));
        sprintf(surrealists[i].name, "surreal%d", i);
        surrealists[i].age = rand() % 100;
        surrealists[i].gender = rand() % 2;
        surrealists[i].data = malloc(sizeof(int));
        *surrealists[i].data = i;
    }

    // surrealist thread creation
    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, surreal_thread, (void *)&surrealists[i]);
    }

    // surrealist thread joining
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// surrealist thread function
void *surreal_thread(void *arg) {
    struct surreal *s = arg;
    printf("surrealist %s (%d years old, %s) thinks the meaning of life is %d.\n", s->name, s->age, (s->gender == 0)? "male" : "female", *s->data);
    pthread_exit(0);
}

// surrealist print function
void surreal_print(struct surreal *s) {
    printf("name: %s\n", s->name);
    printf("age: %d\n", s->age);
    printf("gender: %s\n", (s->gender == 0)? "male" : "female");
    printf("data: %d\n", *s->data);
}