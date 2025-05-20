//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>

#define DEFAULT_PORT 5000
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, portno, n, fdmax, nbytes;
    char buffer[BUFFER_SIZE];
    fd_set master, read_fds;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = argc > 2 ? atoi(argv[2]) : DEFAULT_PORT;
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        error("ERROR opening socket");
    
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    
    FD_ZERO(&master);
    FD_ZERO(&read_fds);
    FD_SET(sock, &master);
    FD_SET(STDIN_FILENO, &master);
    fdmax = sock;
    
    while (1) {
        read_fds = master;
        if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1)
            error("ERROR in select()");
        
        for (int i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == STDIN_FILENO) {
                    // Read input from user and send to server
                    fgets(buffer, sizeof(buffer), stdin);
                    n = send(sock, buffer, strlen(buffer), 0);
                    if (n < 0)
                        error("ERROR writing to socket");
                } else {
                    // Receive data from server and display to user
                    nbytes = recv(i, buffer, sizeof(buffer), 0);
                    if (nbytes <= 0) {
                        if (nbytes == 0)
                            printf("Connection closed by server\n");
                        else
                            error("ERROR receiving data from socket");
                        close(i);
                        FD_CLR(i, &master);
                    } else {
                        printf("%s", buffer);
                    }
                }
            }
        }
    }
    return 0;
}