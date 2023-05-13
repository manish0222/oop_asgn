// Write a program in C++ to use map associative container.
// The keys will be the names of states, and the values will be the populations of the states.
// When the program runs, the user is prompted to type the name of a state. 
//The program then looks in the map, using
// the state name as an index, and returns the population of the state
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class data{
public:
    unordered_map<string,int> mp;
    data(){};
    void getdata(){
       
        cout<<"how many states do you want ";
        int k;cin>>k;
        while(k--){
            cout<<"enter state ";
            string s;cin>>s;
            cout<<"enter polpulation ";
            int n;cin>>n;
            mp[s]=n;
        }
    }
    void enter(){
        cout<<"enter state ";
        string str;cin>>str;
        cout<<"enter population ";
        long long int k;cin>>k;
        mp.insert({str,k});
    }
    void showall(){
        cout<<endl;
        cout<<"=======================================\n";
        cout<<"STATE "<<" "<<"POPULATION"<<endl;
        for(auto it=mp.begin();it!=mp.end();it++){
            cout<<it->first<<"\t\t"<<it->second<<endl;
        }cout<<"=======================================\n";
    }
    void display(){
        cout<<"enter state name ";
        string str;cin>>str;
        if(mp.count(str)==0){cout<<"\n\t\t\tstate not entered in data\n\n";}
        else{
            cout<<"\t\t\t   FOUND \n";
            cout<<"\n"<<" "<<str<<" population is "<<mp[str]<<"\n\n";
           
        }
    }
};
int main() {
    data obj;
   
    while(true){
        cout<<"1)enter data of states\n2)display data\n3)display all\n4)append\n5)end \t";
        int k;cin>>k;
        if(k==1){
            obj.getdata();
        }
        else if(k==2){
            obj.display();
        }
        else if(k==3){
            obj.showall();
        }
        else if(k==4){
            obj.enter();
        }
        else{
            cout<<"program ended ";
            break;
        }
    }
    return 0;
}