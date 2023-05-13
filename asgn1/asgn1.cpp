#include<iostream>
using namespace std;
class complex{
    public:
    int real,imaginary;
    complex(){
        real=0;
        imaginary=0;
        // cout<<"complex number is 0+0i"<<endl;
    }
    complex(int a,int b){
        real=a;
        imaginary=b;
    }

    complex operator+(complex b){
        complex temp;
        temp.real=real+b.real;
        temp.imaginary=imaginary+b.imaginary;
        return temp;
    }
    complex operator*(complex b){
        complex temp;
        temp.real=real*(b.real) - imaginary*(b.imaginary);
        temp.imaginary=real*(b.imaginary)+b.real*(imaginary);
        return temp;
    }
    friend ostream & operator<<(ostream &o,complex &c);
    friend istream & operator>>(istream &o,complex &c);
    friend complex call();   
};                                                           //class end

    ostream & operator<<(ostream &o,complex &c){
        if (c.imaginary>0){
            cout<<c.real<<"+"<<c.imaginary<<"i"<<endl;
        }
        else{
            cout<<c.real<<c.imaginary<<"i"<<endl;
        }
        return o;
    }

    istream & operator>>(istream &i,complex &c){
        int a,b;
        cout<<"enetr real no "<<endl;
        cin>>a;
        c.real=a;
        cout<<"enetr imaginary no "<<endl;
        cin>>b;
        c.imaginary=b;
        return i;
    }
int main(){
complex c1,c2,c3,c4;
cout<<"enter no\n";
cin>>c1;
cout<<c1;
cout<<"enter no ";
cin>>c2;
cout<<c2;
c3=c1+c2;
cout<<"sum is "<<c3<<endl;
c4=c1*c2;
cout<<"multiplication is "<<c4<<endl;
return 0;
}