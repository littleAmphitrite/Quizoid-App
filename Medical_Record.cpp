#include <fstream>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include<windows.h>
#include<time.h>
using namespace std;

//student class.
class student
{
public:
    char name[100];
    char address[1000];
    char rollno[10];
    char contactno[13];
    char branch[100];
    int year;
    char disease[100];
    char doctorsName[80];
    int noOfMedicines;
    char medicinesPrescribed[100][100];
    char delivered[5];
    char dateOfarrival[15];
};

// Employee class
class employee
{
public:
    char name[100];
    char address[1000];
    char empid[10];
    char contactno[13];
    char department[100];
    char dateofjoining[15];
    char disease[100];
    char doctorsName[80];
    int noOfMedicines;
    char medicinesPrescribed[100][100];
    char delivered[5];
    char dateOfarrival[15];
};

// Function to load the database management.
void loading()
{
    srand(time(NULL));
    cout << endl << endl << endl;
    cout.width(40);
    for(int i=0; i<50; i++)
    {
        int r=rand()% 500;
        cout << (char)219;
        if(i<25)
            Sleep(r/7);
        else if(i>=25 && i<35)
            Sleep(r/11);
        else if(i>=35 && i<40)
            Sleep(r/3);
        else if(i>=40)
            Sleep(r/9);
    }
    system("cls");
}

