Given a constant *K* and a singly linked list *L*, you are supposed to reverse the links of every *K* elements on *L*. For example, given *L* being 1→2→3→4→5→6, if *K*=3, then you must output 3→2→1→6→5→4; if *K*=4, you must output 4→3→2→1→5→6.

### Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive *N* (≤105) which is the total number of nodes, and a positive *K* (≤*N*) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then *N* lines follow, each describes a node in the format:

```
Address Data Next
```

where `Address` is the position of the node, `Data` is an integer, and `Next` is the position of the next node.

### Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

### Sample Input:

```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
```

### Sample Output:

```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```

### Answers:

First try:

```c
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode *List;
struct LNode {
    int Address;
    int Data;
    int Next;
    List RNext;
};

int main()
{
    int i, Start, N, K, times, n;
    scanf("%d %d %d", &Start, &N, &K);
    int Adds[N], Datas[N], Nexts[N];
    List L, tmp;
    L = (List) malloc( sizeof(struct LNode));
    //tmp = L;
    for ( i = 0; i < N; i++ ) {
        scanf("%d %d %d", (Adds+i), (Datas+i), (Nexts+i));
    }
    while(L->Address != Start) {
        for ( i = 0; i < N; i++ ) {
            if( Nexts[i] == -1 ) {
                L->Address = Adds[i];
                L->Data = Datas[i];
                L->Next = Nexts[i];
                L->RNext = NULL;
            }
            if( Nexts[i] == L->Address ) {
                L->RNext = L;
                L->Address = Adds[i];
                L->Data = Datas[i];
                L->Next = Nexts[i];
            }
        }
    }
    List past, now, future;
    times = N/K;
    while(times--) {
        for( n = K; n > 0; n-- ) {
            
        }
    }
}
```

（未完成）

