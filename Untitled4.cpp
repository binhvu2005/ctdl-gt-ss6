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

int peek() {
    if (isEmpty()) {
        printf("Ngan xep rong!\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
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

    int topElement = peek();
    if (topElement != -1) {
        printf("Phan tu tren cung: %d\n", topElement);
    }

    return 0;
}

