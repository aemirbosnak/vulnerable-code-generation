//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *name;
    char **attNames;
    char **attValues;
    int numAttributes;
}Element;

void parseXML(char *filename);
void parseElement(FILE *file, Element *element);
char *extractName(char *line);
int extractAttributes(char *line, char ***attNames, char ***attValues);

int main(){
    char *filename = "example.xml";
    parseXML(filename);
    return 0;
}

void parseXML(char *filename){
    FILE *file;
    Element *element = (Element*)malloc(sizeof(Element));
    file = fopen(filename, "r");
    if(file){
        parseElement(file, element);
        fclose(file);
    }else{
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
}

void parseElement(FILE *file, Element *element){
    char line[256];
    fgets(line, sizeof(line), file);
    element->name = extractName(line);
    element->numAttributes = extractAttributes(line, &(element->attNames), &(element->attValues));
    printf("<%s", element->name);
    for(int i=0; i<element->numAttributes; i++){
        printf(" %s=\"%s\"", element->attNames[i], element->attValues[i]);
    }
    printf(">\n");

    while(fgets(line, sizeof(line), file)){
        if(line[1] == '/'){
            printf("</%s>\n", element->name);
            break;
        }else if(line[1] == '?'){
            continue;
        }else{
            Element *subElement = (Element*)malloc(sizeof(Element));
            subElement->name = extractName(line);
            subElement->numAttributes = extractAttributes(line, &(subElement->attNames), &(subElement->attValues));
            printf("<%s", subElement->name);
            for(int i=0; i<subElement->numAttributes; i++){
                printf(" %s=\"%s\"", subElement->attNames[i], subElement->attValues[i]);
            }
            printf(">\n");
            parseElement(file, subElement);
            free(subElement);
        }
    }
}

char *extractName(char *line){
    char *name = (char*)malloc(sizeof(char)*256);
    int index = 1;
    while(line[index] != ' ' && line[index] != '>'){
        name[index-1] = line[index];
        index++;
    }
    name[index-1] = '\0';
    return name;
}

int extractAttributes(char *line, char ***attNames, char ***attValues){
    int count = 0;
    char *str = strstr(line, " ");
    while(str){
        (*attNames) = (char**)realloc((*attNames), sizeof(char*)*(count+1));
        (*attValues) = (char**)realloc((*attValues), sizeof(char*)*(count+1));
        str++;
        (*attNames)[count] = str;
        while(*str != '='){
            str++;
        }
        *str = '\0';
        str++;
        (*attValues)[count] = str;
        while(*str != '"'){
            str++;
        }
        *str = '\0';
        count++;
        str = strstr(str+1, " ");
    }
    return count;
}