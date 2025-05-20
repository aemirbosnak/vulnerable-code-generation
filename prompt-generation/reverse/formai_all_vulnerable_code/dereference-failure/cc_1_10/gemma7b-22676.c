//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SECRET_MESSAGE_LENGTH 1024
#define AGENT_COUNT 20

struct Agent
{
    char name[SECRET_MESSAGE_LENGTH];
    int id;
    struct Agent* next;
};

struct Agent* CreateAgent(int id)
{
    struct Agent* newAgent = malloc(sizeof(struct Agent));
    newAgent->id = id;
    newAgent->next = NULL;

    return newAgent;
}

void InsertAgent(struct Agent* head, struct Agent* newAgent)
{
    if (head == NULL)
    {
        head = newAgent;
    }
    else
    {
        head->next = newAgent;
        head = newAgent;
    }
}

void PrintAgentList(struct Agent* head)
{
    struct Agent* currentAgent = head;

    while (currentAgent)
    {
        printf("%s (ID: %d) -> ", currentAgent->name, currentAgent->id);
        currentAgent = currentAgent->next;
    }

    printf("\n");
}

int main()
{
    struct Agent* head = NULL;

    // Create a bunch of agents
    for (int i = 0; i < AGENT_COUNT; i++)
    {
        struct Agent* newAgent = CreateAgent(i);
        sprintf(newAgent->name, "Agent %d", i);
        InsertAgent(head, newAgent);
    }

    // Print the agent list
    PrintAgentList(head);

    // Now, let's add some secret messages to each agent
    for (struct Agent* currentAgent = head; currentAgent; currentAgent = currentAgent->next)
    {
        sprintf(currentAgent->name, "Agent %d: %s", currentAgent->id, "This is agent secret message number: "  );
    }

    // Print the updated agent list
    PrintAgentList(head);

    return 0;
}