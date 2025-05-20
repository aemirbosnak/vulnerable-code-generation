//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct member{
    char firstName[20];
    char lastName[20];
    char email[50];
    struct member* next;
};

void addMember(struct member** head, char* firstName, char* lastName, char* email){
    struct member* newMember = (struct member*)malloc(sizeof(struct member));
    strcpy(newMember->firstName, firstName);
    strcpy(newMember->lastName, lastName);
    strcpy(newMember->email, email);
    newMember->next = NULL;

    if (*head == NULL){
        *head = newMember;
        printf("Element added to the Mailing List!\n");
        return;
    }
    struct member* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newMember;
    printf("Element added to the Mailing List!\n");
}

void deleteMember(struct member** head, char* email){
    if (*head == NULL){
        printf("Mailing List is Empty\n");
        return;
    }
    struct member* prev = NULL;
    struct member* current = *head;

    while (current != NULL && strcmp(current->email, email) != 0){
        prev = current;
        current = current->next;
    }
    if (current == NULL){
        printf("Member not found\n");
        return;
    }

    if (prev == NULL){
        *head = current->next;
    }
    else{
        prev->next = current->next;
    }
    free(current);
    printf("Member Deleted from the Mailing List\n");
}

void searchMember(struct member* head, char* email){
    if (head == NULL){
        printf("Mailing List is Empty\n");
        return;
    }
    struct member* temp = head;
    while (temp != NULL){
        if (strcmp(temp -> email,email) == 0){
            printf("First Name: %s\nLast Name: %s\nEmail: %s\n",temp->firstName,temp->lastName,temp->email);
            return;
        }
        temp = temp->next;
    }
    printf("Member not found\n");
}

void displayMailingList(struct member* head){
    if (head == NULL){
        printf("Mailing List is Empty\n");
        return;
    }
    struct member* temp = head;
    while (temp != NULL){
        printf("First Name: %s\nLast Name: %s\nEmail: %s\n\n",temp->firstName,temp->lastName,temp->email);
        temp = temp->next;
    }
}

void clean(char * string) {
    char* p = string;
    int len = strlen(p);

    while (isspace(p[len - 1])) p[--len] = 0;
    while (*p && isspace(*p)) ++p, --len;
    memmove(string, p, len + 1);
}

void welcome(){
    printf("Greetings!\nThis is your C Mailing List Manager!\n");
    printf("I am your assistant, Sherlock Homes, here to help manage your mailing list.\n");
    printf("Lets get started!\n");
}

int main(){
    struct member* head = NULL;
    char choice, email[50],firstName[20],lastName[20];

    welcome();

    while (1){
        printf("What would you like to do? Press:\n");
        printf("1 to Add a Member to the Mailing List\n");
        printf("2 to Remove a Member from the Mailing List\n");
        printf("3 to Search for a Member in the Mailing List\n");
        printf("4 to Display the Mailing List\n");
        printf("5 to Exit\n");
        choice=getchar();
        printf("\n");

        switch (choice){
            case '1':
                printf("Enter the details of Member to be added below: \n\n");
                printf("First Name: ");
                fgets(firstName,20,stdin); clean(firstName);
                printf("Last Name: ");
                fgets(lastName,20,stdin); clean(lastName);
                printf("Email: ");
                fgets(email,50,stdin); clean(email);
                addMember(&head,firstName,lastName,email); 
                break;

            case '2':
                printf("Enter the email of a member to be deleted: ");
                fgets(email,50,stdin); clean(email);
                deleteMember(&head,email);
                break;

            case '3': 
                printf("Enter the email of a member to search: ");
                fgets(email,50,stdin); clean(email);
                searchMember(head,email);
                break;

            case '4': 
                printf("Mailing List:\n\n");
                displayMailingList(head);
                break;

            case '5': 
                printf("\nThank you for using C Mailing List Manager!Goodbye!!\n");
                exit(0);
            default: 
                printf("Invalid input, try again please!\n");
        }
        getchar();
    }

    return 0;
}