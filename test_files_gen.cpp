#include <bits/stdc++.h>
using namespace std;
int NOF=20;//Number of files to generate
string int2string(int i)
{
    vector<int>v;
    while(i>0)
    {
        v.push_back(i%10);
        i/=10;
    }
    reverse(v.begin(),v.end());
    string a;
    for(int i=0;i<v.size();i++)
        a+=(v[i]+'0');
    return a;
}
int main()
{
   string a="test";
   string b;

    for(int i=1;i<=NOF;i++)
    {
        b=a;
        b+=int2string(i);
        char *ta =new char[b.size()+1];
        for(int j=0;j<=b.size();j++)
            ta[j]=b[j];
        ta[b.size()]='\0';
        freopen(ta,"w",stdout);
        delete[] ta;
    }
    return 0;
}
