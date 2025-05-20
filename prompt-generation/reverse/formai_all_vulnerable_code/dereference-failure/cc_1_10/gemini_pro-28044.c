//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct couple {
	char name[20];
	int age;
	char gender;
	char hobbies[100];
	struct couple *next;
};

struct couple *head = NULL;

void add_couple(char *name, int age, char gender, char *hobbies) {
	struct couple *new_couple = malloc(sizeof(struct couple));
	strcpy(new_couple->name, name);
	new_couple->age = age;
	new_couple->gender = gender;
	strcpy(new_couple->hobbies, hobbies);
	new_couple->next = NULL;

	if (head == NULL) {
		head = new_couple;
	} else {
		struct couple *current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_couple;
	}
}

void print_couple(struct couple *couple) {
	printf("Name: %s\n", couple->name);
	printf("Age: %d\n", couple->age);
	printf("Gender: %c\n", couple->gender);
	printf("Hobbies: %s\n\n", couple->hobbies);
}

void find_compatible_couples() {
	struct couple *current1 = head;
	struct couple *current2;

	while (current1 != NULL) {
		current2 = current1->next;
		while (current2 != NULL) {
			if (current1->gender != current2->gender && current1->age == current2->age && strcmp(current1->hobbies, current2->hobbies) == 0) {
				printf("Compatible couple found:\n");
				print_couple(current1);
				print_couple(current2);
			}
			current2 = current2->next;
		}
		current1 = current1->next;
	}
}

int main() {
	srand(time(NULL));

	// Add some couples to the database
	add_couple("John", 25, 'M', "hiking, camping, fishing");
	add_couple("Mary", 23, 'F', "reading, writing, painting");
	add_couple("Bob", 30, 'M', "running, biking, swimming");
	add_couple("Alice", 28, 'F', "dancing, singing, acting");
	add_couple("Tom", 35, 'M', "playing guitar, singing, songwriting");
	add_couple("Susan", 32, 'F', "cooking, baking, gardening");

	// Find compatible couples
	find_compatible_couples();

	return 0;
}