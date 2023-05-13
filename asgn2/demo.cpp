#include <iostream>
using namespace std;
class Student{
public:
  char name[30],cls[10],division[10],dob[15],bloodgroup[10];
  static string college;
  int rollno;
  static int count; //declaring static member
public:
  friend class info;  //making friend class
   Student()
   {  
       char *name = new char[30];
       char *cls = new char[10];
       char *division = new char[10];
       char *dob = new char[15];
       char *bloodgroup = new char[10];
       rollno = count;
       count++;
   }
   Student(string n){
    college = n;
   }
   
   

//   static int getrollno()
//     {
//         cout << "Roll No : " << count << endl;
//     }
};

int Student::count = 1; //initializing the static member

class info{
    char telephone[15],address[20],drivinglicense[20];
public:
    info()
    {
        char *telephone = new char[15];
        char *address = new char[20];
        char *drivinglicense = new char[20];
    }
    void setdata(Student &s)
    {
        cout << "Enter the Name of the Student :" << endl;
        cin >> s.name;
        cout << "Enter the Class of the Student : " << endl;
        cin >> s.cls;
        cout << "Enter the Division of the Student :" << endl;
        cin >> s.division;
        cout << "Enter the Date of Birth the Student :" << endl;
        cin >> s.dob;
        cout << "Enter the Blood Group of the Student :" << endl;
        cin >> s.bloodgroup;
        cout << "Enter the telephone Number of the Student :" << endl;
        cin >> this->telephone;
        cout << "Enter the Address of the Student :" << endl;
        cin >> this->address;
        cout << "Enter the Driving License Number of the Student :" << endl;
        cin >> this->drivinglicense;
    }
    void getdata(Student &s){
    
        cout << "The Roll NO :" << s.rollno << endl;
        cout << "The Name of the Student : " << s.name << endl;
        cout << "The Class of the Student :" << s.cls << endl;
        cout << "The Division of the Student :" << s.division << endl;
        cout << "The Date of Birth of the Student :" << s.dob << endl;
        cout << "The college is "<<s.college;
        cout << "The Blood Group of the Student :" << s.bloodgroup << endl;
        cout << "The telephone Number of the Student :" << this->telephone << endl;
        cout << "The Address of the Student :" << this->address << endl;
        cout << "The Driving License Number of the Student :" << this->drivinglicense << endl;
       
    }

};  
int main()
{
    // info d,d1;
    // Student s,s1;
    // d.setdata(s);
    // d.getdata(s);
    // d1.setdata(s1);
    // d1.getdata(s1);
    Student e("PICT");
    Student d(e);
    int n; cout << "Enter the Number of Student :" << endl; cin >> n;
    try{
        if(n <= 0){
            throw 404;
        }
    }
    catch(int n){
       cout << "invalid Number " << n << endl;
    }
    info *arr = new info[n];
    Student *stu = new Student[n];
    for(int i = 0; i < n ; i++){
      arr[i].setdata(stu[i]);
    }
    for(int i = 0; i < n ; i++){
    cout << "---------------------------------------------------------" << endl;
       arr[i].getdata(stu[i]);
    cout << "-----------------------------------------------------------" << endl;
    }
    return 0;
}