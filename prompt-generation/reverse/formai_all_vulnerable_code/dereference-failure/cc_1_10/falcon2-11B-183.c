//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_USERNAME_LENGTH 64
#define MAX_PASSWORD_LENGTH 64
#define MAX_DOMAIN_LENGTH 64
#define MAX_PORT_LENGTH 10

struct email {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char domain[MAX_DOMAIN_LENGTH];
    int port;
};

void send_email(struct email* email) {
    // Implementation of sending email function
}

void receive_email(struct email* email) {
    // Implementation of receiving email function
}

void display_email_info(struct email* email) {
    printf("Username: %s\n", email->username);
    printf("Password: %s\n", email->password);
    printf("Domain: %s\n", email->domain);
    printf("Port: %d\n", email->port);
}

int main() {
    struct email email;
    email.username[0] = '\0';
    email.password[0] = '\0';
    email.domain[0] = '\0';
    email.port = 0;

    printf("Enter your email username: ");
    fgets(email.username, MAX_USERNAME_LENGTH, stdin);

    printf("Enter your email password: ");
    fgets(email.password, MAX_PASSWORD_LENGTH, stdin);

    printf("Enter your email domain: ");
    fgets(email.domain, MAX_DOMAIN_LENGTH, stdin);

    printf("Enter your email port (default: 25): ");
    fgets(email.port, MAX_PORT_LENGTH, stdin);

    if (strlen(email.username) > MAX_USERNAME_LENGTH || strlen(email.password) > MAX_PASSWORD_LENGTH || strlen(email.domain) > MAX_DOMAIN_LENGTH || strlen(email.port) > MAX_PORT_LENGTH) {
        printf("Invalid input! Please enter valid username, password, domain, and port.\n");
        return 1;
    }

    printf("Email username: %s\n", email.username);
    printf("Email password: %s\n", email.password);
    printf("Email domain: %s\n", email.domain);
    printf("Email port: %d\n", email.port);

    send_email(&email);
    receive_email(&email);

    display_email_info(&email);

    return 0;
}