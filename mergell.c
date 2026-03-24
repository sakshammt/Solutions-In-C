#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to merge two sorted lists
struct Node* merge(struct Node *l1, struct Node *l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    struct Node *result = NULL;

    if(l1->data <= l2->data)
    {
        result = l1;
        result->next = merge(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

// Utility to create node
struct Node* create(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Print list
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
    // List1: 1->3->5
    struct Node *l1 = create(1);
    l1->next = create(3);
    l1->next->next = create(5);

    // List2: 2->4->6
    struct Node *l2 = create(2);
    l2->next = create(4);
    l2->next->next = create(6);

    struct Node *merged = merge(l1, l2);

    display(merged);

    return 0;
}


//split and merge sort of single ll

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// 🔹 Create node
struct Node* create(int x)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// 🔹 Print list
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 🔹 Find middle of linked list
struct Node* getMiddle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // middle node
}

// 🔹 Merge two sorted lists
struct Node* merge(struct Node *l1, struct Node *l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    struct Node *result = NULL;

    if(l1->data <= l2->data)
    {
        result = l1;
        result->next = merge(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

// 🔹 Merge Sort function
struct Node* mergeSort(struct Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;

    // find middle
    struct Node *mid = getMiddle(head);
    struct Node *half = mid->next;

    // split list
    mid->next = NULL;

    // recursive sort
    struct Node *left = mergeSort(head);
    struct Node *right = mergeSort(half);

    // merge
    return merge(left, right);
}

// 🔹 Main
int main()
{
    struct Node *head = create(5);
    head->next = create(2);
    head->next->next = create(9);
    head->next->next->next = create(1);
    head->next->next->next->next = create(3);

    printf("Original:\n");
    display(head);

    head = mergeSort(head);

    printf("Sorted:\n");
    display(head);

    return 0;
}


//dryrun
/*
🔥 Example List
5 → 2 → 9 → 1

We call:

mergeSort(head)
🌳 STEP 1: First split

Find middle using slow-fast:

slow → 2

Split:

Left:  5 → 2
Right: 9 → 1
🌳 STEP 2: Sort left (5 → 2)

Call:

mergeSort(5 → 2)

Find middle:

slow → 5

Split:

Left: 5
Right: 2

Now both are single nodes → already sorted ✅

🔗 STEP 3: Merge (5 and 2)

Call:

merge(5, 2)

Compare:

5 > 2 → pick 2

Now:

result → 2

Next:

merge(5, NULL)

So final:

2 → 5
🌳 STEP 4: Sort right (9 → 1)

Call:

mergeSort(9 → 1)

Split:

Left: 9
Right: 1

Merge:

merge(9,1)

Compare:

9 > 1 → pick 1

Final:

1 → 9
🔥 STEP 5: Final Merge

Now we have:

Left:  2 → 5
Right: 1 → 9

Call:

merge(2→5, 1→9)
🔍 Compare step-by-step
Step 1:
2 vs 1 → pick 1
result → 1
Step 2:
2 vs 9 → pick 2
1 → 2
Step 3:
5 vs 9 → pick 5
1 → 2 → 5
Step 4:
NULL vs 9 → attach 9

Final:

1 → 2 → 5 → 9
🎯 FINAL OUTPUT
1 → 2 → 5 → 9*/