//Falcon2-11B DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>

// Define a custom data type
typedef struct {
    int a;
    char b;
} MyStruct;

// Define a function to convert a MyStruct object to a string
char *convert_to_string(MyStruct obj) {
    // Create a buffer to hold the string
    char buffer[50];

    // Convert the object to a string and store it in the buffer
    sprintf(buffer, "MyStruct (%d, %c)", obj.a, obj.b);

    // Return the string
    return buffer;
}

// Define a function to read two integers and a character from the user
void read_data(MyStruct *obj) {
    // Read the first integer
    printf("Enter the first integer: ");
    scanf("%d", &obj->a);

    // Read the second integer
    printf("Enter the second integer: ");
    scanf("%d", &obj->b);

    // Read the character
    printf("Enter a character: ");
    scanf("%c", &obj->b);
}

// Define a function to write the string representation of a MyStruct object to the console
void write_string(MyStruct obj) {
    // Call the convert_to_string function
    char *str = convert_to_string(obj);

    // Print the string to the console
    printf("%s\n", str);

    // Free the memory allocated for the string
    free(str);
}

int main() {
    // Create a MyStruct object
    MyStruct obj;

    // Read the data from the user
    read_data(&obj);

    // Write the string representation of the object to the console
    write_string(obj);

    return 0;
}