//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*This program is an asynchronous C code that checks if a given word/phrase is a palindrome or not*/

typedef struct node {
    char ch;
    struct node* next;
}node_t;

/*This function pushes a character to the stack*/
void push(node_t** top, char ch){
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    newNode->ch = ch;
    newNode->next = *top;
    *top = newNode;
}

/*This function pops a character from the stack*/
char pop(node_t** top){
    char ch = (*top)->ch;
    node_t* temp = *top;
    *top = (*top)->next;
    free(temp);
    return ch;
}

/*This function checks if a given word/phrase is a palindrome or not*/
void isPalindrome(char* str){
    int n = strlen(str);
    node_t* top = NULL;
    int i;
    for(i=0;i<n/2;i++)
        push(&top, str[i]);
    if(n%2!=0) i++;
    while(str[i]!='\0') {
        if(pop(&top)!=str[i]) {
            printf("%s is NOT a palindrome", str); 
            return;
        }
        i++;
    }
    printf("%s is a palindrome", str);
}

/*Main function that gets the user input and calls the isPalindrome function*/
int main(){
    char str[100];
    printf("Enter a word or phrase: ");
    fgets(str, 100, stdin);
    char* nlPtr = strchr(str, '\n');
    if(nlPtr) *nlPtr = '\0';
    isPalindrome(str);
    return 0;
}