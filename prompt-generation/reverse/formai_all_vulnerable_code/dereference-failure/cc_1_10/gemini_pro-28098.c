//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *email;
} contact;

typedef struct {
    int n;
    contact *contacts;
} mailing_list;

mailing_list *new_mailing_list() {
    mailing_list *ml = malloc(sizeof(mailing_list));
    ml->n = 0;
    ml->contacts = NULL;
    return ml;
}

void free_mailing_list(mailing_list *ml) {
    for (int i = 0; i < ml->n; i++) {
        free(ml->contacts[i].name);
        free(ml->contacts[i].email);
    }
    free(ml->contacts);
    free(ml);
}

void add_contact(mailing_list *ml, char *name, char *email) {
    ml->contacts = realloc(ml->contacts, (ml->n + 1) * sizeof(contact));
    ml->contacts[ml->n].name = strdup(name);
    ml->contacts[ml->n].email = strdup(email);
    ml->n++;
}

void remove_contact(mailing_list *ml, int index) {
    if (index < 0 || index >= ml->n) {
        return;
    }
    for (int i = index + 1; i < ml->n; i++) {
        ml->contacts[i - 1] = ml->contacts[i];
    }
    ml->n--;
    ml->contacts = realloc(ml->contacts, ml->n * sizeof(contact));
}

void print_mailing_list(mailing_list *ml) {
    for (int i = 0; i < ml->n; i++) {
        printf("%s <%s>\n", ml->contacts[i].name, ml->contacts[i].email);
    }
}

int main() {
    mailing_list *ml = new_mailing_list();
    add_contact(ml, "Alice", "alice@example.com");
    add_contact(ml, "Bob", "bob@example.com");
    add_contact(ml, "Carol", "carol@example.com");
    print_mailing_list(ml);
    remove_contact(ml, 1);
    print_mailing_list(ml);
    free_mailing_list(ml);
    return 0;
}