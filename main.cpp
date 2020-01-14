#include <bits/stdc++.h>
#include <stdio.h>
#include "Queue_cpp.h"
using namespace std;

class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    void createTree();
    void Preorder(Node *);
    void Inorder(Node *);
    void Postorder(Node *);
    void levelorder(Node *);
    void Ipreorder(Node *);
    void IInorder(Node *);
    void Ipostorder(Node *);
    int countleaf(Node *);
    int height(Node *,int &);
    int diameter(Node *);
};

void Tree::createTree()
{
     Node *p,*t;
     int x;
     Queue q(100);

     printf("Enter root value ");
     scanf("%d",&x);
     root=new Node;
     root->data=x;
     root->lchild=root->rchild=NULL;
     q.enqueue(root);

     while(!q.isEmpty())
     {
         p=q.dequeue();
         printf("enter left child of %d ",p->data);
         scanf("%d",&x);
         if(x!=-1)
         {
             t=new Node;
             t->data=x;
             t->lchild=t->rchild=NULL;
             p->lchild=t;
             q.enqueue(t);
         }
         printf("enter right child of %d ",p->data);
         scanf("%d",&x);
         if(x!=-1)
         {
            t=new Node;
             t->data=x;
             t->lchild=t->rchild=NULL;
             p->rchild=t;
             q.enqueue(t);
         }
    }
}
void Tree::Preorder(Node *p)
{
     if(p)
     {
         printf("%d ",p->data);
         Preorder(p->lchild);
         Preorder(p->rchild);
     }
}
void Tree::Inorder(Node *p)
{
     if(p)
     {
         Inorder(p->lchild);
         printf("%d ",p->data);
         Inorder(p->rchild);
     }
}
void Tree::Postorder(Node *p)
{
    if(p)
     {
         Postorder(p->lchild);
         Postorder(p->rchild);
         printf("%d ",p->data);
     }
}
void Tree::levelorder(Node *p)
{
    Queue q(100);
    printf("%d ",p->data);
    q.enqueue(p);
    while(!q.isEmpty())
    {
        Node *t=q.dequeue();
        if(t->lchild)
        {
            cout<<t->lchild->data<<" ";
            q.enqueue(t->lchild);
        }
        if(t->rchild)
        {
            cout<<t->rchild->data<<" ";
            q.enqueue(t->rchild);
        }
    }
}

int Tree::height(Node *p,int &ans)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=height(p->lchild,ans);
    y=height(p->rchild,ans);
    ans=max(ans,x+y+1);
    if(x>y)
        return x+1;
    else
        return y+1;
}
void Tree::Ipreorder(Node *t)
{
    mstack s(100);
    while(t!=NULL || !s.isEmpty())
    {
        if(t)
        {
            cout<<t->data<<" ";
            s.push(t);
            t=t->lchild;
        }
        else
        {
            t=s.pop();
            t=t->rchild;
        }
    }
}
void Tree::IInorder(Node *t)
{
    mstack s(100);
    while(t!=NULL || !s.isEmpty())
    {
        if(t)
        {

            s.push(t);
            t=t->lchild;
        }
        else
        {
            t=s.pop();
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
}
void Tree::Ipostorder(Node *t)
{
    mstack stk1(100);
    mstack stk2(100);//using two stacks
    stk1.push(t);
    while(!stk1.isEmpty())
    {
        Node * temp=stk1.pop();
        stk2.push(temp);
        if(temp->lchild)
            stk1.push(temp->lchild);
        if(temp->rchild)
            stk1.push(temp->rchild);
    }
    while(!stk2.isEmpty())
    {
        cout<<stk2.pop()->data<<" ";
    }
}
int Tree::countleaf(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=countleaf(p->lchild);
        y=countleaf(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int Tree::diameter(Node *root)
{
    if(root==NULL)
        return 0;
    int ans=INT_MIN;
    int h=height(root,ans);
    return ans;
}
int main()
{
    Tree t;
    t.createTree();
    //cout<<"diameter of the tree is : "<<t.diameter(t.root);
    t.levelorder(t.root);
    cout<<endl;
    //t.Preorder(t.root);cout<<endl;
   // t.Postorder(t.root);
   // t.Inorder(t.root);
    return 0;
}
