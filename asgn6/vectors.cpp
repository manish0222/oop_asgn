// write a c++ program using STL for sorting and searching user defined records
// such as name, DOB, mobile number, etc using vector container

#include <iostream>  //standard input output stream header file
#include <algorithm> //The STL algorithms are generic because they can operate on a variety of data structures
#include <vector> //The header file for the STL vector library is
using namespace std;
class data{
public:
    string fname,lname;
    string dob;
    string mobilenum;
    long long int adhar_no;
};
vector<data> obj;
void enterData(){
    data temp;
    cout<<"enter name ";cin>>temp.fname;
    cout<<"enter last name ";cin>>temp.lname;
    cout<<"\nenter date of birth ";cin>>temp.dob;
    cout<<"enter mobilenum ";cin>>temp.mobilenum;

    cout<<"enter adhar no ";cin>>temp.adhar_no;
    obj.push_back(temp);
}

void display(data o){
    cout<<"\n=======================================\n";
    cout<<"name "<<o.fname<<" "<<o.lname<<endl;
    cout<<"date of birth "<<o.dob<<endl;
    cout<<"mobilenum "<<o.mobilenum<<endl;
    cout<<"adhar no "<<o.adhar_no<<endl;
    cout<<"=======================================\n";
}

void displayAll(){
    try{
        if(obj.empty()){
            throw 'a';
        }
        // for(int i=0;i<obj.size();i++){
        //     display(obj[i]);
        // }
        for_each(obj.begin(),obj.end(),[](const data n){
            display(n);
        });
    }
    catch(char ){cout<<"vector is empty enter data \n";}
   
}
void displayIndividual(){
    try{
        if(obj.empty()){
            throw 'a';
        }
            cout<<"enter name ";
            string nameToFind;cin>>nameToFind;
            for(int i=0;i<obj.size();i++){
            if(obj[i].fname==nameToFind){
                display(obj[i]);
            }
        }
    }
    catch(char ){cout<<"vector is empty enter data \n";}
   
}
void searchdata(){
    try{
        if(obj.empty()){
            throw 'a';
        }
        cout<<"enter 1)find name\t 2)find by adhar number ";
        int n;cin>>n;
        if(n==1){
            string nam;cin>>nam;
            for(int i=0;i<obj.size();i++){
                if(nam==obj[i].fname){
                    cout<<"\t\t   FOUND \n";
                    display(obj[i]);
                }
            }
        }
        else{
            long long int k;cin>>k;
            for(int i=0;i<obj.size();i++){
                if(k==obj[i].adhar_no){
                    cout<<"\t\t   FOUND \n";
                    display(obj[i]);
                }
            }
        }
    }
    catch(char ){cout<<"vector is empty enter data \n";}

}
bool compareAdhar(data a,data b){
    if(a.adhar_no>b.adhar_no) return 1;
}
bool compareName(data a,data b){
    if(a.fname<b.fname) return 1;
}
void sort(){
    try{
        if(obj.empty()){
            throw 'a';
        }
        cout<<"sort by 1)name\t\t 2)adhar num ";
        int n;cin>>n;
        // if(n==1){
        //     for(int i=0;i<obj.size()-1;i++){
        //         for(int j=i+1;j<obj.size();j++){
        //             if(obj[i].fname > obj[j].fname){
        //                 data bn = obj[i];
        //                 obj[i]=obj[j];
        //                 obj[j]=bn;
        //             }
        //         }
        //     }
        // }
        // else{
        //     for(int i=0;i<obj.size()-1;i++){
        //         for(int j=i+1;j<obj.size();j++){
        //             if(obj[i].adhar_no > obj[j].adhar_no){
        //                 data bn = obj[i];
        //                 obj[i]=obj[j];
        //                 obj[j]=bn;
        //             }
        //         }
        //     }
        // }
        if(n==2) sort(obj.begin(),obj.end(),compareAdhar);
        else{
            sort(obj.begin(),obj.end(),compareName);
        }
    }
    catch(char ){cout<<"vector is empty enter data \n";}
}
int main(){
    while(true){
        cout<<"\n1)enter data\n2)display data\n3)display all data\n4)search\n5)sort data\n6)exit\t";
        int num;cin>>num;
        if(num==1){
            enterData();
        }
        else if(num==2){
            displayIndividual();
        }
        else if(num==3){
            displayAll();
        }
        else if(num==4){
            searchdata();
        }
        else if(num==5){
            sort();
        }
        else {
            cout<<"exited\n";
            break;
        }
    }
return 0;
}