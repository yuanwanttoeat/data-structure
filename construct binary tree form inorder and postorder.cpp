#include <iostream>

using namespace std;
#define N 2000005
int n;
int in[N],post[N],popul[N];
int pIndex;
struct node
{
    int val;
    node *left,*right;
    node(int a){
        val=a; left=NULL; right=NULL;
    }
};

int srch(int strt,int endd,int val)
{
    int i;
    for(i=strt;i<=endd;i++){
        if(in[i]==val) break;
    }
    return i;
}

node* build(int inStrt,int inEnd,int *pIndex)
{
    if(inStrt>inEnd) return NULL;
    node* p=new node(post[*pIndex]);

    (*pIndex)--;

    if(inStrt==inEnd) {
        return p;
    }

    int iIndex=srch(inStrt,inEnd,p->val);

    p->right=build(iIndex+1,inEnd,pIndex);
    p->left=build(inStrt,iIndex-1,pIndex);

    return p;


}



int bad_situation(node *root)
{

    if(root==NULL) return 0;
    int r=0,le=0;
    if(root->right!=NULL ) {

        if(popul[root->right->val-1] > popul[root->val-1]){
            r = 1 + bad_situation(root->right);
        }
        else r =  bad_situation(root->right);
    }
    if(root->left!=NULL){

        if(popul[root->left->val-1 ] > popul[root->val-1]) le = 1 + bad_situation(root->left);
        else le = bad_situation(root->left);
    }
    return r+le;
}
void inOrder(node *root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<' ';
    inOrder(root->right);
}

void postorder(node *root)
{
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<' ';
}
int main()
{

    cin>>n;
    pIndex=n-1;
    for(int i=0;i<n;i++) cin>>popul[i];
    for(int i=0;i<n;i++) cin>>in[i];
    for(int i=0;i<n;i++) cin>>post[i];

    node *root=build(0,n-1,&pIndex);

    /*inOrder(root); cout<<'\n';
    postorder(root); cout<<'\n';*/

    cout<<bad_situation(root);

    return 0;
}
