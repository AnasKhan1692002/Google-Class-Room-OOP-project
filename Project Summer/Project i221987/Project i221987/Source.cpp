#pragma once

#include <iostream>
#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
#include <iomanip>
#include<cstdlib>
#include <conio.h>
#include <ctime>
#include <assert.h>

using std::getline;
using std::cin;
using std::cout;
using namespace std;

class Submissions;
class Class_Managment;
class Time;
class Teacher;


class FileManagment
{
public:
    string* ReadData(string Path)
    {
        int Lenght = 0;
        string* StoreFile = new string[500];
        ifstream Read(Path);

        if (!Read) { cout << "No Such file Exits" << endl; assert(!Read.fail()); }//error Eeman Ijaz
        else
        {
            string lines;
            while (getline(Read, lines))
            {
                StoreFile[Lenght] = lines;
                Lenght++;
            }
            StoreFile[Lenght] = "\0";
        }
        Read.close();
        return StoreFile;
    }

    void WriteData(string Path, string Data)
    {
        ofstream Write(Path, ios::app);

        if (!Write) { cout << "No Such file Exits" << endl; assert(!Write.fail()); }

        Write << Data << endl;
        Write.close();
    }
};

class User
{
private:
    string Name;
    string Role;
    string E_Mail;
    string ID;
    string Contact_Number;
    string Password;

public:

    void setName(string name) { Name = name; }
    void setID(string id) { ID = id; }
    void ReadPassword(string Pass) { Password = Pass; }
    void sete_Mail(string e_Mail) { E_Mail = e_Mail; }
    void setContactNumber(string contact_Number) { Contact_Number = contact_Number; }    // base class having private members Name Password And ID
    void setRole(string role) { Role = role; }
    void changePassword(string PassChange) { Password = PassChange; }

    string getName() { return Name; }
    string getID() { return ID; }
    string getPassword() { return Password; }
    string getE_Mail() { return E_Mail; }
    string getContact() { return Contact_Number; }
    string getRole() { return Role; }


    bool login()
    {
        string StrorePassWord = "";
        string StoreID = "";
        cout << setw(110) << "LOGIN\n";
        cout << endl;
        cout << setw(118) << "FAST NUCES GOOGLE CLASS " << endl;
        cout << endl;
        cout << endl;
        cout << "ID --->  " << ID << endl;
        cout << "Password --->  " << Password << endl;
        cout << endl;
        cout << endl;
        cout << "Pleas Enter you ID : " << endl;
        cin >> StoreID;                                                            // Login Form
        cout << endl;
        cout << "Pleas Enter you Password : " << endl;
        cin >> StrorePassWord;

        if (StoreID == ID && StrorePassWord == Password) { return true; }
        else
        {
            if (Password != StrorePassWord)
            {
                if (ID != StoreID) { system("cls"); cout << "\nwrong Password and ID ! " << endl; }

                else { system("cls"); cout << "\nwrong Password ! " << endl; }

            }
            else { system("cls"); cout << "\nWrong ID ! " << endl; }

            return false;
        }
    }

    string confirmPassword()
    {
        char pass[20] = { 0 };
        char character;
        int j = 0;
        int size = 0;

        for (int i = 0; Password[i] != '\0'; i++)
            size++;

        int cheak = 0;
        cheak = cheakpassword(Password, size);                                                // Password Validation
        while (cheak == 0)
        {
            cout << endl;
            cout << "The Password must contain The following :\n1. Lower Case\n1. Upper Case\n3. Digits\n4. Special Characters\n5. Lenght must be greater then 5  " << endl;
            cout << "\nEnter Password again : " << endl;

            while (j != 18)
            {
                character = _getch();

                if (character == '\b')
                    j--;
                else if (character == '\r')
                    break;
                else
                {
                    pass[j] = character;
                    j++;
                    cout << "*";
                }
            }
            pass[j] = '\0';
            for (int i = 0; i < j; i++)
            {
                Password += pass[i];
            }

            size = 0;
            for (int i = 0; Password[i] != '\0'; i++)
                size++;
            cheak = cheakpassword(Password, size);
        }
        return Password;
    }
    string confirmID()
    {
        int size = 0;

        for (int i = 0; ID[i] != '\0'; i++)
            size++;

        int cheak = 0;
        cheak = cheakID(ID, size);
        // ID Validation
        while (cheak == 0)
        {
            cout << endl;
            cout << "Pleas Enter Correct ID -- ID is 7 Figur long and starts with batch number and Followed bt I ( 22I - 1987 ) : " << endl;
            cin >> ID;

            size = 0;

            for (int i = 0; ID[i] != '\0'; i++)
                size++;

            cheak = cheakID(ID, size);
        }
        return ID;
    }
};


