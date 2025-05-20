//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    char name[20];
    int phone;
}contact;

int main(){
    int choice,i,n;
    contact *book = NULL;
    printf("WELCOME TO THE POST-APOCALYPTIC PHONE BOOK\n");
    printf("1. CREATE CONTACT\n");
    printf("2. DELETE CONTACT\n");
    printf("3. SEARCH CONTACT\n");
    printf("4. EXIT\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("ENTER THE NAME OF THE CONTACT: ");
            scanf("%s",book->name);
            printf("ENTER THE PHONE NUMBER OF THE CONTACT: ");
            scanf("%d",&book->phone);
            n = sizeof(contact);
            book = (contact*)malloc(n);
            strcpy(book->name,book->name);
            book->phone = book->phone;
            printf("\nCONTACT CREATED SUCCESSFULLY\n");
            break;
        case 2:
            printf("ENTER THE NAME OF THE CONTACT TO BE DELETED: ");
            scanf("%s",book->name);
            for(i=0;i<n;i++){
                if(strcmp(book[i].name,book->name)==0){
                    free(book[i].name);
                    free(book[i].phone);
                    printf("\nCONTACT DELETED SUCCESSFULLY\n");
                }
            }
            break;
        case 3:
            printf("ENTER THE NAME OF THE CONTACT TO BE SEARCHED: ");
            scanf("%s",book->name);
            for(i=0;i<n;i++){
                if(strcmp(book[i].name,book->name)==0){
                    printf("\nCONTACT FOUND\n");
                    printf("NAME: %s\n",book[i].name);
                    printf("PHONE NUMBER: %d\n",book[i].phone);
                }
            }
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID CHOICE\n");
    }
    return 0;
}