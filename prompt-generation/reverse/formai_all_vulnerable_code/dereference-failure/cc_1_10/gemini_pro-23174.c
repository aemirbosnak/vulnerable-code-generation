//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

// Custom memory management functions
void* my_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory!\n");
        exit(1);
    }
    return ptr;
}

void my_free(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

// Unique data structure
typedef struct {
    int x;
    float y;
    char* name;
} MyData;

// Memory management example
int main() {
    
    // Allocate memory for an array of MyData structures
    MyData* data = (MyData*) my_malloc(sizeof(MyData) * 10);
    
    // Initialize the data
    for (int i = 0; i < 10; i++) {
        data[i].x = i;
        data[i].y = i * 0.1;
        data[i].name = (char*) my_malloc(10);
        sprintf(data[i].name, "Data %d", i);
    }
    
    // Print the data
    for (int i = 0; i < 10; i++) {
        printf("%d: %.1f, %s\n", data[i].x, data[i].y, data[i].name);
    }
    
    // Free the memory
    for (int i = 0; i < 10; i++) {
        my_free(data[i].name);
    }
    
    my_free(data);
    
    return 0;
}