class Time
{
private:
    int Hour;
    int Min;
    int Sec;
    int Day;
    int Month;
    int Year;

public:

    Time()
    {
        Day = 0;
        Month = 0;
        Year = 0;
        Hour = 0;
        Min = 0;
        Sec = 0;
    }

    void setDay(int D) { Day = D; }
    void setMonth(int M) { Month = M; }
    void setYear(int Y) { Year = Y; }
    int getDay() { return Day; }
    int getMonth() { return Month; }
    int getYear() { return Year; }
    void setH(int H) { Hour = H; }
    void setMin(int M) { Min = M; }
    int getH() { return Hour; }
    int getMin() { return Min; }

    Time& operator=(const Time& other)
    {

        if (this == &other) { return *this; }

        Day = other.Day;
        Month = other.Month;
        Year = other.Year;
        Hour = other.Hour;
        Min = other.Min;
        Sec = other.Sec;

        return *this;
    }

    bool ValidatStartEndTimeDate(Time& Deadline, string AssigmentName, string teacherName)
    {
        ifstream ReadDateTime;
        string Path = "Teacher/Assignments/Questions/" + teacherName + "/" + AssigmentName + "Deadline.txt";

        ReadDateTime.open(Path);
        int Data;
        string text;
        if (!ReadDateTime)
        {
            cout << "Deadline is Not Set Please Set the Dealine First ! " << endl;
            cout << endl;
            char Pause1;
            cout << "Press Any Key !" << endl;
            Pause1 = _getch();
            return false;
        }
        while (getline(ReadDateTime, text))
        {
            Data = stoi(text);
            Deadline.setYear(Data);
            getline(ReadDateTime, text);
            Data = stoi(text);
            Deadline.setMonth(Data);
            getline(ReadDateTime, text);
            Data = stoi(text);
            Deadline.setDay(Data);
            getline(ReadDateTime, text);
            Data = stoi(text);
            Deadline.setH(Data);
            getline(ReadDateTime, text);
            Data = stoi(text);
            Deadline.setMin(Data);

        }

        time_t Timing = time(nullptr);

        struct tm CurrentTime;
        localtime_s(&CurrentTime, &Timing);

        if (CurrentTime.tm_year + 1900 <= Deadline.getYear())
        {
            if (CurrentTime.tm_year + 1900 < Deadline.getYear())
                return true;

            if (CurrentTime.tm_mon + 1 <= Deadline.getMonth())
            {
                if (CurrentTime.tm_mon + 1 < Deadline.getMonth())
                    return true;

                if (CurrentTime.tm_mday <= Deadline.getDay())
                {
                    if (CurrentTime.tm_mday < Deadline.getDay())
                        return true;

                    if (CurrentTime.tm_hour <= Deadline.getH())
                    {
                        if (CurrentTime.tm_hour < Deadline.getH())
                            return true;

                        if (CurrentTime.tm_min <= Deadline.getMin())
                        {
                            return true;
                        }
                        else
                        {
                            cout << endl << "Deadline Has Expired ! " << endl;
                            cout << endl;
                            char Pause1;
                            cout << "Press Any Key !" << endl;
                            Pause1 = _getch();
                            return false;
                        }
                    }
                    else
                    {
                        cout << endl << "Deadline Has Expired ! " << endl;
                        cout << endl;
                        char Pause1;
                        cout << "Press Any Key !" << endl;
                        Pause1 = _getch();
                        return false;
                    }
                }
                else
                {
                    cout << endl << "Deadline Has Expired ! " << endl;
                    cout << endl;
                    char Pause1;
                    cout << "Press Any Key !" << endl;
                    Pause1 = _getch();
                    return false;
                }
            }
            else
            {
                cout << endl << "Deadline Has Expired ! " << endl;
                cout << endl;
                char Pause1;
                cout << "Press Any Key !" << endl;
                Pause1 = _getch();
                return false;
            }
        }
        else
        {
            cout << endl << "Deadline Has Expired ! " << endl;
            cout << endl;
            char Pause1;
            cout << "Press Any Key !" << endl;
            Pause1 = _getch();
            return false;
        }
    }



