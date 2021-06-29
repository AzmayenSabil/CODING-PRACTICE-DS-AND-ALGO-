#include<stdio.h>

#define MAXSIZE 6
#define true 1
#define false 0

int itemcount = 0; // to count the number of elements in the queue
int front = 0;
int rear = -1;

int isFull(){
    if(itemcount == MAXSIZE)
        return true;

    return false;
}

int isEmpty(){
    if(itemcount == 0)
        return true;
    return false;
}

int peek(int *que){
    if(itemcount)
        return que[front];
}

void enque(int *que, int data){ // Do not forget to update the value of itemcount

    if(!isFull()){ //Check if queue is not full
    	//Check for the critical case
    	//increment the value of rear and insert the value
        itemcount++;

    	rear = (rear+1)%MAXSIZE;
    	que[rear] = data;
    }

    else
        printf("Can't push value, queue is full\n");


}

int deque(int *que){ //Do not forget to update the value of itemcount



    if(!isEmpty()){ //Check if the queue is not empty
    	// Save the data from the front index
        itemcount--;

    	int data = que[front];

    	// increment the front and check for critical case

    	front = (front+1)%MAXSIZE;

    	// return the saved value

    	return data;

    }
    else
        printf("\nCan't pop value, queue is empty\n");
        return -1;
}

void display(int *que){
    // Display all the content of the que
    // Front value is diplayed first, then rest of the values are displayed upto rear.
    // Consider the critical cases as well.

    for(int i = 0; i < itemcount; i++){
        int updatedFront = (front+i)%MAXSIZE;
        printf("%d ",que[updatedFront]);
    }

    printf("\n");

}

int main(){
    int x;
    int que[MAXSIZE];
    enque(que, 5);
    enque(que, 6);
    enque(que, 7);
    enque(que, 8);
    enque(que, 9);
    enque(que, 10);

    enque(que, 11);
    display(que);

    int deq = deque(que);
    printf("The item that I removed from the front: %d\n",deq);
    enque(que, 12);

    display(que);


    return 0;
}

