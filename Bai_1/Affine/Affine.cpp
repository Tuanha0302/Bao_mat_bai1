#include <bits/stdc++.h>
using namespace std;

int modInv(int a, int m) {
    a %= m;
    for(int x=1;x<m;x++) if((a*x)%m==1) return x;
    return -1;
}

string affineEncrypt(const string& s, int a, int b) {
    string r;
    for(char c: s){
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int x = c - base;
            r.push_back(char(( (a*x + b) %26 ) + base));
        } else r.push_back(c);
    }
    return r;
}

string affineDecrypt(const string& s, int a, int b){
    int inv = modInv(a,26);
    if(inv == -1) return "Error: a has no inverse mod 26.";
    string r;
    for(char c: s){
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int y = c - base;
            int x = (inv * ( (y - b + 26) % 26 )) % 26;
            r.push_back(char(x + base));
        } else r.push_back(c);
    }
    return r;
}

int main(){
    string text;
    cout<<"Input text: "; getline(cin, text);
    int a,b;
    cout<<"a (must be coprime with 26): "; cin>>a;
    cout<<"b (0-25): "; cin>>b;
    string enc = affineEncrypt(text,a,b);
    cout<<"Encrypted: "<<enc<<"\n";
    cout<<"Decrypted: "<<affineDecrypt(enc,a,b)<<"\n";
    return 0;
}
