#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<pair<int,vector<string>>> vp;
    vector<string> str;
    string line;
    
    while(getline(cin,line)){
        if(line.empty())
            break;
        str.push_back(line);
    }
    for(auto it:str){
        cout<<it<<" ";
    }

}