//MISTRAL-7B DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char name[50];
    int bid;
    struct node *next;
} Node;

typedef struct tree_node {
    int min_bid;
    Node *min_bidder;
    struct tree_node *left;
    struct tree_node *right;
} TreeNode;

Node *create_node(const char *name, int bid) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->bid = bid;
    new_node->next = NULL;
    return new_node;
}

TreeNode *create_tree_node(int min_bid, Node *min_bidder) {
    TreeNode *new_node = (TreeNode *) malloc(sizeof(TreeNode));
    new_node->min_bid = min_bid;
    new_node->min_bidder = min_bidder;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode *insert_bid(TreeNode *root, Node *new_bid) {
    if (root == NULL) {
        root = create_tree_node(new_bid->bid, new_bid);
        return root;
    }

    if (new_bid->bid < root->min_bid) {
        root->left = insert_bid(root->left, new_bid);
    } else {
        root->right = insert_bid(root->right, new_bid);
    }

    return root;
}

void print_winner(TreeNode *root) {
    if (root == NULL) {
        printf("No bids received.\n");
        return;
    }

    printf("The winner is %s with a bid of %d.\n", root->min_bidder->name, root->min_bid);
}

int main() {
    int num_bids;
    printf("Enter the number of bids: ");
    scanf("%d", &num_bids);

    Node *bids[num_bids];
    TreeNode *auction_tree = NULL;

    for (int i = 0; i < num_bids; i++) {
        printf("Enter bidder %d's name and bid: ", i + 1);
        Node *new_bid = create_node(NULL, 0);
        scanf("%s %d", new_bid->name, &new_bid->bid);

        bids[i] = new_bid;

        auction_tree = insert_bid(auction_tree, new_bid);
    }

    print_winner(auction_tree);

    for (int i = 0; i < num_bids; i++) {
        free(bids[i]);
    }

    free(auction_tree);

    return 0;
}