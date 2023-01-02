#include<bits/stdc++.h>
#define for_(i, b, e) for(int i=b; i<=e; i++)
#define filename "list_student.txt"
#define read_ ios_base::in
#define wirte_ ios_base::out
#define fbegin ios_base::beg
#define fend ios_base::end
using namespace std;

fstream f;
int n;
vector< string > l;

void check_status_file(){
    if( f.is_open() )return;
    cout << "Cannot opent file!\n";
    exit(0);
}

// convert to lowercase letters
string lowercase_(string s){
    for(auto &c:s) if( 'A' <= c && c <= 'Z') c += ('a'-'A'); 
    return s;
}

void get_studentName(){
    l.resize(n, "");
    for_(i, 1, n-1) getline(f, l[i]);
    f.seekg(10, fend);
}

bool match_(string const &name, string const &key){
    return lowercase_(name).find(lowercase_(key)) != -1;
}
void find_and_replace(string const &key, string const &new_val){
    for(string &name : l){ 
        if( !match_(name, key) ) continue;
        name = new_val;
        return;
    }
    cout << "Modify file fail!\n";
    exit(0);
}

int main(){
    f.open(filename, wirte_|read_);
    //read n and n students
    f.seekg(0, f.beg); // set position <- fbegin
    n = f.get() - '0';  // read n
    f.ignore(1);     // skip '\0' character
    get_studentName(); //read n student name
    string key, new_val; 
    cout << "Enter current student's name:\n";               
    getline(cin, key);
    cout << "Enter new student's name:\n";     
    getline(cin, new_val);
    find_and_replace(key, new_val);

    //rewirte file
    truncate(filename, 1); //remove all characters in file
    f.clear();          // remove eof flag  :)))
    f.seekg(0, fbegin); // set pos = f.begin
    f.put(n+'0');
    for(auto name:l){
        f.put('\n');
        f.write(name.c_str(), name.size()); 
    } 
    cout << "Modify student success!\n";
    f.close();
return 0;
} 

/*
    //remove all characters in file
    truncate(filename, 0);
*/
