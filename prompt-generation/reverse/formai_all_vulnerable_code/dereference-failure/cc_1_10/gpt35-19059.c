//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DEVICES 100
#define MAX_NAME 50

struct device {
    char name[MAX_NAME];
    char ip[INET6_ADDRSTRLEN];
};

struct topology {
    int num_devices;
    struct device devices[MAX_DEVICES];
    int connectivity_matrix[MAX_DEVICES][MAX_DEVICES];
};

int get_device_index(char *name, struct topology *top) {
    int i;
    for(i=0; i<top->num_devices; i++) {
        if(strcmp(name, top->devices[i].name) == 0) {
            return i;
        }
    }

    return -1;
}


int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <ip or hostname>\n", argv[0]);
        return 1;
    }

    char *target = argv[1];

    struct sockaddr_in address;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Could not create socket");
        return 1;
    }

    struct hostent *host;
    if((host = gethostbyname(target)) == NULL) {
        printf("Could not resolve hostname %s\n", target);
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(80);
    memcpy(&address.sin_addr, host->h_addr_list[0], host->h_length);

    if(connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Could not connect to %s\n", target);
        printf("%s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in local_address;
    socklen_t local_address_len = sizeof(local_address);

    if(getsockname(sock, (struct sockaddr *)&local_address, &local_address_len) < 0) {
        printf("Could not get local address\n");
        return 1;
    }

    char local_ip[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET, &local_address.sin_addr, local_ip, sizeof(local_ip));

    char *message = "GET / HTTP/1.1\r\n\r\n";
    if(send(sock, message, strlen(message), 0) < 0) {
        printf("Could not send message\n");
        return 1;
    }

    char response[1024];
    int response_len = 0;

    while((response_len = recv(sock, response, sizeof(response), 0)) > 0) {
        //parsed response to find device names and ips
    }

    close(sock);

    struct topology top;
    top.num_devices = 0;

    //populated top.devices and top.connectivity_matrix while parsing response

    return 0;
}