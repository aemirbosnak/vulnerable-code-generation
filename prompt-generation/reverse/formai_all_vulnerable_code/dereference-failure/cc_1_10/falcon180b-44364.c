//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

int sockfd, newsockfd, valread;
char buffer[MAX];

void *get_input(void *socket_desc) {
    char *message = (char *) malloc(1000 * sizeof(char));
    while (1) {
        valread = read(*(int *) socket_desc, message, 1000);
        if (valread <= 0) {
            break;
        }
        message[valread] = '\0';
        printf("%s", message);
    }
    free(message);
    close(*(int *) socket_desc);
    pthread_exit(0);
}

int main() {
    int opt = 1;
    int addrlen = sizeof(SA);
    int new_socket = 0;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (char *) &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (SA *) &serv_addr, addrlen) < 0) {
        printf("Error on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error on listening");
        exit(1);
    }

    while (1) {
        new_socket = accept(sockfd, (SA *) &cli_addr, (socklen_t *) &addrlen);

        if (new_socket < 0) {
            printf("Error on accept");
            exit(1);
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, get_input, (void *) &new_socket);
        pthread_detach(thread_id);
    }

    close(sockfd);
    return 0;
}