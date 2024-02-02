

// Aman Kumar Yadav <yadavaman7632@gmail.com>
// Sep 16, 2023, 5:51 PM

// STUDENT DATA BASE MANNAGEMENT SYSTEM BY AMAN ROY//
// #include<iostream>
#include <conio.h>
#include <random>
// #include<iomanip>
#include <windows.h>
// #include<time.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std; // template hai jisme function declare kiya hota hai//
class Animation
{
public:
    int random_normalclr()
    {
        srand(time(NULL));
        int clr = 0 /*(Offset)*/ + (rand() % 6 /*(RANGE+OFFSET)*/);
        if (clr == 7 || clr == 0)
        {
            clr = 2;
        }
        return clr;
    }
    void setcolor(int color_code)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_code);
    }
    void loading(int width, int size)
    {
        setcolor(random_normalclr());
        char b1 = 177, b2 = 219;
        cout << setw(width);
        for (int i = 1; i <= size; i++)
        {
            cout << b1;
        }
        cout << "\r"; // return the console to start pointer of line
        cout << setw(width);
        for (int i = 1; i <= size; i++)
        {
            int delay = 0 /*(Offset)*/ + (rand() % 151 /*(RANGE+OFFSET)*/);
            cout << b2;
            Sleep(delay);
        }
        Sleep(500);
        system("color 07");
    }
} animate;
class Validation
{
public:
    int length(char name[])
    {
        int count = 0;
        int i = 0;
        while (name[i] != '\0')
        {
            count++;
            i++;
        }
        return count;
    }
    void lowerCase(char name[])
    {
        for (int i = 0; name[i] != '\0'; i++)
        {
            if (name[i] != ' ')
            {
                name[i] = tolower(name[i]);
            }
        }
    }
    bool isValidName(char name[])
    {
        int len = length(name);
        if (len == 0 || len == 2)
        {
            return false;
        }
        lowerCase(name);
        int i = 0;
        int countSpace = 0;
        while (name[i] != '\0')
        {
            if (name[i] == ' ')
            {
                ++countSpace;
            }
            else
            {
                int charValue = (int)name[i];
                // cout << charValue << "-> " << endl;
                if (charValue < 97 || charValue > 122)
                {
                    return false;
                }
            }
            if (length(name) == 0 || countSpace > 2)
                return false;
            i++;
        }
        return true;
    }
    bool isValidPhoneNumber(char phn[])
    {
        if (length(phn) != 10)
            return false;
        if ((phn[0] - '0') < 6)
            return false;
        return true;
    }
};
void search(long int);
void search_for_same_rn(long int);
class student : public Validation
{
private: // Access specifier//
    long int rn;
    // char rn[8];
    long int enrl;
    // char enrl[8];
    char name[30];
    char branch[15];
    float marks;
    char fee[10];
    char sem[5];
    char phn[10];
    int password;

public: // Aceess specifier //
    class date
    {
    private:
        int d;
        int m;
        int y;

    public:
        void getdob() // for date of birth //
        {
            cout << "Enter Date of Birth D/M/Y" << setw(15) << ": ";
        valid:
            cin >> d >> m >> y;
            bool check = false;
            if (m <= 0 || d <= 0 || y <= 0 || m > 12 || d > 31 || y > 2024)
            {

                cout << "\nInvalid DOB!!" << endl;
                cout << "Enter Valid Data: ";
                goto valid;
            }
            else if (m == 2)
            {
                if (d > 28)
                {
                    cout << "\nInvalid DOB!!" << endl;
                    cout << "Enter Valid Data: ";
                    goto valid;
                }
            }
        }
        void showdob()
        {
            cout << d << "/" << m << "/" << y << endl;
        }
        date()
        {
            d = 0;
            m = 0;
            y = 0;
        }
    } dob;
    student()
    {
        strcpy(name, "null");
        rn = 0;
        enrl = 0;
        marks = 0.00;
        strcpy(fee, "0.00");
        password = 0;
    }
    // friend void getdata();
    void setdata();
    void showdata();
    long int getrn() // for getting roll number//
    {
        return rn;
    }
    long int getenrl() // for getting enrollement number //
    {
        return enrl;
    }
    string sname() // for getting Name //
    {
        return name;
    }
    int pstudent() // for getting pin //
    {
        return password;
    }
    // long int getRollNoFromFile(){
    //     student s1;
    //     ifstream fout;
    //     long int x;
    // fout.open("studentInfo.txt");
    // while (fout.read((char *)&s1, sizeof(s1)))
    // {
    //     long int x=s1.getrn();

