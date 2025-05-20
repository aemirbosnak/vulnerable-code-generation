//Gemma-7B DATASET v1.0 Category: System administration ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

int main()
{
    // Define a structure to store system information
    typedef struct SystemInfo
    {
        char name[MAX_NAME_LENGTH];
        int port;
        struct SystemInfo *next;
    } SystemInfo;

    // Create a linked list of system information
    SystemInfo *head = NULL;

    // Simulate post-apocalyptic environment
    char environment[] = "The ruins of the once great city of Los Angeles";

    // Print the environment
    printf("%s\n", environment);

    // Add some system information to the linked list
    SystemInfo *new_system = malloc(sizeof(SystemInfo));
    strcpy(new_system->name, "The Oracle");
    new_system->port = 8080;
    new_system->next = NULL;
    head = new_system;

    // Add more system information to the linked list
    new_system = malloc(sizeof(SystemInfo));
    strcpy(new_system->name, "The Phoenix");
    new_system->port = 8081;
    new_system->next = NULL;
    head->next = new_system;

    // Print the system information
    SystemInfo *current_system = head;
    while (current_system)
    {
        printf("System name: %s\n", current_system->name);
        printf("Port: %d\n", current_system->port);
        printf("\n");
        current_system = current_system->next;
    }

    return 0;
}