//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 8

typedef struct {
    char *ip;
    char *mask;
    char *subnet;
    int num_hosts;
    int num_subnets;
} Subnet;

Subnet *create_subnet(char *ip, char *mask) {
    Subnet *s = malloc(sizeof(Subnet));
    s->ip = strdup(ip);
    s->mask = strdup(mask);
    s->subnet = NULL;
    s->num_hosts = 0;
    s->num_subnets = 0;
    return s;
}

void destroy_subnet(Subnet *s) {
    free(s->ip);
    free(s->mask);
    if (s->subnet) {
        free(s->subnet);
    }
    free(s);
}

void add_subnet(Subnet *s, char *subnet) {
    s->subnet = strdup(subnet);
    s->num_subnets++;
}

void add_host(Subnet *s, char *host) {
    s->num_hosts++;
}

void print_subnet(Subnet *s) {
    printf("IP: %s\n", s->ip);
    printf("Mask: %s\n", s->mask);
    printf("Subnet: %s\n", s->subnet);
    printf("Number of hosts: %d\n", s->num_hosts);
    printf("Number of subnets: %d\n", s->num_subnets);
}

int main() {
    Subnet *subnets[MAX_SUBNETS];
    int num_subnets = 0;
    char *ip = "192.168.1.0";
    char *mask = "255.255.255.0";
    char *subnet1 = "192.168.1.0/29";
    char *subnet2 = "192.168.1.8/29";
    char *subnet3 = "192.168.1.16/28";

    Subnet *s1 = create_subnet(ip, mask);
    add_subnet(s1, subnet1);
    add_host(s1, "192.168.1.1");
    add_host(s1, "192.168.1.2");
    add_host(s1, "192.168.1.3");
    add_host(s1, "192.168.1.4");
    add_host(s1, "192.168.1.5");
    add_host(s1, "192.168.1.6");
    add_host(s1, "192.168.1.7");

    Subnet *s2 = create_subnet(ip, mask);
    add_subnet(s2, subnet2);
    add_host(s2, "192.168.1.9");
    add_host(s2, "192.168.1.10");
    add_host(s2, "192.168.1.11");
    add_host(s2, "192.168.1.12");
    add_host(s2, "192.168.1.13");
    add_host(s2, "192.168.1.14");
    add_host(s2, "192.168.1.15");

    Subnet *s3 = create_subnet(ip, mask);
    add_subnet(s3, subnet3);
    add_host(s3, "192.168.1.17");
    add_host(s3, "192.168.1.18");
    add_host(s3, "192.168.1.19");
    add_host(s3, "192.168.1.20");
    add_host(s3, "192.168.1.21");
    add_host(s3, "192.168.1.22");
    add_host(s3, "192.168.1.23");

    subnets[num_subnets++] = s1;
    subnets[num_subnets++] = s2;
    subnets[num_subnets++] = s3;

    for (int i = 0; i < num_subnets; i++) {
        print_subnet(subnets[i]);
    }

    for (int i = 0; i < num_subnets; i++) {
        destroy_subnet(subnets[i]);
    }

    return 0;
}