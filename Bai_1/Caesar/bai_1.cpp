#include <bits/stdc++.h>
using namespace std;

string caesarEncrypt(const string& text, int k) {
    string res;
    for(char c: text) {
        if(isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            res.push_back(char((c - base + k % 26 + 26) % 26 + base));
        } else res.push_back(c);
    }
    return res;
}

string caesarDecrypt(const string& text, int k) {
    return caesarEncrypt(text, (26 - (k%26)) % 26);
}

int main(){
    string s;
    cout << "Input text: ";
    getline(cin, s);
    int k;
    cout << "Key k (0-25): "; cin >> k;
    string enc = caesarEncrypt(s, k);
    string dec = caesarDecrypt(enc, k);
    cout << "Encrypted: " << enc << "\n";
    cout << "Decrypted: " << dec << "\n";
    return 0;
}
