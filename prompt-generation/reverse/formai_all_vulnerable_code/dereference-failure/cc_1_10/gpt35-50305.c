//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 50
#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

void *calculateSubnet(void *);
int getHosts(int);

typedef struct {
    char *ip;
    int subnet;
} ip_subnet;

int main() {
    int num_ips, i,j;
    ip_subnet *ip_sub;
    pthread_t tid[MAX_THREADS];

    printf("Enter number of IP addresses to calculate subnet for: ");
    scanf("%d", &num_ips);

    ip_sub = (ip_subnet*)malloc(num_ips*sizeof(ip_subnet));

    printf("Enter IP addresses (in format xxx.xxx.xxx.xxx with no spaces):\n");
    for(i=0; i<num_ips; i++) {
        ip_sub[i].ip = (char*)malloc((MAX_IP_LENGTH+1)*sizeof(char));
        scanf("%s", ip_sub[i].ip);

        printf("Enter the subnet mask (in range 0-32): ");
        scanf("%d", &ip_sub[i].subnet);

        pthread_create(&tid[i], NULL, calculateSubnet, (void *)&ip_sub[i]);
    }

    for(j=0; j<i; j++) {
        pthread_join(tid[j], NULL);
        free(ip_sub[j].ip);
    }
    free(ip_sub);

    return 0;
}

void *calculateSubnet(void *arg) {
    ip_subnet *ip_sub = (ip_subnet*)arg;
    char *ip = ip_sub->ip;
    int subnet = ip_sub->subnet, i;
    char subnet_bits[MAX_IP_LENGTH+1];
    int decimal_subnet[4];
    int wildcard_mask[4];
    int network_address[4];
    int broadcast_address[4];
    int min_address[4];
    int max_address[4];
    int num_hosts;

    memset(subnet_bits, '0', MAX_IP_LENGTH);

    for(i=0; i<subnet; i++) {
        subnet_bits[i] = '1';
    }

    sscanf(ip, "%d.%d.%d.%d", &decimal_subnet[0], &decimal_subnet[1], &decimal_subnet[2], &decimal_subnet[3]);
    for(i=0; i<4; i++) {
        wildcard_mask[i] = 255 - (int)subnet_bits[i*8];
        network_address[i] = decimal_subnet[i] & (int)subnet_bits[i*8];
        broadcast_address[i] = decimal_subnet[i] | wildcard_mask[i];
        if(i==3) {
            min_address[i] = network_address[i] + 1;
            max_address[i] = broadcast_address[i] - 1;
        } else {
            min_address[i] = network_address[i];
            max_address[i] = broadcast_address[i];
        }
    }

    num_hosts = getHosts(subnet);

    printf("IP: %s\n", ip);
    printf("Subnet: %d\n", subnet);
    printf("Wildcard Mask: %d.%d.%d.%d\n", wildcard_mask[0], wildcard_mask[1], wildcard_mask[2], wildcard_mask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("First Usable Address: %d.%d.%d.%d\n", min_address[0], min_address[1], min_address[2], min_address[3]);
    printf("Last Usable Address: %d.%d.%d.%d\n", max_address[0], max_address[1], max_address[2], max_address[3]);
    printf("Number of Hosts: %d\n", num_hosts);
    printf("----\n");

    pthread_exit(NULL);
}

int getHosts(int subnet) {
    return (1<<(32-subnet))-2;
}