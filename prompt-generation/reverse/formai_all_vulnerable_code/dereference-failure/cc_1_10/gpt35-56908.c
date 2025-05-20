//FormAI DATASET v1.0 Category: Phone Book ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct contact{ //structure for contact details
    char* name;
    int phone_num;
}Contact;

void add_contact(Contact** phone_book, int* size){ //function to add a contact to phone book
    char name[20];
    int phone_num;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter phone number: ");
    scanf("%d", &phone_num);

    (*phone_book) = (Contact*)realloc((*phone_book), ((*size)+1)*sizeof(Contact));
    (*phone_book)[*size].name = (char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy((*phone_book)[*size].name, name);
    (*phone_book)[*size].phone_num = phone_num;

    ++(*size);

    printf("Contact added successfully!\n\n");
}

void search_contact(Contact* phone_book, int size){ //function to search a contact in phone book
    char name[20];
    int index = -1; //initialize index to -1, will be used later to identify if the contact was found or not

    printf("Enter name of the contact to search: ");
    scanf("%s", name);

    for(int i = 0; i < size; i++){
        if(strcmp(phone_book[i].name, name) == 0){
            index = i;
            break;
        }
    }

    if(index != -1){
        printf("Contact found!\n");
        printf("Name: %s\n", phone_book[index].name);
        printf("Phone number: %d\n\n", phone_book[index].phone_num);
    }
    else{
        printf("Contact not found!\n\n");
    }
}

void display_contacts(Contact* phone_book, int size){ //function to display all contacts in phone book
    printf("=====================================\n");
    printf("\tPHONE BOOK\n");
    printf("=====================================\n");

    for(int i = 0; i < size; i++){
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone number: %d\n", phone_book[i].phone_num);
        printf("-------------------------------------\n");
    }

    printf("\n");
}

int main(){
    Contact* phone_book = NULL;
    int size = 0, choice;

    do{
        printf("=====================================\n");
        printf("\tMAIN MENU\n");
        printf("=====================================\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Display all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_contact(&phone_book, &size);
                break;

            case 2:
                search_contact(phone_book, size);
                break;

            case 3:
                display_contacts(phone_book, size);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice != 4);

    return 0;
}