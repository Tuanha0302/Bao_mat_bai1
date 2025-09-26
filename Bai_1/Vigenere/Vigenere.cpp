#include <bits/stdc++.h>
using namespace std;

string normalizeKey(const string& key, int n){
    string k;
    for(char c: key) if(isalpha(c)) k.push_back(tolower(c));
    if(k.empty()) return string(n,'a');
    string res;
    for(int i=0;i<n;i++) res.push_back(k[i % k.size()]);
    return res;
}

string vigenereEncrypt(const string& text, const string& key){
    string k = normalizeKey(key, text.size());
    string r;
    int j=0;
    for(char c: text){
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int p = c - base;
            int shift = k[j] - 'a';
            r.push_back(char((p + shift) % 26 + base));
            j++;
        } else r.push_back(c);
    }
    return r;
}

string vigenereDecrypt(const string& text, const string& key){
    string k = normalizeKey(key, text.size());
    string r;
    int j=0;
    for(char c: text){
        if(isalpha(c)){
            char base = isupper(c)?'A':'a';
            int y = c - base;
            int shift = k[j] - 'a';
            r.push_back(char((y - shift + 26) % 26 + base));
            j++;
        } else r.push_back(c);
    }
    return r;
}

int main(){
    string mode; cout<<"enc/dec: "; cin>>mode; cin.ignore();
    if(mode=="enc"){
        string pt, key;
        cout<<"Plaintext: "; getline(cin, pt);
        cout<<"Key: "; getline(cin, key);
        cout<<"Cipher: "<<vigenereEncrypt(pt,key)<<"\n";
    } else {
        string ct, key;
        cout<<"Ciphertext: "; getline(cin, ct);
        cout<<"Key: "; getline(cin, key);
        cout<<"Plain: "<<vigenereDecrypt(ct,key)<<"\n";
    }
    return 0;
}
