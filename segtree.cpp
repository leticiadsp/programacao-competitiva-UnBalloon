#include <bits/stdc++.h>

using namespace std;

struct segTree{
    int n;
    vector<int>st;

    segTree(int sz): n(sz), st(4*n, 0){}

    int query(int ql, int qr){
        return query(ql, qr, 0, n - 1, 1);
    }

    void update(int i, int v){
        update(i, v, 0, n - 1, 1);
    }

    int query(int ql, int qr, int l, int r, int no){
        if(l > qr || r < qr) return 0; //n tem inter
        if(ql <= l && r <= qr) return st[no];

        int mid = (l + r) / 2;
        int esq = query(ql, qr, l, mid, 2*no);
        int dir = query(ql, qr, mid + 1, r, 2*no+1);
        return merge(esq, dir); 
    }

    void update(int i, int v, int l, int r, int no){
        if(l = r){
            st[no] = v;
            return;
        }
        int mid = (l + r) / 2;
        if(i <= mid) update(i, v, l, mid, 2 * no);
        else update(i, v, mid + 1, r, 2*no+1);

        st[no] = merge(st[2*no], st[2*no+1]);
    }


    int merge(int a, int b){
        return a + b;
    }

};