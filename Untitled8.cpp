#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};


void initStack(struct Stack* stack) {
    stack->top = NULL;
}


int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Da them %d vao ngan xep\n", value);
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("Da lay ra phan tu: %d\n", poppedValue);
}

void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong!\n");
        return;
    }
    printf("Phan tu tren cung: %d\n", stack->top->data);
}


int main() {
    struct Stack stack;
    initStack(&stack); 

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if empty\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                peek(&stack);
                break;
            case 4:
                if (isEmpty(&stack)) {
                    printf("Ngan xep rong\n");
                } else {
                    printf("Ngan xep khong rong\n");
                }
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