// Adding a record in the database.
void addpatient()
{
    system("cls");
    cout<<endl;
    cout<<"Choose patient's category: "<<endl<<"1. STUDENT"<<endl<<"2. STAFF"<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"Enter student's details:- "<<endl;
        student s;
        int flag=0;
        cout<<"Name: ";
        cin.get();
        cin.getline(s.name,100);

        cout<<"Roll No: ";
        cin.getline(s.rollno,100);
        student s1;
        ifstream in;
        in.open("student1.txt");

        if(!in.is_open())
        {

        }
        else
        {
            while(!in.eof())
            {
                in.read((char *) &s1, sizeof(s1));
                if(strcmp(s1.rollno,s.rollno)==0)
                {
                    cout<<"Patient already exists in the database. Please enter the check-up details."<<endl<<endl;
                    strcpy(s.contactno,s1.contactno);
                    strcpy(s.address,s1.address);
                    strcpy(s.branch,s1.branch);
                    s.year=s1.year;
                    cout<<"Problem/Disease: ";
                    cin.getline(s.disease,100);
                    cout<<"Doctor's Name(consulting doctor for that visit) : ";
                    cin.getline(s.doctorsName,80);
                    cout<<"Number of medicines prescibed: ";
                    cin>>s.noOfMedicines;
                    cin.get();
                    for(int i=1; i<=s.noOfMedicines; i++)
                    {
                        cout<<i<<". ";
                        cin.getline(s.medicinesPrescribed[i-1],100);
                    }
                    cout<<"Delivered(Yes/No): ";
                    cin.getline(s.delivered,5);
                    cout<<"Date of visit/checkup: ";
                    cin.getline(s.dateOfarrival,15);

                    flag=1;
                    break;

                }
            }

            in.close();
        }
        if(flag==1)
        {
            char ch;
            fstream out;
            out.open("student1.txt",ios::app);
            out.write((char*) &s, sizeof(s));
            {
                cout<<"Record inserted"<<endl;
            }

            out.close();
        }
        else
        {
            cout<<"Address: ";
            cin.getline(s.address,1000);
            cout<<"Contact Number: ";
            cin>>s.contactno;
            cout<<"Branch: ";
            cin.get();
            cin.getline(s.branch,100);
            cout<<"Year: ";
            cin>>s.year;
            cin.get();
            cout<<"Problem/Disease: ";
            cin.getline(s.disease,100);
            cout<<"Doctor's Name(consulting doctor for that visit) : ";
            cin.getline(s.doctorsName,80);
            cout<<"Number of medicines prescibed: ";
            cin>>s.noOfMedicines;
            cin.get();
            for(int i=1; i<=s.noOfMedicines; i++)
            {
                cout<<i<<". ";
                cin.getline(s.medicinesPrescribed[i-1],100);
            }
            cout<<"Delivered(Yes/No): ";
            cin.getline(s.delivered,5);
            cout<<"Date of visit/checkup: ";
            cin.getline(s.dateOfarrival,15);

            char ch;
            ofstream out;
            out.open("student1.txt",ios::app);
            if(!out.write((char*) &s, sizeof(s)))
            {
                cout<<"error in writing a record..! "<<endl;
            }
            else
            {
                cout<<"Record inserted"<<endl;
            }

            out.close();
        }

    }
    else if(n==2)
    {
        cout<<"Enter employee's details:- "<<endl;
        employee e;
        cout<<"Name: ";
        cin.get();
        cin.getline(e.name,100);
        cout<<"Emp ID: ";
        cin.getline(e.empid,10);
        employee e1;
        ifstream in1;
        in1.open("employee1.txt");
        if(in1.is_open())
        {
            while(!in1.eof())
            {
                in1.read((char *) &e1, sizeof(e1));
                if(strcmp(e1.empid,e.empid)==0)
                {
                    cout<<"Patient already exists in the database. Please enter the check-up details."<<endl<<endl;
                    strcpy(e.contactno,e1.contactno);
                    strcpy(e.address,e1.address);
                    strcpy(e.department,e1.department);
                    strcpy(e.dateofjoining,e1.dateofjoining);
                    cout<<"Problem/Disease: ";
                    cin.getline(e.disease,100);
                    cout<<"Doctor's Name(consulting doctor for that visit) : ";
                    cin.getline(e.doctorsName,80);
                    cout<<"Number of medicines prescibed: ";
                    cin>>e.noOfMedicines;
                    cin.get();
                    for(int i=1; i<=e.noOfMedicines; i++)
                    {
                        cout<<i<<". ";
                        cin.getline(e.medicinesPrescribed[i-1],100);
                    }
                    cout<<"Delivered(Yes/No): ";
                    cin.getline(e.delivered,5);
                    cout<<"Date of visit/checkup: ";
                    cin.getline(e.dateOfarrival,15);

                    char ch;
                    ofstream out1;
                    out1.open("employee1.txt",ios::app);
                    if(!out1.write((char*) &e, sizeof(e)))
                    {
                        cout<<"error in writing a record..! "<<endl;
                    }
                    else
                    {
                        cout<<"Record inserted"<<endl;
                    }

                    out1.close();
                    in1.close();
                    return ;
                }
            }
        }
        cout<<"Address: ";
        cin.getline(e.address,1000);
        cout<<"Contact Number: ";
        cin>>e.contactno;
        cin.get();
        cout<<"Department: ";
        cin.getline(e.department,100);
        cout<<"Date of joining: ";
        cin.getline(e.dateofjoining,15);
        cout<<"Problem/Disease: ";
        cin.getline(e.disease,100);
        cout<<"Doctor's Name(consulting doctor for that visit) : ";
        cin.getline(e.doctorsName,80);
        cout<<"Number of medicines prescibed: ";
        cin>>e.noOfMedicines;
        cin.get();
        for(int i=1; i<=e.noOfMedicines; i++)
        {
            cout<<i<<". ";
            cin.getline(e.medicinesPrescribed[i-1],100);
        }
        cout<<"Delivered(Yes/No): ";
        cin.getline(e.delivered,5);
        cout<<"Date of visit/checkup: ";
        cin.getline(e.dateOfarrival,15);
        ofstream out1;
        out1.open("employee1.txt",ios::app);
        if(!out1.write((char*) &e, sizeof(e)))
        {
            cout<<"error in writing a record..! "<<endl;
        }
        else
        {
            cout<<"Record inserted"<<endl;
        }

        out1.close();
    }
    else
    {
        cout<<"INVALID OPTION..! PLEASE TRY AGAIN. ";
    }

}

