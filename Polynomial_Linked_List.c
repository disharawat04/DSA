# include <stdio.h>
# include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node *next;
};

struct Node *create_list(int nodes) {
    printf("\n");
    struct Node *newnode = NULL, *temp;

    struct Node *head = (struct Node *) malloc (sizeof(struct Node));
    printf("Enter the Power in Node 1 :-  ");
    scanf("%d", &head->power);
    printf("Enter the Coefficient in Node 1 :-  ");
    scanf("%d", &head->coeff);
    head->next = NULL;

    temp = head;
    for (int i = 2; i <= nodes; i++) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        printf("Enter the Power in Node %d :-  ", i);
        scanf("%d", &newnode->power);
        printf("Enter the Coefficient in Node %d :-  ", i);
        scanf("%d", &newnode->coeff);
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    return head;
} 

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("(%d x^ %d) ", temp->coeff, temp->power);
        if (temp->next != NULL) {
            printf(" +  ");
        }
        temp = temp->next;
    }
    printf("\n");
}

struct Node *add_polynomial(struct Node *old, struct Node *new) {
    struct Node *head = NULL, *newnode, *temp;
    struct Node *before = old, *after = new;

    while (before != NULL && after != NULL) {
        newnode = (struct Node *) malloc (sizeof(struct Node));
        if (before->power > after->power) {
            newnode->power = before->power;
            newnode->coeff = before->coeff;
            newnode->next = NULL;
            if (head == NULL) {
                head = newnode;
            }
            else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            before = before->next;
        }
        else if (after->power > before->power) {
            newnode->power = after->power;
            newnode->coeff = after->coeff;
            newnode->next = NULL;
            if (head == NULL) {
                head = newnode;
            }
            else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            after = after->next;
        }
        else if (after->power == before->power) {
            newnode->power = before->power;
            newnode->coeff = before->coeff + after->coeff;
            newnode->next = NULL;
            if (head == NULL) {
                head = newnode;
            }
            else {
                temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            before = before->next;
            after = after->next;
        }
    }
    if (before != NULL) {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = before;
    }

    if (after != NULL) {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = after;
    }

    return head;
}


int main() {
    int nodes;
    printf("Enter the Number of Nodes in List 1:-  ");
    scanf("%d", &nodes);
    struct Node *head = create_list(nodes);
    printf("\nEnter the Number of Nodes in List 2:-  ");
    scanf("%d", &nodes);
    struct Node *new_head = create_list(nodes);
    struct Node *add_head = add_polynomial(head, new_head);
    printf("\nThe First Linked List is  :-  ");
    display(head);
    printf("\nThe Second Linked List is  :-  ");
    display(new_head);
    printf("\nThe Resultant Linked List is  :-  ");
    display(add_head);
}

