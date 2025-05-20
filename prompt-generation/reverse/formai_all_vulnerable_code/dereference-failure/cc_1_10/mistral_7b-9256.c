//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#define TARGET_IP "192.168.1.1"
#define BUFFER_SIZE 1024
typedef struct {
    int port;
    int status;
} port_info;
void print_banner(void) {
    printf("______________________________________________________________\n");
    printf("|                                                           |\n");
    printf("|            The Puzzling Port Scanner v1.0                ||\n");
    printf("|                                                           |\n");
    printf("|                                                           |\n");
    printf("|  Created by The Mysterious One                            ||\n");
    printf("|  Use at your own risk                                    ||\n");
    printf("|  For educational purposes only                            ||\n");
    printf("|                                                           |\n");
    printf("|____________________________________________________________|");
    printf("\n");
}
port_info *init_ports(void) {
    port_info *ports = (port_info *) malloc(256 * sizeof(port_info));
    int i;
    for (i = 0; i < 256; i++) {
        ports[i].port = i;
        ports[i].status = -1;
    }
    return ports;
}
void scan_port(port_info *ports, int target_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, TARGET_IP, &serv_addr.sin_addr);
    int conn_status = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    if (conn_status < 0) {
        ports[target_port].status = 0;
    } else {
        ports[target_port].status = 1;
        close(sockfd);
    }
}
void print_results(port_info *ports) {
    printf("Scanning results for IP address: %s\n", TARGET_IP);
    int i;
    for (i = 0; i < 256; i++) {
        if (ports[i].status == 1) {
            printf("Port %d is open\n", ports[i].port);
        } else {
            printf("Port %d is closed\n", ports[i].port);
        }
    }
}
int main(int argc, char **argv) {
    srand(time(NULL));
    print_banner();
    port_info *ports = init_ports();
    int i;
    for (i = 0; i < 256; i++) {
        int random_delay = rand() % 500 + 100;
        usleep(random_delay * 1000);
        scan_port(ports, i);
    }
    print_results(ports);
    free(ports);
    return 0;
}