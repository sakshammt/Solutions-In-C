//middle node
struct Node *slow = head;
struct Node *fast = head;

while(fast != NULL && fast->next != NULL)
{
    slow = slow->next;           // move 1 step
    fast = fast->next->next;     // move 2 steps
}

printf("Middle node: %d", slow->data);

//insert at k
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtPos(struct Node **head, int x, int k)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    // case 1: insert at beginning
    if(k == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    // move to (k-1)th node
    for(int i = 1; i < k-1; i++)
    {
        if(temp == NULL)
        {
            printf("Position out of range\n");
            return;
        }
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insertAtPos(&head, 10, 1);
    insertAtPos(&head, 20, 2);
    insertAtPos(&head, 30, 3);
    insertAtPos(&head, 25, 3);

    display(head);

    return 0;
}

//length is even or odd
struct Node *fast = head;

while(fast != NULL && fast->next != NULL)
{
    fast = fast->next->next;
}

if(fast == NULL)
    printf("Even length");
else
    printf("Odd length");