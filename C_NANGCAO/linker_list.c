#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
/////////////////=========KHAI BAO CAU TRUC DANH SACH LIEN KET DON ==============////
typedef struct node    /// khai bao ra mot node
{
    uint8_t data; //du lieu data chua trong tung node
    struct node *next;   /// con tro next dung de lien ket giua cac data voi nhau 
}node;

typedef struct list
{
    node *pHead;        // node quan ly dau danh sach
    node *pTail;       /// node quan ly cuoi danh sach
}list;
 


/////////////////=========KHOI TO CAU TRUC DANH SACH LIEN KET DON ==============////
void khoitao(list *l)
{
    l->pHead = NULL;    ///cho hai node tro den null vi danh sach lien ket don chua co phan tu
    l->pTail = NULL;
}

node *KhoitaoNODE( uint8_t x)// ham khoi tao mot node dau tien
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = x; //truyen gia tri x cho data
    newNode->next = NULL;
    
}

void AddHead(list *l, node *p) ///them vao dau danh sach
{
    if(l->pHead == NULL)    //neu danh sach rong
    {
        l->pHead = l->pTail = p;    // node dau va node cuoi chinh bang p
    }
    else{
        p->next = l->pHead; //cho con tro node can them lien ket den node dau phead
        l->pHead = p;  // cap nhat lai pHead chinh la node p
    }
}

void AddTail(list *l, node *p)  //tham vao cuoi danh sach
{
     if(l->pHead == NULL)    //neu danh sach rong
    {
        l->pHead = l->pTail = p;    // node dau va node cuoi chinh bang p
    }
    else{
        l->pTail->next = p;   //cho con tro pTail lien ket voi node p
        l->pTail = p; //cap nhat node p la node cuoi la pTail
    }
}

void Export_list(list f){
    for(node *k = f.pHead; k != NULL; k = k->next)      ///cho vong lap chay tu dau den cuoi danh sach
    {
        printf("data: %d\n", k->data);
    }
}

int main(int argc, char const *argv[])
{
    list l;
    khoitao(&l); //khoi tao danh sach lien ket don
    int n;
    printf("nhap so luong node can them: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        printf("\nnhap gia tri can them: ");
        scanf("%d", &x);
        node *p = KhoitaoNODE(x);
        AddHead(&l, p);         ///them vao dau danh sach
    }
    printf("DANH SACH LIEN KET DON:\n");
    Export_list(l);     // xuat danh sach
    return 0;
}