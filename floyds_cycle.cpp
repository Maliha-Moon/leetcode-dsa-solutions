#include <bits/stdc++.h>
using namespace std;
// 1.create linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
// 2.find if cycle present or not
bool cycle(Node *head)
{
    // initialize two pointers
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 1 step at a time
        fast = fast->next->next; // 2 steps at a time

        if (slow == fast)
        {
            break;
        }
    }

    if (slow != fast)
    {
        return false;
     } 
    //else{
    //     return true;
    // }
}
// without creating cycle
int main()
{
    // 1->2->3->4->5->6->7->3
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = head->next->next;

    if (cycle(head))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}