//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

typedef struct user
{
    char name[20];
    char email[40];
    char phone[10];
    struct user* next;
} user;

int is_spelled_correctly(char* word)
{
    int i, j;

    for (i = 0; i < strlen(word); i++)
    {
        for (j = i + 1; j < strlen(word); j++)
        {
            if (word[i] == word[j])
                return 0; // not a palindrome
        }
    }

    return 1; // palindrome
}

void add_user(user** users, char* name, char* email, char* phone)
{
    user* new_user = (user*)malloc(sizeof(user));

    strcpy(new_user->name, name);
    strcpy(new_user->email, email);
    strcpy(new_user->phone, phone);
    new_user->next = NULL;

    (*users)->next = new_user;
    (*users) = new_user;
}

void delete_user(user** users, char* name)
{
    user* current = *users;

    while (current!= NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (current->next == NULL)
            {
                *users = NULL;
                free(current);
            }
            else
            {
                user* temp = current->next;
                free(current);
                *users = temp;
            }
            break;
        }

        current = current->next;
    }
}

void print_users(user* users)
{
    user* current = users;

    while (current!= NULL)
    {
        printf("Name: %s, Email: %s, Phone: %s\n", current->name, current->email, current->phone);
        current = current->next;
    }
}

int main()
{
    user* users = NULL;

    add_user(&users, "John", "john@example.com", "1234567890");
    add_user(&users, "Jane", "jane@example.com", "0987654321");
    add_user(&users, "Bob", "bob@example.com", "5555555555");

    print_users(users);

    printf("Is 'hello' spelled correctly? %d\n", is_spelled_correctly("hello"));

    delete_user(&users, "John");

    print_users(users);

    return 0;
}