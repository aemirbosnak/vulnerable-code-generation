//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_USERS 1000

typedef struct user_data {
    char name[MAX_STRING_LENGTH];
    int age;
    char email[MAX_STRING_LENGTH];
} user_data_t;

typedef struct {
    user_data_t users[MAX_USERS];
    int num_users;
} dataset_t;

void load_data(dataset_t *data) {
    int i, j;
    char line[MAX_STRING_LENGTH];
    FILE *file = fopen("users.txt", "r");

    for (i = 0; i < MAX_USERS; i++) {
        fgets(line, MAX_STRING_LENGTH, file);
        sscanf(line, "%s %d %s", data->users[i].name, &data->users[i].age, data->users[i].email);
    }

    fclose(file);
}

void analyze_data(dataset_t *data) {
    int i, j;
    for (i = 0; i < MAX_USERS; i++) {
        for (j = i + 1; j < MAX_USERS; j++) {
            if (strcmp(data->users[i].name, data->users[j].name) == 0) {
                printf("User %s has duplicate name\n", data->users[i].name);
            }
        }
    }
}

int main() {
    dataset_t data;

    load_data(&data);
    analyze_data(&data);

    return 0;
}