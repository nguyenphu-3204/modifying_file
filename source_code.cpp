#include<bits/stdc++.h>
#define for_(i, b, e) for(int i = b; i <= e; i++)
#include "matrix.h"
#include "mod_file.h"
using namespace std;

fstream fs;
int n;
vector<string> l;

void check_status_file();
void bai1();
void bai2();
void bai3();
void bai4();

int main(){
    fs.open("D:\\vscode\\multiple_matrix\\input", fstream::in|fstream::out );
    check_status_file();
    fs.clear();
    bai1();
    bai2();
    bai3();
    bai4();
    fs.close();
    system("pause");
return 0;
}

void check_status_file(){
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
    fs.seekg(0, fs.beg);
    cout << "Enter name of new student:\n";
    string tmp; getline(cin, tmp); 
    fs << 5;
    fs.seekg(0, fs.end);
    fs << endl << tmp;
    cout << "Insert student success!\n";
    system("pause");
}

void bai3(){
    bai1();
    system("cls");
    fs.seekg(0, fs.beg);
    cout << "Enter key: \n";
    string key; getline(cin, key);
    cout << "Result:\n";
    for(auto name:l){
        if( name.find(key) != -1 ) cout << name << endl;
    }

    system("pause");
}

void bai4(){
    bai1();
    system("cls");
    fs.seekg(0, fs.beg);
    cout << "Enter key: \n";
    string key; getline(cin, key);
    cout << "Enter new value: \n";
    string new_val; getline(cin, new_val);
    cout << "Result:\n";
    for(auto &name:l){
        int pos = name.find(key);
        if( pos != -1 ) cout << name << endl;
        name = new_val;
    }
    fs.seekg(fs.beg);
    fs << "hehe";
    system("pause");
}
