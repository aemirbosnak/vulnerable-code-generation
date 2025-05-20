//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
} Member;

typedef struct {
    int count;
    Member* members;
} List;

void add_member(List* list, const char* name, const char* email) {
    if (list->count == list->members - 1) {
        Member* new_member = (Member*)malloc(sizeof(Member));
        memcpy(new_member->name, name, sizeof(name));
        memcpy(new_member->email, email, sizeof(email));
        list->members = (Member*)realloc(list->members, (list->count + 1) * sizeof(Member));
        list->members[list->count++] = *new_member;
        return;
    } else {
        Member* new_member = &list->members[list->count];
        memcpy(new_member->name, name, sizeof(name));
        memcpy(new_member->email, email, sizeof(email));
        list->members = (Member*)realloc(list->members, (list->count + 1) * sizeof(Member));
        return;
    }
}

void remove_member(List* list, const char* name) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].name, name) == 0) {
            memcpy(name, list->members[i].email, sizeof(name));
            list->members[i].email[sizeof(name)] = '\0';
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return;
        }
    }
}

void display_members(List* list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->members[i].name, list->members[i].email);
    }
}

int main() {
    List list;
    list.count = 0;
    list.members = NULL;

    add_member(&list, "John Doe", "johndoe@example.com");
    add_member(&list, "Jane Smith", "janesmith@example.com");

    display_members(&list);

    remove_member(&list, "Jane Smith");

    display_members(&list);

    return 0;
}