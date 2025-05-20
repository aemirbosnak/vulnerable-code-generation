//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ATTRIBUTES 10

typedef struct attribute
{
    char name[50];
    char value[50];
} Attribute;

typedef struct node
{
    char name[50];
    Attribute attributes[MAX_ATTRIBUTES];
    int num_attributes;
    char text[100];
    struct node* children[20];
    int num_children;
} Node;

Node* root;

void parse_node(char* xml_string, int* index, Node* current_node);
void parse_attributes(char* xml_string, int* index, Node* current_node);
void skip_whitespace(char* xml_string, int* index);
void print_node(Node* current_node, int depth);

int main()
{
    char xml_string[200] = "<bookstore><book category=\"children\"><title>The Cat in the Hat</title><author>Dr. Seuss</author></book><book category=\"cooking\"><title>The Joy of Cooking</title><author>Irma S. Rombauer</author></book></bookstore>";
    int index = 0;
    root = malloc(sizeof(Node));
    root->num_attributes = 0;
    root->num_children = 0;
    parse_node(xml_string, &index, root);
    print_node(root, 0);
    return 0;
}

void parse_node(char* xml_string, int* index, Node* current_node)
{
    int i = 0;
    char name[50];
    skip_whitespace(xml_string, index);
    if(xml_string[*index] != '<')
    {
        while(isalnum(xml_string[*index + i]) || xml_string[*index + i] == ' ')
        {
            i++;
        }
        strncpy(current_node->text, &xml_string[*index], i);
        *index += i;
    }
    if(xml_string[*index] == '<')
    {
        *index = *index + 1;
        if(xml_string[*index] == '/')
        {
            return;
        }
        i = 0;
        while(isalnum(xml_string[*index + i]))
        {
            name[i] = xml_string[*index + i];
            i++;
        }
        name[i] = '\0';
        *index += i;
        strncpy(current_node->name, name, strlen(name));
        parse_attributes(xml_string, index, current_node);
        skip_whitespace(xml_string, index);
        if(xml_string[*index] == '/')
        {
            *index += 2;
            return;
        }
        *index += 1;
        current_node->children[current_node->num_children] = malloc(sizeof(Node));
        current_node->num_children++;
        parse_node(xml_string, index, current_node->children[current_node->num_children-1]);
        while(xml_string[*index] == '<' && xml_string[*index + 1] != '/')
        {
            current_node->children[current_node->num_children] = malloc(sizeof(Node));
            current_node->num_children++;
            parse_node(xml_string, index, current_node->children[current_node->num_children-1]);
        }
        *index += strlen(name) + 3;
    }
}

void parse_attributes(char* xml_string, int* index, Node* current_node)
{
    int i,j,k;
    char attribute_name[50];
    char attribute_value[50];
    skip_whitespace(xml_string, index);
    while(xml_string[*index] != '>' && xml_string[*index] != '/')
    {
        i = 0;
        j = 0;
        k = 0;
        while(isalnum(xml_string[*index + i]) || xml_string[*index + i] == '-')
        {
            attribute_name[i] = xml_string[*index + i];
            i++;
        }
        attribute_name[i] = '\0';
        *index += i;
        while(!isalnum(xml_string[*index]) && xml_string[*index] != '\"')
        {
            *index += 1;
        }
        while(xml_string[*index + j] != '\"')
        {
            attribute_value[j] = xml_string[*index + j];
            j++;
        }
        attribute_value[j] = '\0';
        *index += j + 1;
        strncpy(current_node->attributes[current_node->num_attributes].name, attribute_name, strlen(attribute_name));
        strncpy(current_node->attributes[current_node->num_attributes].value, attribute_value, strlen(attribute_value));
        current_node->num_attributes++;
        skip_whitespace(xml_string, index);
    }
}

void skip_whitespace(char* xml_string, int* index)
{
    while(isspace(xml_string[*index]))
    {
        *index += 1;
    }
}

void print_node(Node* current_node, int depth)
{
    int i,j;
    for(i = 0; i < depth; i++)
    {
        printf("  ");
    }
    printf("%s", current_node->name);
    for(i = 0; i < current_node->num_attributes; i++)
    {
        printf(" %s=\"%s\"", current_node->attributes[i].name, current_node->attributes[i].value);
    }
    printf("\n");
    for(i = 0; i < current_node->num_children; i++)
    {
        print_node(current_node->children[i], depth + 1);
    }
    if(strlen(current_node->text) > 0)
    {
        for(i = 0; i < depth + 1; i++)
        {
            printf("  ");
        }
        printf("%s\n", current_node->text);
    }
}