#include <stdio.h>

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
        printf("Ngan xep rong!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    char str[MAX];
    int i = 0;

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0' && str[i] != '\n') {
        push(str[i]);
        i++;
    }
    printf("Chuoi dao nguoc: ");
    while (!isEmpty()) {
        printf("%c", pop());
    }

    return 0;
}

