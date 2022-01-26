#include<bits/stdc++.h>
using namespace std;
int ara[1009];
int tree[4009];

void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=ara[l];
        return ;
    }

    int mid=(l+r)/2;

    build(node*2,l,mid);
    build(node*2+1,mid+1,r);

    tree[node]=tree[node*2]+tree[node*2+1];
}

void update(int node,int l, int r, int pos, int val)
{
    if(l>=pos && r<=pos)
    {
        tree[node]+=val;
        return ;
    }

    if(r<pos || l>pos)
        return ;

    int mid=(l+r)/2;

    update(node*2,l,mid,pos,val);
    update(node*2+1,mid+1,r,pos,val);

    tree[node]=tree[node*2]+tree[node*2+1];

}

int query(int node, int l, int r, int i, int j)
{
    if(r<i || l>j)
        return 0;
    if(l>=i && r<=j)
        return tree[node];

    int mid=(l+r)/2;

    int x=query(node*2,l,mid,i,j);
    int y=query(node*2+1,mid+1,r,i,j);

    return x+y;
}

int main()
{
    int i,j,k,l,m,n;

    cout<<"Numbers of element of the array : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ara[i];
    }

    build(1,1,n);

    cout<<"How many queries : ";
    cin>>m;
    while(m--)
    {
        cout<<"1 to update and 2 to query : ";
        cin>>k;
        if(k==1)
        {
            int indx,val;
            cout<<"Enter indx and value to update : ";
            cin>>indx>>val;
            update(1,1,n,indx,val);

            cout<<indx<<" updated"<<endl<<endl;
        }
        else
        {
            cout<<"Enter query indx : ";
            cin>>i>>j;

            cout<<"sum from index "<<i<<" to "<<j<<" :  "<<query(1,1,n,i,j)<<endl<<endl;
        }
    }

    main();
    return 0;
}
