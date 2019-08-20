#include<stdio.h>
#include<stdlib.h>
#define Null -1
#define MAXSIZE 10

typedef int Tree;
struct TNode {
    char Data;
    Tree Left;
    Tree Right;
}T1[MAXSIZE],T2[MAXSIZE];

int check[MAXSIZE];
int N, i;
char cl, cr;

Tree BuildTree( TNode T[] )
{
    Tree Root = Null;
    scanf("%d", &N);
    if(N) {
        for( i = 0; i < N; i++ ) check[i] = 0;
        for( i = 0; i < N; i++ ) {
            scanf("\n%c %c %c", &T[i].Data, &cl, &cr);
            if( cl != '-' ) {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else T[i].Left = Null;
            if( cr != '-' ) {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else T[i].Right = Null;
        }
        for( i = 0; i < N; i++ ) {
            if(!check[i]) break;
        }
        Root = i;
    }
    return Root;
}

int Isomorphic ( Tree R1, Tree R2 )
{
    if(R1==Null && R2==Null) return 1;
    else if(R1!=Null && R2!=Null && T1[R1].Data == T2[R2].Data)
        return( Isomorphic(T1[R1].Left, T2[R2].Left) &&
                Isomorphic(T1[R1].Right, T2[R2].Right) ||
                Isomorphic(T1[R1].Left, T2[R2].Right) &&
                Isomorphic(T1[R1].Right, T2[R2].Left));
    else return 0;
}

int main()
{
    Tree R1, R2;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}