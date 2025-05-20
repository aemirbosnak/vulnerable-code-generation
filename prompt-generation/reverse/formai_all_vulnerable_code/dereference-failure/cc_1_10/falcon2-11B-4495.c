//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

// Function to get host IP address
void getHostIP(char *host, char *ip) {
    struct hostent *server;
    struct in_addr *ipaddr;

    if ((server = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    ipaddr = (struct in_addr *) server->h_addr;
    strcpy(ip, inet_ntoa(*ipaddr));
}

// Function to get network topology
void getNetworkTopology(char *host, char *ip) {
    FILE *fp;
    char file[50];

    sprintf(file, "/proc/%s/net/dev", ip);
    if ((fp = fopen(file, "r")) == NULL) {
        printf("Error opening file %s\n", file);
        exit(1);
    }

    while (fgets(host, 100, fp)!= NULL) {
        printf("%s\n", host);
    }

    fclose(fp);
}

int main() {
    char host[50];
    char ip[50];

    printf("Enter hostname: ");
    scanf("%s", host);

    getHostIP(host, ip);

    getNetworkTopology(host, ip);

    return 0;
}