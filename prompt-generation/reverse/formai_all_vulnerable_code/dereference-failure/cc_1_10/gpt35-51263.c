//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LINE 1024

pthread_mutex_t lock_send;
pthread_mutex_t lock_recv;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void *send_thread(void *arg)
{
    int sockfd = *(int *)arg;
    char sendline[MAX_LINE];
    while(1)
    {
        // Acquire send lock
        pthread_mutex_lock(&lock_send);
        printf("Enter message to send: ");
        fgets(sendline, MAX_LINE, stdin);
        if(strncmp(sendline, ".exit", 5) == 0)
        {
            pthread_mutex_unlock(&lock_send);
            break;
        }
        send(sockfd, sendline, strlen(sendline), 0);
        // Release send lock
        pthread_mutex_unlock(&lock_send); 
    }
    close(sockfd);
    pthread_exit(NULL);
}

void *recv_thread(void *arg)
{
    int sockfd = *(int *)arg;
    char recvline[MAX_LINE];
    while(1)
    {
        // Acquire recv lock
        pthread_mutex_lock(&lock_recv); 
        int n = recv(sockfd, recvline, MAX_LINE, 0); 
        if(n <= 0) 
        {
            pthread_mutex_unlock(&lock_recv);
            break; 
        }

        recvline[n] = '\0';
        printf("Received: %s", recvline);
        // Release recv lock
        pthread_mutex_unlock(&lock_recv);

    }
    close(sockfd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LINE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connect to the server */
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    pthread_t send_t, recv_t;

    pthread_mutex_init(&lock_send, NULL);
    pthread_mutex_init(&lock_recv, NULL);

    /* Create separate threads for sending and receiving data */
    pthread_create(&send_t, NULL, send_thread, &sockfd);
    pthread_create(&recv_t, NULL, recv_thread, &sockfd);

    /* Wait for threads to join */
    pthread_join(send_t, NULL);
    pthread_join(recv_t, NULL);

    pthread_mutex_destroy(&lock_send);
    pthread_mutex_destroy(&lock_recv);

    return 0;
}