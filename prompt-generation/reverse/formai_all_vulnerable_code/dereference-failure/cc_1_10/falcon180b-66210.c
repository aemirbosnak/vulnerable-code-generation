//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define PORT_RANGE "1-65535"

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    char *port_range = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char *token = strtok(port_range, "-");
    int start_port = atoi(token);
    int end_port = atoi(strtok(NULL, "-"));

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(sock);
    return 0;
}