// Search a patient's record by rollno/empolyee id.
void searchpatient()
{
    system("cls");
    cout<<"Category of the patient: Student or Staff. "<<endl<<"Select 1 for student and 2 for staff. "<<endl;
    int n;
    cin>>n;
    cin.get();
    if(n==1)
    {
        char name[100];
        char rollno[10];
        cout<<"Enter the Patient's Name: ";
        cin.getline(name,100);
        cout<<"Enter the Patient's Employee ID: ";
        cin.getline(rollno,10);
        student s;
        ifstream in;
        in.open("student1.txt");
        if(!in)
        {
            cout<<"Error in opening the file. "<<endl;
        }
        else
        {
            int count=1;
            while(in.read((char *) &s, sizeof(s)))
            {
                if(!in.eof())
                {
                    if(strcmp(s.rollno,rollno)==0)
                    {
                        if(count==1)
                        {
                            cout<<"PATIENT'S DETAILS:-- "<<endl<<endl;
                            cout<<"NAME: "<<s.name<<endl;
                            cout<<"ROLL NO: "<<s.rollno<<endl;
                            cout<<"CONTACT NUMBER: "<<s.contactno<<endl;
                            cout<<"ADDRESS: "<<s.address<<endl;
                            cout<<"BRANCH: "<<s.branch<<endl;
                            cout<<"YEAR : "<<s.year<<endl<<endl;
                            cout<<"CHECK DETAILS :-- "<<endl<<endl;
                        }
                        cout<<"VISIT NUMBER: "<<count<<endl<<endl;
                        cout<<"DISEASE: "<<s.disease<<endl;
                        cout<<"DOCTORS'S NAME: "<<s.doctorsName<<endl;
                        cout<<"MEDICINE'S PRESCRIBED:-- "<<endl;
                        char arr[]= {'\0'};
                        for(int i=0; i<s.noOfMedicines; i++)
                        {
                            cout<<i+1<<". ";
                            cout<<s.medicinesPrescribed[i]<<endl;
                        }
                        cout<<"DELIVERY STATUS: "<<s.delivered<<endl;
                        cout<<"DATE OF VISIT: "<<s.dateOfarrival<<endl<<endl;
                        count++;
                    }
                }
            }
            if(count==1)
                cout<<"Record not found\n";
        }
    }
    else if (n==2)
    {
        char name[100];
        char empid[10];
        cout<<"Enter the Patient's Name: ";
        cin.getline(name,100);
        cout<<"Enter the Patient's Employee ID: ";
        cin.getline(empid,10);
        employee e;
        ifstream in;
        in.open("employee1.txt");
        if(!in)
        {
            cout<<"Error in opening the file. "<<endl;
        }
        else
        {
            int count=1;
            bool flag = false;
            while(in.read((char *) &e, sizeof(e)))
            {

                //if(in.eof()) {cout<<"dfgaef";break;}
                if(strcmp(e.empid,empid)==0)
                {
                    flag = true;
                    //cout<<"VISIT NUMBER: "<<count<<endl<<endl;
                    if(count==1)
                    {
                        cout<<"PATIENT'S DETAILS:-- "<<endl<<endl;
                        cout<<"NAME: "<<e.name<<endl;
                        cout<<"ROLL NO: "<<e.empid<<endl;
                        cout<<"CONTACT NUMBER: "<<e.contactno<<endl;
                        cout<<"ADDRESS: "<<e.address<<endl;
                        cout<<"BRANCH: "<<e.department<<endl;
                        cout<<"DATE OF JOINING : "<<e.dateofjoining<<endl<<endl;
                        cout<<"CHECK DETAILS :-- "<<endl<<endl;
                    }
                    cout<<"VISIT NUMBER: "<<count<<endl<<endl;
                    cout<<"DISEASE: "<<e.disease<<endl;
                    cout<<"DOCTORS'S NAME: "<<e.doctorsName<<endl;
                    cout<<"MEDICINE'S PRESCRIBED:-- "<<endl;
                    //cout<<s.medicinesPrescribed.size();
                    char arr[]= {'\0'};
                    for(int i=0; i<e.noOfMedicines; i++)
                    {
                        //int p=i+1;
                        cout<<i+1<<". ";
                        cout<<e.medicinesPrescribed[i]<<endl;
                    }
                    cout<<"DELIVERY STATUS: "<<e.delivered<<endl;
                    cout<<"DATE OF VISIT: "<<e.dateOfarrival<<endl<<endl;
                    count++;
                }
            }
            if(flag==false)
                cout<<"Record not found\n";
        }

    }
    else
    {
        cout<<"INVALID CHOICE . TRY AGAIN . "<<endl;
    }
}

