#include <bits/stdc++.h>
using namespace std;
/*
Use comp() function for character pair similarity
*/

/*functions*/
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

int LevenshteinDistance(string s, int len_s, string t, int len_t)
{ int cost;

  /* base case: empty strings */
  if (len_s == 0) return len_t;
  if (len_t == 0) return len_s;

  /* test if last characters of the strings match */
  if (s[len_s-1] == t[len_t-1])
      cost = 0;
  else
      cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char from both */
  return min(LevenshteinDistance(s, len_s - 1, t, len_t    ) + 1,
                 min(LevenshteinDistance(s, len_s    , t, len_t - 1) + 1,
                 LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost));
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





int NOF=20;//Define number of files you want to take currently 20
int main()
{

   string a="test";
   string FOO,str,b;
cout<<"Running test with Source file name of FOO"<<endl;
cout<<endl;
cout<<"Currently comparing it with "<<NOF<<" Files"<<endl;
cout<<endl;
      ifstream fin("FOO",ios::in);
            while(fin>>str)
             {
                 FOO+=str;
                 FOO+=" ";
             }
           fin.close();

vector< pair<string,string> >testfiles; // vector of pairs of strings to store strings of particular test file
    string temp;
    int i=1;
    for(int i=1;i<=NOF;i++)//For taking one by one all files
    {
        pair<string,string>qw;
        b=a;
        b+=int2string(i);
        //cout<<b<<endl;
        qw.second=b;
        char *ta =new char[b.size()+1];
        for(int j=0;j<=b.size();j++)
            ta[j]=b[j];
        ta[b.size()]='\0';


              ifstream fin1(ta,ios::in);
             while(fin1>>str)
             {
                 temp+=str;
                 temp+=" ";
             }
             fin1.close();
              qw.first=temp;
             testfiles.push_back(qw);
             temp.clear();
        delete[] ta;
    }
   cout<<endl;
    priority_queue< pair<int,string> >pq;//A priority queue for checking the maximum match of a file we have taken a pair of int and a string value

       cout<<"Filename "<<" Matching percentage"<<endl;
       cout<<endl;
        for(int i=0;i<testfiles.size();i++)
           {
               int sim=comp(FOO,testfiles[i].first);
               cout<<"  "<<testfiles[i].second<<"      "<<sim<<"%"<<endl;
               cout<<endl;
             pq.push(make_pair(sim,testfiles[i].second));
           }

    cout<<endl;
      pair<int,string> ans=pq.top();
     cout<<"File matches :- "<<ans.second<<endl;
     cout<<"String Metric similarity Measure "<<ans.first<<"%"<<endl;
    return 0;
}
