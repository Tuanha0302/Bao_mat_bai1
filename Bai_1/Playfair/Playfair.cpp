#include <bits/stdc++.h>
using namespace std;

string prepareKey(const string& key){
    string s;
    for(char c: key){
        if(isalpha(c)){
            char ch = toupper(c);
            if(ch=='J') ch='I';
            if(s.find(ch)==string::npos) s.push_back(ch);
        }
    }
    for(char c='A'; c<='Z'; c++){
        if(c=='J') continue;
        if(s.find(c)==string::npos) s.push_back(c);
    }
    return s.substr(0,25);
}

vector<vector<char>> makeSquare(const string& key){
    string sq = prepareKey(key);
    vector<vector<char>> m(5, vector<char>(5));
    for(int i=0;i<25;i++) m[i/5][i%5] = sq[i];
    return m;
}

pair<int,int> findPos(const vector<vector<char>>& m, char ch){
    for(int r=0;r<5;r++) for(int c=0;c<5;c++) if(m[r][c]==ch) return {r,c};
    return {-1,-1};
}

string prepareText(const string& text){
    string s;
    for(char c: text) if(isalpha(c)) { char ch = toupper(c); if(ch=='J') ch='I'; s.push_back(ch); }
    string res;
    for(size_t i=0;i<s.size();){
        char a = s[i];
        char b = (i+1 < s.size())? s[i+1] : 'X';
        if(a==b){
            res.push_back(a);
            res.push_back('X');
            i++;
        } else {
            res.push_back(a);
            res.push_back(b);
            i += 2;
        }
    }
    if(res.size()%2==1) res.push_back('X');
    return res;
}

string playfairEncrypt(const string& text, const string& key){
    auto m = makeSquare(key);
    string pt = prepareText(text);
    string out;
    for(size_t i=0;i<pt.size(); i+=2){
        char a=pt[i], b=pt[i+1];
        auto pa=findPos(m,a), pb=findPos(m,b);
        if(pa.first==pb.first){ // same row
            out.push_back( m[pa.first][ (pa.second+1)%5 ] );
            out.push_back( m[pb.first][ (pb.second+1)%5 ] );
        } else if(pa.second==pb.second){ // same col
            out.push_back( m[(pa.first+1)%5][pa.second] );
            out.push_back( m[(pb.first+1)%5][pb.second] );
        } else {
            out.push_back( m[pa.first][pb.second] );
            out.push_back( m[pb.first][pa.second] );
        }
    }
    return out;
}

string playfairDecrypt(const string& text, const string& key){
    auto m = makeSquare(key);
    string out;
    for(size_t i=0;i<text.size(); i+=2){
        char a=text[i], b=text[i+1];
        auto pa=findPos(m,a), pb=findPos(m,b);
        if(pa.first==pb.first){
            out.push_back( m[pa.first][ (pa.second+4)%5 ] );
            out.push_back( m[pb.first][ (pb.second+4)%5 ] );
        } else if(pa.second==pb.second){
            out.push_back( m[(pa.first+4)%5][pa.second] );
            out.push_back( m[(pb.first+4)%5][pb.second] );
        } else {
            out.push_back( m[pa.first][pb.second] );
            out.push_back( m[pb.first][pa.second] );
        }
    }
    return out;
}

int main(){
    cout<<"Playfair Cipher\n";
    string mode; cout<<"enc/dec: "; cin>>mode; cin.ignore();
    if(mode=="enc"){
        string pt, key;
        cout<<"Plaintext: "; getline(cin, pt);
        cout<<"Key: "; getline(cin, key);
        cout<<"Cipher: "<<playfairEncrypt(pt, key)<<"\n";
    } else {
        string ct, key;
        cout<<"Ciphertext: "; getline(cin, ct);
        cout<<"Key: "; getline(cin, key);
        cout<<"Plain (raw pairs): "<<playfairDecrypt(ct, key)<<"\n";
    }
    return 0;
}