// Edit the contact number and address of a person that exists in the record.
void editpatient()
{
    system("cls");
    cout<<"Choose 1 for STUDENT and 2 for STAFF. "<<endl;
    int n;
    cin>>n;
    cin.get();
    cout<<"PATIENT'S NAME: ";
    char name[100];
    cin.getline(name,100);
    int k=1;
    if(n==1)
    {
        cout<<"ROLL NO: ";
        char rollno[10];
        cin.getline(rollno,10);
        student s;

        cout<<endl;
        cout<<"DETAILS YOU WANT TO EDIT:--"<<endl<<endl;
        while(k==1)
        {
            ifstream in;
            in.open("student1.txt");

            ofstream out;
            out.open("temp.txt");
            cout<<"1 - ADDRESS"<<endl;
            cout<<"2 - CONTACT NUMBER"<<endl;

            cout<<"Please press any other character to exit. "<<endl;
            cout<<"YOUR CHOICE: ";
            int n;
            cin>>n;
            switch(n)
            {
            case 1:
                cout<<"Enter NEW ADDRESS: ";
                char address[1000];
                cin.get();
                cin.getline(address,1000);

                if(!in)
                {
                    cout<<"Error in opening the file. "<<endl;
                }
                if(!out)
                {
                    cout<<"Error";
                }
                else
                {
                    while(!in.eof())
                    {
                        in.read((char *) &s, sizeof(s));
                        if(!in.eof())
                        {
                            if(strcmp(s.rollno,rollno)==0)
                            {
                                strcpy(s.address,address);
                                out.write((char *) &s, sizeof(s));
                            }
                            else
                                out.write((char* ) &s, sizeof(s));
                        }
                    }
                }

                break;

            case 2:
                cout<<"Enter CONTACT NUMBER: ";
                char contact[13];
                cin.get();
                cin.getline(contact,13);

                if(!in)
                {
                    cout<<"Error in opening the file. "<<endl;
                }
                if(!out)
                {
                    cout<<"Error";
                }
                else
                {
                    while(!in.eof())
                    {
                        in.read((char *) &s, sizeof(s));
                        if(strcmp(s.rollno,rollno)==0)
                        {
                            strcpy(s.contactno,contact);
                            out.write((char *) &s, sizeof(s));
                        }
                        else
                            out.write((char* ) &s, sizeof(s));
                    }
                }

                break;

            default:
                return ;

            }
            in.close();
            out.close();
            remove("student1.txt");
            rename("temp.txt","student1.txt");
            cout<<"Do you want to edit more entries? "<<endl;
            cout<<"Press 1 for YES and 2 for NO."<<endl;
            cin>>k;

        }

        cout<<"Changes implemented :) "<<endl;
    }
    else if(n==2)
    {
        k=1;
        cout<<"EMPLOYEE ID: ";
        char empid[10];
        cin.getline(empid,10);
        employee e;
        fstream in;
        in.open("employee1.txt");
        ofstream out;
        out.open("temp.txt");
        cout<<endl;
        cout<<"DETAILS YOU WANT TO EDIT:--"<<endl<<endl;
        while(k==1)
        {
            cout<<"1 - ADDRESS"<<endl;
            cout<<"2 - CONTACT NUMBER"<<endl;
            cout<<"YOUR CHOICE: ";
            int n;
            cin>>n;
            switch(n)
            {
            case 1:
                cout<<"Enter NEW ADDRESS: ";
                char address[1000];
                cin.get();
                cin.getline(address,1000);

                if(!in)
                {
                    cout<<"Error in opening the file. "<<endl;
                }
                if(!out)
                {
                    cout<<"Error";
                }
                else
                {
                    while(!in.eof())
                    {
                        in.read((char *) &e, sizeof(e));
                        if(!in.eof())
                        {
                            if(strcmp(e.empid,empid)==0)
                            {
                                strcpy(e.address,address);
                                out.write((char *) &e, sizeof(e));
                            }
                            else
                                out.write((char* ) &e, sizeof(e));
                        }
                    }
                }

                break;
            case 2:
                cout<<"Enter NEW CONTACT NUMBER: ";
                char contact[13];
                cin.get();
                cin.getline(contact,13);

                if(!in)
                {
                    cout<<"Error in opening the file. "<<endl;
                }
                if(!out)
                {
                    cout<<"Error";
                }
                else
                {
                    while(!in.eof())
                    {
                        in.read((char *) &e, sizeof(e));
                        if(!in.eof())
                        {
                            if(strcmp(e.empid,empid)==0)
                            {
                                strcpy(e.contactno,contact);
                                out.write((char *) &e, sizeof(e));
                            }
                            else
                                out.write((char* ) &e, sizeof(e));
                        }
                    }
                }

                break;
            default:
                return ;

            }
            in.close();
            out.close();
            remove("employee1.txt");
            rename("temp.txt","employee1.txt");
            cout<<"Do you want to edit more entries? "<<endl;
            cout<<"Press 1 for YES and 2 for NO."<<endl;
            cin>>k;
            system("cls");
        }
        cout<<"Changes implemented :) "<<endl;
    }
    else
    {
        cout<<"Choose valid option. PLEASE TRY AGAIN..! "<<endl<<endl;
    }

}

