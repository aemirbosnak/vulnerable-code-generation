//FormAI DATASET v1.0 Category: Firewall ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FireWall
{
    char *ip;
    char *protocol;
    int port;
};

void firewallRule(struct FireWall f[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("FireWall Rule #%d:\n", i + 1);
        printf("\tIP Address: %s\n", f[i].ip);
        printf("\tProtocol: %s\n", f[i].protocol);
        printf("\tPort: %d\n", f[i].port);
    }
}

int main()
{
    int numOfRules;
    printf("Enter the number of Firewall Rules: ");
    scanf("%d", &numOfRules);

    struct FireWall rules[numOfRules];

    for (int i = 0; i < numOfRules; i++)
    {
        rules[i].ip = (char *)malloc(sizeof(char) * 15);
        printf("\nEnter IP Address for Rule #%d: ", i + 1);
        scanf("%s", rules[i].ip);

        rules[i].protocol = (char *)malloc(sizeof(char) * 5);
        printf("Enter Protocol (TCP/UDP): ");
        scanf("%s", rules[i].protocol);

        printf("Enter Port: ");
        scanf("%d", &rules[i].port);
    }

    printf("\n\nFirewall Rules Set:\n");
    firewallRule(rules, numOfRules);

    // free up allocated memory
    for (int i = 0; i < numOfRules; i++)
    {
        free(rules[i].ip);
        free(rules[i].protocol);
    }

    return 0;
}