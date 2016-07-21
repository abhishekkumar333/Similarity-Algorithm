#include <bits/stdc++.h>
#include "header.h"//This includes all necessary functions
using namespace std;
/*
Use comp() function for character pair similarity
*/
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
