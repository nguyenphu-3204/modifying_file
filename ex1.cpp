#include<bits/stdc++.h>
#define for_(i, b, e) for(int i=b; i<=e; i++)
using namespace std;

fstream fs;
int n;
vector< string > l;
//Sets the position of the next character to be extracted from begin of the input stream.
void mv_beg(long off = 0){
    fs.seekg(off, ios_base::beg);
}

void check_status_file(){
    if( fs.is_open() ) return;
    cout << "Cannot opent file!\n";
    exit(0);
}


int main(){
    fs.open("list_student.txt", ios_base::in | ios_base::out);
    check_status_file();
    mv_beg();
    n = fs.get() - '0'; //read n
    fs.ignore(1);      //ignore 1 character
    for_(i, 0, n-1){   //read n students
        char s[254];
        fs.getline(s, 254);
        l.push_back(s);
    }
    for(auto name:l) cout << name << endl;
return 0;
}
