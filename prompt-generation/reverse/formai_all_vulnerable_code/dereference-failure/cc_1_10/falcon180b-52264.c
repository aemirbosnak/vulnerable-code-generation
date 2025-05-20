//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* name;
    int age;
    int weight;
    int height;
    int steps;
    int calories;
    time_t last_updated;
} User;

User* create_user(char* name, int age, int weight, int height) {
    User* user = (User*)malloc(sizeof(User));
    user->name = name;
    user->age = age;
    user->weight = weight;
    user->height = height;
    user->steps = 0;
    user->calories = 0;
    user->last_updated = time(NULL);
    return user;
}

void update_user(User* user, int steps, int calories) {
    user->steps += steps;
    user->calories += calories;
    user->last_updated = time(NULL);
}

void print_user(User* user) {
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %d\n", user->weight);
    printf("Height: %d\n", user->height);
    printf("Steps: %d\n", user->steps);
    printf("Calories: %d\n", user->calories);
    printf("Last Updated: %s\n", ctime(&user->last_updated));
}

void delete_user(User* user) {
    free(user->name);
    free(user);
}

int main() {
    User* user1 = create_user("John", 25, 70, 180);
    User* user2 = create_user("Jane", 30, 60, 170);

    update_user(user1, 5000, 300);
    update_user(user2, 7000, 400);

    print_user(user1);
    print_user(user2);

    delete_user(user1);
    delete_user(user2);

    return 0;
}