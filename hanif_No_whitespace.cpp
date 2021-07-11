#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
bool operand(char op){
    if(op=='0'||op=='1'||op=='2'||op=='3'||op=='4'||op=='5'||op=='6'||op=='7'||op=='8'||op=='9'){
        return 1;
    }
    else{
        return 0;
    }
}
bool operat(char oper){
    if(oper=='+'||oper=='-'||oper=='*'||oper=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
int prioritas(char a){
    {
    if(a == '+' || a =='-')
    {
        return(1);
    }
 
    if(a == '*' || a =='/')
    {
        return(2);
    }
    return 0;
}
}

int main(){
    string str,str1,hasil; ///str==input, str1==operasikan
    getline(cin,str);
    char tmp;
    stack <char> st;
        for(int i=0;i<str.length();i++){
        if(isdigit(str[i])){
            str1+=str[i];
            if(!(isdigit(str[i+1]))){
                str1+=" ";
            }
        }else if(!(isdigit(str[i])) && str[i]!= ' '){
            str1+=str[i];
            if (i==0&&isdigit(str[i+1])&&str[i]=='-'){
                str1+="";
            }
            else if(str[i]=='-'&&str[i+1]=='('&&isdigit(str[i-2])){
                str1+="1 * ";
            }else if(str[i]=='-'&&isdigit(str[i+1])&&!(isdigit(str[i-1]))){
                str1+="1 * ";
            }
            else if(str[i]=='-'&&str[i-2]!=')'&&str[i-1]!=')'&&str[i+1]=='('&&!(isdigit(str[3-2]))){
                str1+="1 * ";
            }else if(i==(str.length())-1){
                str1+="";
            }
            else{
                str1+=" ";
            }
        }

    }
    for(int i=0;i<str1.length();i++){
        tmp=str1[i];
        if(isdigit(tmp)==true){
            hasil+=tmp;
        }
        if(tmp=='('){
            st.push('(');
        }
        if(tmp==')'){
            while(!(st.empty()) && st.top() != '('){
                hasil += st.top();
                st.pop();
            }
            st.pop();
        }if(operat(tmp)==true){
            if(st.empty() || st.top()=='('){
                st.push(tmp);
            }
            else{
                while(!(st.empty()) && st.top() != '(' && prioritas(str1[i])<=prioritas(st.top())){
                hasil += st.top();st.pop();
             
            }
            st.push(tmp);
            }
        } 
    }
    while(!(st.empty())){
        hasil+=st.top();
        st.pop();
    }
    cout<<hasil;
    return 0;
}
