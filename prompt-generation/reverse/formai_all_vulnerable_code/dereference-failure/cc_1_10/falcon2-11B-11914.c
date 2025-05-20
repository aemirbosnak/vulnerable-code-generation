//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int status;
    char buffer[256];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(argv[1], "21", &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    for(p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(connect(sockfd, p->ai_addr, p->ai_addrlen) < 0) {
            continue;
        }

        printf("Connected to FTP server: %s\n", argv[1]);

        int n = 0;
        while(n < sizeof(buffer)) {
            if(read(sockfd, buffer + n, sizeof(buffer) - n) < 0) {
                perror("read");
                return 1;
            }
            n += read(sockfd, buffer + n, sizeof(buffer) - n);
            if(n == 0)
                break;
        }

        printf("%s\n", buffer);

        n = 0;
        while(n < sizeof(buffer)) {
            if(write(sockfd, buffer + n, sizeof(buffer) - n) < 0) {
                perror("write");
                return 1;
            }
            n += write(sockfd, buffer + n, sizeof(buffer) - n);
            if(n == 0)
                break;
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}