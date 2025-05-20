//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include<stdio.h>   //header file for standard input and output
#include<stdlib.h>  //header file for dynamically allocating memory
#include<string.h>  //header file for string operations

struct Node{   //defining a structure Node
    char date[11];    //a string variable to store date
    char topic[100];  //a string variable to store topic
    char content[1000];  //a string variable to store content
    struct Node *next;   //a pointer to Node structure to store the address
};

void addEntry(struct Node** head_ref){   //function to add an entry
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));  //allocating memory
    printf("\nEnter the Date(dd/mm/yyyy): ");
    scanf("%s", new_node->date);     //taking input from user
    printf("Enter the Topic: ");
    scanf("%s", new_node->topic);   //taking input from user
    printf("Enter the Content: ");
    scanf("%s", new_node->content);   //taking input from user
    new_node->next = (*head_ref);    //linking the new_node with head
    (*head_ref) = new_node;     //making the new_node as the head
}

void editEntry(struct Node** head_ref){  //function to edit an entry
    char d[11];   //for date
    char t[100];  //for topic
    printf("\nEnter the Date(dd/mm/yyyy) of the entry you want to edit: ");
    scanf("%s", d);   //taking input from user
    printf("Enter the Topic of the entry you want to edit: ");
    scanf("%s", t);  //taking input from user
    struct Node* temp = *head_ref;   //making a temporary node to contain the head
    while(temp!=NULL){   //looping through till the end of the list
        if(strcmp(temp->date, d)==0){  //checking for date match
            if(strcmp(temp->topic, t)==0){   //checking for topic match
                printf("Update the Content: ");
                scanf("%s", temp->content);  //taking input from user
                printf("\nEntry Successfully Updated!\n");
                return;   //returning the control to main()
            }
        }
        temp = temp->next;   //moving to the next node
    }
    printf("\nNo Matching Entry Found!\n");  //if no matching entry is found
}

void deleteEntry(struct Node** head_ref){  //function to delete an entry
    char d[11];   //for date
    char t[100];  //for topic
    printf("\nEnter the Date(dd/mm/yyyy) of the entry you want to delete: ");
    scanf("%s", d);  //taking input from user
    printf("Enter the Topic of the entry you want to delete: ");
    scanf("%s", t);  //taking input from user
    
    struct Node* temp = *head_ref;   //making a temporary node to contain the head
    struct Node* prev;
    if(temp!=NULL && strcmp(temp->date, d)==0 && strcmp(temp->topic, t)==0){   //if first node is matching
        *head_ref = temp->next;
        free(temp);    //deleting the first node
        printf("\nEntry Successfully Deleted!\n");
        return;
    }
    while(temp!=NULL && (strcmp(temp->date, d)!=0 || strcmp(temp->topic, t)!=0)){   //loop through till the end of the list
        prev = temp;     //saving the previous node
        temp = temp->next;  //moving to the next node
    }
    if(temp==NULL){   //if no matching entry is found
        printf("\nNo Matching Entry Found!\n");
        return;
    }
    prev->next = temp->next;  //linking the previous node with the next node
    free(temp);   //deleting the matching node
    printf("\nEntry Successfully Deleted!\n");
}

void displayEntries(struct Node* head){  //function to display all entries
    printf("\nHere are all the entries:\n");
    while(head!=NULL){   //loop through till the end of the list
        printf("\nDate: %s\n", head->date);
        printf("Topic: %s\n", head->topic);
        printf("Content: %s\n", head->content);
        head = head->next;    //moving to the next node
    }
    printf("\n");
}

void searchEntry(struct Node* head){  //function to search for an entry
    char d[11];   //for date
    char t[100];  //for topic
    printf("\nEnter the Date(dd/mm/yyyy) of the entry you want to search: ");
    scanf("%s", d);   //taking input from user
    printf("Enter the Topic of the entry you want to search: ");
    scanf("%s", t);   //taking input from user
    
    struct Node* temp = head;   //making a temporary node to contain the head
    while(temp!=NULL){   //loop through till the end of the list
        if(strcmp(temp->date, d)==0){  //checking for date match
            if(strcmp(temp->topic, t)==0){  //checking for topic match
                printf("\nDate: %s\n", temp->date);
                printf("Topic: %s\n", temp->topic);
                printf("Content: %s\n", temp->content);
                return;   //returning the control to main()
            }
        }
        temp = temp->next;   //moving to the next node
    }
    printf("\nNo Matching Entry Found!\n");   //if no matching entry is found
}

int main(){     //main function starts here
    struct Node* head = NULL;    //initializing head as NULL
    int choice=0;  //variable to store user's choice
    printf("\n******** Welcome to My Personal Diary ********\n");
    while(choice!=6){   //running the menu until user input is 6
        printf("\nWhat would you like to do?\n");
        printf("1. Add an Entry\n");
        printf("2. Edit an Entry\n");
        printf("3. Delete an Entry\n");
        printf("4. Display all Entries\n");
        printf("5. Search for an Entry\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);   //taking input from user
        switch(choice){   //using switch case to direct to respective functions
            case 1:
                addEntry(&head);  //calling addEntry function
                break;
            case 2:
                editEntry(&head);  //calling editEntry function
                break;
            case 3:
                deleteEntry(&head);  //calling deleteEntry function
                break;
            case 4:
                displayEntries(head);   //calling displayEntries function
                break;
            case 5:
                searchEntry(head);    //calling searchEntry function
                break;
            case 6:
                printf("\nThank You for using My Personal Diary!\n");  //exiting the program
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");  //invalid selection by user
        }
    }
    return 0;   //end of program
}