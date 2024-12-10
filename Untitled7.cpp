#include <stdio.h>
#include <ctype.h>
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

int isPalindrome(char* sentence) {
    int length = strlen(sentence);

    for (int i = 0; i < length; i++) {
        char ch = sentence[i];
        if (isalnum(ch)) { 
            push(tolower(ch)); 
        }
    }


    for (int i = 0; i < length; i++) {
        char ch = sentence[i];
        if (isalnum(ch)) {  
            if (tolower(ch) != pop()) {
                return 0; 
            }
        }
    }

    return 1;  
}

int main() {
    char sentence[MAX];

    printf("Nhap cau: ");
    fgets(sentence, sizeof(sentence), stdin);  

    if (isPalindrome(sentence)) {
        printf("Cau nay la doi xung\n");
    } else {
        printf("Cau nay khong phai la doi xung\n");
    }

    return 0;
}

