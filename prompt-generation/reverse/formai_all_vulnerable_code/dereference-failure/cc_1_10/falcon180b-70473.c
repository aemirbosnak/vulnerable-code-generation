//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 200

typedef struct element_t{
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
    struct element_t* next;
}element_t;

typedef struct{
    element_t* root;
}xml_t;

xml_t* xml_create(){
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    xml->root = NULL;
    return xml;
}

void xml_destroy(xml_t* xml){
    element_t* curr = xml->root;
    while(curr!=NULL){
        element_t* temp = curr->next;
        free(curr->name);
        free(curr->value);
        free(curr);
        curr = temp;
    }
    free(xml);
}

element_t* xml_add_element(xml_t* xml,char* name,char* value){
    element_t* new_element = (element_t*)malloc(sizeof(element_t));
    strcpy(new_element->name,name);
    strcpy(new_element->value,value);
    new_element->next = NULL;
    if(xml->root==NULL){
        xml->root = new_element;
    }else{
        element_t* curr = xml->root;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = new_element;
    }
    return new_element;
}

int main(){
    xml_t* xml = xml_create();
    xml_add_element(xml,"name","John");
    xml_add_element(xml,"age","30");
    xml_add_element(xml,"gender","Male");
    xml_add_element(xml,"city","New York");
    xml_add_element(xml,"country","USA");

    element_t* curr = xml->root;
    while(curr!=NULL){
        printf("%s : %s\n",curr->name,curr->value);
        curr = curr->next;
    }

    xml_destroy(xml);
    return 0;
}