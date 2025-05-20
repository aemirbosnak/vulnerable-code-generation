//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int count;
} Element;

void insert(Element *elements, int n, int val) {
    for (int i = 0; i < n; i++) {
        if (elements[i].value >= val) {
            elements[i].value = val;
            elements[i].count++;
        }
    }
}

void printArray(Element *elements, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", elements[i].value);
    }
    printf("\n");
}

void bucketSort(Element *elements, int n) {
    int maxVal = elements[0].value;
    for (int i = 1; i < n; i++) {
        if (elements[i].value > maxVal) {
            maxVal = elements[i].value;
        }
    }
    
    int buckets[maxVal + 1];
    for (int i = 0; i < maxVal + 1; i++) {
        buckets[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        insert(buckets, maxVal + 1, elements[i].value);
    }
    
    for (int i = 0; i < maxVal + 1; i++) {
        Element *temp = (Element *) malloc(sizeof(Element) * buckets[i]);
        for (int j = 0; j < buckets[i]; j++) {
            temp[j].value = i;
            temp[j].count = elements[j].count;
        }
        
        for (int j = 0; j < buckets[i]; j++) {
            insert(elements, n, temp[j].value);
        }
        
        free(temp);
    }
}

int main() {
    int n = 10;
    Element *elements = (Element *) malloc(sizeof(Element) * n);
    for (int i = 0; i < n; i++) {
        elements[i].value = rand() % 100;
        elements[i].count = 0;
    }
    
    printf("Before sorting: ");
    printArray(elements, n);
    
    bucketSort(elements, n);
    
    printf("After sorting: ");
    printArray(elements, n);
    
    return 0;
}