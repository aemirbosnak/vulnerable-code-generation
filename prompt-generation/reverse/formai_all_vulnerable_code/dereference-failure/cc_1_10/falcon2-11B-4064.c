//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct activity {
    char name[20];
    int duration;
    struct activity *next;
};

struct activity *create_activity(char *name, int duration) {
    struct activity *new_activity = (struct activity *)malloc(sizeof(struct activity));
    strcpy(new_activity->name, name);
    new_activity->duration = duration;
    new_activity->next = NULL;
    return new_activity;
}

void add_activity(struct activity **activity_list, char *name, int duration) {
    struct activity *new_activity = create_activity(name, duration);
    if (*activity_list == NULL) {
        *activity_list = new_activity;
    } else {
        struct activity *current = *activity_list;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_activity;
    }
}

void remove_activity(struct activity **activity_list, char *name) {
    struct activity *current = *activity_list;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            break;
        }
        current = current->next;
    }
    if (current!= NULL) {
        if (current == *activity_list) {
            *activity_list = current->next;
        } else {
            struct activity *prev = *activity_list;
            while (prev->next!= current) {
                prev = prev->next;
            }
            prev->next = current->next;
        }
        free(current);
    }
}

void display_activity_list(struct activity *activity_list) {
    struct activity *current = activity_list;
    printf("Activity List:\n");
    while (current!= NULL) {
        printf("%s: %d minutes\n", current->name, current->duration);
        current = current->next;
    }
}

void get_activity(struct activity **activity_list, char *name) {
    struct activity *current = *activity_list;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Activity: %s, Duration: %d minutes\n", current->name, current->duration);
            return;
        }
        current = current->next;
    }
    printf("Activity not found.\n");
}

void delete_activity(struct activity **activity_list, char *name) {
    remove_activity(activity_list, name);
}

int main() {
    struct activity *activity_list = NULL;
    while (1) {
        printf("\n1. Add activity\n2. Display activity list\n3. Get activity\n4. Delete activity\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter activity name: ");
                char name[20];
                fgets(name, sizeof(name), stdin);
                printf("Enter duration (in minutes): ");
                int duration;
                scanf("%d", &duration);
                add_activity(&activity_list, name, duration);
                break;
            case 2:
                display_activity_list(activity_list);
                break;
            case 3:
                printf("Enter activity name: ");
                fgets(name, sizeof(name), stdin);
                get_activity(&activity_list, name);
                break;
            case 4:
                printf("Enter activity name: ");
                fgets(name, sizeof(name), stdin);
                delete_activity(&activity_list, name);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}