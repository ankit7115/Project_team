#include<bits/stdc++.h>
#include<vector>
using namespace std;
void print_to_cpp(string s){
    cout<<s;
}

int main(){
    freopen("pseudo.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    
   vector<vector<string>> pseudoCode;

    
    while (true) {
        vector<string> block;
        string line;
        while (getline(cin, line)) {
            if (line == "END") {
                break;
            }
            block.push_back(line);
        }

        if (block.empty()) {
            break;
        }

        pseudoCode.push_back(block);
    }
    for (int i = 0; i < pseudoCode.size(); i++) {
        for (int j = 0; j < pseudoCode[i].size(); j++) {
            cout << "    " << pseudoCode[i][j] << endl;
        }
    }
    cout<<pseudoCode[0][1];

    return 0;
}
    

   