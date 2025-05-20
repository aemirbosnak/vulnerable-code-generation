//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct node  //creating a struct node for storing values
{
    int frequency;
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int frequency, char data)  //creating a function to create a new node
{
    struct node* node = (struct node*)malloc(sizeof(struct node)); //memory allocation

    node->frequency = frequency;  //assigning values to the node
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node); //returning the created node
}

void encode(struct node* root, char str[], int top) //function to encode the given data
{
    if (root->left) {
        str[top] = '0'; //assign the left as '0' 
        encode(root->left, str, top + 1);
    }

    if (root->right) {
        str[top] = '1'; //assign the right as '1'
        encode(root->right, str, top + 1);
    }

    if (!root->left && !root->right) { //if both are NULL then assign the code
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%c", str[i]);
        printf("\n");
    }
}

void HuffmanCoding(char data[], int frequency[], int size) //main code 
{
    struct node *left, *right, *top; //creating struct node pointers
    int i, j;

    struct node** nodes = (struct node**)malloc(size * sizeof(struct node*)); //creating array of pointers

    for (i = 0; i < size; ++i)
        nodes[i] = newNode(frequency[i], data[i]);  

    for (i = 0; i < size - 1; ++i) //loop for creating the huffman tree
    {
        left = nodes[i];
        right = nodes[i + 1];

        top = newNode(left->frequency + right->frequency, '$');

        top->left = left;
        top->right = right;

        int j = i + 2;
        while (j < size && nodes[j]->frequency < top->frequency) { //while loop to check priority
            nodes[j - 1] = nodes[j];
            j++;
        }
        nodes[j - 1] = top;
    }

    char str[100]; //creating a char array to store the value
    encode(nodes[0], str, 0);
}

int main() //main function
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCoding(data, frequency, size); //function call to encode the given data

    return 0; //returning 0 after the execution
}