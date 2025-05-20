//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a person
typedef struct Person {
    char name[50];
    int age;
    struct Person *left;
    struct Person *right;
} Person;

// Function to create a new person node
Person* createPerson(char *name, int age) {
    Person *newPerson = (Person *)malloc(sizeof(Person));
    strcpy(newPerson->name, name);
    newPerson->age = age;
    newPerson->left = NULL;
    newPerson->right = NULL;
    return newPerson;
}

// Function to insert a person into the binary tree
Person* insertPerson(Person* root, char *name, int age) {
    if (root == NULL) {
        return createPerson(name, age);
    }
    
    if (age < root->age) {
        root->left = insertPerson(root->left, name, age);
    } else {
        root->right = insertPerson(root->right, name, age);
    }
    return root;
}

// Function to search for a person by name recursively
Person* searchPerson(Person* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    
    if (strcmp(name, root->name) < 0) {
        return searchPerson(root->left, name);
    }
    
    return searchPerson(root->right, name);
}

// Function to find the minimum age in the tree
Person* findMinAge(Person* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL) {
        return root;
    }
    return findMinAge(root->left);
}

// Function to delete a person from the binary tree
Person* deletePerson(Person* root, char *name) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = deletePerson(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deletePerson(root->right, name);
    } else {
        if (root->left == NULL) {
            Person *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Person *temp = root->left;
            free(root);
            return temp;
        }
        
        Person *temp = findMinAge(root->right);
        strcpy(root->name, temp->name);
        root->age = temp->age;
        root->right = deletePerson(root->right, temp->name);
    }
    return root;
}

// Function to perform an in-order traversal of the tree
void inOrderTraversal(Person* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("Name: %s, Age: %d\n", root->name, root->age);
        inOrderTraversal(root->right);
    }
}

// Main function to illustrate the use of the above functions
int main() {
    Person *root = NULL;
    root = insertPerson(root, "Alice", 30);
    root = insertPerson(root, "Bob", 25);
    root = insertPerson(root, "Charlie", 35);
    root = insertPerson(root, "Diane", 28);
    root = insertPerson(root, "Eve", 22);
    
    printf("In-order Traversal of the Tree:\n");
    inOrderTraversal(root);
    
    char searchName[50];
    printf("Enter the name to search for: ");
    scanf("%s", searchName);
    
    Person *foundPerson = searchPerson(root, searchName);
    if (foundPerson != NULL) {
        printf("Found: Name: %s, Age: %d\n", foundPerson->name, foundPerson->age);
    } else {
        printf("Person not found.\n");
    }
    
    char deleteName[50];
    printf("Enter the name to delete: ");
    scanf("%s", deleteName);
    
    root = deletePerson(root, deleteName);
    
    printf("In-order Traversal after Deletion:\n");
    inOrderTraversal(root);
    
    // Cleanup memory (optional)
    while (root != NULL) {
        root = deletePerson(root, root->name);
    }
    
    return 0;
}