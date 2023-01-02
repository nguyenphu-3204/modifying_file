/*
Ở phiên bản này mình dùng get_name() - hàm tự viết thay cho fs.getline()
để tường minh hơn, tuy nhiên ở những bài tập sau mình sẽ dùng hàm có sẵn.
Thứ hai, trong biểu diễn chuỗi ta có thể dùng mảng char và kiểu dữ liệu string
NHƯNG fs.getline() không hỗ trợ string.c_str() !!!!
*/
#include<bits/stdc++.h>
#define for_(i, b, e) for(int i=b; i<=e; i++)
using namespace std;

fstream fs;
int n;
vector< string > l;
//Sets the position of the next character to be extracted from begin of the input stream.
void mv_beg(long off = 0){ fs.seekg(off, ios_base::beg); }
//Sets the position of the next character to be extracted from end of the input stream.
void mv_end(long off = 0){ fs.seekg(off, ios_base::end); }

void check_status_file(){
    if( fs.is_open() ) return;
    cout << "Cannot opent file!\n";
    exit(0);
}

// convert to lowercase letters
string convert_to_lowercase(string s){
    for(auto &c:s) if( 'A' <= c && c <= 'Z') c += ('a'-'A'); 
    return s;
}

//extract from current position, stop if '\n' of OEF
string get_name(){
    string tmp;
    for(char c = fs.get();  !fs.eof() && c != '\n'; c = fs.get()) tmp.push_back(c);
    return tmp;
}


int main(){
    fs.open("list_student.txt", ios_base::in | ios_base::out);
    check_status_file();
    mv_beg();
    n = fs.get() - '0'; //read n
    fs.ignore(1);      //ignore 1 character
    cout << "Enter keyword:\n";
    string key, new_val; 
    key = convert_to_lowercase(key);
    getline(cin, key);
    mv_beg(2);
    for_(i,0,n-1){
        string name = get_name();
        if( convert_to_lowercase(name).find(key) != -1 ) cout << name << endl;
    }
return 0;
} 