    friend ostream& operator<<(ostream& output, Time& out);

};

class Assignment_Managment
{
    string Title;
    string Descriptions;
    Time* Deadline;
    int Points;
    bool Assignment_Status = false;

public:
    Assignment_Managment()
    {
        Title = "";
        Descriptions = "";
        Points = 0;
        Assignment_Status = true;
    }

    Assignment_Managment(string teacher)
    {
        Title = "";
        Descriptions = "";
        Points = 0;
        Assignment_Status = true;

        cout << endl;
        string folderName = teacher;
        string directoryPath = "Teacher\\Assignments\\Questions\\";

        string fullFolderPath = directoryPath + folderName;

        ofstream file;

        if (system(("mkdir \"" + fullFolderPath + "\"").c_str()) == 0) {
            cout << "Folder for " << teacher << " Assignments created successfully.\n";
        }
        else {
            cout << "Failed to create Assingment Folder.\n";
        }
        char Pause;
        cout << endl;
        cout << "Press any KEY to go BACK  : " << endl;
        Pause = _getch();
        system("cls");
    }

    Assignment_Managment(string title, string descriptions, Time& deadline, int points)
    {
        Title = title;
        Descriptions = descriptions;
        Deadline = &deadline;
        Points = points;
        Assignment_Status = true;
    }

    string getTitle() const { return Title; }
    string getDescriptions() const { return Descriptions; }
    Time getDeadline() const { return *Deadline; }
    int getPoints() const { return Points; }

    void setTitle(string title) { Title = title; }
    void setDescriptions(string descriptions) { Descriptions = descriptions; }
    void setDeadline(Time& deadline) { Deadline = &deadline; }
    void setPoints(int points) { Points = points; }

