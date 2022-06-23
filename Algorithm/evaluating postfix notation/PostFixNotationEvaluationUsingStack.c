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

Node* createNode(int ch){
    //Declare a pointer to hold the address of a node
    Node* node = (Node*)malloc(sizeof(Node));
    //Allocate the memory and assign the value to the data and addresses

    node->data = ch;
    node->prev = NULL;
    node->next = NULL;

    //return the address of the created node

    return node;
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

//---------------PUSH-------------------------------//

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

void push(Node* newnode, List* list){
    insertAtFront(newnode, list);
}

//------------------------------------------------//


int removeFrom(Node *node, List *list){

    int value;
    value = node->data;

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

    return value;
}

//----------------pop----------------------//

int removeFromFront(List *list){

    int value;
    if (list->firstnode != NULL){
        value = removeFrom(list->firstnode, list);
    }
    else{
        return 0;
    }

    return value;

}

int pop(List *list){
    int value;
    value = removeFromFront(list);
    return value;
}
//----------------------------------------//

//----------EVALUATION PART----------------//

void EvalPostfix(char postfix[])
{
    int i;
    char ch;
    int val;
    int A, B;

    Node *newnode;
    List list;
    list.firstnode = NULL;
    list.lastnode = NULL;

    for (i=0; postfix[i]!=')';i++) {

        ch = postfix[i];

        if((ch - '0') >= 0 && (ch - '0') <= 9){
            newnode = createNode(ch-'0');
            push(newnode, &list);
        }

        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            A = pop(&list);
            B = pop(&list);

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }

            newnode = createNode(val);
            push(newnode, &list);
        }
    }
    printf("\nResult of expression evaluation : %d \n", pop(&list));
}

//-----------------------------------------//



int main(){


    char postfixNotation[100];
    printf("GIVE THE POSTFIX EXPRESSION  ->expression should end with ending bracket<-  : ");
    scanf("%s",postfixNotation);


    EvalPostfix(postfixNotation);

    printf("done\n");


    return 0;
}


