//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256
#define MAX_SUBJECT_LEN 256
#define MAX_BODY_LEN 4096

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    contact *contacts;
    int num_contacts;
} mailing_list;

void init_contact(contact *c) {
    strcpy(c->name, "");
    strcpy(c->email, "");
}

void init_mailing_list(mailing_list *ml) {
    ml->contacts = NULL;
    ml->num_contacts = 0;
}

int add_contact(mailing_list *ml, contact *c) {
    ml->contacts = realloc(ml->contacts, sizeof(contact) * (ml->num_contacts + 1));
    if (ml->contacts == NULL) {
        return -1;
    }
    memcpy(&ml->contacts[ml->num_contacts], c, sizeof(contact));
    ml->num_contacts++;
    return 0;
}

int remove_contact(mailing_list *ml, int index) {
    if (index >= ml->num_contacts || index < 0) {
        return -1;
    }
    ml->num_contacts--;
    ml->contacts = realloc(ml->contacts, sizeof(contact) * ml->num_contacts);
    if (ml->contacts == NULL) {
        return -1;
    }
    return 0;
}

int send_email(mailing_list *ml, char *subject, char *body) {
    int i;
    for (i = 0; i < ml->num_contacts; i++) {
        printf("Sending email to %s (%s)\n", ml->contacts[i].name, ml->contacts[i].email);
    }
    return 0;
}

int main() {
    mailing_list ml;
    init_mailing_list(&ml);

    contact c;
    init_contact(&c);

    while (1) {
        printf("Enter name: ");
        scanf("%s", c.name);

        printf("Enter email: ");
        scanf("%s", c.email);

        add_contact(&ml, &c);
    }

    return 0;
}