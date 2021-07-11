#include<bits/stdc++.h>
using namespace std;
bool operat(char oper){
    if(oper=='+'||oper=='-'||oper=='*'||oper=='/' ||oper=='%'){
        return true;
    }
    else{
        return false;
    }
}
bool operand(char o){
    if(o =='0'||o =='1'||o =='2'||o =='3'||o =='4'||o =='5'||o =='6'||o =='7'||o =='8'||o =='9'){
        return true;
    }
    else{
        return false;
    }
}
int prioritas(char a){
    if (a == '*' || a == '/'){
        return 2;
    }
        
    if (a == '+' || a == '-'){
        return 3;
    }
    return 1;  
}

int main(){
    string string1,string2,hasil,lele; ///string1==input, string2==operasikan
    getline(cin,string1);// lele
    char tmp;
    stack <char> st;
    stack <char> evaluate;
        for (int i = 0; i <(int)string1.length(); i++)
    { //seleksi index string
        if (isdigit(string1[i]))
        {
            string2 += string1[i];
            if (!(isdigit(string1[i + 1])))
            {
                string2 += " ";
            }
        }
        else if (!(isdigit(string1[i])) && string1[i] != ' ')
        {
            string2 += string1[i];
            if (i == 0 && isdigit(string1[i + 1]) && string1[i] == '-')
            {
                string2 += "";
            }
            else if (string1[i] == '-' && string1[i + 1] == '(' && isdigit(string1[i - 2]))
            {
                string2 += "1 * ";
            }
            else if (string1[i] == '-' && isdigit(string1[i + 1]) && !(isdigit(string1[i - 1])))
            {
                string2 += "1 * ";
            }
            else if (string1[i] == '-' && string1[i - 2] != ')' && string1[i - 1] != ')' && string1[i + 1] == '(' && !(isdigit(string1[3 - 2])))
            {
                string2 += "1 * ";
            }
            else if (i == ((int)string1.length()) - 1)
            {
                string2 += "";
            }
            else
            {
                string2 += " ";
            }
        }
    }
    for(int i=0;i<(int)string2.length();i++){
        tmp = string2[i];
        if(operand(tmp)==true || tmp==' '){
            hasil+=tmp;
        }
        if(tmp=='-' && operand(string2[i+1])){
            hasil+=tmp;
        }
        if(operand(tmp) && string2[i-1]!=' '&& string2[i+1]==' '){
            hasil+="";
        }
        if(tmp=='('){
            st.push(tmp);
        }
        if(tmp==')'){
            while(!(st.empty()) && st.top() != '('){
                hasil += st.top();
                st.pop();
            }
            st.pop();
        } 
        if(operat(tmp) && (string2[i-1]==' ' && string2[i+1]==' ')){
            if(((st.empty() || st.top()=='('))){
                st.push(tmp);
            }
            else{
                while(!(st.empty()) && st.top() != '(' && prioritas(st.top())<=prioritas(tmp)){
                hasil += st.top();
                st.pop();
            }
            st.push(tmp);
            }
        }
    
}
    while(!(st.empty())){
        hasil+=st.top();
        st.pop();
    }
    for(int i=0;i<(int)hasil.length();i++){
        if(isdigit(hasil[i])){
            lele+=hasil[i];
            if(!(isdigit(hasil[i+1]))){
                lele+=" ";
            }
        }else if(!(isdigit(hasil[i])) && hasil[i]!= ' '){
            lele+=hasil[i];
            if (i==0&&isdigit(hasil[i+1])&&hasil[i]=='-'){
                lele+="";
            }
            else if(hasil[i]=='-'&&hasil[i+1]=='('&&isdigit(hasil[i-2])){
                lele+="1 * ";
            }else if(hasil[i]=='-'&&isdigit(hasil[i+1])&&!(isdigit(hasil[i-1]))){
                lele+="";
            }
            else if(hasil[i]=='-'&&hasil[i-2]!=')'&&hasil[i-1]!=')'&&hasil[i+1]=='('&&!(isdigit(hasil[3-2]))){
                lele+="1 * ";
            }else if(i==((int)hasil.length())-1){
                lele+="";
            }
            else{
                lele+=" ";
            }
        }

    }
    cout<<"Print : "<<lele<<endl;
    return 0;
}