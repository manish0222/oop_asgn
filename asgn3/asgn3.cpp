// Imagine a publishing company which does marketing for book and audio cassette
// versions. Create a class publication that stores the title (a string) and price (type float) of
// a publication.
// From this class derive two classes: book, which adds a page count (type int), and tape,
// which adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape classes, allows user to enter data
// and displays the data members. If an exception is caught, replace all the data member
// values with zero values
#include <iostream>
#include<string>
using namespace std;
class publication
{
    protected:
    string title;
    float price;
   
    public:
    publication()
    {  title="";
        price=0.0;    
    }
    publication(string t,float p)
    {
        title=t;
        if(p>0){price=p;}
        // else{price=0;}
        try{
            if(p<0){throw p;}
        }
        catch(float p){cout<<"exception caught ";price=0;}
    }           
};

class book : public publication
{
    int pagecount;
    public:
    book()
    {
        pagecount=0;
        
    }
    //After : base class constructor is called
    void getdata(string t,float p,int pc)
    {   
        title=t;
        price=p;
        if(pc>=0){pagecount=pc;} 
        // else{"pagecount not valid\n";pagecount=0;}
        try{
            if(p<0){throw p;}
        }
        catch(float p){cout<<"exception caught ";price=0;}

        try{
            if(pc<0){throw pc;}
        }
        catch(int p){cout<<"exception caught ";pagecount=0;}
    }
 
    void display()
    {
        cout<<"title :"<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Pagecount :"<<pagecount<<endl;     
    }      
};

 class CD : public publication
{
        float time;
        public:
        CD()
        {
            time=0.0;
            
        }
        //After : base class constructor is called
        void getdata(string t,float p,float tim)
        {   
            title=t;
            price=p;
            if(tim>=0){time=tim;} 
            // else{cout<<"time not valid\n";time = 0;}
            try{
                if(tim<0){throw tim;cout<<"happy" ;}
            }
            catch(float tim){cout<<"exception caught\n";time=0;}
        }
     
    void display()
    {
        cout<<"title :"<<title<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"time in minutes :"<<time<<endl;     
    }
};
int main()
{
    
    
    // cout<<endl<<"Book data"<<endl;
    // book b("C++ fundamentals ",230,300);
    // b.display();
    // cout<<endl<<"CD Data"<<endl;
    // CD c("programming in c++ ",100,-120.5);
    // c.display();
    cout<<"enter number of books "<<endl;
    int k;cin>>k;
    book *bk=new book[k];
    for(int i=0;i<k;i++){
        string s;
        float p;
        int pc;
        cout<<"enter book name\n";cin>>s;
        cout<<"enter book price\n";cin>>p;
        cout<<"enter book pages\n";cin>>pc;
        (bk+i)->getdata(s,p,pc);
        cout<<"\n===================================\n";
    }
    cout<<"enter number of tapes "<<endl;
    int x;cin>>x;
    CD *cd=new CD[x];
    for(int i=0;i<x;i++){
        string s;
        float p;
        int pc;
        cout<<"enter tape name\n";cin>>s;
        cout<<"enter tape price\n";cin>>p;
        cout<<"enter tape time\n";cin>>pc;
        (cd+i)->getdata(s,p,pc);
        cout<<"===================================\n";
    }
    int l;
    do{
        cout<<"choose option\n1)get book data\n2)get tape data\n3)getdata of all books\n4)getdata of all tapes\n";
        int j;cin>>j;
        if(j==1){
            cout<<"choose book number to find its information ";
            int u;cin>>u;
            cout<<"====================================================\n";
            bk[u-1].display();
            cout<<"====================================================\n";
        }
        else if(j==2){
            cout<<"choose tape number to find its information ";
            int u;cin>>u;
            cout<<"====================================================\n";
            cd[u-1].display();
            cout<<"====================================================\n";
        }
        else if(j==3){
            for(int i=0;i<k;i++){
                cout<<"====================================================\n";
                (*(bk+i)).display();
                cout<<"====================================================\n";
            }
        }
        else if(j==4){
            for(int i=0;i<x;i++){
                cout<<"====================================================\n";
                (*(cd+i)).display();
                cout<<"====================================================\n";
            }
        }
        else{
            cout<<"\nto continue presss 1\n";
            cin>>l;
        }
    }while(l=1);
    delete []bk;
    delete []cd;

    return 0;
}