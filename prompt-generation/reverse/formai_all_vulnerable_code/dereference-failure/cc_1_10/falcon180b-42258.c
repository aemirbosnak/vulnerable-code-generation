//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Structures
struct packet
{
    char *ip;
    char *protocol;
    int port;
};

struct rule
{
    char *ip;
    char *protocol;
    int port;
    int action;
};

//Functions
int stringToIP(char *ipString, char **ip)
{
    char *token = strtok(ipString, ".");
    int count = 0;
    while (token!= NULL)
    {
        (*ip)[count] = token;
        count++;
        token = strtok(NULL, ".");
    }
    (*ip)[count] = '\0';
    return count;
}

int checkRule(struct packet *packet, struct rule *rule)
{
    if (strcmp(packet->protocol, rule->protocol) == 0 && packet->port == rule->port)
    {
        if (rule->action == 1)
        {
            printf("Packet from %s:%d using %s allowed.\n", packet->ip, packet->port, packet->protocol);
        }
        else if (rule->action == 0)
        {
            printf("Packet from %s:%d using %s blocked.\n", packet->ip, packet->port, packet->protocol);
        }
    }
}

int main()
{
    struct packet packet;
    struct rule rule;
    char input[1000];
    while (1)
    {
        printf("Enter packet information (ip protocol port): ");
        fgets(input, sizeof(input), stdin);
        packet.ip = malloc(100);
        packet.protocol = malloc(100);
        packet.port = 0;
        int len = stringToIP(input, &packet.ip);
        strncpy(packet.protocol, input+len+2, strlen(input)-len-3);
        packet.port = atoi(strchr(packet.protocol, ':')+1);
        rule.ip = malloc(100);
        rule.protocol = malloc(100);
        rule.port = 0;
        strncpy(rule.ip, input+len+2, strlen(input)-len-3);
        rule.port = atoi(strchr(rule.protocol, ':')+1);
        strncpy(rule.protocol, input+len+2, strlen(input)-len-3);
        checkRule(&packet, &rule);
    }
    return 0;
}