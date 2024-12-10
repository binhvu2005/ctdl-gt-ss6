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
        printf("Ngan xep day!\n");
    } else {
        stack[++top] = value;
    }
}

void printStack() {
    if (isEmpty()) {
        printf("Ngan xep rong!\n");
    } else {
        printf("ngan xep khong rong")
    }
}

int main() {
    int n;

    printf("So luong phan tu: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("so luong khong qua %d!\n", MAX);
        return 1;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }
    printStack();

    return 0;
}

