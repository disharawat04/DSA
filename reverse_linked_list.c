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

void reverse_list() {
	struct Node *prev = NULL;
	while (head != NULL) {
		struct Node *after = head->next;
		head->next = prev;
		prev = head;
		head = after;
	}
	head = prev;

	struct Node *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	int val = head->data;
	head->data = temp->data;
	temp->data = val;
}

int main() {
	int nodes;
	printf("Enter the number of Nodes :-  ");
	scanf("%d", &nodes);
	create_list(nodes);
	display();
    printf("\n");
	reverse_list();
	display();
}