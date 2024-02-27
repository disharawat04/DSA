# include <stdio.h>
# include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *front = NULL, *rear = NULL;

void insert() {
    struct Queue *newnode = (struct Queue *) malloc (sizeof(struct Queue));
    printf("\nEnter the data you want to insert :-  ");
    scanf("%d", &newnode->data);
    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
    rear->next = front;
}

void display() {
    printf("\n");
    if (front == NULL && rear == NULL) {
        printf("No Elements to display\n");
        return;
    }
    struct Queue *temp = front;
    do {
        printf("%d  ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int isEmpty() {
    if (front == NULL && rear == NULL) {
        return 1;
    }
    return 0;
}

int delete() {
    int value = front->data;
    struct Queue *temp = front;
    if (front == rear) {
        front = NULL;
        rear = NULL;
    }
    else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    return value;
}

int main() {
    int choice;
    while (1) {
        printf("\nPress 1 ---- Insert an element");
        printf("\nPress 2 ---- Delete an element");
        printf("\nPress 3 ---- Display the queue");
        printf("\nPress 4 ---- Display the Front element");
        printf("\nPress 5 ---- Display the Rear element");
        printf("\nPress 6 ---- Exit");

        printf("\n\nEnter the choice :-  ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insert();
                break;
            
            case 2:
                if (isEmpty()) {
                    printf("\nUnderflow Condition\n");
                }
                else {
                    printf("\nThe deleted element is %d\n", delete());
                }
                break;

            case 3:
                display();
                break;
            
            case 4:
                if (front == NULL) {
                    printf("\nThere is no Value assigned to front\n");
                }
                else {
                    printf("\nThe element at the front is %d\n", front->data);
                }
                break;
            
            case 5:
                if (rear == NULL) {
                    printf("\nThere is no Value assigned to rear\n");
                }
                else {
                    printf("\nThe element at the rear is %d\n", rear->data);
                }
                break;

            case 6:
                exit(0);
        }
    }
}