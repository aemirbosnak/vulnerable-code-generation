//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/time.h>

#define MAX_CONN 1024
#define TIMEOUT 5

typedef struct {
    int sockfd;
    char* inbuf;
    char* outbuf;
    int bufpos;
    int buflimit;
    int state;
    struct sockaddr_in addr;
    struct timeval last_heard_from;
} connection;

connection* conns[MAX_CONN];
fd_set readfds;
int maxfd;

void init_conn_array() {
    int i;
    for (i = 0; i < MAX_CONN ; ++i) {
        conns[i] = NULL;
    }
}

void add_new_conn(int sockfd, struct sockaddr_in addr) {
    int i;
    for (i = 0; i < MAX_CONN; ++i) {
        if (!conns[i]) {
            connection* conn = (connection*) calloc(1, sizeof(connection));
            conn->sockfd = sockfd;
            conn->inbuf = (char*) calloc(1, 1024);
            conn->outbuf = (char*) calloc(1, 1024);
            conn->buflimit = 1024;
            conn->state = 1;
            conn->addr = addr;
            gettimeofday(&conn->last_heard_from, NULL);
            conns[i] = conn;
            break;
        }
    }
}

void remove_conn(int i) {
    if (conns[i]->inbuf) free(conns[i]->inbuf);
    if (conns[i]->outbuf) free(conns[i]->outbuf);
    if (conns[i]) free(conns[i]);
    conns[i] = NULL;
}

void write_outbuf(connection* conn) {
    if (conn->outbuf == NULL) return;

    int amt_to_write = strlen(conn->outbuf) - conn->bufpos;

    if (amt_to_write <= 0) return;

    int written = write(conn->sockfd, conn->outbuf + conn->bufpos, amt_to_write);
    if (written < 0) {
        remove_conn(conn);
        return;
    }

    conn->bufpos += written;

    if (conn->bufpos == strlen(conn->outbuf)) {
        conn->bufpos = 0;
        conn->buflimit = 0;
        free(conn->outbuf);
        conn->outbuf = NULL;
    }
}

void read_inbuf(connection* conn) {
    if (conn->inbuf == NULL || conn->buflimit == 0 || strlen(conn->inbuf) >= conn->buflimit - 1) return;

    int avail_space = conn->buflimit - strlen(conn->inbuf) - 1;

    int amt_read = read(conn->sockfd, conn->inbuf + strlen(conn->inbuf), avail_space);

    if (amt_read == 0 || amt_read == -1) {
        remove_conn(conn);
        return;
    }

    conn->inbuf[strlen(conn->inbuf) + amt_read] = '\0';
}

int main(int argc, char *argv[]) {
    int sockfd, port;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;

    if (argc != 2) {
        printf("Usage: ./qos_monitor <port>\n");
        return 1;
    }

    port = atoi(argv[1]);

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        return 1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    if(listen(sockfd, MAX_CONN) < 0) {
        perror("Failed to listen for connections");
        return 1;
    }

    printf("QoS monitor started listening on port %d\n", port);

    init_conn_array();

    while(1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        int i;
        for (i = 0; i < MAX_CONN; ++i) {
            if (conns[i] != NULL) {
                FD_SET(conns[i]->sockfd, &readfds);
            }
        }
        maxfd = sockfd + 1;

        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        int retval = select(maxfd, &readfds, NULL, NULL, &tv);
        if (retval == -1) {
            perror("Error in select");
            continue;
        }
        else if (retval == 0) {
            // no activity; check if any connections have timed out
            for (i = 0; i < MAX_CONN; ++i) {
                if (conns[i] != NULL) {
                    struct timeval now;
                    gettimeofday(&now, NULL);
                    if ((now.tv_sec - conns[i]->last_heard_from.tv_sec) > TIMEOUT) {
                        printf("Connection timed out from IP %s\n", inet_ntoa(conns[i]->addr.sin_addr));
                        remove_conn(i);
                    }
                }
            }
        }
        else {
            if (FD_ISSET(sockfd, &readfds)) {
                // new connection; add it
                len = sizeof(cliaddr);
                int newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
                if (newsockfd < 0) {
                    perror("Error on accept");
                    continue;
                }
                printf("New connection from IP %s\n", inet_ntoa(cliaddr.sin_addr));
                add_new_conn(newsockfd, cliaddr);
            }
            // check for activity on existing connections
            for (i = 0; i < MAX_CONN; ++i) {
                if (conns[i] == NULL) continue;

                if (FD_ISSET(conns[i]->sockfd, &readfds)) {
                    // data available on a socket; read it in
                    read_inbuf(conns[i]);
                    gettimeofday(&conns[i]->last_heard_from, NULL);

                    // process the data; we'll simulate a simple echo service
                    char* nl = strchr(conns[i]->inbuf, '\n');
                    if (nl != NULL) {
                        *nl = '\0';
                        char* res = (char*) calloc(1, strlen(conns[i]->inbuf) + 1);
                        sprintf(res, "%s\n", conns[i]->inbuf);
                        conns[i]->outbuf = res;
                        conns[i]->bufpos = 0;
                        conns[i]->buflimit = strlen(conns[i]->outbuf);

                        // clear the input buffer
                        memset(conns[i]->inbuf, 0, strlen(conns[i]->inbuf));

                        // send response back
                        write_outbuf(conns[i]);
                    }
                }
            }
        }
    }

    return 0;
}