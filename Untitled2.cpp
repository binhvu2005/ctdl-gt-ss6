#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Ngan xep da day!\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Ngan xep rong!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void printStack() {
    if (isEmpty()) {
        printf("Ngan xep rong!\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int n;

    printf("So luong phan tu: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("So luong phan tu khong duoc qua %d!\n", MAX);
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    int popped = pop();
    printf("Phan tu bi xoa: %d\n", popped);

    printf("Cac phan tu trong ngan xep con lai:\n");
    printStack();

    return 0;
}

