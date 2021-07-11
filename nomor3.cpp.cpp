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

float hasilexp(string inputan)
{
    
    float hasil = 0;
    stack <float> s;
    stack<char>op;
    float tmp[100];
    float a = 0, b = 0;
    int c,d;
        for (int i = 0; i < (int)inputan.length(); i++)
        {   
            if(isdigit(inputan[i]))
            {
                tmp[i]=inputan[i];
            }
            else if(inputan[i]==' '){
                if (isdigit(inputan[i-1]) && isdigit(inputan[i-2])){
                    if(inputan[i-3]=='-' && isdigit(inputan[i+1])){
                       int king_tampung = (tmp[i-1]-48) + ((tmp[i-2]-48) * (10));
                s.push(king_tampung *(-1));
                
                    }
                    else if (isdigit(inputan[i-1]) && isdigit(inputan[i-2]) && isdigit(inputan[i-3]) && !isdigit(inputan[i-4])){
                    s.push((tmp[i-1]-48) + ((tmp[i-2]-48) * 10) + ((tmp[i-3]-48) * 100));
                   
                   }
                    else{
                        s.push((tmp[i-1]-48) + ((tmp[i-2]-48) * 10));
               
                    }
                
                }
                else if (isdigit(inputan[i-1]) && isdigit(inputan[i+1]) && !isdigit(inputan[i-2])){
                    if(inputan[i-2]=='-'){
                  
                    s.push((tmp[i-1]-48) * (-1));
                    }
                    else{
                   
                    s.push(tmp[i-1]-48);
                    }   
                }

                else if (operat(inputan[i-1]) && isdigit(inputan[i+1])){
                    tmp[i]=' ';
             
                }
                else if (operat(inputan[i-1])&&inputan[i-2]==' '){
                    if(operat(inputan[i+1])){
                       tmp[i]=' '; 
                      
                    }
                    else{
                    op.push(tmp[i-1]);
                    
                    }
                    
                }
                else if (operat(inputan[i+1])&&isdigit(inputan[i-1])){
                    s.push(tmp[i-1]-48);
                }

            }
            else if(inputan[i]=='+'||inputan[i]=='-'||inputan[i]=='*'||inputan[i]=='/')
            {
                if(s.empty()){
                }
                else if (s.size()==1){
                   a = s.top() * 1.0;
                   s.pop(); 
                   b = 0;
                   if(inputan[i]=='+'){
                    s.push(b+a);
                }
                   if(inputan[i]=='-'){
                    s.push(b-a);
                }
                
                }
                else{
                a = s.top() * 1.0;
                s.pop();
                b = s.top() * 1.0;
                s.pop();
                if(inputan[i]=='+'){
                    s.push(b+a);
                }
                if(inputan[i]=='-'){
                    s.push(b-a);
                }
                if(inputan[i]=='*'){
                    s.push(b*a);
                }
                if(inputan[i]=='/'){
                    s.push((b/a));
                }
            }
        }
        else if(inputan[i]=='%'){
                c = s.top();
                s.pop();
                d = s.top();
                s.pop();
                s.push((d % c));
        }
        }
    hasil = s.top();
    s.pop();
    return hasil;
}
int main(){
    string string1,string2,hasil,tampung; 
    getline(cin,string1);
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
                string2 += " ";
            }
            else if (string1[i] == '-' && string1[i - 2] != ')' && string1[i - 1] != ')' && string1[i + 1] == '(' && !(isdigit(string1[3 - 2])))
            {
                string2 += "1 * ";
            }
            else if (i == ((int)string1.length()) - 1)
            {
                string2 += " ";
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
                tampung+="";
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
    cout<<hasilexp(tampung);
    return 0;
}