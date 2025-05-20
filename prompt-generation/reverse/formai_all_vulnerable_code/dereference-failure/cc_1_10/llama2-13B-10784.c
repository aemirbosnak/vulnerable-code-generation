//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan (1024-65535)
#define MAX_HOST_LEN 50 // maximum length of hostname or IP address

struct host_info {
    char host[MAX_HOST_LEN]; // hostname or IP address
    int port; // port number
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_or_ip_address>\n", argv[0]);
        return 1;
    }

    struct host_info *host_list = malloc(sizeof(struct host_info) * PORT_RANGE);
    int i, j;

    // initialize host list with all possible ports
    for (i = 0; i < PORT_RANGE; i++) {
        host_list[i].port = htons(i + 1); // port number
        strcpy(host_list[i].host, "localhost"); // initialize with localhost
    }

    // parse command line argument and fill in host list
    if (strcmp(argv[1], "--all") == 0) {
        // scan all possible hosts
        for (i = 0; i < PORT_RANGE; i++) {
            host_list[i].host[0] = 0; // clear hostname
        }
    } else {
        // scan specific host
        strcpy(host_list[0].host, argv[1]);
    }

    // loop through host list and perform port scan
    for (i = 0; i < PORT_RANGE; i++) {
        struct sockaddr_in server_addr;
        socklen_t address_len = sizeof(server_addr);
        int client_fd;

        // create socket
        if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket creation failed");
            exit(1);
        }

        // set address and port number
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(host_list[i].host);
        server_addr.sin_port = htons(host_list[i].port);

        // connect to server
        if (connect(client_fd, (struct sockaddr *)&server_addr, address_len) < 0) {
            perror("connect failed");
            exit(1);
        }

        // send request packet
        char request_packet[] = "Hello, world!";
        send(client_fd, request_packet, strlen(request_packet), 0);

        // receive response packet
        char response_packet[1024];
        recv(client_fd, response_packet, 1024, 0);

        // print response
        printf("%s\n", response_packet);

        // close socket
        close(client_fd);
    }

    // free host list memory
    free(host_list);

    return 0;
}