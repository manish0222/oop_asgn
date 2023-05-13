#include <iostream>
#include <fstream>
using namespace std;
int main()
{

    cout << "enter file name " << endl;
    string s;
    cin >> s;
    fstream ofs(s, ios::in | ios::out | ios::trunc);
    cout << "enter line " << endl;
    string line;
    getline(cin >> ws, line);
    ofs << line;
    ofs.seekp(0, ios::beg);



    // if(ofs.is_open()){cout<<"file not closed\n";}
    string u;
    while (!ofs.eof())
    {
        getline(ofs, u);
        cout << u;
    }
    cout << endl;
    ofs.close();


    
    int n=1;
    do{
        cout<<"chose following\n1)change data\n2)view data\n";
        int k;cin>>k;
        if(k==1){
            ofstream ifs;
            ifs.open(s, ios::in | ios::ate);
            ifs.seekp(0, ios::end);
            cout<<"change from index ";
            int t;cin>>t;
            ifs.seekp(t, ios::beg);
            cout << "enter new word ";
            string str1;
            cin >> str1;
            ifs << str1;
            ifs.seekp(0, ios::beg);
            ifs.close();
        }
        else{
            fstream ef(s,ios::in);
            string x;
            while (!ef.eof())
            {
                getline(ef, x);
                cout << x;
            }
            cout << endl;
            ef.close();
        }
        cout<<"continue by 1 ";
        int num;cin>>num;
        if(num==1){
            n=1;
        }
        else{
            n=2;
        }
    }while (n==1);


return 0;
}
