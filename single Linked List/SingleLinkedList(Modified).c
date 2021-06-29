#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node{
    int data;
    struct node *next;
};

typedef struct Node Node;

Node *head;

void createList(int n);
void displayList();
int  search(int value);


int main()
{
    int n, valueToSearch, index;

    // Input node count to create
    printf("Enter number of node to create: ");
    scanf("%d", &n);

    createList(n);

    // Display list
    printf("\nData in list: \n");
    displayList();

    // Input element to search from user.
    printf("\nEnter element to search: ");
    scanf("%d", &valueToSearch);

    index = search(valueToSearch);

    // Element found in the list
    if (index == 1)
        printf("%d found\n", valueToSearch);
    else
        printf("%d not found in the list.\n", valueToSearch);


    return 0;
}

void createList(int n)
{
    Node *newNode, *temp;
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

}

void displayList()
{
    Node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;  // Move to next node
    }
    printf("\n");
}

int search(int value)
{
    int index;
    Node *currentNode;

    index = 0;
    currentNode = head;

    // Iterate till last element until key is not found
    while (currentNode != NULL && currentNode->data != value)
    {
        index++;
        currentNode = currentNode->next;
    }


    return (currentNode != NULL) ? 1 : 0;
}
