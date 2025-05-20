//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct knight {
    char name[MAX_NAME_LENGTH];
    int age;
};

void knight_init(struct knight *knight, char *name, int age) {
    strcpy(knight->name, name);
    knight->age = age;
}

void knight_display(struct knight *knight) {
    printf("Hail, good sir/madam! My name is %s, and I am %d years young.\n", knight->name, knight->age);
}

int knight_is_alive(struct knight *knight) {
    if (knight->age > 0) {
        return 1;
    } else {
        return 0;
    }
}

void knight_kill(struct knight *knight) {
    knight->age = -1;
}

int main() {
    struct knight knight;
    char name[MAX_NAME_LENGTH];
    int age;

    // Initialize knight
    knight_init(&knight, name, age);

    // Display knight
    knight_display(&knight);

    // Check if knight is alive
    if (knight_is_alive(&knight)) {
        printf("Ah, a brave knight still lives!\n");
    } else {
        printf("Alas, the knight has met his demise...\n");
    }

    // Kill the knight
    knight_kill(&knight);

    return 0;
}