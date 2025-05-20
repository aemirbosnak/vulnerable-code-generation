//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook{
    char name[50];
    char number[15];
    char email[50];
};

typedef struct phonebook Phonebook;

int main(){
    int choice;
    int count = 0;
    Phonebook *pb;
    pb = (struct phonebook*) malloc(sizeof(struct phonebook));
    
    printf("Welcome to the C Phone Book!\n");
    printf("Please select an option:\n");
    printf("1. Add a contact\n");
    printf("2. Edit a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n");
    scanf("%d", &choice);
    
    while(choice != 5){
        if(choice == 1){
            printf("Enter Name: ");
            scanf("%s", pb[count].name);
            printf("Enter Phone Number: ");
            scanf("%s", pb[count].number);
            printf("Enter Email Address: ");
            scanf("%s", pb[count].email);
            count++;
            pb = (Phonebook*)realloc(pb, (count+1)*sizeof(Phonebook));
            printf("\nContact added successfully!\n\n");
        }
        else if(choice == 2){
            int index;
            printf("Enter the index of the contact you want to edit: ");
            scanf("%d", &index);
            printf("Enter new Name: ");
            scanf("%s", pb[index].name);
            printf("Enter new Phone Number: ");
            scanf("%s", pb[index].number);
            printf("Enter new Email Address: ");
            scanf("%s", pb[index].email);
            printf("\nContact edited successfully!\n\n");
        }
        else if(choice == 3){
            printf("Enter Name to search: ");
            char search[50];
            scanf("%s", search);
            printf("\nResults:\n");
            for(int i=0; i<count; i++){
                if(strcmp(pb[i].name, search) == 0){
                    printf("%s\n", pb[i].name);
                    printf("%s\n", pb[i].number);
                    printf("%s\n\n", pb[i].email);
                }
            }
        }
        else if(choice == 4){
            int index;
            printf("Enter the index of the contact you want to delete: ");
            scanf("%d", &index);
            for(int i=index; i<count-1; i++){
                strcpy(pb[i].name, pb[i+1].name);
                strcpy(pb[i].number, pb[i+1].number);
                strcpy(pb[i].email, pb[i+1].email);
            }
            count--;
            pb = (Phonebook*)realloc(pb, (count+1)*sizeof(Phonebook));
            printf("\nContact deleted successfully!\n\n");
        }
        else{
            printf("Invalid choice!\n\n");
        }
        
        printf("Please select an option:\n");
        printf("1. Add a contact\n");
        printf("2. Edit a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
    }
    
    free(pb);
    printf("Thank you for using C Phone Book!\n");
    
    return 0;
}