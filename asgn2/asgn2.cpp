#include<iostream>
using namespace std;

class student
{
    int roll_num = 21200;
    string  name, surname;
    string  contact_no, class1,division, DOB, driving_lic, bld_grp;
    static int count;    // static var for counting number of students
   
    string address[6];
    string questions[6] = {"Flat number : ", "Society name (one word) : ", "Landmark : ", "Locality : ", "City : ", "Pincode : "  };
       
       public: 

       student()        // constructor 
        {
            count ++;
            cout << "Enter name and surname of student : " << endl;
            cin >>  name >> surname;
            cout << "Enter DOB : dd/mm/yyyy" << endl;
            cin >> DOB;
            class1 = "SE";
            division = 2;
            roll_num += count;

            cout << "\n \n"; 
        }

        ~student()      // destructor
        {
            cout <<"Students left : " <<count << endl;
            count --;
        }

        void accept_info();
        void display();
        int show_RN()
        {
            return  roll_num;
        }
};

int student :: count = 0;

void student :: accept_info()
{
    cout << "======================================" << endl;

    cout << "KINDLY ENTER THE FOLLOWING DETAILS :-" << endl;
           
    cout << "Contact number --> " << endl;
    cin >> contact_no;
           
    cout << "Driving liscence number -->" << endl;
    cin >> driving_lic;
           
    cout << "Blood group " << endl;
    cin >> bld_grp;
           
    cout << "Address(6 words or less) : " << flush;
    for(int i =0; i<6; i++ )
    {
    cout << questions[i] << flush;
    cin >> address[i];
    }

    cout << "======================================" << endl;
}

void student :: display()
{
cout << "\n \n \n ";
cout << "======================================" << endl;
cout <<"Roll number " << roll_num << "'s details are as follows : " << endl;

cout << "NAME : " << name << " " << surname << endl;           
cout << " DOB         Class    Division   Roll number    Contact number    Blood group   Driving liscence number " << endl;
cout << DOB << "\t " << class1 << "\t"  <<  division << "\t \t" << roll_num  << "\t   " << contact_no  << "\t       " << bld_grp << "\t        " << driving_lic << endl;
           
cout << "Address : " << endl;
for(int j = 0; j < 6; j++)
{
    cout << address[j] << " ";
}
cout << endl;
cout << "======================================" << endl;

}



int main()
{
    int n;
    cout << "Enter the number of students : " << endl;
    cin >> n;
    cout << endl;

    student *stu = new student[n];  // Object array created dynamically
  
    for(int i = 0; i<n; i++)
    {
        cout << "Student " << i+1 << " " << stu[i].show_RN() << " : " <<endl;
        cout << "====================================== \n" << endl;    

        stu[i].accept_info();
        // stu ->accept_info();  // He kela tar error dakhavtay

        // stu -> accept_info();

        cout << "\n ";
    }

    char optn;

    cout << "Which students information is to be shown : " << endl;
    cout << "If a particular student's data is to be accessed enter P " << endl;
    cout << "Enter A for all students." << endl;
    cout << "\n \n";

    char choice = ' ';

    do
    {
        cout << "Enter your choice : ";
        cin >> optn;
        
        switch(optn)
        {
            case 'E':

            case 'P':
                int num;
                cout << "Enter student number, eg 1." << endl;
                cin >> num;
                stu[num-1].display();
                break;
            
            case 'A':
                for(int i = 0; i < n; i++)
                {
                    stu[i].display();
                    
                }
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }

        cout << "Do you want to continue [y/n] : " ;
        cin >> choice;


    }while(choice == 'y');

    delete []stu;

    return 0;
}