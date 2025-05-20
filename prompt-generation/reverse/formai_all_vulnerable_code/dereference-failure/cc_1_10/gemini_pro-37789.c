//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16

typedef struct
{
    char ip[MAX_IP_LEN];
    int prefix;
    int netmask[4];
    int broadcast[4];
    int host_min[4];
    int host_max[4];
    int num_hosts;
} subnet_info;

int get_ip_parts(char *ip, int *parts)
{
    int i, j, k;
    char *p;
    char *endptr;

    for (i = 0, j = 0; i < 4; i++)
    {
        p = strtok(ip, ".");
        if (p == NULL)
        {
            return -1;
        }

        k = strtol(p, &endptr, 10);
        if (*endptr != '\0')
        {
            return -1;
        }

        parts[j++] = k;
        ip = NULL;
    }

    return 0;
}

int get_netmask_parts(int prefix, int *parts)
{
    int i, j;

    for (i = 0, j = 0; i < 4; i++)
    {
        if (prefix >= 8)
        {
            parts[j++] = 255;
            prefix -= 8;
        }
        else if (prefix > 0)
        {
            parts[j++] = 255 << (8 - prefix);
            prefix = 0;
        }
        else
        {
            parts[j++] = 0;
        }
    }

    return 0;
}

int get_broadcast_parts(int *ip, int *netmask, int *broadcast)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        broadcast[i] = ip[i] | ~netmask[i];
    }

    return 0;
}

int get_host_min_parts(int *ip, int *netmask, int *host_min)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        host_min[i] = ip[i] & netmask[i];
    }

    return 0;
}

int get_host_max_parts(int *broadcast, int *host_max)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        host_max[i] = broadcast[i] & ~1;
    }

    return 0;
}

int get_num_hosts(int prefix)
{
    return (1 << (32 - prefix)) - 2;
}

int print_subnet_info(subnet_info *subnet)
{
    int i;

    printf("IP Address: %s\n", subnet->ip);
    printf("Prefix: %d\n", subnet->prefix);
    printf("Netmask: ");
    for (i = 0; i < 4; i++)
    {
        printf("%d", subnet->netmask[i]);
        if (i < 3)
        {
            printf(".");
        }
    }
    printf("\n");
    printf("Broadcast Address: ");
    for (i = 0; i < 4; i++)
    {
        printf("%d", subnet->broadcast[i]);
        if (i < 3)
        {
            printf(".");
        }
    }
    printf("\n");
    printf("Host Min Address: ");
    for (i = 0; i < 4; i++)
    {
        printf("%d", subnet->host_min[i]);
        if (i < 3)
        {
            printf(".");
        }
    }
    printf("\n");
    printf("Host Max Address: ");
    for (i = 0; i < 4; i++)
    {
        printf("%d", subnet->host_max[i]);
        if (i < 3)
        {
            printf(".");
        }
    }
    printf("\n");
    printf("Number of Hosts: %d\n", subnet->num_hosts);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <IP address> <prefix>\n", argv[0]);
        return -1;
    }

    subnet_info subnet;

    strcpy(subnet.ip, argv[1]);
    subnet.prefix = atoi(argv[2]);

    int ip_parts[4];
    if (get_ip_parts(subnet.ip, ip_parts) != 0)
    {
        printf("Invalid IP address: %s\n", subnet.ip);
        return -1;
    }

    int netmask_parts[4];
    if (get_netmask_parts(subnet.prefix, netmask_parts) != 0)
    {
        printf("Invalid prefix: %d\n", subnet.prefix);
        return -1;
    }

    int broadcast_parts[4];
    if (get_broadcast_parts(ip_parts, netmask_parts, broadcast_parts) != 0)
    {
        printf("Error while calculating broadcast address\n");
        return -1;
    }

    int host_min_parts[4];
    if (get_host_min_parts(ip_parts, netmask_parts, host_min_parts) != 0)
    {
        printf("Error while calculating host min address\n");
        return -1;
    }

    int host_max_parts[4];
    if (get_host_max_parts(broadcast_parts, host_max_parts) != 0)
    {
        printf("Error while calculating host max address\n");
        return -1;
    }

    subnet.netmask[0] = netmask_parts[0];
    subnet.netmask[1] = netmask_parts[1];
    subnet.netmask[2] = netmask_parts[2];
    subnet.netmask[3] = netmask_parts[3];

    subnet.broadcast[0] = broadcast_parts[0];
    subnet.broadcast[1] = broadcast_parts[1];
    subnet.broadcast[2] = broadcast_parts[2];
    subnet.broadcast[3] = broadcast_parts[3];

    subnet.host_min[0] = host_min_parts[0];
    subnet.host_min[1] = host_min_parts[1];
    subnet.host_min[2] = host_min_parts[2];
    subnet.host_min[3] = host_min_parts[3];

    subnet.host_max[0] = host_max_parts[0];
    subnet.host_max[1] = host_max_parts[1];
    subnet.host_max[2] = host_max_parts[2];
    subnet.host_max[3] = host_max_parts[3];

    subnet.num_hosts = get_num_hosts(subnet.prefix);

    print_subnet_info(&subnet);

    return 0;
}