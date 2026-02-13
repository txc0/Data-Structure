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
    };
};

void create_node (Node *&head, int val)
{
    Node *newNode = new Node(val);
    if(head== NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next != NULL )
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int count (Node *head)
{
    int c = 0;
    Node *tmp = head;
    while(tmp != NULL)
    {
        if(tmp->next != NULL)
        {
            c++;
            tmp  =tmp ->next;
        }
        else
        {
            break;
        }
    }
    return c;
}

void print_linked_list(Node *head)
{
    cout << endl;
    cout << "Your Linked List: ";
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl
         << endl;
}

int main ()
{
    int n ;
    Node *head = NULL;
    while(true)
    {
        cin>>n;
        if(n==-1)
        {
            break;
        }
        create_node(head, n);

    }
    print_linked_list(head);
    
    cout<<count(head)+1<<endl;
    return 0;
    

}