// Display all the student's data present in the record.
void listofstudents()
{
    system("cls");
    student s;
    ifstream in;
    in.open("student1.txt");
    if(!in)
    {
        cout<<"Error in opening the file. "<<endl;
    }
    else
    {
        while(!in.eof())
        {
            int count=1;
            while(in.read((char *) &s, sizeof(s)))
            {
                    cout<<"RECORD: "<<count<<endl;
                    cout<<"PATIENT'S DETAILS:-- "<<endl<<endl;
                    cout<<"NAME: "<<s.name<<endl;
                    cout<<"ROLL NO: "<<s.rollno<<endl;
                    cout<<"CONTACT NUMBER: "<<s.contactno<<endl;
                    cout<<"ADDRESS: "<<s.address<<endl;
                    cout<<"BRANCH: "<<s.branch<<endl;
                    cout<<"YEAR : "<<s.year<<endl<<endl;
                    cout<<"CHECK DETAILS :-- "<<endl<<endl;
                    cout<<"VISIT NUMBER: "<<count<<endl<<endl;
                    cout<<"DISEASE: "<<s.disease<<endl;
                    cout<<"DOCTORS'S NAME: "<<s.doctorsName<<endl;
                    cout<<"MEDICINE'S PRESCRIBED:-- "<<endl;
                    for(int i=0; i<s.noOfMedicines; i++)
                    {
                        cout<<i+1<<". ";
                        cout<<s.medicinesPrescribed[i]<<endl;
                    }
                    cout<<"DELIVERY STATUS: "<<s.delivered<<endl;
                    cout<<"DATE OF VISIT: "<<s.dateOfarrival<<endl<<endl;
                    count++;
            }
        }
    }

    in.close();
}

// Display all the employee's data present in the record.
void listofemployees()
{
    system("cls");
    employee e;
    ifstream in;
    in.open("employee1.txt");
    if(!in)
    {
        cout<<"Error in opening the file. "<<endl;
    }
    else
    {
        while(!in.eof())
        {
            int count=1;
            while(in.read((char *) &e, sizeof(e)))
            {
                    cout<<"RECORD: "<<count<<endl;
                    cout<<"PATIENT'S DETAILS:-- "<<endl<<endl;
                    cout<<"NAME: "<<e.name<<endl;
                    cout<<"EMP ID: "<<e.empid<<endl;
                    cout<<"CONTACT NUMBER: "<<e.contactno<<endl;
                    cout<<"ADDRESS: "<<e.address<<endl;
                    cout<<"DEPARTMENT: "<<e.department<<endl;
                    cout<<"DATE OF JOINING : "<<e.dateofjoining<<endl<<endl;
                    cout<<"CHECK DETAILS :-- "<<endl<<endl;
                    cout<<"VISIT NUMBER: "<<count<<endl<<endl;
                    cout<<"DISEASE: "<<e.disease<<endl;
                    cout<<"DOCTORS'S NAME: "<<e.doctorsName<<endl;
                    cout<<"MEDICINE'S PRESCRIBED:-- "<<endl;
                    for(int i=0; i<e.noOfMedicines; i++)
                    {
                        cout<<i+1<<". ";
                        cout<<e.medicinesPrescribed[i]<<endl;
                    }
                    cout<<"DELIVERY STATUS: "<<e.delivered<<endl;
                    cout<<"DATE OF VISIT: "<<e.dateOfarrival<<endl<<endl;
                    count++;
            }
        }
    }

    in.close();
}

