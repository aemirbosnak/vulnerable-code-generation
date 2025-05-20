//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *username;
    char *password;
} user_t;

typedef struct {
    char *name;
    user_t *users;
    int num_users;
} group_t;

typedef struct {
    group_t *groups;
    int num_groups;
} password_manager_t;

password_manager_t *password_manager_create() {
    password_manager_t *pm = malloc(sizeof(password_manager_t));
    pm->groups = NULL;
    pm->num_groups = 0;
    return pm;
}

void password_manager_destroy(password_manager_t *pm) {
    for (int i = 0; i < pm->num_groups; i++) {
        group_t *group = &pm->groups[i];
        for (int j = 0; j < group->num_users; j++) {
            user_t *user = &group->users[j];
            free(user->username);
            free(user->password);
        }
        free(group->users);
        free(group->name);
    }
    free(pm->groups);
    free(pm);
}

group_t *password_manager_create_group(password_manager_t *pm, char *name) {
    pm->groups = realloc(pm->groups, sizeof(group_t) * (pm->num_groups + 1));
    group_t *group = &pm->groups[pm->num_groups++];
    group->name = strdup(name);
    group->users = NULL;
    group->num_users = 0;
    return group;
}

void password_manager_destroy_group(password_manager_t *pm, group_t *group) {
    for (int i = 0; i < pm->num_groups; i++) {
        if (&pm->groups[i] == group) {
            for (int j = i + 1; j < pm->num_groups; j++) {
                pm->groups[j - 1] = pm->groups[j];
            }
            pm->num_groups--;
            break;
        }
    }
    free(group->name);
    free(group->users);
    free(group);
}

user_t *password_manager_create_user(group_t *group, char *username, char *password) {
    group->users = realloc(group->users, sizeof(user_t) * (group->num_users + 1));
    user_t *user = &group->users[group->num_users++];
    user->username = strdup(username);
    user->password = strdup(password);
    return user;
}

void password_manager_destroy_user(group_t *group, user_t *user) {
    for (int i = 0; i < group->num_users; i++) {
        if (&group->users[i] == user) {
            for (int j = i + 1; j < group->num_users; j++) {
                group->users[j - 1] = group->users[j];
            }
            group->num_users--;
            break;
        }
    }
    free(user->username);
    free(user->password);
    free(user);
}

int main() {
    password_manager_t *pm = password_manager_create();
    group_t *group = password_manager_create_group(pm, "Work");
    user_t *user = password_manager_create_user(group, "Alice", "password123");
    printf("User %s created with password %s\n", user->username, user->password);
    password_manager_destroy_user(group, user);
    password_manager_destroy_group(pm, group);
    password_manager_destroy(pm);
    return 0;
}