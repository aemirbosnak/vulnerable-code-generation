//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a custom type for our object
typedef struct {
    int id;
    char* name;
    int age;
} Object;

// Define a custom allocator for our object
void* custom_allocator(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    return ptr;
}

// Define a custom deallocator for our object
void custom_deallocator(void* ptr) {
    free(ptr);
}

// Define a function to create an object
Object* create_object(int id, char* name, int age) {
    Object* obj = (Object*)custom_allocator(sizeof(Object));
    obj->id = id;
    obj->name = (char*)custom_allocator(strlen(name) + 1);
    strcpy(obj->name, name);
    obj->age = age;
    return obj;
}

// Define a function to destroy an object
void destroy_object(Object* obj) {
    custom_deallocator(obj->name);
    custom_deallocator(obj);
}

int main() {
    Object* obj1 = create_object(1, "Alice", 25);
    Object* obj2 = create_object(2, "Bob", 30);
    
    printf("Object 1: %d, %s, %d\n", obj1->id, obj1->name, obj1->age);
    printf("Object 2: %d, %s, %d\n", obj2->id, obj2->name, obj2->age);
    
    destroy_object(obj1);
    destroy_object(obj2);
    
    return 0;
}