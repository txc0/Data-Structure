#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* next;
    Node (int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Function to get the length of linked list
int get_length(Node *head)
{
    int count = 0;
    Node *tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// Method 1: Using length to find middle
void print_middle_by_length(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    int length = get_length(head);

    if (length % 2 == 1)
    {
        // Odd length: print single middle
        int middle_pos = length / 2 + 1;
        Node *tmp = head;
        for (int i = 1; i < middle_pos; i++)
        {
            tmp = tmp->next;
        }
        cout << "Middle value (odd length): " << tmp->val << endl;
    }
    else
    {
        // Even length: print two middle values
        int middle_pos1 = length / 2;
        int middle_pos2 = length / 2 + 1;

        Node *tmp1 = head;
        Node *tmp2 = head;

        for (int i = 1; i < middle_pos1; i++)
        {
            tmp1 = tmp1->next;
        }
        for (int i = 1; i < middle_pos2; i++)
        {
            tmp2 = tmp2->next;
        }

        cout << "Middle values (even length): " << tmp1->val << " and " << tmp2->val << endl;
    }
}

// Method 2: Using slow and fast pointers (more efficient)
void print_middle_two_pointers(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev_slow = NULL;

    // Move fast by 2 steps, slow by 1 step
    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If odd number of nodes, slow is at middle
    if (fast == NULL)
    {
        cout << "Middle value (odd length): " << slow->val << endl;
    }
    else
    {
        // Even number of nodes, slow and prev_slow are the two middles
        cout << "Middle values (even length): " << prev_slow->val << " and " << slow->val << endl;
    }
}

void print_linked_list(Node *head)
{
    cout << "Linked List: ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    // Test with odd number of nodes: 10 -> 20 -> 30 -> 40 -> 50
    cout << "=== Testing with odd number of nodes ===" << endl;
    Node *head1 = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    head1->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    print_linked_list(head1);
    print_middle_by_length(head1);
    print_middle_two_pointers(head1);

    cout << endl;

    // Test with even number of nodes: 10 -> 20 -> 30 -> 40
    cout << "=== Testing with even number of nodes ===" << endl;
    Node *head2 = new Node(10);
    Node *e = new Node(20);
    Node *f = new Node(30);
    Node *g = new Node(40);

    head2->next = e;
    e->next = f;
    f->next = g;

    print_linked_list(head2);
    print_middle_by_length(head2);
    print_middle_two_pointers(head2);

    return 0;
}