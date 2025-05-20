//FormAI DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <signal.h>

#define PORT "8888" // the port users will be connecting to

#define MAXDATASIZE 1024 // max number of bytes we can get at once 

static int signal_received = 0;

void sigint_handler(int signal_number)
{
    signal_received = 1;
}

int make_non_blocking(int sockfd)
{
    int flags;

    if ((flags = fcntl(sockfd, F_GETFL, 0)) == -1)
        return -1;

    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1)
        return -1;

    return 0;
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
    int sockfd, new_fd; // listen on sock_fd, new connection on new_fd
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    char buf[MAXDATASIZE];
    int numbytes;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1) {
            perror("setsockopt");
            exit(1);
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo); // all done with this structure

    if (p == NULL)  {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    if (make_non_blocking(sockfd) == -1) {
        perror("failed to make socket non-blocking");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    signal(SIGINT, sigint_handler);

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    int max_fd = sockfd;

    while (!signal_received) {
        fd_set tmp_read_fds = read_fds;
        if (select(max_fd + 1, &tmp_read_fds, NULL, NULL, NULL) == -1) {
            if (errno != EINTR) {
                perror("select");
                exit(1);
            } else {
                continue;
            }
        }

        for (int i = 0; i <= max_fd; ++i) {
            if (!FD_ISSET(i, &tmp_read_fds)) {
                continue;
            }

            if (i == sockfd) {
                sin_size = sizeof their_addr;
                new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
                if (new_fd == -1) {
                    perror("accept");
                    continue;
                }

                if (make_non_blocking(new_fd) == -1) {
                    perror("failed to make new_fd non-blocking");
                    exit(1);
                }

                FD_SET(new_fd, &read_fds);
                max_fd = max_fd < new_fd ? new_fd : max_fd;
                printf("server: got connection from %s\n",
                    inet_ntop(their_addr.ss_family,
                        get_in_addr((struct sockaddr *)&their_addr),
                        s, sizeof s));
            } else {
                numbytes = recv(i, buf, sizeof buf, 0);
                if (numbytes <= 0) {
                    if (numbytes == 0) {
                        printf("server: socket %d hung up\n", i);
                    } else {
                        perror("recv");
                    }
                    close(i);
                    FD_CLR(i, &read_fds);
                } else {
                    buf[numbytes] = '\0';
                    printf("server: received '%s'\n", buf);
                    if (send(i, buf, strlen(buf), 0) == -1) {
                        perror("send");
                    }
                }
            }
        }
    }

    for (int i = 0; i <= max_fd; ++i) {
        if (FD_ISSET(i, &read_fds)) {
            close(i);
        }
    }

    return 0;
}