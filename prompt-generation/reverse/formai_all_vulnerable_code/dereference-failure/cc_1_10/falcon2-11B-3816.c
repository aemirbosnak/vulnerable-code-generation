//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 5000

int main() {
    int sockfd, valread;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[256];

    int num_servers = 5;
    int num_connections = 5;
    int i;

    struct hostent *he;

    char *servers[num_servers];

    srand(time(NULL));

    for (i = 0; i < num_servers; i++) {
        servers[i] = (char *)malloc(256);
        servers[i][0] = '\0';
    }

    for (i = 0; i < num_servers; i++) {
        sprintf(servers[i], "172.16.0.%d", i);
        if ((he = gethostbyname(servers[i])) == NULL) {
            fprintf(stderr, "Error, cannot get host info for %s\n", servers[i]);
            exit(1);
        } else {
            memcpy(&serv_addr, he->h_addr_list[0], he->h_length);
        }
    }

    for (i = 0; i < num_connections; i++) {
        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket failed");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            exit(1);
        }

        for (i = 0; i < num_servers; i++) {
            if ((valread = read(sockfd, buffer, sizeof(buffer))) < 0) {
                perror("read failed");
                exit(1);
            }

            if (valread > 0) {
                printf("%s\n", buffer);
            }
        }

        close(sockfd);
    }

    return 0;
}