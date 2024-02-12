#include<bits/stdc++.h>
using namespace std;
int f=0,f2=0;
string arr[]={"asm","double","new","switch",
"auto" ,"else" ,"operator" ,"template",
"break","enum" ,"private" ,"this",
"case" ,"extern" ,"protected" ,"throw",
"catch" ,"float" ,"public", "try",
"char", "for", "register", "typedef",
"class"  ,"friend" ,"return" ,"union",
"const", "goto", "short" ,"unsigned",
"continue" ,"if", "signed" ,"virtual",
"default" ,"inline" ,"sizeof", "void",
"delete", "int" ,"static" ,"volatile",
"do"  ,"long" ,"struct", "while","long" };
vector<string>keyword;
bool sajib(string id)
{
    bool fx=true;
    string ok="";
    for(int i=0;i<id.size();i++)
    {
        bool fx=true;
        if(!isspace(id[i]))
        {
           ok=ok+""+id[i];
        }
        for(auto x:arr)
        {
           if(x==ok)
           {
              keyword.push_back(ok);
              ok="";
           }

        }

    }
    return fx;///eta emni return korchi
}
string call(string s)
{
    long long sz=s.size();
    long long i;
    string cnt="";
    for(i=0;i<sz;i++)
    {
        if(s[i]=='"')
        {
            f2=1;
        }
        if(s[i]=='/' && s[i+1]=='/' && f2==0)
        {
            break;
        }
        if(s[i]=='/' && s[i+1]=='*' && f2==0)
        {
            f=1;
        }
        if(s[i]=='*' && s[i+1]=='/' && f2==0)
        {
            f=0;
           break;
        }
        if(f==0)
        cnt=cnt+""+s[i];
        /*
        sajib
        */
    }
    return cnt;
}
int main()
{
    fstream in,out;
    in.open("input.txt");
    out.open("output.txt");
    string s;
    for(int i=1;i<=2;i++)
    {
    if(i==1)
    {
    while(getline(in,s))
    {

        f2=0;
        string ans=call(s);
        cout<<ans<<endl;
        out<<ans<<endl;
    }
    in.close();
    out.close();
    }
    else
    {
    in.open("output.txt");
    out.open("keyword.txt");
    cout<<"..............................................keyword......................"<<endl;
    string y;
    while(getline(in,y))
    {
        bool res=sajib(y);

    }
    for(auto x:keyword)
    {
        cout<<x<<endl;
        out<<x<<endl;
    }
    in.close();
    out.close();

    }

    }


}
