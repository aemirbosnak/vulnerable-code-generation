//Falcon2-11B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct password_entry
{
    char* username;
    char* password;
} PasswordEntry;

int main()
{
    PasswordEntry* entries = NULL;
    entries = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (entries == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    entries->username = strdup("john.doe");
    entries->password = strdup("password123");

    PasswordEntry* entry2 = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (entry2 == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        free(entries);
        return 1;
    }

    entry2->username = strdup("jane.doe");
    entry2->password = strdup("password456");

    PasswordEntry* entry3 = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (entry3 == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        free(entries);
        free(entry2);
        return 1;
    }

    entry3->username = strdup("jack.black");
    entry3->password = strdup("password789");

    PasswordEntry* entry4 = (PasswordEntry*)malloc(sizeof(PasswordEntry));
    if (entry4 == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        free(entries);
        free(entry2);
        free(entry3);
        return 1;
    }

    entry4->username = strdup("jessica.white");
    entry4->password = strdup("password1011");

    entries = realloc(entries, sizeof(PasswordEntry) * 4);
    if (entries == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        free(entries);
        free(entry2);
        free(entry3);
        free(entry4);
        return 1;
    }

    entries[3].username = strdup("alice.blue");
    entries[3].password = strdup("password2222");

    for (int i = 0; i < 4; i++)
    {
        printf("Username: %s, Password: %s\n", entries[i].username, entries[i].password);
    }

    free(entries);
    free(entry2);
    free(entry3);
    free(entry4);

    return 0;
}