    void CreateAssignment(string teachercourse, string teacherName)
    {
        string AssignmentNumber;
        cin.ignore();
        cout << endl << "Enter Assignment Number # ";
        cin >> AssignmentNumber;

        Title = teachercourse + AssignmentNumber;
        ofstream PrintQuestions("Teacher/Assignments/Questions/" + teacherName + "/" + Title + ".txt");
        if (!PrintQuestions)
        {
            if (!PrintQuestions) { cout << "Failed to open file -> PLease try agian or Re-chech the location of the Assingment.txt file : " << endl; assert(!PrintQuestions.fail()); return; }

        }
        PrintQuestions << setw(118) << "Assignment " << AssignmentNumber << endl << endl << endl;
        cout << endl << "Enter the Total Marks of the Assignment : "; cin >> Points; cout << endl;
        cout << endl;
        cout << "Enter The Discriptions- > " << endl;
        cin.ignore();
        getline(cin, Descriptions);
        PrintQuestions << Title << endl << endl << endl;
        PrintQuestions << "Total Score : " << Points << endl << endl;
        PrintQuestions << "Instructions" << endl << "[ " << Descriptions << " ]" << endl << endl;

        system("cls");
        int QuestionsCount = 1;
        for (int i = 0; i < QuestionsCount; i++)
        {
            system("cls");
            cout << endl;
            int Type;
            cout << endl;
            cout << "Which Type : " << endl;
            cout << "1. Subjective\n2. Objective\n3. True/False\n4. Exit" << endl << endl << "Choice :  ";
            cin >> Type;
            cout << endl;
            if (Type == 1)
            {
                PrintQuestions << endl << "[ Answer the Following Qestions Subjecive ] " << endl << endl;
                cin.ignore();
                string Questions;
                cout << "Enter the Question : " << i + 1 << " [ Press Enter To Proceed ] " << endl << endl; cout << "Q" << i + 1 << " : ";
                getline(cin, Questions);
                PrintQuestions << "Q" << i + 1 << ". " << Questions << "?" << endl; int choice;
                cout << endl; cout << "Enter 1 for Next Q - OR - 0 for Exit : "; cin >> choice; cout << endl;
                if (choice)
                    QuestionsCount++;
                else if (choice == 0)
                    break;
            }
            else if (Type == 2)
            {
                PrintQuestions << endl << "[ Select one of the Options [ A - B - C - D ] for the Following Questions ]" << endl << endl;
                cin.ignore();
                char Alpha = 'A';
                string Options[4];
                string Questions;

                cout << endl << "Enter the Question : " << i + 1 << ". " << " [ Press Enter To Proceed ] " << endl << endl; cout << "Q" << i + 1 << " : ";
                getline(cin, Questions); cout << endl << endl;

                PrintQuestions << "Q" << i + 1 << ". " << Questions << "?" << endl;

                cout << "Enter The Options : " << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << "(" << Alpha++ << ")  "; getline(cin, Options[i]);
                    PrintQuestions << char(Alpha - 1) << ": " << Options[i] << endl;
                }
                PrintQuestions << endl;
                int choice;
                cout << endl; cout << "1 for Next Q -- 0 for Exit : "; cin >> choice; cout << endl;
                if (choice)
                    QuestionsCount++;
                else if (choice == 0)
                    break;
            }
            else if (Type == 3)
            {
                PrintQuestions << endl << "[ Answer By Either True Or False in the following Questions ]" << endl << endl;
                cin.ignore();
                string Questions;
                cout << endl << "Enter the Question : " << i + 1 << ". " << " [ Press Enter To Proceed ] " << endl << endl; cout << "Q" << i + 1 << " : ";
                getline(cin, Questions);
                PrintQuestions << "Q" << i + 1 << ". " << Questions << "?" << endl;
                PrintQuestions << "1. True\n2. False" << endl << endl;

                int choice;
                cout << endl; cout << endl << "1 for Next Q -- 0 for Exit : "; cin >> choice; cout << endl;
                if (choice)
                    QuestionsCount++;
                else if (choice == 0)
                    break;
            }
            else
            {
                cout << endl << "Wrong Input! " << endl;
                system("cls");
                QuestionsCount++;
            }
        }
        PrintQuestions << "END";
    }

    void nullAssignment()
    {
        Title = "";
        Descriptions = "";
        Deadline = NULL;
        delete Deadline;
        Points = 0;
        Assignment_Status = false;
    }
    void ShowAssignment(string teacher)
    {
        system("cls");
        if (Assignment_Status == false)
        {
            cout << endl;
            cout << "No Assignment Created: " << endl;
            cout << endl;
            char Pause1;
            cout << "Press Any Key !" << endl;
            Pause1 = _getch();
        }
        else
        {
            FileManagment FM;
            string Name;
            cin.ignore();
            cout << "Enter the Name of the Assignment : " << endl;
            getline(cin, Name);
            string* StoreFile;
            StoreFile = FM.ReadData("Teacher/Assignments/Questions/" + teacher + "/" + Name + ".txt");

            for (int i = 0; i < 50; i++)
            {
                cout << StoreFile[i] << endl;
            }

            cout << endl << endl;
            char Pause;
            cout << "Press Any Key !" << endl;
            Pause = _getch();
        }
    }

    void UpdateAssignment(string teacher)
    {
        FileManagment FM;
        string Name;
        cin.ignore();
        system("cls");
        cout << "Enter the Name of the Assignment : " << endl;
        getline(cin, Name);
        string* StoreFile;
        StoreFile = FM.ReadData("Teacher/Assignments/Questions/" + teacher + "/" + Name + ".txt");
        cout << endl;
        system("cls");
        for (int i = 0; i < 50; i++)
        {
            cout << i + 1 << ". " << StoreFile[i] << endl;
        }

        cout << endl;
        cout << endl;
        int choiceJ;
        cout << "Do You Want to Update This Assignment [ 1 - 0 ] :  "; cin >> choiceJ;

        if (choiceJ)
        {
            int Edit = 1;
            int LineNumber;
            for (int i = 0; i < Edit; i++)
            {
                cout << "Enter Which Line To Edit -> 1 . 2 . 3 etc Press [ 0 ] To stop Editing  : "; cin >> LineNumber;
                if (LineNumber)
                {
                    string EditData;
                    cout << "Enter Data to Replace" << endl;
                    cin.ignore();
                    getline(cin, EditData);

                    StoreFile[LineNumber - 1] = EditData;
                    Edit++;

                }
                else
                {
                    ofstream printAssig("Teacher/Assignments/Questions/" + teacher + "/" + Name + ".txt", ios::out);
                    for (int i = 0; i < 25; i++)
                    {
                        printAssig << StoreFile[i] << endl;
                        cout << StoreFile[i] << endl;
                    }
                    printAssig.close();
                    char Pause;
                    cout << "Press Any Key!" << endl;
                    Pause = _getch();
                    break;
                }
            }
        }
        else
        {
            int choicek;
            cout << "Do You Want to Update other Assignment or Exit [ 1 - 0 ] :  "; cin >> choicek;
            if (choicek)
            {
                string Name;
                cin.ignore();
                cout << "Enter the Name of the Assignment : " << endl;
                getline(cin, Name);
                string* StoreFile;
                StoreFile = FM.ReadData("Teacher/Assignments/Questions/" + teacher + "/" + Name + ".txt");

                cout << endl << endl;
                char Pause;
                cout << "Press Any Key to go to Edit Mode!" << endl;
                Pause = _getch();

                int Edit = 1;
                int LineNumber;
                for (int i = 0; i < Edit; i++)
                {
                    cout << "Enter Which Line To Edit -> 1 . 2 . 3 etc Press [ 0 ] To stop Editing  : "; cin >> LineNumber;
                    if (LineNumber)
                    {
                        string EditData;
                        cout << "Enter Data to Replace" << endl;
                        cin.ignore();
                        getline(cin, EditData);

                        StoreFile[LineNumber - 1] = EditData;
                        Edit++;
                    }
                    else
                    {
                        ofstream printAssig("Teacher/Assignments/Questions/" + teacher + "/" + Name + ".txt", ios::out);
                        for (int i = 0; i < 25; i++)
                        {
                            printAssig << StoreFile[i] << endl;
                            cout << StoreFile[i] << endl;
                        }
                        printAssig.close();
                        char Pause;
                        cout << "Press Any Key!" << endl;
                        Pause = _getch();
                        break;
                    }
                }
            }
            else
            {
                system("cls");
                cout << "Not Edited !" << endl;
                return;
            }
        }

        cout << endl << endl;
        char Pause;
        cout << "Press Any Key to exit !" << endl;
        Pause = _getch();
        Pause = _getch();
    }
};

