
#include <bits/stdc++.h>
using namespace std;

//------initializer-----//
struct Node
{
    int key;
    Node *left, *right;
};
typedef struct Node Node;
//---------------------//


//--------- TRAVERSAL <<IN,PRE,POST>> ---------------------------//
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

void preorder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

//---------------------------------------------------------//

struct Node *newnode(int item) // done
{
    struct Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


Node *insertNode(Node *Node, int key) // done
{
    if (Node == NULL)
        return newnode(key);

    if (key < Node->key)
        Node->left = insertNode(Node->left, key);
    else
        Node->right = insertNode(Node->right, key);

    return Node;
}



struct Node *minValueNode(Node *Node) // done
{
    struct Node *current = Node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}


int main()
{
    Node *root = NULL;

    root = insertNode(root, 5);

    insertNode(root, 3);
    insertNode(root, 10);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 8);
    insertNode(root, 15);
    insertNode(root, 14);
    insertNode(root, 20);
    insertNode(root, 7);
    insertNode(root, 9);


    printf("\nThe Inorder traversal is: \n");
    inorder(root);

    cout<<endl;

    root = deleteNode(root,8);
    printf("\nDeleted 8\n");

    root = deleteNode(root,2);
    printf("\nDeleted 2\n");

    root = deleteNode(root,20);
    printf("\nDeleted 20\n");

    printf("\nThe In-order traversal is: \n");
    inorder(root);

    printf("\nThe post-order traversal is: \n");
    postorder(root);

    printf("\nThe Pre-order traversal is: \n");
    preorder(root);

    cout<<endl;

    return 0;
}

