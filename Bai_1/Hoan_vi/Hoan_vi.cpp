#include <bits/stdc++.h>
using namespace std;

string permEncrypt(const string& text, const vector<int>& key) {
    int m = key.size();
    string padded = text;
    
    while (padded.size() % m != 0) padded.push_back('X');

    string res;
    for (int i = 0; i < (int)padded.size(); i += m) {
        string block = padded.substr(i, m);
        string newBlock(m, ' ');
        for (int j = 0; j < m; j++) {
            if (key[j] - 1 < (int)block.size())
                newBlock[j] = block[key[j] - 1];
        }
        res += newBlock;
    }
    return res;
}

string permDecrypt(const string& text, const vector<int>& key) {
    int m = key.size();
    string res;
    for (int i = 0; i < (int)text.size(); i += m) {
        string block = text.substr(i, m);
        string newBlock(m, ' ');
        for (int j = 0; j < m; j++) {
            if (key[j] - 1 < (int)block.size())
                newBlock[key[j] - 1] = block[j];
        }
        res += newBlock;
    }
    
    while (!res.empty() && res.back() == 'X') res.pop_back();
    return res;
}

int main() {
    cout << "Permutation Cipher\n";
    string mode;
    cout << "Choose (enc/dec): ";
    cin >> mode;
    cin.ignore();

    string text;
    cout << "Text: ";
    getline(cin, text);

    cout << "Key : ";
    string keyStr;
    getline(cin, keyStr);

    vector<int> key;
    stringstream ss(keyStr);
    string num;
    while (getline(ss, num, ',')) {
        key.push_back(stoi(num));
    }

    if (mode == "enc") {
        cout << "Cipher: " << permEncrypt(text, key) << "\n";
    } else {
        cout << "Plain: " << permDecrypt(text, key) << "\n";
    }

    return 0;
}
