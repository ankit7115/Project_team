#include<bits/stdc++.h>
#include <fstream>
#define BEGIN string("#include<bits/stdc++.h>\nusing namespace std;")
#define END string("\n\treturn 0;\n}")

using namespace std;

class PseudoToCpp {

    string translate_line(const string& line);
    void forImplement(const string& );
    void functionImplement(string& );
    ifstream fin;
    ofstream fout;

    public:
    bool check=false;
    PseudoToCpp(const string& input_file, const string& output_file) : fin(input_file), fout(output_file) {}
    void translate();

};
void PseudoToCpp::functionImplement(string& s1){
    string temp="";
    
    for(int i=0;i<s1.size();i++){
        if(s1[i]==')'){
            for(int j=i+2;j<s1.length();j++){
                temp=temp+s1[j];
            }
            break;
        }
        }
    fout<<temp;
    
    string temp1="";
    for(int i=0;i<s1.size();i++){
        if(s1[i]=='('){
            for(int j=i+1;j<s1.length();j++){
                if(s1[j]==')'){
                    temp1=temp1+s1[j];
                    break;
                }           
                else
                temp1=temp1+s1[j];
            }

    }
}
string demo1="";
    for(int i=0;i<s1.size();i++){    
        if(s1[i]=='(')
        break;
        demo1=demo1+s1[i];
    }
    for(int i=8;i<demo1.size();i++){
        fout<<demo1[i];
    }

    fout<<"(";
    string demo="";
    vector<string>v;
    for(int i=0;i<temp1.size();i++){
        if(temp1[i]==':'||temp1[i]==','||temp1[i]==')'){
            v.push_back(demo);
            demo="";
            i++;
        }
        demo=demo+temp1[i];
    }
    for(int i=1;i<v.size();i=i+2){
        fout<<v[i]<<" ";
        fout<<v[i-1];
        if(i!=v.size()-1)
        fout<<",";
    }
    fout<<"){";

}
void PseudoToCpp::forImplement(const string& s1){
    vector<string>s2;
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
            if(s2[0]=="FOR"){
                fout<<"for ( ";
                fout<<s2[1]<<" ; ";
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
                        fout<<demo<<" <= "<<s2[3]<<" ; ";
                int n3=stoi(s2[5]);

                if(n3==1)
                fout<<demo<<" ++ ";
                else
                fout<<demo<<" = "<<demo<<" + "<<n3;
                fout<<" ){";
                }
                else{
                int n1=stoi(temp);  //string to integer
                int n2=stoi(s2[3]);
                int n3=stoi(s2[5]);   
                if(n1<=n2)
                fout<<demo<<" <= "<<s2[3]<<" ; ";
                else
                fout<<demo<<" >= "<<s2[3]<<" ; ";
                if(n1>=n2){
                //access increase value by 1 2 3...    
                if(n3==1)
                fout<<demo<<" -- ";
                else
                fout<<demo<<" = "<<demo<<" - "<<n3;
                fout<<" ){";
                 }
                else{
                 if(n3==1)
                 fout<<demo<<" ++ ";
                 else
                 fout<<demo<<" = "<<demo<<" + "<<n3;
                 fout<<" ){";
                 }
            }               
        }
}

void PseudoToCpp::translate(){

    vector<string> pseudoCode;

    string line;
        while (getline(fin, line)) {
            pseudoCode.push_back(line);
        }

        for (int i = 0; i < pseudoCode.size(); i++) {
            if(i==0)
                fout << translate_line(pseudoCode[i]) << endl;
            else if(i==1){
                size_t pos=pseudoCode[i].find("FUNCTION");
                if(pos!=string::npos){
                    fout << translate_line(pseudoCode[i]) << endl;
                }
                size_t pos1=pseudoCode[i].find("CLASS");
                if(pos1!=string::npos){
                    check=true;
                    fout << translate_line(pseudoCode[i]) << endl;
                }
                if(pos==string::npos and pos1==string::npos){
                    fout<<"int main() { "<<endl;
                fout <<"\t"<< translate_line(pseudoCode[i]) << endl;
                }
            }
            else{
                size_t pos1=pseudoCode[i].find("ENDCLASS");
                size_t pos2=pseudoCode[i].find("ENDFUNCTION");
                if(pos1!=string::npos){
                    fout << translate_line(pseudoCode[i]) << endl;
                }
                else if(pos2!=string::npos){
                    fout << translate_line(pseudoCode[i]) << endl;
                }
                else
                fout <<"\t"<< translate_line(pseudoCode[i]) << endl;
            }
        }

}

