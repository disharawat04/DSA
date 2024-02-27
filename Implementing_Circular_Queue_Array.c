# include <stdio.h>
# include <stdlib.h>
# define max 4

int front = -1, rear = -1, Queue[max];

int isFull() {
    if ((rear + 1) % max == front) {
        return 1;
    }
    return 0;
}

void insert() {
    int val;
    printf("\nEnter the value you want to Insert :-  ");
    scanf("%d", &val);
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % max;
    }
    Queue[rear] = val;
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    }
    return 0;
}

int delete() {
    int value = Queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % max;
    }
    return value;
}

void display() {
    printf("\n");
    int i = front;
    while (i != rear) {
        printf("%d  ", Queue[i]);
        i = (i + 1) % max;
    }
    printf("%d ", Queue[i]);
    printf("\n");
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
                if (isFull()) {
                    printf("\nOverflow Condition\n");
                }
                else {
                    insert();
                }
                break;
            
            case 2:
                if (isEmpty()) {
                    printf("\nUnderflow Condition\n");
                }
                else {
                    printf("\nThe Deleted Value is %d\n", delete());
                }
                break;
            
            case 3:
                if (front == -1 && rear == -1) {
                    printf("\nThere are No elements in the Queue\n");
                }
                else {
                    display();
                }
                break;
            
            case 4:
                if (front == -1) {
                    printf("\nThe Value of front is %d and it does not contain any value\n", front);
                }
                else {
                    printf("\nThe Value of front is %d and it contains %d\n", front, Queue[front]);
                }
                break;
            
            case 5:
                if (rear == -1) {
                    printf("\nThe Value of rear is %d and it does not contain any value\n", rear);
                }
                else {
                    printf("\nThe Value of rear is %d and it contains %d\n", rear, Queue[rear]);
                }
                break;
            
            case 6:
                exit(0);
        }
    }
}