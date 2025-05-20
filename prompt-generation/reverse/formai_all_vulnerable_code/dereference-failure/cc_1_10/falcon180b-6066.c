//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

typedef struct hash_table{
    char key[50];
    int value;
    struct hash_table *next;
}Hash_Table;

Hash_Table *table[SIZE];

int hash(char *str){
    int sum=0;
    int i=0;
    while(str[i]!='\0'){
        sum+=str[i];
        i++;
    }
    return sum%SIZE;
}

void insert(char *key,int value){
    int index=hash(key);
    Hash_Table *temp=table[index];
    while(temp!=NULL){
        if(strcmp(temp->key,key)==0){
            temp->value=value;
            return;
        }
        temp=temp->next;
    }
    Hash_Table *newnode=(Hash_Table*)malloc(sizeof(Hash_Table));
    strcpy(newnode->key,key);
    newnode->value=value;
    newnode->next=NULL;
    table[index]=newnode;
}

int search(char *key){
    int index=hash(key);
    Hash_Table *temp=table[index];
    while(temp!=NULL){
        if(strcmp(temp->key,key)==0){
            return temp->value;
        }
        temp=temp->next;
    }
    return -1;
}

void delete(char *key){
    int index=hash(key);
    Hash_Table *temp=table[index];
    Hash_Table *prev=NULL;
    while(temp!=NULL){
        if(strcmp(temp->key,key)==0){
            if(prev==NULL){
                table[index]=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
}

void print(){
    int i=0;
    for(i=0;i<SIZE;i++){
        Hash_Table *temp=table[i];
        while(temp!=NULL){
            printf("%s %d\n",temp->key,temp->value);
            temp=temp->next;
        }
    }
}

int main(){
    insert("apple",5);
    insert("orange",10);
    insert("banana",15);
    insert("grapes",20);
    insert("mango",25);
    print();
    int search_result=search("orange");
    if(search_result!=-1){
        printf("Value of %s is %d\n",search_result);
    }
    else{
        printf("Key not found\n");
    }
    delete("orange");
    print();
    return 0;
}