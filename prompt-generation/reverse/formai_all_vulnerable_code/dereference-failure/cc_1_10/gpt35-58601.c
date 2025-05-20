//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

// A structure to represent the binary tree node 
struct node {
  char data;
  int freq;
  struct node *left, *right;
};

// A structure to represent the queue node 
struct qnode {
  struct node *element;
  struct qnode *next;
};

// Function to create a new Queue Node 
struct qnode* create_qnode(struct node* x)
{
  struct qnode* temp = (struct qnode*) malloc(sizeof(struct qnode));
  temp->element = x;
  temp->next = NULL;
  return temp;
}

// Function to create a priority queue 
struct node* create_priority_queue(char data[], int freq[], int size)
{
  struct node *tmp, *left, *right;
  struct qnode *front, *rear;
  int i;

  // Creating the initial Priority Queue 
  front = rear = NULL;

  for (i = 0; i < size; ++i) {
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data[i];
    tmp->freq = freq[i];
    tmp->left = tmp->right = NULL;
    front = create_qnode(tmp);
    rear = front;
  }

  while (front != NULL) {
    left = front->element;
    front = front->next;

    if (front != NULL) {
      right = front->element;
      front = front->next;

      tmp = (struct node*)malloc(sizeof(struct node));
      tmp->data = '*';
      tmp->freq = left->freq + right->freq;
      tmp->left = left;
      tmp->right = right;

      rear->next = create_qnode(tmp);
      rear = rear->next;
    } else {
      rear->next = create_qnode(left);
      rear = rear->next;
    }
  }
  tmp = rear->element;
  return tmp;
}

// Recursive function to generate the huffman codes 
void generate_huffman_codes(struct node *root, int arr[], int size)
{
  if (root->left == NULL && root->right == NULL)
  {
    printf("%c: ", root->data);
    for (int i = 0; i < size; ++i)
      printf("%d", arr[i]);
    printf("\n");
  } else {
    int l[size+1], r[size+1];
    for (int i = 0; i < size; ++i) {
      l[i] = arr[i];
      r[i] = arr[i];
    }
    l[size] = 0;
    r[size] = 1;

    generate_huffman_codes(root->left, l, size+1);
    generate_huffman_codes(root->right, r, size+1);
  }
}

// Main Function 
int main()
{
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data)/sizeof(data[0]);

  struct node *root = create_priority_queue(data, freq, size);
  int arr[size];
  int top = 0;

  generate_huffman_codes(root, arr, top);
  return 0;
}