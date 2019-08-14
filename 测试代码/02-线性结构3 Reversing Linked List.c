#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int address;
    int data;
    int nextAddress;
    struct Node *next;
}Node;
typedef struct Node *LinkList;

int main()
{
    //排序前 
    LinkList L1, p1, q1;            
    L1 = (LinkList)malloc(sizeof(Node));    //创建头指针 
    L1->next = NULL;
    int firstAddress;
    int N, K;//N为总结点数 K为需翻转的数 
    scanf("%d %d %d", &firstAddress, &N, &K);
    p1 = L1;
    for(int i = 0; i < N; i++) {
        q1 =  (LinkList)malloc(sizeof(Node));
        scanf("%d %d %d",&q1->address, &q1->data, &q1->nextAddress);
        p1->next = q1;
        p1 = q1;
    }
    p1->next = NULL;
    
//    //测试没问题 
//    printf("测试1 ：\n");
//    p1 = L1->next;
//    while(p1){
//        printf("%05d %d %d\n", p1->address, p1->data, p1->nextAddress);
//        p1 = p1->next;
//    }
    
    //排序后 
    LinkList L2, p2;
    L2 = (LinkList)malloc(sizeof(Node));    //创建头指针 
    L2->next = NULL;
    int count = 0;
    int findAddress = firstAddress;
    p2 = L2;
    while(findAddress != -1) {            //while(count < N) {有多余结点不在链表上没通过 
    
        q1 = L1;
        while(q1->next) {
            if(q1->next->address == findAddress) {
                p2->next = q1->next;
                q1->next = q1->next->next;
                p2 = p2->next;
                count++;
//                printf("count = %d\n",count);
                findAddress = p2->nextAddress;
//                printf("findAddress = %d\n",findAddress);
            }else {
                q1 = q1->next;
            }
        }
    }
    p2->next = NULL;
    
//    //测试没问题 
//    printf("测试2 ：\n");
//    p2 = L2->next;
//    while(p2){
//        printf("%05d %d %05d\n", p2->address, p2->data, p2->nextAddress);
//        p2 = p2->next;
//    }
    //Reversing
    LinkList L3, p3, q3, tail;
    L3 = (LinkList)malloc(sizeof(Node));    //创建头指针 
    L3->next = NULL;
    //将L2以头插法插入L3
    int n = count;                //防止有多余结点影响 n=N 会影响
    int k = K;
    p3 = L3;
    p2 = L2;
    while(n >= k) {
        n -= k;
        for(int i = 0; i < k; i++) {
            p3->next = p2->next;
            p2->next = p2->next->next;
            if(i == 0)
                tail = p3->next;
            else 
                p3->next->next = q3;
            q3 = p3->next;
        }
        p3 = tail;
    }
    p3->next = L2->next;
    
    p3 = L3->next;
    while(p3->next) {
        printf("%05d %d %05d\n",p3->address, p3->data, p3->next->address);//不到五位数用0补全 
        p3 = p3->next;
    }
    printf("%05d %d -1\n",p3->address, p3->data);
    return 0;
}