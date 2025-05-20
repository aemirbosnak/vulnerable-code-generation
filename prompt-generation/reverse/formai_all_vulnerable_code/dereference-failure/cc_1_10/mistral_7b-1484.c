//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[100];
} Person;

typedef struct Node {
    Person data;
    struct Node *next;
} Node;

Node *head = NULL;

void add_to_list(Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = p;
    new_node->next = head;
    head = new_node;
}

void print_list() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%s: %s\n", temp->data.name, temp->data.email);
        temp = temp->next;
    }
}

void main() {
    Person romeo = {"Romeo Montague", "romeo@montague.com"};
    Person juliet = {"Juliet Capulet", "juliet@capulet.com"};

    add_to_list(romeo);
    add_to_list(juliet);

    printf("Prince Escalus: Call forth those who are to attend\n");
    print_list();

    Person benvolio = {"Benvolio Montague", "benvolio@montague.com"};
    Person tybalt = {"Tybalt Capulet", "tybalt@capulet.com"};

    add_to_list(benvolio);
    add_to_list(tybalt);

    printf("\nFriar Laurence: Now hear this out, you men, you boys,\n");
    print_list();

    Person friar_laurence = {"Friar Laurence", "friar_laurence@friary.com"};

    add_to_list(friar_laurence);

    printf("\nFriar Laurence: Give me your attention, every one,\n");
    print_list();

    Person nurse = {"Nurse", "nurse@capulet.house"};

    add_to_list(nurse);

    printf("\nNurse: Hark ye, good Capulets, get you to the church,\n");
    print_list();

    Person capulet = {"Lord Capulet", "lord_capulet@capulet.com"};

    add_to_list(capulet);

    printf("\nLord Capulet: Hark you, attend, my Capulets and Montagues,\n");
    print_list();
}