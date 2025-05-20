//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

typedef struct ftp_client {
    int sockfd;
    char *host;
    char *username;
    char *password;
} ftp_client_t;

void *ftp_client_thread(void *arg) {
    ftp_client_t *client = (ftp_client_t *)arg;

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(client->host);

    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd == -1) {
        perror("socket");
        pthread_exit(NULL);
    }

    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        pthread_exit(NULL);
    }

    // Send the username and password
    char buf[BUFFER_SIZE];
    sprintf(buf, "USER %s\r\n", client->username);
    send(client->sockfd, buf, strlen(buf), 0);
    recv(client->sockfd, buf, BUFFER_SIZE, 0);
    
    sprintf(buf, "PASS %s\r\n", client->password);
    send(client->sockfd, buf, strlen(buf), 0);
    recv(client->sockfd, buf, BUFFER_SIZE, 0);

    // List the files in the current directory
    send(client->sockfd, "LIST\r\n", 6, 0);
    recv(client->sockfd, buf, BUFFER_SIZE, 0);

    // Print the files
    printf("Files:\n");
    while (recv(client->sockfd, buf, BUFFER_SIZE, 0) > 0) {
        printf("%s", buf);
    }

    // Disconnect from the FTP server
    close(client->sockfd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <host> <username> <password> <num_threads>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_threads = atoi(argv[4]);
    if (num_threads < 1) {
        fprintf(stderr, "Invalid number of threads: %d\n", num_threads);
        return EXIT_FAILURE;
    }

    // Create the FTP clients
    ftp_client_t clients[num_threads];
    for (int i = 0; i < num_threads; i++) {
        clients[i].host = argv[1];
        clients[i].username = argv[2];
        clients[i].password = argv[3];
    }

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, ftp_client_thread, &clients[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}