//function to delete a patient by rollno/emplouee id from the record.
void deletepatient()
{
    system("cls");
    cout<<"Choose 1 for STUDENT and 2 for STAFF. "<<endl;
    int n;
    cin>>n;
    cin.get();
    cout<<"PATIENT'S NAME: ";
    char name[100];
    cin.getline(name,100);
    if(n==1)
    {
        cout<<"ROLL NO: ";
        char rollno[10];
        cin.getline(rollno,10);
        student s;
        ifstream in;
        in.open("student1.txt");
        ofstream out;
        out.open("temp.txt");

        if(!in)
        {
            cout<<"Error in opening the file. "<<endl;
        }
        if(!out)
        {
            cout<<"Error";
        }
        else
        {
            bool flag = false;
            while(!in.eof())
            {

                in.read((char *) &s, sizeof(s));
                if(!in.eof())
                {
                    if(strcmp(s.rollno,rollno)==0)
                    {
                        flag = true;
                    }
                    else
                        out.write((char* ) &s, sizeof(s));
                }
            }
            if(flag)
                cout<<"Record deleted"<<endl;
            else
                cout<<"Record not found\n";
        }

        in.close();
        out.close();
        remove("student1.txt");
        rename("temp.txt","student1.txt");
    }
    else if(n==2)
    {

        cout<<"EMPLOYEE ID: ";
        char empid[10];
        cin.getline(empid,10);
        employee e;
        ifstream in;
        in.open("employee1.txt");
        ofstream out;
        out.open("temp.txt");

        if(!in)
        {
            cout<<"Error in opening the file. "<<endl;
        }
        if(!out)
        {
            cout<<"Error";
        }
        else
        {
            bool flag = false;
            while(!in.eof())
            {
                in.read((char *) &e, sizeof(e));
                if(!in.eof())
                {
                    if(strcmp(e.empid,empid)==0)
                    {
                        flag = true;
                    }
                    else
                        out.write((char* ) &e, sizeof(e));
                }
            }

            if(flag)
                cout<<"Record deleted"<<endl;
            else
                cout<<"Record not found\n";
        }
        in.close();
        out.close();
        remove("employee1.txt");
        rename("temp.txt","employee1.txt");
    }
    else
    {
        cout<<"Invalid Option"<<endl;
    }

}


//main function linking all the function.
int main()
{
    while(1)
    {
        loading();
        system("cls");
        cout<<"     Welcome to NSIT MEDICAL CENTER..!                 \n"<<endl;
        cout<<"Please select any one of the following options... \n"<<endl<<"1. Adding a patient's details in the record. "<<endl<<"2. Searching a patient's previous record. "<<endl<<"3. Editing a patient's details in the record. "<<endl<<"4. List of all students."<<endl<<"5. List of all employees. "<<endl<<"6. Delete a patient's record"<<endl<<"7. EXIT "<<endl;
        int n;
        cin>>n;
        switch(n)
        {
        case 1:
            addpatient();
            break;

        case 2:
            searchpatient();
            break;

        case 3:
            editpatient();
            break;

        case 4:
            listofstudents();
            break;

        case 5:
            listofemployees();
            break;

        case 6:
            deletepatient();
            break;

        case 7:
            return 0;

        default:
            cout<<"INVALID CHOICE..! "<<endl<<endl;


        }
        getch();
    }
    return 0;
}
