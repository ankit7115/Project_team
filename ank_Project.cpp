#include<bits/stdc++.h>
#include <algorithm>
#define BEGIN string("#include<bits/stdc++.h>\nusing namespace std;\n\nint main(){")
#define END string("\n\treturn 0;\n}")

using namespace std;

string translate_line(const string& line) {
    string translated = line;
    bool flag=true;
    size_t pos = translated.find("BEGIN");
    if (pos != string::npos) {
        translated.replace(pos, 5, BEGIN);
    }

    pos = translated.find("END");
    if (pos != string::npos) {
        translated.replace(pos, 3, END);
    }

    pos = translated.find("INPUT");
    if (pos != string::npos) {
        translated.replace(pos, 5, "cin >> ");
        flag=false;
    }

    pos = translated.find("NUMBER");
    if (pos != string::npos) {
        translated.replace(pos, 6, "int");
        flag=false;
    }

    pos = translated.find("OUTPUT (");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        flag=false;
    }

    pos = translated.find("OUTPUT(");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        flag=false;
    }

    pos = translated.find("OUTPUT ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        flag=false;
    }

    if(flag)
    return translated;
    else
    return translated + ";";
}

int main(){
    freopen("pseudo.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    
   vector<vector<string>> pseudoCode;

    //BEGIN;
    while (true) {
        vector<string> block;
        string line;
        while (getline(cin, line)) {
            block.push_back(line);
        }
        if (block.empty()) {
            break;
        }

        pseudoCode.push_back(block);
    }
    for (int i = 0; i < pseudoCode.size(); i++) {
        for (int j = 0; j < pseudoCode[i].size(); j++) {
            if(j==0)
            cout << translate_line(pseudoCode[i][j]) << endl;
            else
            cout <<"\t"<< translate_line(pseudoCode[i][j]) << endl;
        }  
    }
    
    return 0;
}


   