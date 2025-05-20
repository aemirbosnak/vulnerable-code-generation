//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_NUM_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char phone_num[MAX_PHONE_NUM_LEN];
} contact_t;

contact_t g_contacts[10];
int g_num_contacts = 0;

void add_contact(const char *name, const char *phone_num) {
    if (g_num_contacts >= sizeof(g_contacts) / sizeof(g_contacts[0])) {
        printf("Shocked! Your phone book is full! :O\n");
        return;
    }

    strcpy(g_contacts[g_num_contacts].name, name);
    strcpy(g_contacts[g_num_contacts].phone_num, phone_num);
    g_num_contacts++;

    printf("Contact added! :D\n");
}

void display_contacts() {
    printf("Here are your contacts:\n");
    for (int i = 0; i < g_num_contacts; i++) {
        printf("Name: %s\nPhone Number: %s\n", g_contacts[i].name, g_contacts[i].phone_num);
    }
    printf("That's all, folks! :O\n");
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        char name[MAX_NAME_LEN];
        char phone_num[MAX_PHONE_NUM_LEN];

        // Generate a random name and phone number
        snprintf(name, MAX_NAME_LEN, "Person %d", i + 1);
        snprintf(phone_num, MAX_PHONE_NUM_LEN, "123-456-7890%c", 'a' + (i % 2));

        add_contact(name, phone_num);
    }

    display_contacts();

    return 0;
}