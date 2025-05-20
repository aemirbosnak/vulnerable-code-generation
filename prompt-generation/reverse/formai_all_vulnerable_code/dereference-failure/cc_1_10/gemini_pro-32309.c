//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Declaring some funky data structures
typedef struct {
	int age;
	char name[20];
	float salary;
} Employee;

typedef struct {
	char *data;
	int size;
} Buffer;

// Defining a memory manager
void *my_malloc(size_t size) {
	// Let's pretend we're in a circus and allocate memory like clowns juggling balls
	void *ptr = malloc(size);
	if (!ptr) {
		printf("Oops! The clown dropped the ball (memory allocation failed)!\n");
		exit(1);
	}
	return ptr;
}

void my_free(void *ptr) {
	// Time to retire the clown and free the memory
	free(ptr);
	printf("The clown has retired (memory freed)!\n");
}

// Creating our own dynamic array
Buffer *create_buffer(size_t size) {
	// Allocating the buffer like a magician pulling a rabbit out of a hat
	Buffer *buf = my_malloc(sizeof(Buffer));
	buf->data = my_malloc(size);
	buf->size = size;
	printf("Ta-da! A magical buffer has appeared!\n");
	return buf;
}

void destroy_buffer(Buffer *buf) {
	// Vanishing the buffer like a magician disappearing an elephant
	my_free(buf->data);
	my_free(buf);
	printf("Poof! The buffer has disappeared!\n");
}

// Time for some juggling with memory
int main() {
	// Allocating an employee struct like a juggling clown tossing balls
	Employee *emp = my_malloc(sizeof(Employee));
	printf("Meet our juggling employee: %s!\n", emp->name);

	// Playing with a buffer like a circus acrobat
	Buffer *buf = create_buffer(1024);
	printf("Look at that acrobatics with the buffer! It can hold %d bytes.\n", buf->size);
	strcpy(buf->data, "Abracadabra!");
	printf("The buffer has some magic in it: %s\n", buf->data);

	// Releasing the employee and the buffer like letting go of balloons
	my_free(emp);
	destroy_buffer(buf);
	printf("The employee has gone home, and the buffer has been deflated.\n");

	return 0;
}