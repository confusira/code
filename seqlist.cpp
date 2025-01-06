#include<iostream>

using namespace std;

typedef struct LinkNode{
    int value;
    struct LinkNode *next;
}LinkNode,*LinkList;

//单个链表操作
void initlist(LinkList &L){
    L=new LinkNode;
    L->value=-1;
    L->next=NULL;
}

void destroylist(LinkList &L){
    LinkNode* cur=L;

    while(cur!=NULL){
        LinkNode* p=cur;
        cur=cur->next;
        delete p;
    }
}

void display(const LinkList &L){
    LinkNode* cur=L->next;

    while(cur!=NULL){
        cout << cur->value << " ";
        cur=cur->next;
    }
    cout << endl;
}

void insert1(LinkList &L,int pos,int elem){
    LinkNode* cur=L;
    int index=1;

    while(cur!=NULL){
        if(index==pos){
            LinkNode* p=new LinkNode;
            p->value=elem;
            p->next=cur->next;
            cur->next=p;
            return;
        }
        cur=cur->next;
        index++;
    }
}

void inputList(int n,LinkList &L,int *num){
    for(int i=1;i<=n;i++){
        insert1(L,i,num[i-1]);
    }
}

void delete1(LinkList &L,int pos){
    LinkNode* cur=L;
    int index=1;

    while(cur!=NULL){
        if(index==pos){
            LinkNode* p=cur->next;
            cur->next=p->next;
            delete p;
            return;
        }
        cur=cur->next;
        index++;
    }
}

void delete2(LinkList &L,int elem){
    LinkNode* cur=L;

    while(cur!=NULL){
        if(cur->next->value==elem){
            LinkNode* p=cur->next;
            cur->next=p->next;
            delete p;
            return;
        }
        cur=cur->next;
    }
}

/*
int main(){
    LinkList L;
    initlist(L);

    int n;
    cin >> n;

    int num[100];

    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    inputList(n,L,num);

    display(L);

    destroylist(L);
    return 0;
}
*/

int main(){
    
}