//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_EMAIL_SIZE 100
#define MAX_NAME_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
    struct node* next;
} node;

typedef struct {
    node* head;
    int size;
} list;

void init_list(list* lst) {
    lst->head = NULL;
    lst->size = 0;
}

void add_node(list* lst, char* name, char* email) {
    node* new_node = (node*) malloc(sizeof(node));
    strcpy(new_node->name, name);
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if(lst->head == NULL) {
        lst->head = new_node;
    } else {
        node* curr_node = lst->head;
        while(curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }

    lst->size++;
}

void print_list(list* lst) {
    node* curr_node = lst->head;
    while(curr_node!= NULL) {
        printf("Name: %s\nEmail: %s\n", curr_node->name, curr_node->email);
        curr_node = curr_node->next;
    }
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    list mailing_list;
    init_list(&mailing_list);

    char line[MAX_LINE_SIZE];
    while(fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        char* name = strtok(line, ",");
        char* email = strtok(NULL, ",");

        if(name!= NULL && email!= NULL) {
            add_node(&mailing_list, name, email);
        }
    }

    fclose(input_file);

    print_list(&mailing_list);

    return 0;
}