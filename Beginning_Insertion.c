// Write a program in c to insert a new node at the beginning of Linked List.
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    int data;
    struct Node *newnode = NULL, *temp;
    head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data you want to insert ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data you want to insert ");
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    } 
}

void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insert_at_beginning() {
    int data;
    struct Node *newnode = NULL;
    newnode = (struct Node *) malloc (sizeof(struct Node));
    printf("\nEnter the data you want to insert ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    insert_at_beginning();
    display();
}