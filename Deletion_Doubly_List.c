// User defined doubly Linked List
# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
        newnode->prev = temp;
        newnode->next = NULL;
        temp = temp->next;
    }
}

void display() {
    struct Node *temp = head, *m;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        m = temp;
        temp = temp->next;
    }
    printf("\n");
    // while (m != NULL) {
    //     printf("%d  ", m->data);
    //     m = m->prev;
    // }
}

void del_at_beg() {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    head->prev = NULL;
}

void del_at_end() {
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp = temp->prev;
    temp->next = NULL;
}

void del_at_mid() {
    int val;

    printf("Enter the value you want to delete :-  ");
    scanf("%d", &val);

    if (head->data == val) {
        head = head->next;
        return;
    }
    struct Node *temp = head;
    while (temp->data != val) {
        temp = temp->next;
    }
    struct Node *before = temp->prev;
    before->next = temp->next;
    temp = temp->next;
    temp->prev = before;
//                                                                  OR  OR  OR  OR
    // temp = temp->prev;
    // temp->next = temp->next->next;
    // temp->next->next->prev = temp;
}

int main() {
    int nodes;
    printf("Enter the Number of Nodes :-  ");
    scanf("%d", &nodes);
    create_list(nodes);
    // printf("%d\n", head->next->next->data);              [This can also be used]
    display();
    del_at_beg();
    display();
    del_at_end();
    display();
    del_at_mid();
    display();
}