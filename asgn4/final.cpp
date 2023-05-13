#include<iostream>
#include<fstream>
using namespace std;
class write{
public:
    write(){
        string s;
        fstream myfile;
        myfile.open("manish.txt",ios::ate | ios::out);
        if(!myfile)cout<<"file not open\n";
        else{
            cout<<"\nfile open\n";
            while(myfile){
                cout<<"enter ";
                getline(cin,s);
                if(s=="-1") break;
                myfile<<s;
            }
        }
        myfile.close();
    }
};
class read{
public:
    read(){
        string s;
        fstream myfile;
        myfile.open("manish.txt",ios::in);
        if(!myfile)cout<<"file not open\n";
        else{
            cout<<"\nfile open\n";
            while(myfile){
                getline(myfile,s);
                
                cout<<s<<endl;
                break;
            }
        }
        myfile.close();
    }
};
class edit{
public:
    edit(){
        string s;
        fstream myfile;
        myfile.open("manish.txt");                    //imp
        cout<<"enter position of pointer ";
        int pos;cin>>pos;
        myfile.seekp(pos,ios::beg);
        cout<<"position of pointer is  "<<myfile.tellp()<<endl;
        if(!myfile)cout<<"file not open\n";
        else{
            cout<<"file open\n";
            while(myfile){
                cout<<"enter ";
                getline(cin,s);             //imp cin,s
                if(s=="-1") break;
                myfile<<s;
            }
        }
        myfile.close();
    }
};
class fromdis{
public:
    fromdis(){
        string s;
        fstream myfile;
        myfile.open("manish.txt",ios::in);
        cout<<"enter position ";
        int pos;cin>>pos;
        myfile.seekp(pos,ios::beg);
        cout<<"position is "<<myfile.tellg()<<endl;
        while(true){
            char x;
           x=myfile.get();
           if(myfile.eof()) break;
           cout<<x;
        }
        myfile.close();
    }
};
int main()
{
    write a;
    read b;
    edit c;
    read d;
    fromdis f;
    read e;
return 0;
}
