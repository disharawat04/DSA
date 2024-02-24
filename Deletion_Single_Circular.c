// Deletion of Circular Linked List
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

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the data in Node %d :-  ", i);
        scanf("%d", &newnode->data);
        temp->next = newnode;
        temp = temp->next;
    }
    temp->next = head;
}

void display() {
    printf("\n");
    struct Node *temp = head;
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

void del_at_beg() {
    struct Node *temp = head;
    do {
        temp = temp->next;
    } while (temp->next != head);
    head = head->next;
    temp->next = head;
}

void del_at_end() {
    struct Node *prev = head, *after = head->next;
    do {
        after = after->next;
        prev = prev->next;
    } while (after->next != head);
    prev->next = head;
}

void del_value() {
    int val;
    printf("\nEnter the value you want to delete :-  ");
    scanf("%d", &val);
    if (head->data == val) {
        struct Node *temp = head;
        do {
            temp = temp->next;
        } while (temp->next != head);
        head = head->next;
        temp->next = head;
        return;
    }
    struct Node *prev = head, *after = head->next;
    do {
        after = after->next;
        prev = prev->next;
    } while (after->data != val);
    prev->next = after->next;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    display();
    del_at_beg();
    display();
    del_at_end();
    display();
    del_value();
    display();
}