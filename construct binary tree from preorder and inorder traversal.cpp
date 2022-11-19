#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char in[30],pre[30];
int preIndex=0;
struct node
{
    char val;
    node *left,*right;
    node(char a){
        val=a; left=NULL; right=NULL;
    }
};
int srch(int inStrt,int inEnd,char tar)
{
    int i=0;
    for(i=inStrt;i<=inEnd;i++){
        if(in[i]==tar)
            break;
    }
    return i;
}
node *build_tree(int inStrt,int inEnd,int &preIndex)
{
    if(inStrt>inEnd) return NULL;
    node *p=new node(pre[preIndex]);

    preIndex++;

    if(inStrt==inEnd) return p;


    int pos = srch(inStrt,inEnd,p->val);

    p->left=build_tree(inStrt,pos-1,preIndex);
    p->right=build_tree(pos+1,inEnd,preIndex);

    return p;


}

void post_order(node *root)
{
    if(root==NULL) return;
    post_order(root->left);

    post_order(root->right); // this position is important
    cout<<char(root->val)<<' ';
}

int main()
{
    int n;cin>>n;
    while(n--){
        int k; cin>>k;
        preIndex=0; // reset variable every time

        for(int i=0;i<k;i++)cin>>pre[i];
        for(int i=0;i<k;i++)cin>>in[i];



        node *root=build_tree(0,k-1,preIndex);
        post_order(root);
        cout<<'\n';
    }
    return 0;
}
