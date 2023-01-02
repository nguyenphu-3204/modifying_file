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
    cout << "Enter name of new student:\n";
    string new_val; 
    getline(cin, new_val);
    l.push_back(new_val);  n++;
    mv_beg();
    fs << char ('0' + n);
    mv_end();
    fs << endl << new_val;
    cout << "Import successed!\n";
return 0;
} 
