# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *create_Node(struct Node *root) {
    int data;
    printf("Enter the data :-  ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    root = (struct Node *) malloc (sizeof(struct Node));
    root->data = data;
    printf("\nEnter the data in the Left Node of %d:-  \n", root->data);
    root->left = create_Node(root->left);
    printf("\nEnter the data in the Right Node of %d:-  \n", root->data);
    root->right = create_Node(root->right);

    return root;
}

void Preorder_Traversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right);
}

int main() {
    struct Node *root = create_Node(NULL);
    printf("\n%d\n", root->data);
    Preorder_Traversal(root);
}