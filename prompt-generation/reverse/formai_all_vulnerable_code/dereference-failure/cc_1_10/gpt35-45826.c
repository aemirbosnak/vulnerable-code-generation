//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact{
    char name[50];
    char phone_no[15];
};

int main(){
    int n, choice, i;
    printf("How many contacts do you want to store? ");
    scanf("%d",&n);

    struct contact *phonebook = (struct contact*) malloc(n * sizeof(struct contact));

    // Adding Contacts
    printf("\nEnter the details for each contact:\n");
    for(i=0; i<n; i++){
        printf("\nContact %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]s", phonebook[i].name);
        printf("Phone Number: ");
        scanf(" %s", phonebook[i].phone_no);
    }
    
    // Searching Contacts
    char search_name[50];
    printf("\nEnter the contact name you want to search for: ");
    scanf(" %[^\n]s", search_name);

    for(i=0; i<n; i++){
        if(strcmp(search_name, phonebook[i].name) == 0){
            printf("\nContact found:\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phone_no);
            break;
        }
    }
    if(i==n){
        printf("\nContact not found.\n");
    }
    
    // Deleting Contacts
    printf("\nEnter the contact number you want to delete: ");
    scanf("%d", &choice);

    if(choice <= n){
        for(i=choice-1; i<n-1; i++){
            strcpy(phonebook[i].name, phonebook[i+1].name);
            strcpy(phonebook[i].phone_no, phonebook[i+1].phone_no);
        }
        n--;
        phonebook = (struct contact*) realloc(phonebook, n * sizeof(struct contact));
        printf("\nContact deleted successfully.\n");
    }
    else{
        printf("\nInvalid contact number.\n");
    }

    // Printing Contacts
    printf("\nPhonebook:\n");
    for(i=0; i<n; i++){
        printf("\n%d:\n", i+1);
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone Number: %s\n", phonebook[i].phone_no);
    }
    
    free(phonebook);
    return 0;
}