class GradeBook;
class Teacher : public User // teacher Class inherited from user
{
private:
    string CourseAssigned;

public:
    Submissions* S;
    Assignment_Managment* AM;
    Class_Managment* CM;
    GradeBook* GB;

    void setTeacherCourse(string Course) { CourseAssigned = Course; } // Gettersa and setters
    string getAssignedCourse() { return CourseAssigned; }

    friend istream& operator>>(istream& input, Teacher& in);
    friend ostream& operator<<(ostream& output, Teacher& out);
};


class Submissions
{
    Teacher* Class_Teacher;
    Time* time;
public:
    Submissions(Teacher* teacher)
    {
        Class_Teacher = teacher;
        time = new Time();
    }
    void Create_Submission()
    {

        cin.ignore();
        string AssigName;
        cout << "Enter Assignment Name : "; getline(cin, AssigName);
        string folderName = AssigName + "Submissions\\";
        string directoryPath = "D:\\Project Summer\\Project i221987\\Project i221987\\Class_Managment\\" + Class_Teacher->getName() + "Class\\";

        string fullFolderPath = directoryPath + folderName;

        bool DealineExist = time->ValidatStartEndTimeDate(*time, AssigName, Class_Teacher->getName());
        if (DealineExist == false)
            return;
        else {
            ofstream file;
            cout << endl;
            if (system(("mkdir \"" + fullFolderPath + "\"").c_str()) == 0) {
                cout << "Submission for " << AssigName << " created successfully.\n";
            }
            else {
                cout << "Failed to create Submissions.\n";
            }
        }

    }

};

