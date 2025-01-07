#include<iostream>
#include<stack>
#include<queue>

using namespace std;

typedef struct BiNode{
    char data;
    struct BiNode* lchild;
    struct BiNode* rchild;
}BiNode,*BiTree;

char* GetTree(BiTree &tree,char *str){
    if('#'==*str){
        tree=NULL;
        return str+1;
    }

    tree=new BiNode;
    tree->data=*str;
    char* afterleft=GetTree(tree->lchild,str+1);
    char* afterright=GetTree(tree->rchild,afterleft);
    return afterright;
}

void DestroyBiTree(BiTree& tree){
    if (tree != NULL) {
        DestroyBiTree(tree->lchild); // 递归删除左子树
        DestroyBiTree(tree->rchild); // 递归删除右子树
        delete tree; // 删除当前节点
        tree = NULL;
    }
}

void pretraverse1(BiTree &T){
    if(T==NULL) return;

    cout << T->data;
    pretraverse1(T->lchild);
    pretraverse1(T->rchild);
}

void pretraverse2(BiTree &T){
    stack<BiNode*> s;
    s.push(T);

    while(!s.empty()){
        while(s.top()!=NULL){
            cout << s.top()->data;
            s.push(s.top()->lchild);
        }

        s.pop();

        if(!s.empty()){
            BiNode* top=s.top();
            s.pop();
            s.push(top->rchild);
        }
    }
}

void intraverse1(BiTree &T){
    if(T==NULL) return;

    intraverse1(T->lchild);
    cout << T->data;
    intraverse1(T->rchild);
}

void intraverse2(BiTree &T){
    stack<BiNode*> s;
    s.push(T);

    while(!s.empty()){
        while(s.top()!=NULL){
            s.push(s.top()->lchild);
        }

        s.pop();

        if(!s.empty()){
            BiNode* top=s.top();
            cout << top->data;
            s.pop();
            s.push(top->rchild);
        }
    }
}

void aftraverse1(BiTree &T){
    if(T==NULL) return;

    aftraverse1(T->lchild);
    aftraverse1(T->rchild);
    cout << T->data;
}

void leveltraverse(BiTree &T){
    queue<BiNode*> q;
    q.push(T);

    while(!q.empty()){
        BiNode* cur=q.front();

        cout << cur->data;
        if(cur->lchild!=NULL) q.push(cur->lchild);
        if(cur->rchild!=NULL) q.push(cur->rchild);
        q.pop();
    }
}

int main(){
    BiTree T;
    char str[14]="abc###d#ef###";

    GetTree(T,str);

    // pretraverse1(T);
    // cout << endl;

    pretraverse2(T);
    cout << endl;

    // intraverse1(T);
    // cout << endl;

    intraverse2(T);
    cout << endl;

    // aftraverse1(T);
    // cout << endl;

    // leveltraverse(T);
    // cout << endl;

    return 0;
}