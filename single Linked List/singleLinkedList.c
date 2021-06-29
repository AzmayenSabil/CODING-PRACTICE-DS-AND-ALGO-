//incomplete

#include<stdio.h>


struct Node{
    int data;
    struct node *next;
};

typedef struct Node Node;

struct List{
    Node* firstnode;
};

typedef struct List List;

Node* createNode(int n){

    Node *newNode, *temp;
    Node *head;
    int data, i;

    head = (Node*)malloc(sizeof(Node));

    /* Input head node data from user */
    printf("Enter data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL

    temp = head;

    for (i=2; i<=n; i++)
    {
        newNode = (Node*)malloc(sizeof(Node));

        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // The newNode should point to nothing

        temp->next = newNode; // Link previous node i.e. temp to the newNode
        temp = temp->next;
    }

    return head;

}

void displayList(List* list){

    Node *temp;

    if (list->firstnode == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = list->firstnode;

    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;  // Move to next node
    }
    printf("\n");
}

void insertAtFront(Node* newnode, List* list){

    newnode->next = list->firstnode;
    list->firstnode = newnode;

}

int search(List *list, int value)
{
    int index;
    Node *currentNode;

    index = 0;
    currentNode = list->firstnode;

    // Iterate till last element until key is not found
    while (currentNode != NULL && currentNode->data != value)
    {
        index++;
        currentNode = currentNode->next;
    }


    return (currentNode != NULL) ? 1 : 0;
}

int main(){
    int n, i;
    List list;
    list.firstnode = NULL;

    printf("Enter the number of elements you want to store: ");
    scanf("%d", & n);

    list.firstnode = createNode(n);
    displayList(&list);

    Node *node;
    int data;
    node = (Node*)malloc(sizeof(Node));

    printf("Enter data of node to insert at front: ");
    scanf("%d", &data);

    node->data = data; // Link data field with data
    node->next = NULL; // Link address field to NULL

    insertAtFront(node, &list);

    displayList(&list);

    int found = search(&list, 12);

    if(found){
        printf("FOUND\n");
    }
    else{
        printf("NOT FOUND\n");
    }

    printf("\nEnd\n");
    return 0;
}
