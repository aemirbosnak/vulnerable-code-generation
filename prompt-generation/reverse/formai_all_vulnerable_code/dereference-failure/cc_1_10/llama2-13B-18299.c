//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan
#define MAX_HOSTS 1024    // maximum number of hosts to scan

struct host_info {
    char *host;      // hostname or IP address
    int port;        // open port or error message
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host_or_ip_address>\n", argv[0]);
        return 1;
    }

    // initialize list of host_info structures
    struct host_info *hosts = calloc(MAX_HOSTS, sizeof(struct host_info));

    // loop through hosts and ports
    for (int i = 0; i < MAX_HOSTS; i++) {
        // generate a random hostname or IP address
        char *host = calloc(1, sizeof(char));
        if (rand() % 2 == 0) {
            // generate a random IP address
            host = calloc(4, sizeof(char));
            sprintf(host, "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        } else {
            // generate a random hostname
            host = calloc(1, sizeof(char));
            sprintf(host, "%d.%d.%d.%d", rand() % 256, rand() % 256, rand() % 256, rand() % 256);
        }

        // create a socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket creation failed");
            continue;
        }

        // set address and port
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(rand() % 65536);
        inet_pton(AF_INET, host, &server_addr.sin_addr);

        // connect to the server
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connection failed");
            continue;
        }

        // send a SYN packet to the server
        char *packet = calloc(1, sizeof(char));
        packet[0] = 0x12; // SYN packet
        send(sock, packet, 1, 0);

        // receive a response from the server
        char buffer[1024];
        recv(sock, buffer, 1024, 0);

        // check if the response is a SYN-ACK packet
        if (buffer[0] == 0x12) {
            // port is open
            hosts[i].port = ntohs(server_addr.sin_port);
        } else {
            // port is closed or error
            hosts[i].port = -1;
        }

        // close the socket
        close(sock);
    }

    // print the list of open ports
    for (int i = 0; i < MAX_HOSTS; i++) {
        if (hosts[i].port > 0) {
            printf("%d.%d.%d.%d: %d\n", hosts[i].host, hosts[i].port);
        }
    }

    // free memory
    free(hosts);

    return 0;
}