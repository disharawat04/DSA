// Write a program to insert the numbers in the list in the following manner.
//                  4  2  1  3  5

# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// struct Node *head = NULL;

struct Node *create_list(int nodes) {
    struct Node *temp_head = (struct Node *) malloc (sizeof(struct Node));
    temp_head->next = NULL;
    printf("Enter the Data in Node 1 :-  ");
    scanf("%d", &temp_head->data);
    struct Node *newnode = NULL, *temp;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the Data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        if (i % 2 == 0) {
            newnode->next = temp_head;
            temp_head = newnode;
        }
        else {
            temp = temp_head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }
    }
    return temp_head;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d  ", head->data);
        head = head->next; 
    }
}

int main() {
    int nodes;
    printf("Enter the Number of nodes :-  ");
    scanf("%d", &nodes);
    struct Node *head = create_list(nodes);
    display(head);
}