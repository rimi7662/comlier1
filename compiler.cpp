#include<bits/stdc++.h>
using namespace std;



int main()
{
    freopen("in.txt","r",stdin);
    char a[1000];
    while(gets(a))
    {
        map<char,char>mp;
        stack<char>s;
        stack<char>o;
        stack<int>t;
        for(int i=0; i<strlen(a); i++)
        {
            if(a[i]==')')
            {
                while(s.size()!=0)
                {
                    char c=s.top();
                    if(c=='(')
                    {
                        s.pop();
                        break;
                    }
                    else
                    {
                        o.push(c);
                        s.pop();
                    }
                }
            }
            else if(a[i]=='('||a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')s.push(a[i]);
            else o.push(a[i]);
        }
        while(s.size()!=0)s.pop();
//        while(o.size()!=0)
//        {
//           char c=o.top();
//           //s.push(c);
//           cout<<c;
//           o.pop();
//        }
//        while(s.size()!=0)
//        {
//           char c=s.top();
//           cout<<c;
//           s.pop();
//        }
//        cout<<endl;
        mp['a']='1';
        mp['b']='2';
        mp['c']='2';
        while(o.size()!=0)
        {
            char c=o.top();
            if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                s.push(c);
                o.pop();
            }
            else
            {
                s.push(mp[c]);
                o.pop();
            }
        }
//        while(s.size()!=0)
//        {
//            char c=s.top();
//            o.push(c);
//            cout<<c;
//            s.pop();
//        }
//        cout<<endl;
        while(s.size()!=0)
        {
            char c=s.top();
            s.pop();
            cout<<"c"<<c<<endl;
            if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                char d=o.top();
                o.pop();
                char e=o.top();
                o.pop();
                int p=d-'0';
               cout<<"p"<<p<<endl;
                int q=e-'0';
               cout<<"q"<<q<<endl;
                if(c=='+')
                {
                    int r=p+q;
                    char ab=r+'0';
                    o.push(ab);
                    cout<<"ab"<<ab<<endl;
                }
                else if(c=='-')
                {
                    int r=p-q;
                    char ab=r+'0';
                    o.push(ab);
                     cout<<"ab"<<ab<<endl;
                }
                else if(c=='*')
                {
                    int r=p*q;
                    char ab=r+'0';
                    o.push(ab);
                     cout<<"ab"<<ab<<endl;
                }
                else if(c=='/')
                {
                    int r=p/q;
                    char ab=r+'0';
                    o.push(ab);
                   // cout<<"p"<<p<<endl;
                   // cout<<"q"<<q<<endl;
                    cout<<"ab"<<ab<<endl;
                }
            }
            else o.push(c);
        }
        //cout<<endl;
        char ab=o.top();
        cout<<ab<<endl;
        memset(a,0,sizeof a);
    }

    return 0;
}