class Student : public User
{
    // Student Class inherited from user
private:
    string Course;
    float score;
    Time* time;

public:
    Student()
    {
        time = new Time();
        score = 0;
    }

    Student& operator=(const Student& other) {
        if (this == &other) { return *this; }

        score = other.score;
        Course = other.Course;

        User::operator=(other);

        return *this;
    }
    string* Show_Submited_Assignments(string Courses)
    {

        string FoundTeacher = FinderStudentTeacher(Courses);
        FileManagment FM;
        string* StoreFile;
        string Paths = "Class_Managment/" + (FoundTeacher + "Class/");
        StoreFile = FM.ReadData(Paths + "Assignments_Details.txt");

        return StoreFile;
    }
    bool CheakIF_StudentIs_Enrolled(Student Stu)
    {
        string FoundTeacher = FinderStudentTeacher(Stu.getStudentCourse());
        string Paths = "Class_Managment/" + (FoundTeacher + "Class/");

        FileManagment FM;
        string* StoreFile;

        StoreFile = FM.ReadData(Paths + Stu.getStudentCourse() + "Enrolled.csv");

        for (int i = 0; i < 50; i++)
        {
            if (StoreFile[i] == Stu.getID())
                return true;

        }
        return false;
    }
    void Do_Assignment(string Path, Student Std)
    {
    Back:
        FileManagment FM;
        string* StoreFile;

        StoreFile = FM.ReadData(Path);

        string FoundTeacher = FinderStudentTeacher(Std.getStudentCourse());
        string Paths = "Class_Managment/" + (FoundTeacher + "Class/");
        string AssignmentName;
        cin.ignore();
        for (int i = 0; i < 50; i++)
        {
            cout << StoreFile[i] << endl;
        }
        cout << endl;
        cout << "Enter Assignment Name (Specified in the Above Assignment): " << endl; getline(cin, AssignmentName);
        cout << endl;
        cout << endl;
        /* bool DealineExist = time->ValidatStartEndTimeDate(*time, AssignmentName, FoundTeacher);
         if (DealineExist == false)
             return;*/

        cout << endl;
        int ChoiceR;
        cout << "Attempt Assignment [ 1 - 0 ] : "; cin >> ChoiceR;
        if (ChoiceR == 1)
        {
            int END = 1;
            FM.WriteData(Paths + (AssignmentName + "Submissions\\") + Std.getID() + AssignmentName + ".txt", AssignmentName + " : Asweres --->");
            for (int i = 0; i < END; i++)
            {
                int ChoiceT;

                string Answer;
                cin.ignore();
                cout << "Q" << i + 1 << " =>\n\n" << "Enter Ansewer  : ";
                getline(cin, Answer);
                FM.WriteData(Paths + (AssignmentName + "Submissions\\") + Std.getID() + AssignmentName + ".txt", "Answere :  " + Answer);
            Again:
                cout << "Attempt Next Question :"; cin >> ChoiceT;
                if (ChoiceT == 1)
                    END++;
                else if (ChoiceT == 0)
                {
                    break;
                }
                else
                {
                    cout << "Wrong input!";
                    goto Again;
                }
            }
        }
        else if (ChoiceR == 0)
        {
            return;
        }
        else
        {
            cout << "Wrong input!" << endl;
            system("cls");
            goto Back;
        }

    }
    void SetStudentCourse(string course) { Course = course; }
    string getStudentCourse() { return Course; }
    void setscore(float sc) { score = sc; }                                        // Gettersa and setters
    float getscore() { return score; }

    friend istream& operator>>(istream& input, Student& in);
    friend ostream& operator<<(ostream& output, Student& out);
};


