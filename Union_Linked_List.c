# include <stdio.h>
# include <stdlib.h>
union Node {
    int data;
    union Node *next;
};

void printlist(union Node *n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    union Node *head = NULL;
    union Node *first = NULL;
    union Node *second = NULL;


    head = (union Node *) malloc (sizeof(union Node));
    first = (union Node *) malloc (sizeof(union Node));
    second = (union Node *) malloc (sizeof(union Node));

    head->data = 1;
    head->next = first;
    first->data = 2;
    first->next = second;
    second->data = 3;
    second->next = NULL;

    printlist(head);
}