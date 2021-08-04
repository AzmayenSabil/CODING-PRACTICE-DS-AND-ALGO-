#include <stdio.h>

#define MAXSIZE 6
#define true 1
#define false 0


int top = -1;

int isempty() {

    if(top == -1)  //Complete the missing condition
        return true;
    else
        return false;
}

int isfull() {

    if(top == MAXSIZE-1) //Complete the missing condition
        return true;
    else
        return false;
}

int peek(int *stack) {
    // Complete the body of the function
    if(isempty())
    {
        printf("Stack is empty--top value cannot be returned\n");
        return true;
    }
    return stack[top];

}

int pop(int *stack) {
    int data;

    if(!isempty()) { // Check if the list is not empty
        // Save the data from top
        data = stack[top];
        // Decrement the top and return the saved data
        top--;
        return data;
    }
    else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push( int *stack, int data) {

    if(!isfull()) { //Check if the stack is not full
        // Increment the top and push the data
        top++;
        stack[top] = data;
        return 0;
    }
    else {
        printf("Could not insert %d, Stack is full.\n", data);
    }
}

int main() {
    int stack[MAXSIZE];
    // push items on to the stack
    push(stack, 1);
    push(stack, 1);
    push(stack, 4);
    push(stack, 4);
    push(stack, 5);
    push(stack, 0);
    push(stack, 3);

    int data;
    data = pop(stack);
    printf("%d\n",data);
    data = pop(stack);
    printf("%d\n",data);
    data = pop(stack);
    printf("%d\n",data);
    data = pop(stack);
    printf("%d\n",data);
    data = pop(stack);
    printf("%d\n",data);

    printf("Element at top of the stack: %d\n" ,peek(stack));
    printf("Elements: \n");

    // print stack data
    while(!isempty()) {
        int data = pop(stack);
        printf("%d\n",data);
    }

    printf("Stack full: %s\n" , isfull()?"true":"false");
    printf("Stack empty: %s\n" , isempty()?"true":"false");

    return 0;
}
