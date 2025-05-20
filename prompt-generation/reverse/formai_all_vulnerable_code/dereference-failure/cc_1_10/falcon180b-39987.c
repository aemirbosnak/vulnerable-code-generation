//Falcon-180B DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define ALLOWED_PORTS "80,443"

int is_allowed_port(int port) {
    char *allowed_ports = ALLOWED_PORTS;
    char *token = strtok(allowed_ports, ",");

    while (token!= NULL) {
        if (atoi(token) == port) {
            return 1;
        }
        token = strtok(NULL, ",");
    }

    return 0;
}

void log_packet(char *src_ip, int src_port, char *dest_ip, int dest_port) {
    FILE *log_file = fopen("firewall.log", "a");

    if (log_file!= NULL) {
        fprintf(log_file, "Packet from %s:%d to %s:%d\n", src_ip, src_port, dest_ip, dest_port);
        fclose(log_file);
    }
}

int main() {
    int src_port, dest_port;
    char src_ip[16], dest_ip[16];
    struct sockaddr_in src_addr, dest_addr;
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Firewall started\n");

    while (1) {
        memset(&src_addr, 0, sizeof(src_addr));
        memset(&dest_addr, 0, sizeof(dest_addr));

        if (recvfrom(sock, (char *)&src_addr, sizeof(src_addr), 0, NULL, NULL) == -1) {
            printf("Error receiving packet\n");
            continue;
        }

        src_port = ntohs(src_addr.sin_port);
        inet_ntop(AF_INET, &src_addr.sin_addr, src_ip, sizeof(src_ip));

        if (!is_allowed_port(src_port)) {
            printf("Packet from %s:%d dropped\n", src_ip, src_port);
            continue;
        }

        if (recvfrom(sock, (char *)&dest_addr, sizeof(dest_addr), 0, NULL, NULL) == -1) {
            printf("Error receiving packet\n");
            continue;
        }

        dest_port = ntohs(dest_addr.sin_port);
        inet_ntop(AF_INET, &dest_addr.sin_addr, dest_ip, sizeof(dest_ip));

        if (!is_allowed_port(dest_port)) {
            printf("Packet to %s:%d dropped\n", dest_ip, dest_port);
            continue;
        }

        log_packet(src_ip, src_port, dest_ip, dest_port);

        if (sendto(sock, (char *)&src_addr, sizeof(src_addr), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
            printf("Error forwarding packet\n");
        }
    }

    close(sock);

    return 0;
}