string PseudoToCpp::translate_line(const string& line){
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
     pos = translated.find("ENDCLASS");
    if (pos != string::npos) {
        translated.replace(pos, 8, "};\nint main() { ");
        flag=true;
        
    }
    pos = translated.find("PRIVATE");
    if (pos != string::npos) {
        translated.replace(pos, 7, "private:");
        flag=true;
    }
    pos = translated.find("PUBLIC");
    if (pos != string::npos) {
        translated.replace(pos, 6, "public:");
        flag=true;
    }
    pos = translated.find("PROTECTED");
    if (pos != string::npos) {
        translated.replace(pos, 9, "protected:");
        flag=true;
    }
    pos = translated.find("CLASS");
    if (pos != string::npos) {
        translated.replace(pos, 5, "class");
        translated =translated+"{";
        flag =true;
    }
    pos = translated.find("ENDWHILE");
    if (pos != string::npos) {
        translated.replace(pos, 8, "\t}");
        flag=true;
    }
    pos = translated.find("ENDFOR");
    if (pos != string::npos) {
        translated.replace(pos, 6, "}");
        flag=true;
    }

    pos = translated.find("ENDIF");
    if (pos != string::npos) {
        translated.replace(pos, 5, "\n\t}");
        flag=true;
    }
    pos = translated.find("ENDFUNCTION");
    if (pos != string::npos) {
        if(check){
            translated.replace(pos, 11, "} ");
            flag=true;
        }
        else{
        translated.replace(pos, 11, "}\nint main() { ");
        flag=true;
        }
    }
    pos = translated.find("END");
    if (pos != string::npos) {
        translated.replace(pos, 3, END);
        flag=true;
    }
    pos = translated.find("RETURN");
    if (pos != string::npos) {
        translated.replace(pos, 6, "return");
        
    }
    pos = translated.find("TRUE");
    if (pos != string::npos) {
        translated.replace(pos, 4, "true");
        
    }
    pos = translated.find("FALSE");
    if (pos != string::npos) {
        translated.replace(pos, 6, "false");
        
    }
    pos = translated.find("INPUT");
    if (pos != string::npos) {
        translated.replace(pos, 5, "cin >> ");
        pos = translated.find(",");
        if (pos != string::npos) {
        translated.replace(pos, 1, " >> ");
    }

    pos = translated.find("(");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ");
         pos = translated.find(")");
        if (pos != string::npos) 
        translated.replace(pos, 1, " ]");
     pos = translated.find(",");
        if (pos != string::npos) {
        translated.replace(pos, 1, " >> ");
    }

     pos = translated.find(",");
        if (pos != string::npos) {
        translated.replace(pos, 1, " >> ");
    }
     pos = translated.find(",");
        if (pos != string::npos) {
        translated.replace(pos, 1, " >> ");
    }
     pos = translated.find(",");
        if (pos != string::npos) {
        translated.replace(pos, 1, " >> ");
    }
    }


    pos = translated.find("INCREMENT ");
    if (pos != string::npos) {
        size_t pos1 = translated.find("TO");
        if (pos1 != string::npos) {
             translated.replace(pos, 10, "");
             pos1 = translated.find("TO");
             translated.replace(pos1, 2, "+=");
        }
        else{
        translated.replace(pos, 10, "");
        translated=translated+"++";
        }
    }
    pos = translated.find("DECREMENT ");
    if (pos != string::npos) {
        size_t pos1 = translated.find("TO");
        if (pos1 != string::npos) {
             translated.replace(pos, 10, "");
             pos1 = translated.find("TO");
             translated.replace(pos1, 2, "-=");
        }
        else{
        translated.replace(pos, 10, "");
        translated=translated+"--";
        }
    }
    pos = translated.find("OUTPUT (");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        //To print the variable through + operator
        pos = translated.find("\" + ");
        if (pos != string::npos) {
        translated.replace(pos, 4, " << ");
    }
    }

    pos = translated.find("OUTPUT(");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        //To print the variable through + operator
        pos = translated.find("\" + ");
        if (pos != string::npos) {
        translated.replace(pos, 4, " << ");
    }
    }
    pos = translated.find("ADD ");
    if (pos != string::npos) {
        translated.replace(pos, 4, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " + ");
    }
    }
    pos = translated.find("SUB ");
    if (pos != string::npos) {
        translated.replace(pos, 4, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " - ");
    }
    }
    pos = translated.find("SUBTRACT ");
    if (pos != string::npos) {
        translated.replace(pos, 9, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " - ");
    }
    }
    pos = translated.find("MULTIPLY ");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " * ");
    }
    }
    pos = translated.find("DIVIDE ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " / ");
    }
    }
    pos = translated.find("MODULO ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        //To print the variable through + operator
        pos = translated.find("AND");
        if (pos != string::npos) {
        translated.replace(pos, 3, " / ");
    }
    }
    pos = translated.find("OUTPUT ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        //To print the variable through + operator
        pos = translated.find("\"+");
        if (pos != string::npos) {
        translated.replace(pos, 2, "\" << ");
    }
    }
    pos = translated.find("DISPLAY (");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        //To print the variable through + operator
        pos = translated.find("\" + ");
        if (pos != string::npos) {
        translated.replace(pos, 4, " << ");
    }
    }

    pos = translated.find("DISPLAY(");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        //To print the variable through + operator
        pos = translated.find("\" + ");
        if (pos != string::npos) {
        translated.replace(pos, 4, " << ");
    }
    }

    pos = translated.find("DISPLAY ");
    if (pos != string::npos) {
        translated.replace(pos, 7, "cout << ");
        //To print the variable through + operator
        pos = translated.find("\"+");
        
        if (pos != string::npos) {
        translated.replace(pos, 2, " << ");
    }
    }
    pos = translated.find("PRINT (");
    if (pos != string::npos) {
        translated.replace(pos, 8, "cout << \"");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        translated=translated+"\"";
    }

    pos = translated.find("PRINT(");
    if (pos != string::npos) {
        translated.replace(pos, 6, "cout << \"");
        pos=translated.find(")");
        if (pos != string::npos) {
            translated.erase(pos);
        }
        translated=translated+"\"";
    }

    pos = translated.find("PRINT ");
    if (pos != string::npos) {
        translated.replace(pos, 6, "cout << \"");
        translated=translated+"\"";
    }

    pos = translated.find("CHARACTER ARRAY");
    if (pos != string::npos) {
        translated.replace(pos, 15, "char");
        pos = translated.find("=");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ] = ");
        pos = translated.find("(");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ");
         pos = translated.find(")");
        if (pos != string::npos) 
        translated.replace(pos, 1, " ]");
    }

    pos = translated.find("INTEGER ARRAY");
    if (pos != string::npos) {
        translated.replace(pos, 13, "int");
        pos = translated.find("=");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ] = ");
        pos = translated.find("(");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ");
         pos = translated.find(")");
        if (pos != string::npos) 
        translated.replace(pos, 1, " ]");
    }

    pos = translated.find("ARRAY");
    if (pos != string::npos) {
        translated.replace(pos, 5, "int");
        pos = translated.find("=");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ] = ");

        pos = translated.find("(");
        if (pos != string::npos) 
        translated.replace(pos, 1, "[ ");
         pos = translated.find(")");
        if (pos != string::npos) 
        translated.replace(pos, 1, " ]");
    }

    pos = translated.find("CHARACTER");
    if (pos != string::npos) {
        translated.replace(pos, 9, "char ");
    }
    pos = translated.find("FLOATING");
    if (pos != string::npos) {
        translated.replace(pos, 8, "float ");
    }

    pos = translated.find("FLOAT");
    if (pos != string::npos) {
        translated.replace(pos, 5, "float ");
    }
    pos = translated.find("CHAR");
    if (pos != string::npos) {
        translated.replace(pos, 4, "char ");
    }

    pos = translated.find("STRING ");
    if (pos != string::npos) {
        translated.replace(pos, 8, "string ");
    }

    pos = translated.find("DOUBLE");
    if (pos != string::npos) {
        translated.replace(pos, 8, "double ");
    }

    pos = translated.find("NUMBER");
    if (pos != string::npos) {
        translated.replace(pos, 6, "int");
    }
    pos = translated.find("INTEGER");
    if (pos != string::npos) {
        translated.replace(pos, 8, "int ");
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

    pos = translated.find("FOR");
    if (pos != string::npos) {
        forImplement(translated);
        translated = "\0";
        // return translated;
        flag=true;
    }

    pos = translated.find("OR");
    if (pos != string::npos) {
        translated.replace(pos, 2, "||");
        flag=true;
    }

    pos = translated.find("COMPUTE");
    if (pos != string::npos) {
        translated.replace(pos, 7, "");
    }

    pos = translated.find("WHILE");
    if (pos != string::npos) {
        translated.replace(pos, 5, "while ( ");
    }

    pos = translated.find("DO");
    if (pos != string::npos) {
        translated.replace(pos, 2, " ){");
        flag=true;
    }
    pos = translated.find("CALL");
    if (pos != string::npos) {
        translated.replace(pos, 4, "");
    }
    pos = translated.find("FUNCTION");
    if(pos != string::npos){
        functionImplement(translated);
        translated="\0";
        flag = true;
    }

    if(flag)
    return translated;
    else
    return translated + ";";
}

