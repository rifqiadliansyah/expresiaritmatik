#include <iostream>
#include <cstring>
using namespace std;
bool IsOperator(){
    if('+'||'*'||'/'||'%'){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    string str,str1; ///str==input, str1==operasikan
    int a;
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i])){
            str1+=str[i];
            if(!(isdigit(str[i+1]))){
                str1+=" ";
            }
        }else if(!(isdigit(str[i])) && str[i]!= ' '){
            str1+=str[i];
            if(str[i]=='-'&&str[i+1]=='-'||str[i+2]=='('){
            	str1+=" -1 * ";
//            	str1[i+1]='';
			}
            	str1+=" ";            	
        }

    }
    cout << str1<<endl;
//    char p[str1.length()];
// 
//    for (int i = 0; i < sizeof(p); i++) {
//        p[i] = str1[i];
//        cout << p[i];
//    }
//    for(int o=0; o<sizeof(p); o++){
//    	if(str1[o]=='-'&&str1[o+1]==' '||str1[o+2]=='(')
//    	p[o]='';
//	}
    return 0;
}
