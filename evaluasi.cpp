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
int hasilexp(string halo)
{
    
    int hasil = 0;
    stack <int> s;
    stack<char> spasi;
    stack<char>op;
    int tmp[100];
    
    int a = 0, b = 0,num;
        for (int i = 0; i < (int)halo.length(); i++)
        {
            
            if (isdigit(halo[i]))
            {
                tmp[i]=halo[i];
            }
            if(halo[i]==' '){
                if (isdigit(halo[i-1]) && isdigit(halo[i-2])){
                s.push((tmp[i-1]-48) + ((tmp[i-2]-48) * 10));
                cout<<"1"<<endl;
                }
                else if (isdigit(halo[i-1]) && halo[i-2]==' '){
                    s.push(tmp[i-1]-48);
                    cout << "2" << endl;
                }
                else if (operand(tmp[i-1])&&halo[i-2]==' '){
                    op.push(tmp[i-1]);
                    cout << "3" << endl;
                }
                else{
                    s.push(tmp[i-1]-48);
                    cout << "4" << endl;
                }

            }
            if(operat(halo[i]))
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                if(halo[i]=='+'){
                    s.push(b+a);
                }
                if(halo[i]=='-'){
                    s.push(b-a);
                }
                if(halo[i]=='*'){
                    s.push(b*a);
                }
                if(halo[i]=='/'){
                    s.push(b/a);
                }
            }
        }
    hasil = s.top();
    s.pop();
    return hasil;
}
int main(){
    string str,str1,hasil,lele; ///str==input, str1==operasikan
    getline(cin,str);// lele
    char tmp;
    stack <char> st;
    stack <char> evaluate;
        for (int i = 0; i <(int)str.length(); i++)
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
            else if (i == ((int)str.length()) - 1)
            {
                str1 += "";
            }
            else
            {
                str1 += " ";
            }
        }
    }
    for(int i=0;i<(int)str1.length();i++){
        tmp = str1[i];
        if(operand(tmp)==true || tmp==' '){
            hasil+=tmp;
        }
        if(tmp=='-' && operand(str1[i+1])){
            hasil+=tmp;
        }
        if(operand(tmp) && str1[i-1]!=' '&& str1[i+1]==' '){
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
        if(operat(tmp) && (str1[i-1]==' ' && str1[i+1]==' ')){
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
    cout<<lele<<endl;
    cout<<hasilexp(lele);
    return 0;
}