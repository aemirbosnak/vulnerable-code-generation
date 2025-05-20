//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: protected
// Network Topology Mapper in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// Data structures
struct host_info {
    char hostname[1024];
    struct sockaddr_in addr;
};

struct link {
    struct host_info src;
    struct host_info dst;
    int weight;
};

// Function prototypes
int get_host_info(struct host_info *host);
int get_link_info(struct link *link);
void print_topology(struct host_info *hosts, int num_hosts, struct link *links, int num_links);

int main() {
    // Get the number of hosts and links
    int num_hosts, num_links;
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);
    printf("Enter the number of links: ");
    scanf("%d", &num_links);

    // Allocate memory for the hosts and links
    struct host_info *hosts = malloc(sizeof(struct host_info) * num_hosts);
    if (hosts == NULL) {
        perror("malloc");
        exit(1);
    }

    struct link *links = malloc(sizeof(struct link) * num_links);
    if (links == NULL) {
        perror("malloc");
        exit(1);
    }

    // Get the host information
    for (int i = 0; i < num_hosts; i++) {
        printf("Enter the hostname of host %d: ", i + 1);
        scanf("%s", hosts[i].hostname);

        if (get_host_info(&hosts[i]) != 0) {
            fprintf(stderr, "Error getting host information for %s\n", hosts[i].hostname);
            exit(1);
        }
    }

    // Get the link information
    for (int i = 0; i < num_links; i++) {
        printf("Enter the source host of link %d: ", i + 1);
        scanf("%s", links[i].src.hostname);

        if (get_host_info(&links[i].src) != 0) {
            fprintf(stderr, "Error getting source host information for link %d\n", i + 1);
            exit(1);
        }

        printf("Enter the destination host of link %d: ", i + 1);
        scanf("%s", links[i].dst.hostname);

        if (get_host_info(&links[i].dst) != 0) {
            fprintf(stderr, "Error getting destination host information for link %d\n", i + 1);
            exit(1);
        }

        printf("Enter the weight of link %d: ", i + 1);
        scanf("%d", &links[i].weight);
    }

    // Print the topology
    print_topology(hosts, num_hosts, links, num_links);

    // Free the memory
    free(hosts);
    free(links);

    return 0;
}

// Get the IP address and port number of a host
int get_host_info(struct host_info *host) {
    // Get the IP address
    struct hostent *h = gethostbyname(host->hostname);
    if (h == NULL) {
        return -1;
    }

    host->addr.sin_family = h->h_addrtype;
    memcpy(&host->addr.sin_addr, h->h_addr, h->h_length);

    // Get the port number
    struct servent *s = getservbyname("tcp", NULL);
    if (s == NULL) {
        return -1;
    }

    host->addr.sin_port = s->s_port;

    return 0;
}

// Get the weight of a link
int get_link_info(struct link *link) {
    // Get the IP addresses of the source and destination hosts
    struct hostent *h_src = gethostbyname(link->src.hostname);
    if (h_src == NULL) {
        return -1;
    }

    struct hostent *h_dst = gethostbyname(link->dst.hostname);
    if (h_dst == NULL) {
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Connect to the source host
    if (connect(sockfd, (struct sockaddr *)&link->src.addr, sizeof(link->src.addr)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send a message to the source host
    char message[] = "Hello world!";
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive a message from the destination host
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Calculate the round-trip time
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long time = (tv.tv_sec * 1000000) + tv.tv_usec;

    // Calculate the weight of the link
    link->weight = time;

    return 0;
}

// Print the network topology
void print_topology(struct host_info *hosts, int num_hosts, struct link *links, int num_links) {
    printf("Network Topology:\n\n");

    // Print the hosts
    printf("Hosts:\n");
    for (int i = 0; i < num_hosts; i++) {
        printf("    %s (%s)\n", hosts[i].hostname, inet_ntoa(hosts[i].addr.sin_addr));
    }

    // Print the links
    printf("\nLinks:\n");
    for (int i = 0; i < num_links; i++) {
        printf("    %s (%s) - %s (%s) (%d)\n",
            links[i].src.hostname, inet_ntoa(links[i].src.addr.sin_addr),
            links[i].dst.hostname, inet_ntoa(links[i].dst.addr.sin_addr),
            links[i].weight);
    }
}