//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* name;
    char* email;
} Contact;

typedef struct {
    Contact* sender;
    Contact* receiver;
    char* subject;
    char* body;
} Email;

typedef struct {
    char* username;
    char* password;
} Login;

typedef struct {
    bool connected;
    Login* login_info;
} Server;

Contact* create_contact(char* name, char* email){
    Contact* new_contact = malloc(sizeof(Contact));
    new_contact->name = name;
    new_contact->email = email;
    return new_contact;
}

Email* create_email(Contact* sender, Contact* receiver, char* subject, char* body){
    Email* new_email = malloc(sizeof(Email));
    new_email->sender = sender;
    new_email->receiver = receiver;
    new_email->subject = subject;
    new_email->body = body;
    return new_email;
}

Server* connect_to_server(char* username, char* password){
    Server* new_server = malloc(sizeof(Server));
    new_server->connected = true;
    Login* new_login = malloc(sizeof(Login));
    new_login->username = username;
    new_login->password = password;
    new_server->login_info = new_login;
    printf("Welcome to the IMAP Surrealist Client. You are now connected to the server.\n");
    printf("Please enter a command to continue.\n");
    return new_server;
}

void disconnect_from_server(Server* server){
    server->connected = false;
    free(server->login_info);
    free(server);
    printf("You have disconnected from the server. Thank you for using the IMAP Surrealist Client.\n");
}

void print_email(Email* email){
    printf("From: %s <%s>\n", email->sender->name, email->sender->email);
    printf("To: %s <%s>\n", email->receiver->name, email->receiver->email);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

void receive_emails(Server* server){
    printf("Receiving emails from the server...\n");
    Contact* sender = create_contact("Salvador Dali", "dali@smtp.com");
    Contact* receiver = create_contact("Rene Magritte", "magritte@smtp.com");
    Email* email1 = create_email(sender, receiver, "The Persistence of Memory", "The soft melting watches are a symbol of the relativity of time.");
    Email* email2 = create_email(sender, receiver, "The Elephants", "The elephants are a symbol of the weight of the subconscious mind.");
    Email* email3 = create_email(sender, receiver, "The Son of Man", "The apple is a symbol of the conflict between the desire to reveal and the desire to conceal.");
    printf("You have received the following emails:\n");
    print_email(email1);
    print_email(email2);
    print_email(email3);
}

void send_email(Server* server, Contact* receiver, char* subject, char* body){
    printf("Sending email to %s <%s>...\n", receiver->name, receiver->email);
    Contact* sender = create_contact("Salvador Dali", "dali@smtp.com");
    Email* email = create_email(sender, receiver, subject, body);
    printf("Your email has been sent successfully.\n");
}

int main(){
    Server* server = connect_to_server("my_username", "my_password");
    char command[100];
    while(server->connected){
        scanf(" %[^\n]s", command);
        if(strcmp(command, "receive") == 0){
            receive_emails(server);
        }
        else if(strcmp(command, "send") == 0){
            printf("Please enter the email address of the recipient:\n");
            char email_address[100];
            scanf("%s", email_address);
            printf("Please enter the subject of the email:\n");
            char subject[100];
            scanf(" %[^\n]s", subject);
            printf("Please enter the body of the email:\n");
            char body[1000];
            scanf(" %[^\n]s", body);
            Contact* receiver = create_contact("Unknown", email_address);
            send_email(server, receiver, subject, body);
        }
        else if(strcmp(command, "disconnect") == 0){
            disconnect_from_server(server);
        }
        else{
            printf("Command not recognized. Please try again.\n");
        }
    }
    return 0;
}