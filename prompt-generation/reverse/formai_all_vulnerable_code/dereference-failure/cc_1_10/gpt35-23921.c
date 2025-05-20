//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

//set up constants for use in the program (useful and readable)
#define MAX_NODES 100
#define MAX_CONN 500

//define structures you will be using in the program (e.g. for nodes and connections)
typedef struct node { 
    char *name; 
    char *ip_str; 
    struct in_addr ip_address;
    int has_details; 
} node;

typedef struct connection {
    node *node1; 
    node *node2;
    int has_details; 
} connection;

//declare variables that you will use in the program
node *nodes[MAX_NODES];
connection *connections[MAX_CONN];
int num_nodes = 0, num_connections = 0;

//utility function to allow printing of IP addresses
void print_ip(struct in_addr ip_address) {
   char str[INET_ADDRSTRLEN];
   inet_ntop(AF_INET, &ip_address, str, INET_ADDRSTRLEN);
   printf("%s", str);
}

int main(int argc, char **argv) {
    struct addrinfo hints, *res;
    struct sockaddr_in *addr;
    struct hostent *hostinfo;
    const char *node_name;

    node_name = argv[1];
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(node_name, NULL, &hints, &res)) {
        perror("Error: ");
        exit(1);
    }
    addr = (struct sockaddr_in *) res->ai_addr;
    hostinfo = gethostbyaddr((char *) &addr->sin_addr, sizeof(addr->sin_addr), AF_INET);
    if (hostinfo == NULL) {
        printf("Couldn't resolve host %s\n", node_name);
        exit(1);

    } else
        printf("Hostname of %s is %s\n", node_name, hostinfo->h_name);
    printf("IP address of %s is ", node_name);
    print_ip(addr->sin_addr);
    printf("\n");
    return 0;
}