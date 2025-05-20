//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mailing_list{
    char *email;
    struct mailing_list *next;
} mailing_list;

mailing_list *create_mailing_list(char *email){
    mailing_list *new_list = (mailing_list *)malloc(sizeof(mailing_list));
    new_list->email = email;
    new_list->next = NULL;
    return new_list;
}

void add_email_to_mailing_list(mailing_list **head, char *email){
    mailing_list *new_email = create_mailing_list(email);
    
    if (*head == NULL){
        *head = new_email;
    }
    else{
        mailing_list *current = *head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new_email;
    }
}

void remove_email_from_mailing_list(mailing_list **head, char *email){
    mailing_list *current = *head;
    mailing_list *previous = NULL;
    
    while (current != NULL && strcmp(current->email, email) != 0){
        previous = current;
        current = current->next;
    }
    
    if (current == NULL){
        printf("Email not found in mailing list.\n");
        return;
    }
    
    if (previous == NULL){
        *head = current->next;
    }
    else{
        previous->next = current->next;
    }
    
    free(current);
}
void send_email_to_mailing_list(mailing_list *head, char * subject, char *message){
    mailing_list *current = head;
    while (current != NULL){
        // TODO: Implement sending email functionality
        printf("Sending email to %s with subject %s and message %s.\n", current->email, subject, message);
        current = current->next;
    }
}

int main(){
    mailing_list *head = NULL; // Create an empty mailing list
    
    // Add some emails to the mailing list
    add_email_to_mailing_list(&head, "johndoe@example.com");
    add_email_to_mailing_list(&head, "janedoe@example.com");
    add_email_to_mailing_list(&head, "johndoe@example.com");
    
    // Remove an email from the mailing list
    remove_email_from_mailing_list(&head, "johndoe@example.com");
    
    // Send an email to the mailing list
    send_email_to_mailing_list(head, "Hello from the future!", "This is a test email from your futuristic mailing list manager.");
    
    return 0;
}