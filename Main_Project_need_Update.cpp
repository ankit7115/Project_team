#include<bits/stdc++.h>
#include <algorithm>
#define BEGIN string("#include<bits/stdc++.h>\nusing namespace std;\n\nint main(){")
#define END string("\n\treturn 0;\n}")

using namespace std;

string translate_line(const string& line) {
    string translated = line;
    bool flag=false;
    if(line.size()==0){
        flag=true;
    }
    auto pos = translated.find("BEGIN");
    if (pos != string::npos) {
        translated.replace(pos, 5, BEGIN);
        flag=true;
    }

    pos = translated.find("ENDIF");
    if (pos != string::npos) {
        translated.replace(pos, 5, "\n\t}");
        flag=true;
    }

    pos = translated.find("END");
    if (pos != string::npos) {
        translated.replace(pos, 3, END);
        flag=true;
    }

    pos = translated.find("INPUT");
    if (pos != string::npos) {
        translated.replace(pos, 5, "cin >> ");
    }

    pos = translated.find("NUMBER");
    if (pos != string::npos) {
        translated.replace(pos, 6, "int");
    }

    pos = translated.find("OUTPUT (");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
    }

    pos = translated.find("OUTPUT(");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
    }

    pos = translated.find("OUTPUT ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
    }

    pos = translated.find("ELSE IF ");
    if (pos != string::npos) {
        translated.replace(pos, 8, "}\n\telse if ( ");
        flag=true;
    }
    pos = translated.find("IF ");
    if (pos != string::npos) {
        translated.replace(pos, 3, "if ( ");
        flag=true;
    }

    pos = translated.find("THEN");
    if (pos != string::npos) {
        translated.replace(pos, 4, " ) { ");
        flag=true;
    }
    pos = translated.find("ELSE");
    if (pos != string::npos) {
        translated.replace(pos, 4, "}\n\telse {");
        flag=true;
    }
    pos = translated.find("AND");
    if (pos != string::npos) {
        translated.replace(pos, 3, "&&");
        flag=true;
    }

    pos = translated.find("OR");
    if (pos != string::npos) {
        translated.replace(pos, 2, "||");
        flag=true;
    }

    // pos = translated.find("FOR");
    // if (pos != string::npos) {
    //     translated.replace(pos, 3, "for ( ");
    //     flag=true;
    // }

    if(flag)
    return translated;
    else
    return translated + ";";
}

int main(){
    freopen("pseudo.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    
   vector<vector<string>> pseudoCode;
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


   