#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, cnt=-1;
    string str, s="", ds="";
    char flag, esc;
    cout<<"Enter the flag : ";
    cin>>flag;
    cout<<"Enter the escape : ";
    cin>>esc;
    cout<<"\nEnter the bit string : ";
    cin>>str;
    for(i=0; i<str.size(); i++){
        if(str[i]==flag)
            s+=esc;
        if(str[i]==esc)
            s+=esc;
        s+=str[i];
    }
    //cout<<"Resultant string after stuffing: "<<s<<'\n';
    cout<<"\n\nAfter stuffing : "<<flag<<s<<flag<<'\n';
    for(i=0; i<s.size(); i++){
        if (s[i]==esc)
            i++;
        ds+=s[i];
    }
    cout<<"\n\nResultant string after destuffing: "<<ds;
	return 0;
}
