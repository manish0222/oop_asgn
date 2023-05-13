#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    cout<<"enter file name ";
    string t;cin>>t;
    fstream ofs(t,ios::trunc | ios::in | ios::out);
    cout<<"enter name ";
    string name;cin>>name;
    ofs<<"added name "<<name<<endl;
    if(ofs){
        cout<<"file open "<<endl;
    }
    ofs.close();

    fstream ifs("myfile0311.txt" ,ios::in);
    char u;
    while(!ifs.eof()){
        ifs>>u;
        cout<<u;
        if(u==_SPACE){
            cout<<" ";
        }
    }cout<<endl;
    ifs.close();
    
    fstream edf(t,ios::in | ios::ate);
    cout<<"enter location to change ";
    int n;cin>>n;
    edf.seekp(n,ios::beg);
    cout<<"enter new string ";
    string add;cin>>add;
    edf<<add;
    edf.seekp(n,ios::beg);
    edf.close();
    
return 0;
}