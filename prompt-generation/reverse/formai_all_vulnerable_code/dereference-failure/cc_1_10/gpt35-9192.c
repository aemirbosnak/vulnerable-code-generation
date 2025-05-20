//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* structure for data record */
struct record{
    int id;
    char name[20];
    float score;
};

/* node structure for B+ tree */
struct node{
    int is_leaf;
    int n;
    int key[4];
    struct node *ptr[5];
    struct record *rec_ptr[4];  
};

/* function to create a new node */
struct node * createNode(int leaf){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->is_leaf = leaf;
    new_node->n = 0;
    return new_node;
}

/* function to search for a record with given id */
struct record * searchRecord(struct node *root, int id){
    int i;
    struct node *ptr;
    ptr = root;
    if(ptr == NULL){
        printf("Error: Database is empty\n");
        return NULL;
    }
    /* find the leaf node where record may be */
    while(ptr->is_leaf == 0){
        for(i=0; i<ptr->n; i++){
            if(id < ptr->key[i]){
                ptr = ptr->ptr[i];
                break;
            }
            else if(i == (ptr->n-1)){
                ptr = ptr->ptr[i+1];
                break;
            }
        }
    }
    /* search the record in the leaf node */
    for(i=0; i<ptr->n; i++){
        if(ptr->rec_ptr[i]->id == id){
            return ptr->rec_ptr[i];
        }
    }
    printf("Record not found\n");
    return NULL;
}

/* function to insert a record */
struct node * insertRecord(struct node *root, struct record *rec){
    int i, j;
    struct node *ptr, *new_node, *parent;
    int id = rec->id;
    if(root == NULL){
        root = createNode(1);
        root->rec_ptr[0] = rec;
        root->n++;
        return root;
    }
    /* find the leaf node where record may be inserted */
    ptr = root;
    while(ptr->is_leaf == 0){
        for(i=0; i<ptr->n; i++){
            if(id < ptr->key[i]){
                ptr = ptr->ptr[i];
                break;
            }
            else if(i == (ptr->n-1)){
                ptr = ptr->ptr[i+1];
                break;
            }
        }
    }
    /* if there is space in the leaf node */
    if(ptr->n < 4){
        i=0;
        while(id > ptr->rec_ptr[i]->id && i < ptr->n){
            i++;
        }
        for(j=ptr->n; j>i; j--){
            ptr->rec_ptr[j] = ptr->rec_ptr[j-1];
        }
        ptr->rec_ptr[i] = rec;
        ptr->n++;
        return root;
    }
    /* if there is no space in the leaf node */
    new_node = createNode(1);
    /* shift records to new node */
    for(i=0; i<3; i++){
        new_node->rec_ptr[i] = ptr->rec_ptr[i+1];
    }
    ptr->n = 2;
    new_node->n = 2;
    /* connect new node to parent node */
    if(ptr == root){
        parent = createNode(0);
        root = parent;
        parent->key[0] = new_node->rec_ptr[0]->id;
        parent->ptr[0] = ptr;
        parent->ptr[1] = new_node;
        parent->n++;
        return root;
    }
    else{
        parent = ptr->ptr[4];
    }
    /* if there is space in the parent node */
    if(parent->n < 4){
        i=0;
        while(ptr->rec_ptr[0]->id > parent->key[i] && i < parent->n){
            i++;
        }
        for(j=parent->n; j>i; j--){
            parent->key[j] = parent->key[j-1];
        }
        for(j=parent->n+1; j>i+1; j--){
            parent->ptr[j] = parent->ptr[j-1];
        }
        parent->key[i] = new_node->rec_ptr[0]->id;
        parent->ptr[i+1] = new_node;
        parent->n++;
        return root;
    }
    /* if there is no space in the parent node */
    else{
        struct node *new_parent;
        new_parent = createNode(0);
        int mid = parent->key[2];
        parent->n = 2;
        new_parent->n = 1;
        new_parent->key[0] = mid;
        new_parent->ptr[0] = parent;
        new_parent->ptr[1] = new_node;
        return new_parent;
    }
}

/* function to print the B+ tree */
void display(struct node *root){
    int i;
    struct node *ptr;
    ptr = root;
    if(ptr != NULL){
        printf("[");
        for(i=0; i<ptr->n; i++){
            if(ptr->is_leaf == 0){
                printf("%d ", ptr->key[i]);
                display(ptr->ptr[i]);
            }
            else{
                printf("%d:%s:%f ", ptr->rec_ptr[i]->id, ptr->rec_ptr[i]->name, ptr->rec_ptr[i]->score);
            }
        }
        if(ptr->is_leaf == 0){
            display(ptr->ptr[i]);
        }
        printf("]");
    }
}

/* main function */
int main(){
    struct node *root = NULL;
    struct record *rec;
    char ch[20];
    int id, i;
    float score;
    while(1){
        printf("\nSelect an option:\n1. Insert a record\n2. Search for a record\n3. Display all records\n4. Exit\n");
        scanf("%d", &i);
        switch(i){
            case 1: printf("Enter student ID, name and score:\n");
                    scanf("%d %s %f", &id, ch, &score);
                    rec = (struct record *)malloc(sizeof(struct record));
                    rec->id = id;
                    strcpy(rec->name, ch);
                    rec->score = score;
                    root = insertRecord(root, rec);
                    break;
            case 2: printf("Enter student ID to search:\n");
                    scanf("%d", &id);
                    rec = searchRecord(root, id);
                    if(rec != NULL){
                        printf("Record Found: %d %s %f\n", rec->id, rec->name, rec->score);
                    }
                    break;
            case 3: printf("All Records: ");
                    display(root);
                    printf("\n");
                    break;
            case 4:
            default: printf("Exiting...\n");
                     return 0;
        }
    } 
    return 0;
}