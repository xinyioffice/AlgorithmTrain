#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 30
#define Null -1


typedef struct SNode* Stack;
typedef struct TNode* Tree;
struct SNode {
	int Data[MaxSize];
	int Top;
};

struct TNode {
	int Data;
	Tree Left;
	Tree Right;
};

void Push(Stack PtrS, int item)
{
	if (PtrS->Top == MaxSize - 1) return;
	else {
		PtrS->Data[++(PtrS->Top)] = item;
		return;
	}
}

int Pop(Stack PtrS)
{
	if (PtrS->Top == -1) return Null;
	else {
		return PtrS->Data[(PtrS->Top)--];
	}
}

Tree NewNode(int V)
{
	Tree T;
	T = (Tree)malloc(sizeof(struct TNode));
	T->Data = V;
	T->Left = T->Right = NULL;
	return T;
}

void PostOrderTraversal(TNode T[], int Root, int N)
{
	int cnt = 0;
	Tree BT = T + Root, PrePop = NULL;
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = 0;
	while (BT || S->Top != 0) {
		while (BT) {
			Push(S, BT->Data);
			BT = BT->Left;
		}
		while (S->Top != 0) {
			BT = T + Pop(S);
			if (BT->Right == PrePop || BT->Right == NULL) {
				if (cnt == 0) printf("%d", BT->Data);
				else printf(" %d", BT->Data);
				cnt++;
			}
			else {
				Push(S, BT->Data);
				BT = BT->Right;
				break;
			}
		}
	}
}

int main()
{
	int N, cnt, v, i, Root;
	char Method[5];
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Top = 0;
	scanf_s("%d", &N, sizeof(N));
	cnt = 2 * N;
	struct TNode T[MaxSize];
	for (i = 0; i < N; i++) {
		T[i].Data = i;
		T[i].Left = NULL;
		T[i].Right = NULL;
	}
	while (cnt) {
		scanf_s("%s", Method, sizeof(Method));
		if (strcmp(Method, "Push") == 0) {
			scanf_s("%d", &v, sizeof(v));
			Push(S, v);
			if (cnt == N) Root = v;
		}
		if (strcmp(Method, "Pop") == 0) {
			v = Pop(S);
			if (T[S->Data[S->Top]].Left) {
				T[S->Data[S->Top]].Right = (T + v);
			}
			else {
				T[S->Data[S->Top]].Left = (T + v);
			}
		}
		cnt -= 1;
	}
	PostOrderTraversal(T, Root, N);
	return 0;
}