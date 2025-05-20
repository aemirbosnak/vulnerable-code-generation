//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define PORT 25
#define HOST "smtp.gmail.com"

struct email {
    char *from;
    char *to;
    char *subject;
    char *message;
};

struct email_list {
    struct email *emails;
    int count;
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <from> <to> <subject> <message>\n", argv[0]);
        return 1;
    }

    struct email_list *emails = malloc(sizeof(struct email));
    emails->emails = malloc(sizeof(struct email));
    emails->count = 1;

    struct email *email = emails->emails;
    email->from = argv[1];
    email->to = argv[2];
    email->subject = argv[3];
    email->message = argv[4];

    email->message = malloc(strlen(email->message) + 1);
    strcpy(email->message, email->message);

    // Connect to the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, HOST, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send the email
    char buffer[1024];
    int bytes_sent = 0;
    int bytes_to_send = strlen(email->message);

    while (bytes_to_send > 0) {
        int bytes_sent_now = send(sock, email->message + bytes_sent, bytes_to_send, 0);
        if (bytes_sent_now < 0) {
            perror("send() failed");
            return 1;
        }
        bytes_sent += bytes_sent_now;
        bytes_to_send -= bytes_sent_now;
    }

    // Receive the email ID from the server
    char id[1024];
    recv(sock, id, 1024, 0);

    // Print the email ID
    printf("Email sent successfully! ID: %s\n", id);

    // Close the socket
    close(sock);

    // Free memory
    free(email->message);
    free(emails->emails);
    free(emails);

    return 0;
}