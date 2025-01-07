#include<iostream>
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

void pretraverse(BiTree &T){
    if(T==NULL) return;

    cout << T->data;
    pretraverse(T->lchild);
    pretraverse(T->rchild);
}

void intraverse(BiTree &T){
    if(T==NULL) return;

    intraverse(T->lchild);
    cout << T->data;
    intraverse(T->rchild);
}

void aftraverse(BiTree &T){
    if(T==NULL) return;

    aftraverse(T->lchild);
    aftraverse(T->rchild);
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

    pretraverse(T);
    cout << endl;

    intraverse(T);
    cout << endl;

    aftraverse(T);
    cout << endl;

    leveltraverse(T);
    cout << endl;

    return 0;
}