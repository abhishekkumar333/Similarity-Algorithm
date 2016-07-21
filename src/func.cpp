#include<bits/stdc++.h>
using namespace std;
string convU(string a)
{
    for(int i=0;i<a.size();i++)
        if(isalpha(a[i]))
        {
            if(islower(a[i]))
                a[i]=toupper(a[i]);
        }
        return a;
}

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


vector<string> convP(string a)
{
    vector<string>pa;
    int i=0;
    while(i<a.size())
    {
        string ta;
        if(i+1<=a.size()-1)
        {
            ta+=a[i];
            ta+=a[i+1];
            pa.push_back(ta);
        }
        i++;
    }
    return pa;
}
float comp(string a,string b)
{
    a=convU(a);
    b=convU(b);
    vector<string>pa,pb;
    pa=convP(a);pb=convP(b);


   /*for(int i=0;i<pa.size();i++)
     cout<<pa[i]<<" ";
   cout<<endl;

   for(int i=0;i<pb.size();i++)
    cout<<pb[i]<<" ";
    cout<<endl;*/

    int inter=0;
    map<string,int>vis;
    for(int i=0;i<pa.size();i++)      //} This is the logic of finding intersection of set
        vis[pa[i]]++;

      for(int i=0;i<pb.size();i++)
           if(vis[pb[i]]>0)
            {
                vis[pb[i]]--;//This is for handling duplicates
                inter++;
            }                        //}
            int deno=pa.size()+pb.size();
            inter*=2;

      float similarity=(float)inter/(float)deno;
       similarity*=100;

     return similarity;
}

