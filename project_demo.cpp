#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("pseudo.txt","r",stdin);
    freopen("output1.cpp","w",stdout);
  
    vector<string>v;
    
    string s;
    while(s!="END"){
    
        getline(cin,s);
        v.push_back(s);
    }
   // cout<<v.size();
    cout<<"#include<bits/stdc++.h>\n";
    cout<<"using namespace std;\n";
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

        if(s1=="")
        cout<<s1;

        else if(s2[0]=="FOR"){
                cout<<"for(";
                cout<<s2[1]<<";";
                string demo="";
                string temp="";
                for(int i=0;i<s2[1].length();i++){
                    if(s2[1][i]=='='){
                        //here temp store initialize value
                        temp=s2[1].substr(i+1,s2[1].length());
                        break;
                    }
                
                    else{
                        
                    demo=demo+s2[1][i];
                    }
                }
                
                if(s2[3][0]>=65&&s2[3][0]<=90||s2[3][0]>=97&&s2[3][0]<=122){
                        cout<<demo<<"<="<<s2[3]<<";";
                int n3=stoi(s2[5]);

                if(n3==1)
                cout<<demo<<"++";
                else
                cout<<demo<<"="<<demo<<"+"<<n3;

                cout<<"){";
                }
                else{
                int n1=stoi(temp);  //string to integer
                int n2=stoi(s2[3]);
                int n3=stoi(s2[5]);
    
                if(n1<=n2)
                cout<<demo<<"<="<<s2[3]<<";";
                else
                cout<<demo<<">="<<s2[3]<<";";

                if(n1>=n2){
                //access increase value by 1 2 3...    
                if(n3==1)
                cout<<demo<<"--";
                else
                cout<<demo<<"="<<demo<<"-"<<n3;

                cout<<"){";
                }
                else{
    
                if(n3==1)
                cout<<demo<<"++";
                else
                cout<<demo<<"="<<demo<<"+"<<n3;

                cout<<"){";
                }
            


                }
                
        }

        else if(s2[0]=="ENDFOR"){
            cout<<"}";
        }
        else if(s2[0]=="ENDIF"){
            cout<<"}";
    }
        else if(s2[0]=="IF"){
            cout<<"if(";
            for(int i=1;i<s2.size();i++){
               
                cout<<s2[i]<<" ";
            }
            cout<<"){";
        }
        else if(s2[0]=="WHILE"){
                cout<<"while(";
                    for(int i=1;i<s2.size();i++){
                        if(s2[i]=="DO"){}
                        cout<<s2[i]<<" ";
                    }
                
            }
             
        else if(s2[0]=="ELSE"){
            
                cout<<"else ";
            for(int i=1;i<s2.size();i++){
                if(s2[i]=="IF"){
                        
                cout<<"if(";
                }
                else
                cout<<s2[i]<<" ";
            }
            cout<<")";
        }
 
        //initialization

        else if(s2[0]=="SET"){
            cout<<"int ";
            for(int i=1;i<s2.size();i++){
                if(i==s2.size()-1)
                cout<<s2[i]<<";";
                else
                cout<<s2[i]<<",";
            }
        }
        //output statement
       else if (s2[0] == "OUTPUT("){
        cout<<"cout<<";
        cout<<"\"";
        for(int i=1;i<s2.size()-1;i++){
            cout<<s2[i]<<" ";
        }
        cout<<"\""<<";";
        }   

        else if(s2[0]=="OUTPUT"){
            if(s2.size()==1){
                 cout<<"cout<< "<<s2[i]<<" <<endl;";
            }
            else
            for(int i=1;i<s2.size();i++)
            cout<<"cout<< "<<s2[i]<<" <<endl;"<<"\n";
        }
        
       else if(s2[0]=="INPUT"){
            cout<<"cin>> ";
            for(int i=1;i<s2.size();i++){
                if(i==s2.size()-1)
                cout<<s2[i]<<";";
                else
                cout<<s2[i]<<" >> ";
            }
            
        }


        //variable declared
       else if(s2[0]=="NUMBER"){
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

        else{
            for(int i=0;i<s2.size();i++){
                if(s2[i]=="")
                cout<<" ";
                else
                cout<<s2[i]<<";";
            }
        }
                cout<<"\n";
    }
    cout<<"\nreturn 0;"<<endl<<"}";
    return 0;
}

