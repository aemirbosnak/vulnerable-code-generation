//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define MAX_LINE_LEN 1024
#define MAX_HOSTS 100

struct host {
    char* name;
    char* ip;
};

struct host_list {
    struct host hosts[MAX_HOSTS];
    int size;
};

struct host_list* map_network_topology(char* starting_address) {
    struct host_list* topology = malloc(sizeof(struct host_list));
    memset(topology, 0, sizeof(struct host_list));
    char line[MAX_LINE_LEN];

    // Create a socket for connecting to hosts
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s (errno %d)\n", strerror(errno), errno);
        return topology;
    }

    // Get information about starting host
    struct hostent* host_info = gethostbyname(starting_address);
    if (!host_info) {
        printf("Error getting information about host: %s (errno %d)\n", hstrerror(h_errno), h_errno);
        close(sock);
        return topology;
    }

    // Connect to starting host
    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr = *(struct in_addr*)host_info->h_addr_list[0],
        .sin_port = htons(80)
    };
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to host: %s (errno %d)\n", strerror(errno), errno);
        close(sock);
        return topology;
    }

    // Send HTTP GET request for index page
    char* request = "GET / HTTP/1.0\r\nHost: %s\r\n\r\n";
    char buffer[MAX_LINE_LEN];
    sprintf(buffer, request, starting_address);
    ssize_t bytes_sent = send(sock, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        printf("Error sending data: %s (errno %d)\n", strerror(errno), errno);
        close(sock);
        return topology;
    }

    // Receive and parse HTML for links to other hosts
    while (recv(sock, line, MAX_LINE_LEN, 0) > 0) {
        char* link_start = strstr(line, "<a href=\"http://");
        if (link_start) {
            char* link_end = strstr(link_start, "\">");
            if (link_end) {
                int name_len = link_end - (link_start + 16);
                if (name_len > 0) {
                    char* name = malloc(name_len + 1);
                    strncpy(name, link_start + 16, name_len);
                    name[name_len] = '\0';

                    int ip_len = strlen(starting_address) + 1;
                    char* ip = malloc(ip_len);
                    strncpy(ip, starting_address, ip_len);

                    struct host new_host = {
                        .name = name,
                        .ip = ip
                    };
                    topology->hosts[topology->size++] = new_host;
                }
            }
        }
    }

    // Clean up and return topology
    close(sock);
    return topology;
}

int main(int argc, char** argv) {
    // Check for command-line argument
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    // Map network topology and print results
    struct host_list* topology = map_network_topology(argv[1]);
    printf("Found %d hosts:\n", topology->size);
    for (int i = 0; i < topology->size; i++) {
        printf("%s (%s)\n", topology->hosts[i].name, topology->hosts[i].ip);
        free(topology->hosts[i].name);
        free(topology->hosts[i].ip);
    }

    free(topology);
    return 0;
}