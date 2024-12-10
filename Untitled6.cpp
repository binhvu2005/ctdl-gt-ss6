#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(char value) {
    if (isFull()) {
        printf("Ngan xep da day!\n");
    } else {
        stack[++top] = value;
    }
}

char pop() {
    if (isEmpty()) {
        return -1;
    } else {
        return stack[top--];
    }
}

int isValid(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

      
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = pop();
            if ((ch == ')' && topChar != '(') || 
                (ch == '}' && topChar != '{') || 
                (ch == ']' && topChar != '[')) {
                return 0; 
            }
        }
    }


    return isEmpty();
}

int main() {
    char expression[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expression, sizeof(expression), stdin); 

    if (isValid(expression)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}

