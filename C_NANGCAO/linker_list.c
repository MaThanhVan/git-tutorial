#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
                                    /////////////////=========KHAI BAO CAU TRUC DANH SACH LIEN KET DON ==============////
typedef struct node    /// khai bao ra mot node
{
    uint8_t data;       //du lieu data chua trong tung node
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

node *KhoitaoNODE( uint8_t x)                         ////==== ham khoi tao mot node dau tien=====////
{
    node *newNode = (node *)malloc(sizeof(node));   //cap phat vung nho cho malloc
    newNode->data = x;                              //truyen gia tri x cho data
    newNode->next = NULL;
    
}

void AddHead(list *l, node *p)                      ///========them vao dau danh sach=========///////
{
    if(l->pHead == NULL)             //neu danh sach rong
    {
        l->pHead = l->pTail = p;    // node dau va node cuoi chinh bang p
    }
    else{
        p->next = l->pHead;         //cho con tro node can them lien ket den node dau phead
        l->pHead = p;           // cap nhat lai pHead chinh la node p
    }
}

void AddTail(list *l, node *p)                       //////======them vao cuoi danh sach=====//////
{
     if(l->pHead == NULL)            //neu danh sach rong
    {
        l->pHead = l->pTail = p;    // node dau va node cuoi chinh bang p
    }
    else{
        l->pTail->next = p;   //cho con tro pTail lien ket voi node p
        l->pTail = p;        //cap nhat node p la node cuoi la pTail
    }
}


void assign(list *li, uint8_t location, uint8_t data){////Ham thay the mot node, bang cach thay the gia tri cu bang node moi
   
    int i = 0;                               // tao bien i de tim xac dinh vi tri
    node *Newnode  = KhoitaoNODE(data);     //Tao node moi co gia tri ta dua vao
    node *tmp = li->pHead;                  // tmp = pHead de tao vong lap duyet tu dau mang den cuoi mang
    while (tmp->next != NULL || i != location )      
    {
        i++;
        node *temp = tmp->next;                 // temp chinh la node co vi tri sau node minh muon thay the
        Newnode->next = tmp->next->next;  // gan con tro next cua node moi den node tiep theo = cach cho hai lan cua bien temp 
        tmp->next = Newnode;        // node sau se tro den vi tri node moi
        free(temp);                 /// xoa node cu
        return;
       
    }
    
}

void clearHead(list *li){       // XOA DAU DANH SACH
    if(li->pHead == NULL)   // neu danh sach rong
    {
        return;
    }
    node *p = li->pHead;    // p la node se xoa
    li->pHead = li->pHead->next;    //cap nhat lai node dau la phan tu ke tiep
    free(p);        // xoa phan tu dau 
}

void pop_back(list *li){        // XOA CUOI DANH SACH
    if(li->pHead == NULL)   // neu danh sach rong
    {
        return;
    }

    if(li->pHead->next == NULL)///neu danh sach co mot phan tu thi ta se goi ham xoa dau
    {
        clearHead(li);
        return;
    }

    for(node *n = li->pHead; n != NULL; n = n->next) // duyet dau den cuoi danh sach
    {
        if(n->next == li->pTail)        // phat hien node sau node cuoi
        {
            free(li->pTail);        // Xoa node cuoi
            n->next = NULL;         //cho node sau node cuoi bang null
        }
    }
}


void erase(list *l, int index){            /// XOA MOT NODE CO VI TRI BAT KY
    if(l->pHead->data == index){
        clearHead(l);
        return;
    }
    if(l->pTail->data == index){
        pop_back(l);
        return;
    }

    node *g = g->next;
    for(node *n = l->pHead; n != NULL; n = n->next) // duyet dau den cuoi danh sach
    {
        if(n->data == index){//phat hien vi tri phan tu can xoa
            
            g->next = n->next;
            free(n);
            return;
        }
        g = n;
    }
    
}   

void getData(list f, uint8_t index){         // doc gia tri tai vi tri index 
    int i = 0;
   for(node *k = f.pHead; k != NULL; k = k->next)       ///cho vong lap chay tu dau den cuoi danh sach
    {
        i++;
        if(i == index){
            printf("data: %d\n", k->data);
        }
    }
    return;
}

void clear(node *ptr){              ///Xoa tat ca phan tu co trong vector
    node *temp=ptr;             
    while(ptr->next!=NULL){
        temp=temp->next;
        free(ptr);
        temp=ptr;
    }
    free(ptr);
}



void Export_list(list f){                    /////===== Xuat danh sach=====////
    for(node *k = f.pHead; k != NULL; k = k->next)      ///cho vong lap chay tu dau den cuoi danh sach
    {
        printf("data: %d\n", k->data);
        
    }
    return;
}


int main(int argc, char const *argv[])
{
    list arr;
    khoitao(&arr); //khoi tao danh sach lien ket don
    int n;
    printf("nhap so luong node can them: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int x;
        printf("\nnhap gia tri can them: ");
        scanf("%d", &x);
        node *p = KhoitaoNODE(x);
        AddTail(&arr, p);         ///them vao dau danh sach
    }
    printf("DANH SACH LIEN KET DON:\n");
    Export_list(arr);     // xuat danh sach

    assign(&arr, 2, 36);
    printf("DANH SACH LIEN KET DON SAU KHI DA THAY DOI:\n");
    Export_list(arr);     // xuat danh sach
    
    pop_back(&arr);
    printf("DANH SACH LIEN KET DON SAU KHI DA xoa cuoi:\n");
    Export_list(arr);     // xuat danh sach

    erase(&arr, 3);
    printf("DANH SACH LIEN KET DON SAU KHI DA xoa la:\n");
    Export_list(arr);     // xuat danh sach

    getData(arr, 2);
    return 0;

}