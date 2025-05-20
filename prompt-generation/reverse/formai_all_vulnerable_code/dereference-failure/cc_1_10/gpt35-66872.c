//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXCHAR 1000

// Function to perform DNS lookup and resolve hostname
char *nslookup(char *hostname) {
    struct hostent *he;
    struct in_addr **addr_list;
    char *ip = malloc(15);
    if ((he = gethostbyname(hostname)) == NULL) {
        herror("gethostbyname");
        return NULL;
    }
    addr_list = (struct in_addr **) he->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }
    return ip;
}

// Main function to generate network topology
int main() {
    char *filename = "network_info.txt"; // File containing network topology information
    FILE *file;
    char line[MAXCHAR];
    char *hostname1, *hostname2, *ip1, *ip2;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }
    printf("Network Topology:\n");
    printf("Hostname 1\tIP Address 1\tHostname 2\tIP Address 2\n");
    printf("---------------------------------------------------------------\n");
    while (fgets(line, MAXCHAR, file) != NULL) {
        hostname1 = strtok(line, ",");
        hostname2 = strtok(NULL, ",");
        ip1 = nslookup(hostname1); // Perform DNS lookup on hostname1
        ip2 = nslookup(hostname2); // Perform DNS lookup on hostname2
        printf("%-15s\t%-15s\t%-15s\t%-15s\n", hostname1, ip1, hostname2, ip2);
        free(ip1); // Free memory allocated for ip1 using malloc
        free(ip2); // Free memory allocated for ip2 using malloc
    }
    fclose(file);
    return 0;
}