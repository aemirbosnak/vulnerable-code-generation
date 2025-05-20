//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE 1024
#define HOST_RANGE 10

struct host_info {
    char *host_name;
    int port;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct hostent *he;
    char host_name[NI_MAXHOST];
    int i;

    for (i = 0; i < HOST_RANGE; i++) {
        sprintf(host_name, "%d.%d.%d.%d", i, i, i, i);
        he = gethostbyname(host_name);
        if (he == NULL) {
            perror("Gethostbyname failed");
            continue;
        }

        for (int j = 0; j < PORT_RANGE; j++) {
            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(j + 1);
            inet_pton(AF_INET, he->h_addr, &serv_addr.sin_addr);

            if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                perror("Connect failed");
                continue;
            }

            char buffer[256];
            recv(sock, buffer, 256, 0);
            printf("Port %d on host %s is open\n", j + 1, he->h_name);
        }
    }

    close(sock);
    return 0;
}