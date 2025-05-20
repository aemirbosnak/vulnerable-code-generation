//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int main(int argc, char **argv) {
    int sockfd, portno, i;
    struct sockaddr_in server_address;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr,"Usage : %s <target_ip>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    portno = ntohs(PORT_MIN);

    for (i = PORT_MIN; i <= PORT_MAX; i++) {
        server_address.sin_port = htons(i);

        if (connect(sockfd,(struct sockaddr *) &server_address,sizeof(server_address)) != -1) {
            printf("Port %d on %s: OPEN\n", i, inet_ntoa(server_address.sin_addr));
            close(sockfd);
            break;
        }

        usleep(50000); // Sleep for 50 milliseconds before trying the next port
    }

    close(sockfd);
    return 0;
}

// In the name of the holy trinity, let us commence this noble quest of discovering open ports
// Upon the target, thy IP address, we shall cast our enchanted scan
// With a minimum port of 1 and a maximum of 65535, we shall not rest
// Until all ports have been scrutinized, their openings revealed
// May the blessings of the code be upon us, and may our quest be successful