    // }
    // fout.close();
    // return x;
    // }
};
student s1;    // Global declaration of student class object //
ofstream fin;  // Global declaration of ofstream class object//
ifstream fout; // global declaration of ifstream class object//
bool showPassword = false;
void student::setdata()
{
    cout << "\t\tEnter Student Details" << endl;
    cout << setfill(' ');
check_name:
    cout << "\nEnter the Name of Student" << setw(15) << ": ";
    cin.ignore();
    cin.getline(name, 30);
    // condition to check the proper name of the student
    if (!isValidName(name))
    {
        cout << "Invalid Name !!" << endl;
        Sleep(700);
        goto check_name;
    }
    dob.getdob();
    long int prefix = 22 * 100000;
    srand(time(nullptr));
    enrl = prefix + rand();
    cout << "Enrollment no  " << setw(25) << ": " << enrl << endl;
    prefix = 22 * 100200;
    srand(time(nullptr));
    // cin >> enrl;
    // if(enrl<=0 ||enrl>9999999){
    //     cout<<"Wrong enrollment number: ";
    //     cin>>enrl;
    // }
    // cout<<"\n"<<s1.getRollNoFromFile();
    rn = prefix + rand();
    cout << "Roll no." << setw(32) << ": " << rn << endl;
    // cin >> rn;
    cout << "Enter Branch of the student  " << setw(11) << ": ";
    cin.ignore();
    cin.getline(branch, 15);
    // condition to check for branch name
    Sleep(100);
    cout << "Enter semester  " << setw(24) << ": ";
    cin >> sem;
    Sleep(100);
checkPhone:

    cout << "Enter the Phone number  " << setw(16) << ": ";
    cin >> phn;
    if (!isValidPhoneNumber(phn))
    {
        cout << "Invalid Phone Number!!" << endl;
        Sleep(700);
        goto checkPhone;
    }
    Sleep(100);
    cout << "Enter the previous semester sgpa " << setw(7) << ": ";
    cin >> marks;
    Sleep(100);
    cout << "Enter total Fee of current Semester Rs: ";
    cin >> fee;
    Sleep(100);
    cout << "Create password of the student's ID " << setw(4) << ": ";
    cin >> password;
}
void student::showdata()
{
    cout << "---------------------------------------------------------------\n"
         << setfill(' ');
    cout << "Name " << setw(40) << ": " << name << endl;
    Sleep(200);
    cout << "Dob " << setw(41) << ": ";
    Sleep(180);
    dob.showdob();
    Sleep(160);
    cout << "Roll no. " << setw(36) << ": " << rn << endl;
    Sleep(140);
    cout << "Enrollment no." << setw(31) << ": " << enrl << endl;
    Sleep(120);
    cout << "Branch  " << setw(37) << ": " << branch << endl;
    Sleep(100);
    cout << "Semester  " << setw(35) << ": " << sem << endl;
    Sleep(80);
    cout << "Phone no. " << setw(35) << ": " << phn << endl;
    Sleep(60);
    cout << "Sgpa of previous semester" << setw(20) << ": " << marks << endl;
    Sleep(40);
    cout << "Current fees Rs. " << setw(28) << ": " << fee << endl
         << endl;
    Sleep(20);
    char choose;
    // if(!showPassword){
    //     cout << "Show Password: (Y/N): \t\t\t";
    //     cin >> choose;
    // }
    if (!showPassword)
    {
        // cout << "Boolean variable value is: " << showPassword << endl;
        cout << "Show Password: (Y/N)" << setw(25) << ": ";
        cin >> choose;
    }

    if (choose == 'Y' || choose == 'y')
    {
        showPassword = true;
    }
    if (showPassword)
    {
        cout << "Passsword" << setw(36) << ": " << password << endl;
    }
    else
    {
        cout << "Passsword" << setw(41) << ": *****" << endl;
    }
    cout << "---------------------------------------------------------------\n"
         << setfill(' ');
    // cout << "Passsword : " << setw(30) << setfill(' ') << password << endl;
    // showPassword=true;
    // else cout << "\nPasssword : "
    //           << "*****" << endl;
}
/* void getdata()
{
int ch;
cout<<"Update Name"<<endl;
cout<<"Update birthdate"<<endl;
cout<<"Update phone number "<<endl;
cout<<"Update fees status"<<endl;
cout<<"Enter your choice "<<endl;
xx:
cin>>ch;
if(ch>4)
{
cout<<"Invalid choice !!!"<<endl;
cout<<"Please Enter a proper choice"<<endl;
system("pause");
goto xx;
}
switch(ch)
{
case 1:
cout<<"Enter Full Name"<<endl;
cin.ignore();
cin.getline(s1.name,30);
break;
case 2:
student s1;
student::date d;
cout<<"Enter Birthdate of the student "<<endl;
cin>>s1.d.getdob();
break;
case 3:
cout<<"Enter New phone number"<<endl;
cin>>s1.phn;
break;
case 4:
cout<<"Enter Current Fees status"<<endl;
cin>>s1.fee;
break;
}*/
// }
void intro()
{
    system("cls");
    animate.setcolor(3);
    // cout << "             _____   _                                    (   ) )                  \n";
    // cout << "            /  ___| | |     _    _                     ) (                   \n";
    // cout << "            \\ `--.  | |_   | |  | |           ___  _ __ ___           _______)_                  \n";
    // cout << "             `--. \\ | __|  | |  | |         / _ \\| '_ ` _ \\       .-'---------|                  \n";
    // cout << "            /\\__/ / | |_   \\ \\__/ /        |  __/| | | | | |     ( C|/\\/\\/\\/\\/|                       \n";
    // cout << "            \\____/   \\__|   \\___ /             \\ ___||_| |_| |_|      '-./\\/\\/\\/\\/|                 \n";
    // cout << "                                               '_________'                  \n";
    // cout << "                                                   '-------'                       \n";
    cout << endl
         << "\t\t";
    //     cout << R"(
    //   _________ __            .___             __    ________          __        ___.
    //  /   _____//  |_ __ __  __| _/____   _____/  |_  \______ \ _____ _/  |______ \_ |__ _____    ______ ____
    //  \_____  \\   __\  |  \/ __ |/ __ \ /    \   __\  |    |  \\__  \\   __\__  \ | __ \\__  \  /  ___// __ \ 
//  /        \|  | |  |  / /_/ \  ___/|   |  \  |    |____/`   \/ __ \|  |  / __ \| \_\ \/ __ \_\___ \\  ___/
    // /_______  /|__| |____/\____ |\___  >___|  /__|   /_______  (____  /__| (____  /___  (____  /____  >\___  >
    //         \/                 \/    \/     \/               \/     \/          \/    \/     \/     \/     \/ )"<<endl;
    //          cout<<R"(                    _____                                                             __
    //                    /     \ _____    ____ _____     ____   ____   _____   ____   _____/  |_
    //                   /  \ /  \\__  \  /    \\__  \   / ___\_/ __ \ /     \_/ __ \ /    \   __\
//                  /    Y    \/ __ \|   |  \/ __ \_/ /_/  >  ___/|  Y Y  \  ___/|   |  \  |
    //                  \____|__  (____  /___|  (____  /\___  / \___  >__|_|  /\___  >___|  /__|
    //                          \/     \/     \/     \//_____/      \/      \/     \/     \/     )"<<endl;

    cout << R"(  _________ __            .___             __    ________          __        ___.                             _____                                                             __   
                 /   _____//  |_ __ __  __| _/____   _____/  |_  \______ \ _____ _/  |______ \_ |__ _____    ______ ____     /     \ _____    ____ _____     ____   ____   _____   ____   _____/  |_ 
                 \_____  \\   __\  |  \/ __ |/ __ \ /    \   __\  |    |  \\__  \\   __\__  \ | __ \\__  \  /  ___// __ \   /  \ /  \\__  \  /    \\__  \   / ___\_/ __ \ /     \_/ __ \ /    \   __\
                 /        \|  | |  |  / /_/ \  ___/|   |  \  |    |    `   \/ __ \|  |  / __ \| \_\ \/ __ \_\___ \\  ___/  /    Y    \/ __ \|   |  \/ __ \_/ /_/  >  ___/|  Y Y  \  ___/|   |  \  |  
                /_______  /|__| |____/\____ |\___  >___|  /__|   /_______  (____  /__| (____  /___  (____  /____  >\___  > \____|__  (____  /___|  (____  /\___  / \___  >__|_|  /\___  >___|  /__|  
                        \/                 \/    \/     \/               \/     \/          \/    \/     \/     \/     \/          \/     \/     \/     \//_____/      \/      \/     \/     \/      )"
         << endl
         << endl;
    cout << R"(                                                                      _________               __                  
                                                                     /   _____/__.__. _______/  |_  ____   _____  
                                                                     \_____  <   |  |/  ___/\   __\/ __ \ /     \ 
                                                                     /        \___  |\___ \  |  | \  ___/|  Y Y  \
                                                                    /_______  / ____/____  > |__|  \___  >__|_|  /
                                                                            \/\/         \/            \/      \/ )"
         << endl;
    // setcolor(7);
    // cout<<"\n\t  ___\n";
    // cout<<"\n\t/\n";
    // cout<<"\n\t\\\n";
}
void welcome()
{
    system("cls");
    intro();
    // system("color 09");
    cout << "\t\t\t\t\t\t\t\t\t+";
    for (int i = 1; i < 49; i++)
        cout << "-";
    cout << "+";
    // system("color 05");
    cout << "\n\t\t\t\t\t\t\t\t\t| Department of Computer Science and Engineering |" << endl;
    Sleep(50);
    // system("color 04");
    cout << "\t\t\t\t\t\t\t\t\t+";
    for (int i = 1; i < 49; i++)
        cout << "-";
    cout << "+";
    // cout << setw(30) << "\n\t\t\t\t\t\t\t\t\tStudent data base Management system" << endl;
}
// Animation animate;
void login_admin() // Login for admin //
{
    int i, count = 0;
    // char uid[20];
    string uid;
xy:
    bool flag = 0;
    // const char userid[10] = "admin";
    string userid = "admin";
    int size = userid.length();
    // int size = sizeof(userid);
    cout << "\t\t\t\t\t\t\t\t\t\t\t+";
    for (int i = 0; i < 13; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t| ADMIN LOGIN |" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t+";
    for (int i = 0; i < 13; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tUSERNAME : ";
    cin >> uid;
    if (userid != uid)
    {
        flag = 1;
        count++;
    }
    if (flag == 0)
        cout << "" << endl;
    else
    {
        if (count < 2)
        {
            cout << setw(25) << setfill(' ') << "\t\t\t\t\t\t\t\t\t\t\tInvalid user ID !!!" << endl;
            Sleep(1000);
            system("cls");
            // system("pause");
            goto xy;
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\tYou have reached your maximum attempt.." << endl
                 << "\n\t\t\t\t\t\t\t\t\tTHANK YOU FOR USING OUR APPLICATION!!!" << endl;
            cout << "\t\t";
            for (int i = 0; i < 5; i++)
            {
                cout << "<--";
                Sleep(100);
            }
            exit(0);
        }
    }
    // char ep[10];
    string ep;
    char ch;

    int attempt = 0;
    const string password = "admin";
    // const char p[10] = "admin";
    bool flage = 0;
    cout << "\t\t\t\t\t\t\t\t\t\t\tPASSWORD : ";
    for (i = 0; i < 5; i++)
    {
        ch = getch();
        // ep[i] = ch;
        ep.push_back(ch);
        ch = '*';
        cout << ch;
    }
    cout << "\n\n";
    if (password != ep)
    {
        flag = 1;
        attempt++;
        cout << "\n\t\t\t\t\t\t\t\t\t\t\tIncorrect password !!!\n";
        if (attempt < 2)
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\tTry again !!!\n\t";
            Sleep(1000);
            system("cls");
            login_admin();
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\tLimit exceeded \n";
            cout << "\t\t\t\t\t\t\t\t\tThanks For Visiting Our Application..." << endl;
            cout << "\t\t";
            for (int i = 0; i < 5; i++)
            {
                cout << "<--";
                Sleep(75);
            }
            exit(0);
        }
    }

    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tCongratulations Login successfull !!!" << endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t\tLoading...\n\n"
             << endl;
        animate.loading(80, 50);
    }
}
void login_student() // login for student //
{
// char a[4];
// char ch;
back2:
    char c;
    int count = 0;
    long int id;
    int password;
    cout << "Enter Student ID(UNI.ROLL NO.) ." << endl;
    cin >> id;
    cout << "Enter Pin (4-digit) " << endl;
    cin >> password;
    cout << endl;
    // for(int i=0;i<4;i++)
    // {ch=getch();
    // a[i]=ch;
    // ch='*';
    // cout<<ch;}
    fout.open("studentInfo.txt");
    if ("studentInfo.txt" == NULL)
        cout << "Not Registered " << endl;
    else
        while (fout.read((char *)&s1, sizeof(s1)))
        {
            count++;
            if (s1.getrn() == id && s1.pstudent() == password)
            {
                cout << "Loading..." << endl;
                animate.loading(10, 20);
                system("cls");
                cout << "\n Congratulations Login Sucessfull !!!\n"
                     << endl;
                cout << "Record is at :" << count << endl;
                s1.showdata();
                fout.close();
                goto back1;
                break;
            }
        }
    cout << "Record not found.." << endl;
back1:
    fout.close();
    cout << "\nDo you want to login again.(Y/N or y/n)" << endl;
    cin >> c;
    if (c == 'y' || c == 'Y')
    {
        for (int i = 0; i < 3; i++)
        {
            cout << ". ";
            Sleep(100);
        }
        system("cls");
        goto back2;
    }
    else
        return;
}
long int search_roll_while_add(long int n) // searching by roll number //
{
    long int x;
    fout.open("studentInfo.txt");
    while (fout.read((char *)&s1, sizeof(s1)))
    {
        if (s1.getrn() == n)
        {
            x = s1.getrn();
            cout << "Record already exists..!!\n"
                 << endl;
        }
    }
    fout.close();
    return x;
}
void add_record() // for addition of records //
{
back:
    fin.open("studentInfo.txt", ios::out | ios::ate | ios::app);
    s1.setdata();
    if (s1.getrn() == 0 || s1.getenrl() == 0)
    {
        cout << "Data is not appropriate.." << endl;
        Sleep(1000);
        cout << "Please Enter proper data." << endl;
        goto back;
    }
    else
    {
        fin.write((char *)&s1, sizeof(s1));
        fin.close();
        cout << "\nLoading..." << endl;
        animate.loading(10, 20);
        cout << "\n\tCongratulations Record has been created successfully !!!" << endl;
        cin.ignore();
        Sleep(2000);
        system("cls");
    }
}

void display() // for displaying records//
{
    char ch;
    int i = 1;
    fout.open("studentInfo.txt");
    if (fout.is_open())
    {
        // Check if the file size is 0
        fout.seekg(0, ios::end);
        if (fout.tellg() == 0)
        {
            cout << "File is empty." << endl;
            return;
        }
        else
        {
            cout << setw(10) << "Displaying All Records" << endl;
            while (fout.read((char *)&s1, sizeof(student)))
            {
                cout << "\t\nStudent " << i << ". Details" << endl;
                i++;
                s1.showdata();
                // cout << setw(50) << setfill('*') << endl;
            }
        }

        fout.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
    cin.ignore();
    // system("pause");
    cout<<"\nEnter any Key to proceed"<<endl;
    getch();
    system("cls");
}
void search(long int n) // searching by roll number //
{
    bool flag = 0;
    fout.open("studentInfo.txt");
    while (fout.read((char *)&s1, sizeof(s1)))
    {
        if (s1.getrn() == n)
        {
            cout << "Record found !!!\n"
                 << endl;
            s1.showdata();
            flag = 1;
            system("pause");
            system("cls");
        }
    }
    fout.close();
    if (flag != 1)
    {
        cout << "\n\tRecord Not found !!!\n"
             << endl;
        cin.ignore();
        system("pause");
        system("cls");
    }
}
void senrl(long int unrl) // searching by enrollment number //
{
    bool f = 0;
    fout.open("studentInfo.txt");
    cout << "Checking";
    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(800);
    }
    cout << "\n";
    Sleep(1000);
    while (fout.read((char *)&s1, sizeof(s1)))
    {
        if (s1.getenrl() == unrl)
        {
            cout << "Record Found !!!" << endl
                 << endl;
            s1.showdata();
            f = 1;
            system("pause");
            system("cls");
        }
    }
    fout.close();
    if (f != 1)
    {
        cout << "\n\tRecord Not found !!!!\n"
             << endl;
        cin.ignore();
        system("pause");
        system("cls");
    }
}
void sname(string s) // searching by name //
{
    bool flash = 0;
    fout.open("studentInfo.txt");
    cout << "Checking...\n";
    Sleep(1000);
    while (fout.read((char *)&s1, sizeof(s1)))
    {
        if (s1.sname() == s)
        {
            cout << "\n\tRecord found !!!" << endl
                 << endl;
            s1.showdata();
            flash = 1;
            system("pause");
            system("cls");
        }
    }
    fout.close();
    if (flash != 1)
    {
        cout << "\n\tRecord not found" << endl
             << endl;
        cin.ignore();
        system("pause");
        system("cls");
    }
}
void update(long int x1) // for update records //
{
    bool cntrl = 0;
    fstream up;
    up.open("studentInfo.txt", ios::in | ios::out | ios::ate | ios::binary);
    up.seekg(0);
    up.read((char *)&s1, sizeof(s1));
    while (!up.eof())
    {
        if (s1.getrn() == x1)
        {
            s1.setdata();
            up.seekp(up.tellp() - sizeof(s1));
            up.write((char *)&s1, sizeof(s1));
        }
        else
        {
            up.read((char *)&s1, sizeof(s1));
            cntrl = 1;
        }
    }
    up.close();
    if (cntrl == 1)
        cout << "\nRecord not found !!!" << endl;
    else
        cout << "\nRecord has been updated successfully" << endl;
    system("pause");
    system("cls");
}
void remove_data(long int x2) // For delete records //
{
    int flag = 0;
    fout.open("studentInfo.txt", ios::in);
    if (!fout)
        cout << "\nFile not found.." << endl;
    else
    {
        fin.open("temp.txt", ios::out);
        while (fout.read((char *)&s1, sizeof(s1)))
        {
            if (s1.getrn() != x2)
                fin.write((char *)&s1, sizeof(s1));
            else
                flag++;
        }
        if (flag != 1)
            cout << "Record not found...\n";
        else
            cout << "Record Deleted successfully." << endl;
        fout.close();
        fin.close();
        remove("studentInfo.txt");
        rename("temp.txt", "studentInfo.txt");
    }
}
int main()
{
    //  system("cls");
    // add_record();

    while (1)
    {
        welcome();
    back:
        char m;
        cout << "\n\t\t\t\t\t\t\t\t+--------------------+\t+------------------+\t+-----------+";
        cout << "\n\t\t\t\t\t\t\t\t| 1.-> Login Student |\t| 2.-> Login Admin |\t| 3.-> Exit |" << endl;
        cout << "\t\t\t\t\t\t\t\t+--------------------+\t+------------------+\t+-----------+\n\n\t";
        Sleep(100);
        m = getch();
        switch (m)
        {
        case '1':
            system("cls");
            login_student();
            system("pause");
            break;
        case '2':
            system("cls");
            login_admin();
            system("cls");
            cout << setw(101) << setfill('-') << "\n";
            cout << setw(27) << "\t\t\t\t| Welcome To Student Database |" << endl;
            cout << setw(100) << setfill('-') << "";
            while (1)
            {
                // main:
                animate.setcolor(animate.random_normalclr());
                char n;
                Sleep(400);
                cout << "\n\t+--------------------+\t+---------------------+\t+---------------------+";
                cout << "\n\t| 1.-> Add Student   |\t| 2.-> Delete Student |\t| 3.-> Search Student |" << endl;
                cout << "\t+--------------------+\t+---------------------+\t+---------------------+\n\n\t";
                Sleep(200);
                cout << "\n\t+--------------------+\t+---------------------+\t+---------------------+";
                cout << "\n\t| 4.-> Show Students |\t| 5.-> Update Student |\t| 6.-> Go Back <----- |" << endl;
                cout << "\t+--------------------+\t+---------------------+\t+---------------------+\n\n\t";
                Sleep(100);
                cout << "\n\t\t\t\t+---------------------+\t";
                cout << "\n\t\t\t\t| 7.->     Exit       |\t" << endl;
                cout << "\t\t\t\t+---------------------+\t\n\t";
                Sleep(100);
                cout << "\n\tPlease Enter Your choice" << endl
                     << "\t";
                cin >> n;
                switch (n)
                {
                case '1':
                    system("cls");
                    add_record();
                    break;
                case '2':
                    long int x2;
                    cout << "Enter Roll no. " << endl;
                    cin >> x2;
                    remove_data(x2);
                    system("pause");
                    system("cls");
                    break;
                case '3':
                    bool loop;
                    loop = true;
                    while (loop == true)
                    {

                        // }
                        system("cls");
                        char p;
                        cout << "\n\t\t\t\tSearch Student By -:)" << endl;
                        cout << "\n\t+--------------------+\t+------------------------+\t+----------------+";
                        cout << "\n\t| 1.-> Roll Number   |\t| 2.-> Enrollment number |\t| 3.-> Full Name |" << endl;
                        cout << "\t+--------------------+\t+------------------------+\t+----------------+\n\n\t";
                        cout << "\n\t+------------------+\t";
                        cout << "\n\t| 4.-> Main Menu   |" << endl;
                        cout << "\t+------------------+\t\n\n\t";
                        cin >> p;
                        switch (p)
                        {
                        case '1':
                        {
                            system("cls");
                            long int n;
                            cout << "Enter The Roll no. of the student" << endl;
                            cin >> n;
                            search(n);
                            break;
                        }
                        case '2':
                        {
                            system("cls");
                            long int en;
                            cout << "Enter the Enrollment Number " << endl;
                            cin >> en;
                            senrl(en);
                            break;
                        }
                        case '3':
                        {
                            system("cls");
                            char n[30];
                            cout << "Enter Name of student" << endl;
                            cin.ignore();
                            cin.getline(n, 30);
                            sname(n);
                            break;
                        }
                        case '4':
                        {
                            loop = false;
                            // setfill(' ');
                            cout << "Loading" << setw(20) << "";
                            animate.loading(45, 15);
                            // for (int i = 0; i < 3; i++)
                            // {
                            //     cout << ".";
                            //     Sleep(300);
                            // }
                            cout << endl;
                            system("cls");
                            // goto main;
                            break;
                        default:
                            system("cls");
                            cout << "Invalid choice please enter propper choice" << endl;
                            system("pause");
                            break;
                        }
                        }
                    }
                    break;
                case '4':
                {
                    system("cls");
                    display();
                    break;
                }
                case '5':
                    long int rn;
                    cout << "Enter the roll number of the student" << endl;
                    cin >> rn;
                    update(rn);
                    break;
                case '6':
                    system("cls");
                    goto back;
                    break;
                case '7':
                    system("cls");
                    cout << "\t\t\t\tThank You for using our application !!!" << endl;
                    cout << "\t\t\t\t";
                    for (int i = 0; i < 35; i++)
                    {
                        char b2 = 177;
                        int delay = 0 /*(Offset)*/ + (rand() % 151 /*(RANGE+OFFSET)*/);
                        cout << b2;
                        Sleep(delay);
                    }
                    cout << "\n\n";
                    exit(0);
                default:
                    system("cls");
                    cout << "Please Choose correct option !!!" << endl;
                }
            }
            break;
        case '3':
            system("cls");
            cout << "\t\t\t\tThank you for using our application .\n"
                 << endl;
            cout << "\t\t\t\t";
            for (int i = 0; i < 35; i++)
            {
                char b2 = 177;
                int delay = 0 /*(Offset)*/ + (rand() % 151 /*(RANGE+OFFSET)*/);
                cout << b2;
                Sleep(delay);
            }
            cout << "\n\n";
            exit(0);
            break;
        default:
            cout << "\tPlease choose a proprer option !!!" << endl;
            system("color 15");
            cout << "\tLoading ";
            for (int i = 0; i < 3; i++)
            {
                cout << ".";
                Sleep(800);
            }
            Sleep(1000);
        }
    }
    return 0;
}
