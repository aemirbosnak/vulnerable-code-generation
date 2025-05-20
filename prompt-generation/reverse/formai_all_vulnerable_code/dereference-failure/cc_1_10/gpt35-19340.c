//FormAI DATASET v1.0 Category: Phone Book ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact{
    char name[20];
    char phone[10];
    char email[30];
};

// function declarations
void add(struct contact *c, int *n);
void search(struct contact *c, int n);
void display(struct contact *c, int n);
void sort(struct contact *c, int n);

int main(){
    int n = 0, choice;
    struct contact *c = malloc(sizeof(struct contact));
    while(1){
        printf("\n------------------------\n");
        printf("\nPHONE BOOK\n\n");
        printf("1. Add a contact\n");
        printf("2. Search a contact\n");
        printf("3. Display contacts\n");
        printf("4. Sort contacts by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: add(c, &n);
                    break;
            case 2: search(c, n);
                    break;
            case 3: display(c, n);
                    break;
            case 4: sort(c, n);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    free(c);
    return 0;
}

void add(struct contact *c, int *n){
    printf("\nEnter details for contact %d:\n", (*n)+1);
    printf("Name: ");
    scanf("%s",c[*n].name);
    printf("Phone: ");
    scanf("%s",c[*n].phone);
    printf("Email: ");
    scanf("%s",c[*n].email);
    (*n)++;
    printf("\nContact added successfully!\n");
}

void search(struct contact *c, int n){
    char key[20];
    int i, flag=0;
    printf("Enter name to search: ");
    scanf("%s",key);
    for(i=0; i<n; i++){
        if(strcmp(c[i].name, key)==0){
            printf("\nDetails for %s:\n", key);
            printf("Phone: %s\n",c[i].phone);
            printf("Email: %s\n",c[i].email);
            flag = 1;
        }
    }
    if(!flag)
        printf("\nContact not found!\n");
}

void display(struct contact *c, int n){
    int i;
    if(n==0){
        printf("\nPhone book is empty!\n");
        return;
    }
    printf("\n------------------------\n");
    printf("PHONE BOOK LISTING\n\n");
    for(i=0; i<n; i++){
        printf("%s %s\t%s\n", c[i].name, c[i].phone, c[i].email);
    }
    printf("------------------------\n");
}

void sort(struct contact *c, int n){
    int i, j;
    struct contact temp;
    if(n==0){
        printf("\nPhone book is empty!\n");
        return;
    }
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(c[i].name, c[j].name)>0){
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    printf("\nContacts sorted by name!\n");
}