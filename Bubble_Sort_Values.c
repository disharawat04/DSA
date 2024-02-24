# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_list(int nodes) {
    head = (struct Node *) malloc (sizeof(struct Node));
    struct Node *newnode = NULL, *temp;
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
    temp->next = NULL;
}


void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void sort_list() {
    struct Node *temp = head;
    while (temp != NULL) {
        struct Node *before = head;
        struct Node *after = head->next;
        while (after != NULL) {
            if (before->data > after->data) {
                int tem = before->data;
                before->data = after->data;
                after->data = tem;
            }
            else {
                before = before->next;
                after = after->next;
            }
        }
        temp = temp->next;
    }
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes ");
    scanf("%d", &nodes);
    create_list(nodes);
    printf("The Original Array is :-  ");
    display();
    sort_list();
    printf("\nThe Sorted Array is :-  ");
    display();

}