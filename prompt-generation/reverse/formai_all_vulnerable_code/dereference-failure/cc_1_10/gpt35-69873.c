//FormAI DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_EMAILS 1000
 
struct email {
    char name[50];
    char email[100];
};
 
struct emailList {
    struct email *list;
    int size;
    int capacity;
};
 
void addEmail(struct emailList *eList, char *name, char *email) {
    if (eList->size == eList->capacity) {
        eList->capacity *= 2;
        eList->list = (struct email *)realloc(eList->list, sizeof(struct email) * eList->capacity);
    }
    strcpy(eList->list[eList->size].name, name);
    strcpy(eList->list[eList->size].email, email);
    eList->size++;
}
 
void printEmail(struct email e) {
    printf("%s - %s\n", e.name, e.email);
}
 
void printList(struct emailList eList) {
    for (int i = 0; i < eList.size; i++)
        printEmail(eList.list[i]);
}
 
void deleteEmail(struct emailList *eList, int index) {
    if (index < 0 || index >= eList->size)
        printf("Invalid index\n");
    else {
        eList->size--;
        for (int i = index; i < eList->size; i++)
            eList->list[i] = eList->list[i+1];
    }
}
 
int main() {
    struct emailList eList;
    eList.list = (struct email *)malloc(sizeof(struct email) * MAX_EMAILS);
    eList.size = 0;
    eList.capacity = MAX_EMAILS;
 
    addEmail(&eList, "Samantha Smith", "samantha.smith@gmail.com");
    addEmail(&eList, "John Doe", "john.doe@yahoo.com");
    addEmail(&eList, "Jane Smith", "jane_smith@outlook.com");
 
    printf("Initial List:\n");
    printList(eList);
    printf("\n");
 
    addEmail(&eList, "Peter Jones", "peter_jones@gmail.com");
 
    printf("List after addition:\n");
    printList(eList);
    printf("\n");
 
    deleteEmail(&eList, 2);
 
    printf("List after deletion:\n");
    printList(eList);
    printf("\n");
 
    return 0;
}