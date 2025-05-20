//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct member {
    char name[50];
    int phone;
} member_t;

typedef struct list {
    member_t* members;
    int num_members;
} list_t;

void add_member(list_t* list, char name[], int phone) {
    member_t* new_member = (member_t*)malloc(sizeof(member_t));
    if (!new_member) {
        printf("Memory allocation error.\n");
        return;
    }
    strcpy(new_member->name, name);
    new_member->phone = phone;
    list->num_members++;
    list->members = realloc(list->members, list->num_members * sizeof(member_t));
    list->members[list->num_members - 1] = *new_member;
}

void delete_member(list_t* list, int index) {
    if (index < 0 || index >= list->num_members) {
        printf("Invalid index.\n");
        return;
    }
    list->num_members--;
    list->members = realloc(list->members, list->num_members * sizeof(member_t));
    for (int i = index; i < list->num_members - 1; i++) {
        list->members[i] = list->members[i + 1];
    }
}

void display_members(list_t* list) {
    int i;
    for (i = 0; i < list->num_members; i++) {
        printf("Name: %s\nPhone: %d\n", list->members[i].name, list->members[i].phone);
    }
}

int main() {
    list_t* mailing_list = (list_t*)malloc(sizeof(list_t));
    if (!mailing_list) {
        printf("Memory allocation error.\n");
        return 1;
    }
    mailing_list->num_members = 0;
    mailing_list->members = NULL;

    add_member(mailing_list, "John Doe", 12345);
    add_member(mailing_list, "Jane Smith", 56789);
    add_member(mailing_list, "Bob Johnson", 98765);

    display_members(mailing_list);

    delete_member(mailing_list, 1);
    display_members(mailing_list);

    free(mailing_list->members);
    free(mailing_list);

    return 0;
}