//Falcon2-11B DATASET v1.0 Category: Password management ; Style: rigorous
#include <stdio.h>
#include <string.h>

struct Password {
    char* password;
    struct Password* next;
};

struct Password* createPassword(char* password) {
    struct Password* p = (struct Password*)malloc(sizeof(struct Password));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    p->password = password;
    p->next = NULL;
    return p;
}

void printPasswords(struct Password* p) {
    while (p!= NULL) {
        printf("%s\n", p->password);
        p = p->next;
    }
}

void freePasswords(struct Password* p) {
    while (p!= NULL) {
        struct Password* temp = p->next;
        free(p);
        p = temp;
    }
}

int main() {
    struct Password* head = NULL;

    struct Password* p1 = createPassword("password1");
    struct Password* p2 = createPassword("password2");
    struct Password* p3 = createPassword("password3");

    head = p1;
    p1->next = p2;
    p2->next = p3;

    printf("Passwords:\n");
    printPasswords(head);

    freePasswords(head);

    return 0;
}