class GradeBook
{
public:
    void Grade$Cheak(string teacherName)
    {
        cin.ignore();
        string StudentID;
        cout << endl;
        cout << "Enter Assignment Name : "; string AssignmentName;
        getline(cin, AssignmentName);
        cout << endl;
        cout << "Enter Student ID : "; cin >> StudentID;
        string FileName = StudentID + AssignmentName;
        string Path = "Class_Managment/" + teacherName + "Class" + "/" + AssignmentName + "Submissions/" + FileName + ".txt";
        string PathGradeBook = "Class_Managment/" + teacherName + "GradeBook.csv";
        FileManagment FM;
        string* StoreFile;

        StoreFile = FM.ReadData(Path);

        for (int i = 0; i < 5; i++)
        {
            cout << StoreFile[i] << endl;
        }
        cout << endl;
    ScoreAgain:
        int Score;
        cout << "Enter The Markings : " << endl;
        cin >> Score;
        if (Score > 100)
        {
            cout << "Score Cannot be greater then 100" << endl << endl;
            goto ScoreAgain;
        }

        ofstream Write(PathGradeBook, ios::app);

        if (!Write)
        {
            cout << "Failed to open file -> PLease try agian or Re-chech the location of file : " << endl;
            return;
        }

        Write << AssignmentName << "," << StudentID << "," << Score << endl;
        Write.close();
    }
};

class Class_Managment
{
    string ClassName;
    string Subject;
    Teacher* ClassTeacher;
    Student* Enrolled_Student = new Student[217];
    int Num_Student_Enrolled;
    static int StdNum;
    bool ClassStatus = false;
    string* AssignmentsDetails = new string[100];
    static int AssignmentCount;
    string* AssignmentNames = new string[100];


public:
    Class_Managment(string name, Teacher& teacher)
    {
        ClassName = name;
        teacher.sete_Mail(teacher.getName() + "." + teacher.getAssignedCourse() + "@nu.edu.pk");
        teacher.setContactNumber("03189426258");
        teacher.setRole("Teacher");
        Subject = teacher.getAssignedCourse();
        ClassTeacher = &teacher;

        ClassStatus = true;

        string folderName = teacher.getName() + "Class\\";
        string directoryPath = "D:\\Project Summer\\Project i221987\\Project i221987\\Class_Managment\\";

        string fullFolderPath = directoryPath + folderName;

        ofstream file;

        if (system(("mkdir \"" + fullFolderPath + "\"").c_str()) == 0) {
            cout << "Class for " << teacher.getName() << " created successfully.\n";
        }
        else {
            cout << "Failed to create class.\n";
        }
        PrintTeacherData(*ClassTeacher);
    }
    Class_Managment(Student Std[], Teacher teacher)
    {
        FileManagment FM;

        ClassName = "";
        Subject = "";
        ClassTeacher = &teacher;
        StdNum = 0;

        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        string StoreName = (teacher.getAssignedCourse() + "Enrolled.csv");
        string* StoreFile;

        StoreFile = FM.ReadData(Paths + StoreName);

        int j = 0;
        for (int i = 0; i < 217; i++)
        {
            if (Std[i].getID() == StoreFile[j])
            {
                Enrolled_Student[StdNum] = Std[i];
                StdNum++;
                j++;
            }
        }


        ClassStatus = true;
    }

    void setName(string name) { ClassName = name; }
    void setSubject(string subject) { Subject = subject; }
    void setClassTeacher(Teacher& techername) { ClassTeacher = &techername; }

    void EnrolleStudents(Student Std[], Teacher teacher)
    {
        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        string StoreName = (teacher.getAssignedCourse() + "Enrolled.csv");

        ofstream file(Paths + StoreName, ios::out);

        if (!file) {
            cout << "Failed to open file -> PLease try agian or Re-chech the location of the Enrolled_Student.csv file : " << endl; assert(!file.fail()); return;
        }

        for (int i = 0; i < 217; i++)
        {
            if (Std[i].getStudentCourse() == teacher.getAssignedCourse())
            {
                Enrolled_Student[StdNum] = Std[i];
                file << Enrolled_Student[StdNum].getID() << endl;
                StdNum++;
            }
        }
        char Pause;
        cout << "Press Any Key !" << endl;
        Pause = _getch();
        file.close();
    }

    void AddStudent(Student& Std, Teacher teacher)
    {
        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        string StoreName = (teacher.getAssignedCourse() + "Enrolled.csv");
        ofstream file(Paths + StoreName, ios::app);

        if (!file) {
            cout << "Failed to open file -> PLease try agian or Re-chech the location of the Enrolled_Student.csv file : " << endl; assert(!file.fail());
        }

        file << Std.getID() << endl;
        Enrolled_Student[StdNum] = Std;
        StdNum++;

        file.close();
    }

