# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define max_size 100

struct Node {
    char array[max_size];
    struct Node *next;
};

struct Node *top = NULL;

void push(char* symbol) {
    struct Node *newnode = (struct Node *) malloc (sizeof(struct Node));
    strcpy(newnode->array, symbol);
    newnode->next = top;
    top = newnode;
}

char* pop() {
    char* value = top->array;
    top = top->next;
    return value;
}

void display() {
    struct Node *temp = top;
    while (temp != NULL) {
        printf("%s ", temp->array);
        temp = temp->next;
    }
}

int main() {
    char expression[] = "ab*c+";
    int lenght = strlen(expression);

    for (int i = 0; i < lenght; i++) {
        if (isalnum(expression[i])) {
            char operand[2];
            operand[0] = expression[i];
            operand[1] = '\0';
            push(operand);
        }
        else {
            char* value1 = pop();
            char* value2 = pop();
            char string[max_size];
            sprintf(string, "(%s%s%s)", value2, expression[i], value1);
            // strcat(string, "(" + value2 + expression[i] + value1 + ")");
            printf("%s", string);
            push(string);
        }
        display();
    }
}