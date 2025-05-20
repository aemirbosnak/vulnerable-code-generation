//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Tag;

void parseXML(char *xml) {
    int i = 0, j = 0, k = 0;
    char *tag = NULL;
    char *p = xml;
    Tag *tags = (Tag*)malloc(sizeof(Tag) * 10);
    
    while (*p != '\0') {
        tag = (char*)malloc(sizeof(char) * 20);
        memset(tag, 0, sizeof(char) * 20);
        
        if (*p == '<') {
            p++;
            j = 0;
            
            while (*p != '>') {
                tag[j++] = *p++;
            }
            
            tag[j] = '\0';
            
            if (strcmp(tag, "/xml") == 0) {
                break;
            }
            
            if (*p == '>') {
                p++;
            }
            
            if (tag[0] != '/') {
                tags[i].name = tag;
                
                while (*p != '<') {
                    tags[i].value[k++] = *p++;
                }
                
                tags[i].value[k] = '\0';
                i++;
            } else {
                free(tag);
                k = 0;
            }
        } else {
            p++;
        }
    }
    
    for (int j = 0; j < i; j++) {
        printf("%s: %s\n", tags[j].name, tags[j].value);
    }
}

int main() {
    char xml[] = "<xml><name>John</name><age>30</age><email>john@gmail.com</email></xml>";
    
    parseXML(xml);
    
    return 0;
}