int main() {
    //PseudoToCpp translator("1.arithmetic.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("2.float.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("3.incrementPre.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("4.increment.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("5.relational.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("6.condition.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("7.sizeof.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("8.-vecheck.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("9.checkEvenOdd.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("10.largestIn3.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("11.leapYear.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("12.printWhile.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("14.sumofdigit.txt", "ank_OutputCpp.cpp");
     //PseudoToCpp translator("15.productDigit.txt", "ank_OutputCpp.cpp");
     //PseudoToCpp translator("16.factorial.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("18.printForLoop1-10.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("19.fibbSeries.txt", "ank_OutputCpp.cpp");
    //  PseudoToCpp translator("20.check_Armstrong.txt", "ank_OutputCpp.cpp");
    //  PseudoToCpp translator("21.check_prime.txt", "ank_OutputCpp.cpp");
    // // PseudoToCpp translator("22.AvgOf_10_num.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("23.swapWithout3rd.txt", "ank_OutputCpp.cpp");
    // PseudoToCpp translator("24.drawLine.txt", "ank_OutputCpp.cpp");
     //PseudoToCpp translator("25.drawlineWithClass.txt", "ank_OutputCpp.cpp");
     PseudoToCpp translator("26.isprime.txt", "ank_OutputCpp.cpp");
    // //PseudoToCpp translator1("pseudo.txt", "output1.txt");
    translator.translate();
    //translator1.translate();
    return 0;
}