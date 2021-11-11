#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertAtbeginning( Node *&head , int data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
}
void Print_list(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<"->";
        n=n->next;
    }
}
int main()
{
    Node *head = NULL;
    insertAtbeginning(head,3);
    insertAtbeginning(head,4);
    insertAtbeginning(head,5);
    Print_list(head);
    return 0;
}
