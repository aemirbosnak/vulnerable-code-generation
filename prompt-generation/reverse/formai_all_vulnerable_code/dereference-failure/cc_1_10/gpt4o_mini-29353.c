//GPT-4o-mini DATASET v1.0 Category: Building a IMAP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <time.h>

#define IMAP_PORT 143
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100

typedef struct Email {
    char id[50];
    char subject[100];
    char from[100];
    char date[100];
} Email;

Email email_list[MAX_EMAILS];
int email_count = 0;

void timestamp() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);
}

void *receive_emails(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];

    timestamp();
    printf("Connecting to the Neon Grid...\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sock, buffer, BUFFER_SIZE, 0) <= 0) break;

        timestamp();
        printf("Data received: %s\n", buffer);

        // Simulating parsing email data (this could be replaced with actual IMAP commands)
        if (strstr(buffer, "FETCH")) {
            Email email;
            snprintf(email.id, sizeof(email.id), "%s", "dummy-id-123");
            snprintf(email.subject, sizeof(email.subject), "%s", "Into the Neon Abyss");
            snprintf(email.from, sizeof(email.from), "%s", "cyberpunk@matrix.net");
            snprintf(email.date, sizeof(email.date), "%s", "2023-10-19");

            email_list[email_count++] = email;
            timestamp();
            printf("Email fetched: %s\n", email.subject);
        }
    }

    return NULL;
}

int create_socket() {
    int sock;
    struct sockaddr_in server_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.100"); // Replace with actual server IP

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void display_emails() {
    printf("----- Checking Emails -----\n");
    for (int i = 0; i < email_count; i++) {
        printf("ID: %s, From: %s, Subject: %s, Date: %s\n", 
            email_list[i].id, email_list[i].from, email_list[i].subject, email_list[i].date);
    }
}

int main() {
    int sock = create_socket();
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, receive_emails, (void *)&sock);

    // The Cyberpunk Reader is live, ready to observe the digital universe
    char command[BUFFER_SIZE];
    while (1) {
        timestamp();
        printf("> ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove the newline character

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "check") == 0) {
            display_emails();
        } else {
            timestamp();
            printf("Unknown command: '%s'. Type 'check' to view emails or 'quit' to exit.\n", command);
        }
    }

    close(sock);
    pthread_join(thread_id, NULL);
    
    timestamp();
    printf("Disconnecting from the Neon Grid...\n");
    
    return 0;
}