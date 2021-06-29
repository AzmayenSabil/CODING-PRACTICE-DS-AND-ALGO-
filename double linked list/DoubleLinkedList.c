#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;

    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

struct List{
    Node* firstnode;
    Node* lastnode;
};

typedef struct List List;

Node* createNode(){
    //Declare a pointer to hold the address of a node
    Node* node = (Node*)malloc(sizeof(Node));
    //Allocate the memory and assign the value to the data and addresses
    int input;
    printf("please enter the value of a node: ");
    scanf("%d",&input);
    node->data = input;
    node->prev = NULL;
    node->next = NULL;
    //return the address of the created node

    return node;
}

void forward(List* list){
    //Traverse the list in forward direction and print the data
    Node* node;
    node = list->firstnode;
    while(node != NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void backward(List* list){
    //Traverse the list in backward direction and print the data
    Node* node;
    node = list->lastnode;
    while(node != NULL){
        printf("%d ",node->data);
        node = node->prev;
    }
    printf("\n");
}

void insertBefore(Node* newnode, Node* node, List* list){ // newnode, list.lastnode, list
    // Insert the "newnode" before the "node" in the provided "list"
    newnode->next = node;
    newnode->prev = node->prev;

    if(node->prev != NULL){
        (node->prev)->next = newnode;
    }
    else{
        list->firstnode = newnode;
    }
    node->prev = newnode;
}

void insertAfter(Node* newnode, Node* node, List* list){
    //Insert the "newnode" after the "node" in th "list"
    newnode->next = node->next;
    newnode->prev = node;

    if(node->next != NULL){
        (node->next)->prev = newnode;
    }
    else{
        list->lastnode = newnode;
    }
    node->next = newnode;

}

void insertAtFront(Node* newnode, List* list){
    // Insert the "newnode" at the beginning of the list
    if(list->firstnode != NULL){
        insertBefore(newnode,list->firstnode,list);
    }
    else{
        list->firstnode = newnode;
        list->lastnode = newnode;
    }
}

void insertAtEnd(Node* newnode, List* list){
    // Insert the "newnode" at the end of the "list"
    if(list->lastnode != NULL){
        insertAfter(newnode,list->lastnode,list);
    }
    else{
        insertAtFront(newnode,list);
    }
}

void removeFrom(Node *node, List *list){

    if(node->prev != NULL){
        (node->prev)->next = node->next;
    }
    else{
        list->firstnode = node->next;
    }

    if(node->next != NULL){
        (node->next)->prev = node->prev;
    }
    else{
        list->lastnode = node->prev;
    }

    free(node);

}

void removeFromFront(List *list){

    if (list->firstnode != NULL){
        removeFrom(list->firstnode, list);
    }
    else{
        printf("EMPTY LIST\n");
    }

}

void removeFromLast(List *list){

     if (list->lastnode != NULL){
        removeFrom(list->lastnode, list);
    }
    else{
        printf("EMPTY LIST\n");
    }

}

int main(){

    Node* newnode;

    int n, i;

    List list;
    list.firstnode = NULL;
    list.lastnode = NULL;


    newnode = createNode();
    insertAtFront(newnode, &list);

    newnode = createNode();
    insertAtFront(newnode, &list);

    newnode = createNode();
    insertBefore(newnode, list.lastnode, &list);

    newnode = createNode();
    insertAfter(newnode, list.firstnode, &list);

    newnode = createNode();
    insertAfter(newnode, list.firstnode, &list);

    newnode = createNode();
    insertAtEnd(newnode, &list);

    forward(&list);

    backward(&list);

    printf("Deleted a node\n");

    removeFrom(list.lastnode,&list);

    removeFromFront(&list);

    removeFromLast(&list);

    forward(&list);

    printf("done");


    return 0;
}

