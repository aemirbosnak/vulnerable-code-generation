//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_SIZE 1024

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct email *email = malloc(sizeof(struct email));
    if (email == NULL) {
        perror("memory allocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Enter sender's email address: ");
    fgets(email->from, MAX_SIZE, stdin);
    email->from[strcspn(email->from, "\n")] = '\0';

    printf("Enter recipient's email address: ");
    fgets(email->to, MAX_SIZE, stdin);
    email->to[strcspn(email->to, "\n")] = '\0';

    printf("Enter subject: ");
    fgets(email->subject, MAX_SIZE, stdin);
    email->subject[strcspn(email->subject, "\n")] = '\0';

    printf("Enter message: ");
    fgets(email->message, MAX_SIZE, stdin);
    email->message[strcspn(email->message, "\n")] = '\0';

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    send(sock, email->from, strlen(email->from), 0);
    send(sock, email->to, strlen(email->to), 0);
    send(sock, email->subject, strlen(email->subject), 0);
    send(sock, email->message, strlen(email->message), 0);

    recv(sock, NULL, 0, 0);

    close(sock);
    free(email);

    return 0;
}