//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct {
    char tag[20];
    char attr_name[20][20];
    char attr_value[20][50];
    int attr_count;
    char data[100];
} Element;

FILE *file;
Element *elements[20];
int element_count = 0;
pthread_mutex_t mutex;

void insert_element(Element *element) {
    pthread_mutex_lock(&mutex);
    elements[element_count++] = element;
    pthread_mutex_unlock(&mutex);
}

void parse_element(char *line) {
    Element *element = (Element *)malloc(sizeof(Element));
    
    char *temp = strtok(line, "<>");
    strcpy(element->tag, temp);
    
    temp = strtok(NULL, "<>");
    while(temp != NULL) {
        if(temp[0] != '/') {
            char *attr = strtok(temp, "=");
            char *value = strtok(NULL, "=");
            memset(element->attr_value[element->attr_count], 0, sizeof(element->attr_value[0]));
            strcpy(element->attr_name[element->attr_count], attr);
            value[strlen(value)-1] = '\0';
            value++;
            strcpy(element->attr_value[element->attr_count], value);
            element->attr_count++;
        } else {
            break;
        }
        temp = strtok(NULL, "<>");
    }
    
    insert_element(element);
}

void parse_file() {
    char line[150];
    while(fgets(line, sizeof(line), file)) {
        parse_element(line);
    }
}

void print_elements() {
    for(int i = 0; i < element_count; i++) {
        Element *element = elements[i];
        printf("Tag: %s\n", element->tag);
        printf("Attributes: \n");
        for(int j = 0; j < element->attr_count; j++) {
            printf("%s: %s\n", element->attr_name[j], element->attr_value[j]);
        }
        printf("Data: %s\n", element->data);
        printf("\n");
    }
}

void *parse_xml(void *args) {
    parse_file();
    return NULL;
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    file = fopen("example.xml", "r");
    if(file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    pthread_t parse_thread;
    pthread_create(&parse_thread, NULL, parse_xml, NULL);
    pthread_join(parse_thread, NULL);
    print_elements();
    pthread_mutex_destroy(&mutex);
    fclose(file);
    return 0;
}