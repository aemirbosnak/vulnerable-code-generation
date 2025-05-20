//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_SERVER_LENGTH 1024

void print_usage() {
    printf("Port scanner? You want to scan ports? You must be a cyber ninja! \n");
    printf("Anyway, here's how you use this program:\n");
    printf("  %s <host_ip> <port_range>\n", __func__);
    printf("Example: %s 192.168.1.1 22-80\n", __func__);
    printf("That's right, ninja! You can scan a whole range of ports! \n");
    printf("Now go forth and find those vulnerabilities! \n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // because who doesn't love HTTP?
    inet_pton(AF_INET, "192.168.1.1", &server_addr.sin_addr);

    int client_len = strlen(argv[1]);
    char *client_ip = malloc(client_len + 1);
    memcpy(client_ip, argv[1], client_len + 1);

    int port_range_start = atoi(argv[2]);
    int port_range_end = atoi(argv[3]);

    for (int port = port_range_start; port <= port_range_end; port++) {
        char port_str[6];
        snprintf(port_str, sizeof(port_str), "%d", port);
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);
        inet_pton(AF_INET, client_ip, &client_addr.sin_addr);

        int conn = connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (conn < 0) {
            perror("Connect failed");
            continue;
        }

        char buffer[1024];
        int bytes_recv = recv(sock, buffer, 1024, 0);
        if (bytes_recv < 0) {
            perror("Recv failed");
            close(sock);
            continue;
        }

        printf("Port %d: %s\n", port, buffer);

        close(sock);
    }

    free(client_ip);
    return 0;
}