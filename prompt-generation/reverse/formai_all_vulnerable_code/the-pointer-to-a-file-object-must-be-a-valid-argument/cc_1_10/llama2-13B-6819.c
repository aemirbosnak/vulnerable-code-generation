//LLAMA2-13B DATASET v1.0 Category: Email Client ; Style: irregular
// 🐰💡 The Email Client That's As Irregular As You 😜

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EMAIL_LENGTH 512
#define MAX_SUBJECT_LENGTH 256
#define MAX_FROM_LENGTH 256
#define MAX_TO_LENGTH 256

// 💡 Structure to hold email data
typedef struct {
    char *subject;
    char *from;
    char *to;
    char *message;
} email_t;

// 🔒 Function to parse email data from a file
email_t *parse_email(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1024];
    email_t *email = malloc(sizeof(email_t));

    // 👀 Parse email subject
    if (fgets(line, sizeof(line), file) != NULL) {
        email->subject = strtok(line, " ");
    }

    // 👀 Parse email from address
    if (fgets(line, sizeof(line), file) != NULL) {
        email->from = strtok(line, " ");
    }

    // 👀 Parse email to address
    if (fgets(line, sizeof(line), file) != NULL) {
        email->to = strtok(line, " ");
    }

    // 👀 Parse email message
    if (fgets(line, sizeof(line), file) != NULL) {
        email->message = strtok(line, "\n");
    }

    fclose(file);
    return email;
}

// 📧 Function to send email
int send_email(email_t *email) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    char *message = NULL;

    // 🌐 Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // 📦 Set email message
    message = malloc(strlen(email->message) + 1);
    strcpy(message, email->message);

    // 📨 Send email
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        send(sock, message, strlen(message), 0);
        close(sock);
        free(message);
        return 1;
    }

    return 0;
}

int main() {
    // 🎨 Parse email from file
    email_t *email = parse_email("example.email");

    // 📧 Send email
    if (send_email(email) == 1) {
        printf("Email sent successfully! 💬\n");
    } else {
        printf("Error sending email 😢\n");
    }

    // 👋 Free email data
    free(email->subject);
    free(email->from);
    free(email->to);
    free(email->message);
    free(email);

    return 0;
}