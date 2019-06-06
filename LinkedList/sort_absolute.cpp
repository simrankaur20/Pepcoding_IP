#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    char data;
    Node * next;
    Node(char val)
    {
        data = val;
        next = NULL;
    }
};

void printll(Node * head)
{
    Node * t = head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
}

pair<Node*,Node*> insertnode(Node * head,Node * tail , Node * nn)
{
    if(head==NULL)
    {
        head=nn;
        tail=nn;
        return make_pair(head,tail);
    }
    tail->next = nn;
    tail = nn;
    return make_pair(head,tail);

}

Node* sortabsolute(Node * head )
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node * temp = head;
    Node *xh = NULL ,*xt = NULL;
    Node * yh = NULL , * yt = NULL;
    while(temp!=NULL)
    {
        if(temp->data < 0)
        {
            if(xh==NULL)
            {
                xh = temp, xt = temp;
                temp = temp->next;
            }
            else{
                yt->next = temp;
                yt = temp;
                temp = temp->next;
            }
        }
        else{
                if(yh == NULL)
                {
                    yh = temp , yt = temp;
                    temp = temp->next;
                }
                else{
                    Node * t2 = temp->next;
                    temp->next = xh;
                    xh = temp;
                    temp = t2;
                }
        }

    }
    xt->next = yh;
    return xh;

}
int main()
{
    Node* head = NULL,*tail=NULL;
    int n;
    char val;
    cin >> n;
     pair<Node*,Node*> p(NULL,NULL);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        Node * nn = new Node(val);
       p = insertnode(p.first,p.second,nn);
    }
    head = p.first;
    tail = p.second;
    printll(sortabsolute(head));
}
