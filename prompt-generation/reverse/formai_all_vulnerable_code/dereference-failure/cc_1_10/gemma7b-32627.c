//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_HOSTS 10

int main()
{
    int num_hosts = 0;
    char **hosts = NULL;
    struct hostent **hp = NULL;

    // Allocate memory for hosts and hp arrays
    hosts = (char**)malloc(MAX_HOSTS * sizeof(char*));
    hp = (struct hostent**)malloc(MAX_HOSTS * sizeof(struct hostent*));

    // Get the number of hosts
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);

    // Create the hostent array
    hp = (struct hostent**)malloc(num_hosts * sizeof(struct hostent*));

    // Get the host information
    for (int i = 0; i < num_hosts; i++)
    {
        printf("Enter the hostname of host %d: ", i + 1);
        hosts[i] = malloc(256);
        scanf("%s", hosts[i]);
    }

    // Resolve the hostnames
    for (int i = 0; i < num_hosts; i++)
    {
        hp[i] = gethostbyname(hosts[i]);
    }

    // Print the host information
    printf("The following hosts were found:\n");
    for (int i = 0; i < num_hosts; i++)
    {
        printf("Host %d: ", i + 1);
        printf("IP address: %s\n", hp[i]->h_addr);
    }

    // Free the memory
    for (int i = 0; i < num_hosts; i++)
    {
        free(hosts[i]);
    }
    free(hosts);
    free(hp);

    return 0;
}