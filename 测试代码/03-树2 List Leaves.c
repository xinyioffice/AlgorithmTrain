#include<stdio.h>
#include<stdlib.h>
#define Null -1
#define MAXSIZE 10
#define ERROR -1

typedef int flag;
typedef int Tree;
typedef struct QNode *Queue;

struct QNode {
    Tree Data[MAXSIZE];
    int rear;
    int front;
};

struct TNode {
    int Data;
    Tree left;
    Tree right;
    flag leaf;/*1表示是叶子结点，0不是叶子结点*/
}T1[MAXSIZE];


void AddQ( Queue PtrQ, Tree item )
{
    if((PtrQ->rear+1) % MAXSIZE == PtrQ->front ) {
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1) % MAXSIZE;
    PtrQ->Data[PtrQ->rear] = item;
}

Tree DeleteQ( Queue PtrQ )
{
    if( PtrQ->front == PtrQ->rear ) {
        return ERROR;
    } else {
        PtrQ->front = (PtrQ->front-1) % MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}

Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

Tree BuildTree( TNode T[] )
{
    int N, i;
    Tree Root = Null;
    char cl, cr;
    scanf("%d", &N);
    int check[N];
    if(N) {
        for( i = 0; i < N; i++ ) check[i] = 0;
        for( i = 0; i < N; i++ ) {
            T[i].Data = i;
            T[i].leaf = 0;
            scanf("\n%c %c", &cl, &cr);
            if(cl == '-' && cr == '-') {
                T[i].leaf = 1;
                T[i].left = Null;
                T[i].right = Null;
            } else if (cl == '-' && cr != '-') {
                T[i].left = Null;
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            } else if (cl != '-' && cr == '-') {
                T[i].left = cl - '0';
                T[i].right = Null;
                check[T[i].left] = 1;
            } else {
                T[i].left = cl - '0';
                T[i].right = cr - '0';
                check[T[i].left] = 1;
                check[T[i].right] = 1;
            }
        }
        for( i = 0; i < N; i++ ) {
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}

int IsEmptyQ( Queue Q )
{
    if( Q->rear == Q->front ) return 1;
    return 0;
}

void LevelOrderTraversal ( Tree node )
{
    Queue Q;
    Tree T;
    if( node == Null ) return;
    Q = CreateQueue();
    AddQ( Q, node );
    int tag = 0;
    int cnt = MAXSIZE;
    while( cnt != 0 ) {
        T = DeleteQ( Q );
        if(T == ERROR) break;
        if( T1[T].leaf ) {
            if(tag == 0) printf("%d", T);
            else printf(" %d", T);
            tag++;
        }
        if( T1[T].left != Null ) AddQ( Q, T1[T].left );
        if( T1[T].right != Null ) AddQ( Q, T1[T].right );
        cnt--;
    }
}

int main()
{
    Tree R1;
    R1 = BuildTree(T1);
    LevelOrderTraversal(R1);
    return 0;
}