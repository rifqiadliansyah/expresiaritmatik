/* 1.Rifqi Adliansyah - 2017051003 
   2.M Hanif Pratama - 2017051040 
   3.Yogi Andaru - 2017051062
   Kelas B */
#include<bits/stdc++.h>
using namespace std;
bool operat(char oper){
    if(oper=='+'||oper=='-'||oper=='*'||oper=='/'){
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
    if (a == '*' || a == '/')
        return 1;
    else if (a == '+' || a == '-')
        return 2;
}

int main(){
    string str,str1,hasil,tampung; ///str==input, str1==operasikan
    getline(cin,str);
    char tmp;
    stack <char> st;
    stack <char> min;
        for (int i = 0; i < str.length(); i++)
    { //seleksi index string
        if (isdigit(str[i]))
        {
            str1 += str[i];
            if (!(isdigit(str[i + 1])))
            {
                str1 += " ";
            }
        }
        else if (!(isdigit(str[i])) && str[i] != ' ')
        {
            str1 += str[i];
            if (i == 0 && isdigit(str[i + 1]) && str[i] == '-')
            {
                str1 += "";
            }
            else if (str[i] == '-' && str[i + 1] == '(' && isdigit(str[i - 2]))
            {
                str1 += "1 * ";
            }
            else if (str[i] == '-' && isdigit(str[i + 1]) && !(isdigit(str[i - 1])))
            {
                str1 += "1 * ";
            }
            else if (str[i] == '-' && str[i - 2] != ')' && str[i - 1] != ')' && str[i + 1] == '(' && !(isdigit(str[3 - 2])))
            {
                str1 += "1 * ";
            }
            else if (i == (str.length()) - 1)
            {
                str1 += "";
            }
            else
            {
                str1 += " ";
            }
        }
    }
    cout<<str1<<endl;
    for(int i=0;i<(int)str1.length();i++){
        tmp = str1[i];
        if(operand(tmp)==true || tmp==' ' || tmp=='%'){
            hasil+=tmp;
        }
        if(tmp=='-' && operand(str1[i+1])){
            hasil+=tmp;
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
        if(operat(tmp)){
            if((st.empty() || st.top()=='(') && str1[i+1]==' '){
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
            tampung+=hasil[i];
            if(!(isdigit(hasil[i+1]))){
                tampung+=" ";
            }
        }else if(!(isdigit(hasil[i])) && hasil[i]!= ' '){
            tampung+=hasil[i];
            if (i==0&&isdigit(hasil[i+1])&&hasil[i]=='-'){
                tampung+="";
            }
            else if(hasil[i]=='-'&&hasil[i+1]=='('&&isdigit(hasil[i-2])){
                tampung+="1 * ";
            }else if(hasil[i]=='-'&&isdigit(hasil[i+1])&&!(isdigit(hasil[i-1]))){
                tampung+="1 ";
            }
            else if(hasil[i]=='-'&&hasil[i-2]!=')'&&hasil[i-1]!=')'&&hasil[i+1]=='('&&!(isdigit(hasil[3-2]))){
                tampung+="1 * ";
            }else if(i==((int)hasil.length())-1){
                tampung+="";
            }
            else{
                tampung+=" ";
            }
        }

    }
    cout<<hasil<<endl;
    cout<<tampung<<endl;
    return 0;
}
