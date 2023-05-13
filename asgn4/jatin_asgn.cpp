#include <iostream>
#include <fstream>
using namespace std;

class Write
{
public:
    Write()
    {
        string s;
        fstream myfile;
        myfile.open("oop.txt", ios::out | ios::app);

        if (!myfile)
            cout << "Error occured while creating the file";
       
        else
        {
            cout << "File created and data written in file\n";
            while (myfile)
            {
                cout << "Enter line:";
                getline(cin,s);
               
                if (s == "-1")
                    break;
                   
                myfile << s;
            }
            myfile.close();
        }
    }
};

class Read
{
public:
    Read()
    {
        string s;
        fstream myfile;
        myfile.open("oop.txt", ios::in);

        if (!myfile)
            cout << "File doesn't exist";

        else
        {
            while (myfile)
   {
                getline(myfile, s);
                cout << s << endl;
                break;
   }
        }
        myfile.close();
    }
};

class Overwrite
{
public:
    Overwrite()
    {
        string s;
        int pos;
        fstream myfile;

        cout << "Enter position where u want to overwrite:";
        cin >> pos;

        myfile.open("oop.txt");
        myfile.seekp(pos,ios::beg);
        cout << "Location of put pointer:" << myfile.tellp();
        while (myfile)
            {
                cout << "Enter line:";
                getline(cin,s);
               
                if (s == "-1")
                    break;
                   
                myfile << s;
            }
        myfile.close();
    }
};

class Overread
{
public:
    Overread()
    {
        int pos;
        string data;
        fstream myfile;

        cout << "Enter position where u want to overread:";
        cin >> pos;

        myfile.open("oop.txt", ios::in);
        myfile.seekg(pos,ios::beg);
        cout << "Location of put pointer:" << myfile.tellg() << endl;
        char x;
        while (true)
        {
            x = myfile.get();

            if (myfile.eof())
                break;
            cout << x;
        }

        myfile.close();
    }
};

int main()
{
    int num;
    string str;

    while (true)
    {
        cout << "1. Create and write data in file\n2. Read and display data in file\n3. Overwrite data in file\n4. Overread data in file";
        cout << "\nEnter your choice no:\n";
        cin >> num;

        if (num == 1)
            Write obj1;
           
        else if (num == 2)
            Read obj2;

        else if (num == 3)
            Overwrite obj3;

        else if (num == 4)
            Overread obj4;
       
        cout << "\ndo u want to perform more operations(y/n)\n";
        cin >> str;
        if (str == "n")
            break;
    }
    return 0;
}
