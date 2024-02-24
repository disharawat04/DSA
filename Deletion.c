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

void beginning_del() {
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void end_del() {
    struct Node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL) {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
}

void middle_del() {
    int pos;
    printf("\n\nEnter the Position you want to delete :-  ");
    scanf("%d", &pos);
    struct Node *temp = NULL, *del;
    temp = head;
    for (int i = 2; i < pos; i++) {
        temp = temp->next;
    }  
    del = temp->next;
    temp->next = del->next;
}

int main() {
	int nodes;
	printf("Enter the number of Nodes :-  ");
	scanf("%d", &nodes);
	create_list(nodes);
	display();
    printf("\n");
    beginning_del();
	display();
    printf("\n");
    end_del();
    display();
    middle_del();
    display();
}