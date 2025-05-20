//FormAI DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to represent a message
struct Message {
    char* text;
    struct Message* next;
};

//Global variables
int count = 0;
struct Message* head = NULL;
struct Message* tail = NULL;

//Function to add a new message to the linked list
void addMessage(char* messageText) {
    //Allocate memory for the new message
    struct Message* new_message = (struct Message*) malloc(sizeof(struct Message));
    
    //Copy the message text to the new message
    new_message->text = strdup(messageText);
    
    //Set the next pointer of the new message to NULL
    new_message->next = NULL;
    
    //If the linked list is empty, set the new message as the head and tail
    if (head == NULL) {
        head = new_message;
        tail = new_message;
    }
    else {
        //Set the next pointer of the tail to the new message and update the tail
        tail->next = new_message;
        tail = new_message;
    }
    
    //Increment the message count
    count++;
}

//Function to detect spam messages
int detectSpam(char* messageText) {
    //Check if the message contains any spam keywords
    char* keywords[] = {"buy", "sale", "discount", "limited", "offer"};
    int keyword_count = sizeof(keywords) / sizeof(keywords[0]);
    
    for (int i = 0; i < keyword_count; i++) {
        if (strstr(messageText, keywords[i]) != NULL) {
            return 1;
        }
    }
    
    return 0;
}

//Function to remove a message from the linked list
void removeMessage(struct Message* message) {
    //If the message is the head, update the head
    if (message == head) {
        head = head->next;
    }
    else {
        //Find the message before the given message and update its next pointer
        struct Message* current = head;
        while (current->next != message) {
            current = current->next;
        }
        current->next = message->next;
    }
    
    //Free the memory allocated for the message
    free(message->text);
    free(message);
    
    //Decrement the message count
    count--;
}

//Function to print all the messages in the linked list
void printMessages() {
    printf("Message count: %d\n", count);
    struct Message* current = head;
    while (current != NULL) {
        printf("%s\n", current->text);
        current = current->next;
    }
}

int main() {
    //Add some sample messages to the linked list
    addMessage("Hello, how are you?");
    addMessage("Limited time offer - Buy one get one free");
    addMessage("Check out our latest sale!");
    addMessage("I am not a spam message");
    
    //Print all the messages in the linked list
    printMessages();
    
    //Detect spam messages and remove them from the linked list
    struct Message* current = head;
    while (current != NULL) {
        if (detectSpam(current->text)) {
            printf("SPAM DETECTED: %s\n", current->text);
            struct Message* temp = current;
            current = current->next;
            removeMessage(temp);
        }
        else {
            current = current->next;
        }
    }
    
    //Print the updated list of messages
    printMessages();
    
    return 0;
}