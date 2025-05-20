//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <termios.h>

#define MAX_LINE 4096

int sockfd;
char recvline[MAX_LINE + 1];
char sendline[MAX_LINE + 1];

void sig_handler(int signo){
    if (signo == SIGINT){
        printf("closing connection...\n");
        close(sockfd);
        exit(0);
    }
}

void init_client(char* server_name, int port){
    struct hostent *he;
    struct sockaddr_in servaddr;

    if ((he = gethostbyname(server_name)) == NULL){
        printf("error: invalid hostname\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("error: socket creation failed\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        printf("error: connection failed\n");
        exit(1);
    }

    printf("connected to %s:%d\n", server_name, port);
}

int main(int argc, char **argv){
    if (argc != 3){
        printf("usage: ./email_client <server_name> <port>\n");
        exit(1);
    }

    char* server_name = argv[1];
    int port = atoi(argv[2]);
    init_client(server_name, port);

    if (signal(SIGINT, sig_handler) == SIG_ERR){
        printf("error: cannot catch SIGINT\n");
        exit(1);
    }

    fd_set read_set;
    FD_ZERO(&read_set);
    FD_SET(sockfd, &read_set);
    FD_SET(fileno(stdin), &read_set);

    int maxfd = sockfd > fileno(stdin) ? sockfd : fileno(stdin);

    while (1){
        fd_set test_set = read_set;
        int nready = select(maxfd + 1, &test_set, NULL, NULL, NULL);

        if (nready == -1){
            printf("error: select failed\n");
            exit(1);
        }

        if (FD_ISSET(fileno(stdin), &test_set)){
            memset(sendline, 0, strlen(sendline));
            fgets(sendline, MAX_LINE, stdin);

            if (send(sockfd, sendline, strlen(sendline), 0) == -1){
                printf("error: send failed\n");
                exit(1);
            }
        }

        if (FD_ISSET(sockfd, &test_set)){
            memset(recvline, 0, strlen(recvline));
            int n = recv(sockfd, recvline, MAX_LINE, 0);

            if (n == -1){
                printf("error: recv failed\n");
                exit(1);
            }else if (n == 0){
                printf("server has closed the connection\n");
                exit(1);
            }

            printf("%s", recvline);
        }
    }

    return 0;
}