    void RemoveStudent(Student& Std, Teacher teacher)
    {
        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        string StoreName = (teacher.getAssignedCourse() + "Enrolled.csv");
        ofstream file(Paths + StoreName, ios::out);

        if (!file) {
            cout << "Failed to open file -> PLease try agian or Re-chech the location of the Enrolled_Student.csv file : " << endl; assert(!file.fail());  return;
        }

        for (int i = 0; i < StdNum; i++)
        {
            if (Std.getID() == Enrolled_Student[i].getID())
            {
                for (int j = i; j < StdNum; j++) { Enrolled_Student[j] = Enrolled_Student[j + 1]; }
            }
        }
        StdNum--;

        for (int i = 0; i < StdNum; i++) { file << Enrolled_Student[i].getID() << endl; }
        file.close();
    }
    void SubmiteAssignment(Teacher teacher)
    {
        string Paths = "D:/Project Summer/Project i221987/Project i221987/Class_Managment/" + (teacher.getName() + "Class/");
        cin.ignore();
        FileManagment FM;
        string AssigName;
        string AssignmentLocation;
        string* StoreFile;
        cout << "Enter Assignment Name : "; getline(cin, AssigName); cout << endl << endl;
        system("cls");

        StoreFile = FM.ReadData("Teacher/Assignments/Questions/" + teacher.getName() + "/" + AssigName + ".txt");

        for (int i = 0; i < 50; i++)
        {
            FM.WriteData(Paths + AssigName + ".txt", StoreFile[i]);
        }

        FM.WriteData(Paths + "Assignments_Details.txt", AssigName + ".txt");
        FM.WriteData(Paths + "Assignments_Details.txt", Paths + AssigName + ".txt");

        AssignmentCount++;
    }
    void Show(Teacher teacher)
    {
        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        if (ClassStatus == false)
        {
            cout << endl;
            cout << "No Class Creted For : " << teacher.getAssignedCourse() << endl;
            cout << endl;
            char Pause1;
            cout << "Press Any Key !" << endl;
            Pause1 = _getch();
        }
        else
        {
            cout << setw(30) << "Class" << endl << endl;
            cout << "Mr. " << teacher.getName() << endl;
            cout << "Course " << teacher.getAssignedCourse() << endl << endl;
            cout << "Class Name " << ClassName << endl;
            cout << "Subject " << Subject << endl << endl;
            cout << "Total Student Enrolled : " << StdNum << endl;

            int ChoiceC;
            cout << "See Enrolled Sudents [ 1 - 0 ] : "; cin >> ChoiceC;
            if (ChoiceC == 1)
            {
                for (int i = 0; i < StdNum; i++)
                {
                    cout << i + 1 << ". " << Enrolled_Student[i].getName() << endl;
                }

            }
            cout << endl << endl;
            char Pause;
            cout << "Press Any Key !" << endl;
            Pause = _getch();
        }

    }

    //void TeacherClasses(Teacher teacher)
    //{
    //    string StoreName = (teacher.getAssignedCourse() + "Enrolled.csv");
    //    string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
    //    string* Storefile;
    //    FileManagment FM;
    //    Storefile = FM.ReadData(Paths + StoreName);
    //    for (int i = 0; i < 60; i++)
    //    {
    //        Enrolled_Student
    //    }
    //    ClassName = "null";
    //    teacher.sete_Mail(teacher.getName() + "." + teacher.getAssignedCourse() + "@nu.edu.pk");
    //    teacher.setContactNumber("03189426258");
    //    teacher.setRole("Teacher");
    //    Subject = teacher.getAssignedCourse();
    //    ClassTeacher = &teacher;
    //    ClassStatus = true;
    //}

    void NUll(Teacher teacher)
    {
        string Paths = "Class_Managment/" + (teacher.getName() + "Class/");
        ClassStatus = false;
        ClassName = "";
        Subject = "";
        Num_Student_Enrolled = 0;
        StdNum = 0;

    }
};