//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan (1024-65535)
#define MAX_HOSTS 1024    // maximum number of hosts to scan
#define BUFFER_SIZE 1024  // buffer size for reading and writing

struct host_info {
    char *host_name;  // hostname of the target machine
    int port;        // port number found on the target machine
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <target_host>\n", argv[0]);
        return 1;
    }

    // initialize the host list
    struct host_info *host_list = malloc(MAX_HOSTS * sizeof(struct host_info));
    int i = 0;

    // loop through the target hosts
    for (i = 0; i < MAX_HOSTS; i++) {
        host_list[i].host_name = argv[1];
        host_list[i].port = 0;
    }

    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    // set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(0),
        .sin_addr.s_addr = inet_addr(host_list[i].host_name)
    };

    // connect to the first host
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // loop through the range of ports
    for (int port = 1; port <= PORT_RANGE; port++) {
        // send a SYN packet to the target host
        struct sockaddr_in client_addr = {
            .sin_family = AF_INET,
            .sin_port = htons(port),
            .sin_addr.s_addr = server_addr.sin_addr.s_addr
        };
        int client_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (client_sock < 0) {
            perror("socket() failed");
            exit(1);
        }
        sendto(client_sock, "A", 1, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

        // listen for a response
        char buffer[BUFFER_SIZE];
        int bytes_read = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_read < 0) {
            perror("recvfrom() failed");
            exit(1);
        }

        // check if the response is a SYN-ACK packet
        if (buffer[0] == 0x13 && buffer[1] == 0x00) {
            // extract the port number from the response
            host_list[i].port = ntohs(inet_addr(buffer + 4));
            printf("Port %d found on %s\n", host_list[i].port, host_list[i].host_name);
        }

        // close the client socket
        close(client_sock);
    }

    // close the socket
    close(sock);

    return 0;
}