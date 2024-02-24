// WAP to find the display the middle element in the list.
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    struct Node *newnode = NULL, *temp;
    head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the data in Node 1 :-  ");
    scanf("%d", &head->data);
    head->next = NULL;
    
    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
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
    printf("\n");
}

void middle_element() {
    if (head == NULL) {
        printf("There are No elements present in the linked list ");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = head;
    
    while (temp != NULL && temp->next != NULL) {
        prev = prev->next;
        temp = temp->next->next;
    }
    printf("The Element in the middle of the list is %d\n", prev->data);
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    middle_element();
}