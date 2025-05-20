//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 993
#define BUFFER_SIZE 4096

void display_menu() {
    printf("\n*** Welcome to the Magical C Email Client ***\n");
    printf("1. Connect to Mail server\n");
    printf("2. Send Email\n");
    printf("3. Read Inbox\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int connect_to_server(const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host;
    int sock;

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("Could not resolve hostname");
        return -1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to the server");
        close(sock);
        return -1;
    }

    return sock;
}

void send_email(int sock) {
    char recipient[100], subject[100], message[500], buffer[BUFFER_SIZE];
    
    printf("Enter recipient's email: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf(" %[^\n]", subject);
    printf("Enter message: ");
    scanf(" %[^\n]", message);
    
    // Craft the email
    snprintf(buffer, BUFFER_SIZE, "To: %s\nSubject: %s\n\n%s\n", recipient, subject, message);
    
    // Sending email to the server
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send email");
    } else {
        printf("Email sent successfully!\n");
    }
}

void read_inbox(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Request inbox
    snprintf(buffer, BUFFER_SIZE, "GET INBOX\n");
    send(sock, buffer, strlen(buffer), 0);

    printf("\nInbox Messages:\n");
    while((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
        printf("%s", buffer);
        break; // Stop after first response for demo purpose
    }

    if (bytes_received < 0) {
        perror("Error reading from inbox");
    }
}

int main() {
    int sock;
    char hostname[100];

    printf("Enter mail server hostname: ");
    scanf("%s", hostname);

    sock = connect_to_server(hostname);

    if (sock < 0) {
        return 1; // Could not connect
    }

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Connected to %s on port %d\n", hostname, PORT);
                break;
            case 2:
                send_email(sock);
                break;
            case 3:
                read_inbox(sock);
                break;
            case 4:
                printf("Exiting the Magical C Email Client. Farewell, friend!\n");
                close(sock);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    close(sock); // Clean up socket
    return 0;
}