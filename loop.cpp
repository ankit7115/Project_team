/*  By this we can compute any program realted 
    to while loop only
    ankit
    PSEUDO CODE:-
    SET fact = 1,t=1
    NUMBER n
    INPUT n 
    WHILE i<= 10 DO
    COMPUTE fact = fact * t
    INCREASE t by 1
    END LOOP
    PRINT fact
    END
    In code:-
    # = any variable
    * = any number 
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("intput.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout << "#include<bits/stdc++.h>"<< endl;
    cout << "using namespace std;" << endl;
    cout << "int main(){" << endl;
    vector<string> s;
    string str;
    while ( str != "END"){
        getline(cin,str);
        s.push_back(str);
    }

    for(int i = 0; i < s.size(); i++){
        //SET fact = *,t= *
        if ( s[i][0] =='S' && s[i][1] == 'E' && s[i][2] == 'T'){
            string stemp = "";
            for(int j = 4; j < s[i].size(); j++){
                stemp += s[i][j];
            }
            cout << "int " << stemp <<";";
            cout << endl;
            continue;
        }
        //NUMBER #
        if(s[i][0] == 'N' && s[i][1] == 'U' && s[i][2] == 'M' && s[i][3] == 'B'&& s[i][4] =='E'&& s[i][5] =='R'){
            string stemp0="";
            for(int j = 7; j < s[i].size(); j++){
                stemp0 +=s[i][j];
            }
            cout <<"long long " <<  stemp0<<";";
            cout << endl;
            continue;
        }
        //INPUT # 
        if(s[i][0] == 'I' && s[i][1] == 'N' && s[i][2] == 'P' && s[i][3] == 'U'&& s[i][4] =='T'){
            string stemp00="";
            for(int j = 6; j < s[i].size(); j++){
                stemp00 +=s[i][j];
            }
            cout << "cin >> " <<  stemp00<<";";
            cout << endl;
            continue;
        }
        //INCREASE t by *
        if(s[i][0] == 'I' && s[i][1] == 'N' && s[i][2] == 'C' && s[i][3] == 'R'&& s[i][4] =='E'&& s[i][5] =='A'&&s[i][6]=='S'&&s[i][7]=='E'){
            string stemp1 ="",st1="";
            for(int j = 14; j < s[i].size(); j++){
                stemp1 +=s[i][j];
            }
            int k = 9;
            while( s[i][k] != 'b' && s[i][k] != 'y'){
                st1 += s[i][k];
                k++;
            }
            cout << st1 << "+="<< stemp1<<";"; 
            cout << endl; 
            continue;
        }
        //DECREASE t by *
        if(s[i][0] == 'D' && s[i][1] == 'E' && s[i][2] == 'C' && s[i][3] == 'R'&& s[i][4] =='E'&& s[i][5] =='A'&&s[i][6]=='S'&&s[i][7]=='E'){
            string stemp2 ="",st="";
            for(int j = 14; j < s[i].size(); j++){
                stemp2 +=s[i][j];
            }
            int k = 9;
            while( s[i][k] != 'b' && s[i][k] != 'y'){
                st += s[i][k];
                k++;
            }
            cout << st << "-="<< stemp2<<";"; 
            cout << endl;
            continue;
        }
        //END LOOP
        if(s[i][0] == 'E' && s[i][1] == 'N' && s[i][2] == 'D' && s[i][3] == ' '&& s[i][4] =='L'&& s[i][5] =='O'&&s[i][6]=='O'&&s[i][7]=='P'){
            cout << "}"; 
            cout << endl;
            continue;
        }
        //WHILE # <= * DO
        if(s[i][0] == 'W' && s[i][1] == 'H' && s[i][2] == 'I' && s[i][3] == 'L'&& s[i][4] =='E'){
            int j = 6;
            string stemp3 ="";
            while(s[i][j] != 'D' && s[i][j+1] != 'O'){
                stemp3 +=s[i][j];
                j++;    
            }
            cout << "while ("<< stemp3 << "){";
            cout << endl;
            continue;
        }
        //COMPUTE fact = fact * t
        if(s[i][0] == 'C' && s[i][1] == 'O' && s[i][2] == 'M' && s[i][3] == 'P'&& s[i][4] =='U'&& s[i][5] =='T'&& s[i][6] =='E'){
            string stemp4 ="";
            for(int j = 8; j < s[i].size(); j++){
                stemp4 +=s[i][j];
            }
            cout << stemp4 << ";";
            cout << endl;
            continue;
        }
        //PRINT #
        if(s[i][0] == 'P' && s[i][1] == 'R' && s[i][2] == 'I' && s[i][3] == 'N'&& s[i][4] =='T'){
            string stemp5="";
            for(int j = 6; j < s[i].size(); j++){
                stemp5 +=s[i][j];
            }
            cout << "cout << " << stemp5 <<";";
            continue;
        }
    }
    cout << "\nreturn 0;\n}";
    return 0;
}