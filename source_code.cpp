#include<bits/stdc++.h>
#define for_(i, b, e) for(int i = b; i <= e; i++)
#include "matrix.h"
#include "mod_file.h"
using namespace std;

fstream fs;
int n;
vector<string> l;

void check_file_status();
void bai1();
void bai2();

int main(){
    fs.open("D:\\vscode\\multiple_matrix\\input", fstream::in|fstream::out );
    check_file_status(fs);
    bai1();
    bai2();
    bai1();
    fs.close();
    system("pause");
return 0;
}

void check_file_status(){
    if(!fs.is_open()){
        cout << "Cannot open this file!\n";
        exit(0);
    }
}

void bai1(){
    system("cls");
    fs.seekg(0, fs.beg);
    //get a list of student
    n = fs.get() - '0'; fs.ignore(1);
    l.resize(n);
    for_(i, 0, n-1){
        getline(fs, l.at(i));
    }
    for(auto name:l) cout << name << endl;
    system("pause");
}

void bai2(){
    system("cls");
    cout << "Enter a name of new student:\n";
    string tmp; getline(cin, tmp); 
    fs.seekg(0, fs.beg);
    fs << 5;
    fs.seekg(0, fs.end);
    fs << endl << tmp;
    cout << "insert student success\n";
    system("pause");
}
