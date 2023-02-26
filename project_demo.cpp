#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("pseudo.txt","r",stdin);
   freopen("output1.txt","w",stdout);
  
    vector<string>v;
    
    string s;
    while(s!="END"){
    
        getline(cin,s);
        v.push_back(s);
    }
   // cout<<v.size();
    cout<<"#include<bits/stdc++.h>\n";
    cout<<"using namespace std\n";
    cout<<"int main(){\n\n";
    for(int i=1;i<v.size()-1;i++){
        string s1;
        vector<string>s2;
        s1=v[i];
        string demo="";
        for(int i=0;i<s1.length();i++){
            if(i==s1.length()-1){
                demo=demo+s1[i];
                s2.push_back(demo);
            }
            
            else if(s1[i]==' '||s1[i]==','||s1[i]=='"'){
                s2.push_back(demo);
                demo="";
            }
            else{
                demo=demo+s1[i];
            }
        }
        //output statement
        if (s2[0] == "OUTPUT("){
        cout<<"cout<<";
        cout<<"\"";
        for(int i=1;i<s2.size()-1;i++){
            cout<<s2[i];
        }
        cout<<"\""<<";";
        }   

        

        //variable declared
        if(s2[0]=="NUMBER"){
            if(s2[0]=="NUMBER"){
            cout<<"int ";
            for(int i=1;i<s2.size();i++){
                if(i==s2.size()-1)
                cout<<s2[i]<<";";
                else
                cout<<s2[i]<<",";
            }
        }
        else{
            
            cout<<s2[0]<<" ";
        }

        }
                cout<<"\n";
    }
    cout<<"\nreturn 0;"<<endl<<"}";
    return 0;
}
