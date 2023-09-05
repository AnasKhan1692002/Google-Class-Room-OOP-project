
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




bool cheakpassword(string password, int size)
{
    if (size < 6)
    {
        return 0;
    }

    int index = 0;
    int uppercase = 0, lowercase = 0, digits = 0, specail = 0;

    for (int j = 0; j < size; j++)
    {
        if (password[j] >= 'A' && password[j] <= 'Z') { uppercase++; }
        if (password[j] >= 'a' && password[j] <= 'z') { lowercase++; }                               // for cheaking password specs
        if (password[j] >= '1' && password[j] <= '9') { digits++; }
        if ((password[j] >= 33 && password[j] <= 47) || (password[j] >= 58 && password[j] <= 64) || (password[j] >= 91 && password[j] <= 96) || (password[j] >= 123 && password[j] <= 126)) { specail++; }
    }
    if (uppercase > 0 && lowercase > 0 && digits > 0 && specail > 0)
        return 1;
    else
        return 0;
}

//====================================================

bool cheakID(string id, int size)
{
    int a = 0, b = 0, c = 0;

    if (size != 7) { return 0; }

    if (id[0] == 105)
        a = 1;                                                      // for cheaikng ID sprcs

    if (id[1] == 49 || id[1] == 50 && id[2] == 49 || id[2] == 50)
        b = 1;

    if (id[3] >= 48 || id[3] <= 57 && id[4] >= 48 || id[4] <= 57 && id[5] >= 48 || id[5] <= 57 && id[6] >= 48 || id[6] <= 57)
        c = 1;

    if (a == 0 || b == 0 || c == 0)
        return 0;
    else
        return 1;
}
//int ChoiceH;
//cout << "Choice File Type\n\n1. TXT\n2. CSV\n3. XLXL\n\nChoice : "; cin >> ChoiceH; cout << endl << endl;
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
    
    void WriteData(string Path,string Data)
    {
        ofstream Write(Path,ios::app);
      
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


//---------------------------------------------------------------------------------------------------------------------------------------------------------------->

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

//=================================================================================

ostream& operator<<(ostream& output, Time& out)
{
    cout << endl;
    output << "Date : " << out.getDay() << " / " << out.getMonth() << " / " << out.getYear() << endl;
    output << "Time : " << out.getH() << " : " << out.getMin() << endl;
    cout << endl;
    return output;
}

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
            cout << "Folder for "<<teacher<<" Assignments created successfully.\n";
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

    void CreateAssignment(string teachercourse ,string teacherName)
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

                    StoreFile[LineNumber-1] = EditData;
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

                        StoreFile[LineNumber-1] = EditData;
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


//=====================================================

istream& operator>>(istream& input, Teacher& in)
{
    string cp = "";

    char pass[20] = { 0 };
    char character;          // hidden password Getter and Setter
    int j = 0;

    cout << "Pleas Enter you Password : " << endl;
   
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
        cp += pass[i];
    }
    in.changePassword(cp);
    in.confirmPassword(); cout << endl;

    return input;
}

//======================================================

ostream& operator<<(ostream& output, Teacher& out)
{
    output << "Your Name is : " << out.getName(); cout << endl;
    cout << endl;
    output << "Your Password is : " << out.getPassword(); cout << endl;
    output << "Your ID is : " << out.getID(); cout << endl;
    output << "Your Course is : " << out.CourseAssigned; cout << endl;
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    return output;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------->


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

string FinderStudentTeacher(string Course)
{
    string teacherName;
    if (Course == "Computer Science")
    {
        teacherName = "Hassan Mujtaba";
    }
    else if (Course == "Software Engeneering")
    {
        teacherName = "Abdul Hannan";
    }
    else if (Course == "Data Science ")
    {
        teacherName = "Mehran Jan";
    }
    else if (Course == "Artificial Intelligence")
    {
        teacherName = "Khalid";
    }
    else if (Course == "Cyber Security")
    {
        teacherName = "Usamn Rashid";
    }

    return teacherName;
}
//=============================================================================================
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
    void Do_Assignment(string Path,Student Std)
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
            FM.WriteData(Paths + (AssignmentName + "Submissions\\") + Std.getID() + AssignmentName + ".txt", AssignmentName+" : Asweres --->");
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

//=========================================================

istream& operator>>(istream& input, Student& in)
{
    string cp = "";

    char pass[20] = { 0 };
    char character;
    int j = 0;

    cout << "Pleas Enter you Password : " << endl;

    while (j != 18)
    {
        character = _getch();

        if (character == '\b')
            j--;                                 // hidden password Getter and Setters
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
        cp += pass[i];
    }
    in.changePassword(cp);
    in.confirmPassword(); cout << endl;

    return input;
}

//========================================================
ostream& operator<<(ostream& output, Student& out)
{
    output << out.getName() << "           " << out.getID() << "           " << out.getPassword() << "           " << out.getStudentCourse() << endl;

    return output;
}
void PrintTeacherData(Teacher& teacher)
{
    ofstream TeacherData("Class_Managment/"+teacher.getName() + "Class\\" + "TeacherDetais.csv", ios::app);

    if (!TeacherData)
    {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of file : " << endl;
        assert(!TeacherData.fail());
    }
    TeacherData << teacher.getName() << ",";
    TeacherData << teacher.getID() << ",";
    TeacherData << teacher.getE_Mail() << ",";
    TeacherData << teacher.getAssignedCourse() << ",";
    TeacherData << teacher.getContact() << ",";
    TeacherData << endl << endl;
    TeacherData.close();
}
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
        string Path = "Class_Managment/"+ teacherName +"Class" + "/" + AssignmentName+"Submissions/"+ FileName + ".txt";
        string PathGradeBook = "Class_Managment/" + teacherName +"GradeBook.csv";
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

            ofstream Write(PathGradeBook,ios::app);

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
            cout << "Class for "<<teacher.getName()<<" created successfully.\n";
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

int Class_Managment::StdNum = 0;
int Class_Managment::AssignmentCount = 1;

Time& SettingDateTime(Time& T, string AssignmentName,Teacher teacher)
{
    int day, months, years;
    ofstream SaveTime;

    SaveTime.open("Teacher/Assignments/Questions/" + teacher.getName() + "/" + AssignmentName + "Deadline.txt", ios::out);

    if (!SaveTime)
    {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of " << AssignmentName << " file : " << endl; assert(!SaveTime.fail());
    }
    system("cls");
    cout << endl;
    cout << "Set Year : ";
    cin >> years;
    T.setYear(years);
    cout << endl;
    SaveTime << T.getYear() << endl;

    cout << "Set Month : ";
    cin >> months;
    T.setMonth(months);
    cout << endl;
    SaveTime << T.getMonth() << endl;

    bool daybool = false;

    while (daybool == false)
    {
        cout << "Set Day : ";
        cin >> day;
        cout << endl;
        if (months == 2)
        {
            if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)
            {
                if (day <= 28)
                {
                    T.setDay(day);
                    SaveTime << T.getDay() << endl;
                    daybool = true;
                }
                else
                    cout << "Date Does not exist in this Month and Year " << endl;
            }
            else
            {
                if (day <= 29)
                {
                    T.setDay(day);
                    SaveTime << T.getDay() << endl;
                    daybool = true;
                }
                else
                    cout << "Date Does not exist in this Month and Year " << endl;
            }
        }
        else if (months == 4 || months == 6 || months == 9 || months == 11)
        {
            if (day <= 30)
            {
                T.setDay(day);
                SaveTime << T.getDay() << endl;
                daybool = true;
            }
            else
                cout << "Date Does not exist in this Month and Year " << endl;
        }
        else
        {
            if (day <= 31)
            {
                T.setDay(day);
                SaveTime << T.getDay() << endl;
                daybool = true;
            }
            else
                cout << "Date Does not exist in this Month and Year " << endl;
        }
    }
    system("cls");
    int h, M;
    cout << "TIME " << endl; cout << endl;
    cout << "Set Hour Use 24 Hour Formate : ";
    cin >> h;
    T.setH(h);
    cout << endl;
    SaveTime << T.getH() << endl;

    cout << "Set Minutes : ";
    cin >> M;
    T.setMin(M);
    cout << endl;
    SaveTime << T.getMin() << endl;
    system("cls");
    cout << endl << "Deadline : " << endl << endl;
    cout << "Date : " << T.getDay() << " / " << T.getMonth() << " / " << T.getYear() << endl;
    cout << "Time : " << T.getH() << " : " << T.getMin() << endl;

    ofstream PrintQuestions;

    PrintQuestions.open("Teacher/Assignments/Questions/" + teacher.getName() + "/" + AssignmentName + ".txt", ios::app);
    if (!PrintQuestions) {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of the .CSV file : " << endl;   assert(!PrintQuestions.fail());;
    }

    PrintQuestions << "Deadline--> " << T.getYear() << " / " << T.getMonth() << " / " << T.getDay() << endl;
    PrintQuestions << "At ------->. " << T.getH() << " : " << T.getMin() << " [O.Clock]" << endl;
    PrintQuestions << endl << "Good Luck" << endl;

    SaveTime.close();
    PrintQuestions.close();
    return T;
}

//=========================================================

void ReadStudentData(Student Class_Students[])
{
    ifstream file("Student/StudentDataBase.csv");

    if (!file) {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of the StudentDataBase.CSV file : " << endl;   assert(!file.fail());  return;
    }

    string CellData;
    char read;
    bool condition = false;
    int Row = 1, Column = 1, CellCountNames = 1, CellCountID = 1, CellCountCourse = 1;

    while (file.get(read))
    {
        if (read == '"') { condition = !condition; }
        else if (read == ',')
        {
            if (Column == 1) { Class_Students[CellCountID].setID(CellData); CellCountID++; }                       // Read from the file Name ID And Password 
            if (Column == 2) { Class_Students[CellCountNames].setName(CellData);  CellCountNames++; }
            if (Column == 3) { Class_Students[CellCountCourse].SetStudentCourse(CellData); CellCountCourse++; }
            CellData.clear();
            Column++;
        }
        else if (read == '\n') {
            if (Column == 1) { Class_Students[CellCountID].setID(CellData); CellCountID++; }                       // Read from the file Name ID And Password 
            if (Column == 2) { Class_Students[CellCountNames].setName(CellData);  CellCountNames++; }
            if (Column == 3) { Class_Students[CellCountCourse].SetStudentCourse(CellData); CellCountCourse++; }
            CellData.clear();
            Row++;
            Column = 1;
            condition = false;
        }
        else
        {
            if (!condition || read != '"') { CellData += read; }
        }
    }

    file.close();
}

void ReadTeacherData(Teacher teacher[])
{
    ifstream file("Teacher/TeacherDataBase.csv");

    if (!file) { cout << "Failed to open file -> PLease try agian or Re-chech the location of the StudentDataBase.CSV file : " << endl;   assert(!file.fail()); }

    string CellData;
    char read;
    bool condition = false;
    int Row = 1, Column = 1, CellCountNames = 1, CellCountID = 1, CellCountCourse = 1;

    while (file.get(read))
    {
        if (read == '"') { condition = !condition; }
        else if (read == ',')
        {
            if (Column == 1) { teacher[CellCountID].setID(CellData); CellCountID++; }                       // Read from the file Name ID And Password 
            if (Column == 2) { teacher[CellCountNames].setName(CellData); CellCountNames++; }
            if (Column == 3) { teacher[CellCountCourse].setTeacherCourse(CellData); CellCountCourse++; }
            CellData.clear();
            Column++;
        }
        else if (read == '\n') {
            if (Column == 1) { teacher[CellCountID].setID(CellData); CellCountID++; }                       // Read from the file Name ID And Password 
            if (Column == 2) { teacher[CellCountNames].setName(CellData); CellCountNames++; }
            if (Column == 3) { teacher[CellCountCourse].setTeacherCourse(CellData); CellCountCourse++; }
            CellData.clear();
            Row++;
            Column = 1;
            condition = false;
        }
        else
        {
            if (!condition || read != '"') { CellData += read; }
        }
    }

    file.close();
}

string Encrypt(string& Data)
{
    int j = 0;                                   // change password in sheets 


    for (int i = 0; Data[i] != '\0'; i++)
    {
        if (Data[i] > 47 && Data[i] < 58) { Data[i] -= 1; }
        else if (Data[i] > 64 && Data[i] < 91) { Data[i] -= 1; }
        else if (Data[i] > 96 && Data[i] < 123) { Data[i] -= 1; }
    }
    return Data;
}


string De_Encrypt(string& Data)
{
    int j = 0;                                   // change password in sheets 

    for (int i = 0; Data[i] != '\0'; i++)
    {
        if (Data[i] > 47 && Data[i] < 58) { Data[i] += 1; }
        else if (Data[i] > 64 && Data[i] < 91) { Data[i] += 1; }
        else if (Data[i] > 96 && Data[i] < 123) { Data[i] += 1; }
    }
    return Data;
}

void PasswordGetter(Student Class_Students[], Teacher teacher[])
{
    ifstream file("Password/Passwords_Teachers_Students.csv");

    if (!file) {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of the passwordfile.csv file : " << endl; assert(!file.fail());  return;
    }

    char read;
    bool condition = false;
    string CellData;
    int CellCoutStudent = 1, CellCoutTeacher = 1, Row = 1, Column = 1;

    while (file.get(read))
    {
        if (read == '"') { condition = !condition; }
        else if (read == ',') {
            if (Column == 1 && Row <= 216) { CellData = De_Encrypt(CellData); Class_Students[CellCoutStudent].ReadPassword(CellData);          CellCoutStudent++; }
            if (Column == 1 && Row >= 217) { CellData = De_Encrypt(CellData); teacher[CellCoutTeacher].ReadPassword(CellData);         CellCoutTeacher++; }
            CellData.clear();
            Column++;
        }
        else if (read == '\n') {
            if (Column == 1 && Row <= 216) { CellData = De_Encrypt(CellData); Class_Students[CellCoutStudent].ReadPassword(CellData);          CellCoutStudent++; }
            if (Column == 1 && Row >= 217) { CellData = De_Encrypt(CellData); teacher[CellCoutTeacher].ReadPassword(CellData); CellCoutTeacher++; }
            CellData.clear();
            Row++;
            Column = 1;
            condition = false;
        }
        else { if (!condition || read != '"') { CellData += read; } }
    }
    file.close();
}

//========================================================


int TeacherFinder(string PersonName, Teacher teacher[])
{
    for (int i = 0; i < 11; i++)
    {
        if (teacher[i].getName() == PersonName) { return i; }                                   // read usrname and return a number  (place )
    }
    return -1;
}

int StudentFinder(string PersonName, Student Class_Students[])
{
    for (int i = 0; i < 217; i++)
    {
        if (Class_Students[i].getName() == PersonName) { return i; }                                   // read usrname and return a number  (place )
    }
    return -1;
}

//=========================================================


void OverWritePasswords(Student Class_Students[], Teacher teacher[])
{
    ofstream overwrite;

    overwrite.open("Password/Passwords_Teachers_Students.csv");

    if (!overwrite)
    {
        cout << "Failed to open file -> PLease try agian or Re-chech the location of the passwordfile.csv file : " << endl;
        assert(!overwrite.fail());
    }

    int j = 0;                                   // change password in sheets 

    for (int i = 1; i <= 227; i++) {
        if (i >= 1 && i <= 216) {
            string CellDataStudent = Class_Students[i].getPassword();
            CellDataStudent = Encrypt(CellDataStudent);
            overwrite << CellDataStudent << endl;
        }

        if (i >= 217 && i <= 227) {

            string CellDataTeacher = teacher[j].getPassword();
            CellDataTeacher = Encrypt(CellDataTeacher);
            overwrite << CellDataTeacher << endl;
            j++;
        }
    }
    overwrite.close();

}

//===========================================================================================================================================================================
void Menu(Student Class_Students[], Teacher teacher[])
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(110) << "WELCOME\n";
    cout << endl;
    cout << setw(125) << "FAST NUCES Google Class Room Project " << endl;
    cout << setw(135) << "__________________________________________________________";
    cout << endl;
    cout << endl;
    char choiceA;

    Time* time;

    cout << "View Instructions  \n\n1. Yes Press [ Y ]\n2. NO Press [ N ]\n\nChoice  :  ";
    cin >> choiceA; cout << endl;

    if (choiceA == 'y' || choiceA == 'Y')
    {
        system("cls");
    instruction:
        cout << "Salam Aliakum !" << endl; cout << endl;
        cout << "Instructions -> Read Carefully" << endl; cout << endl;

        cout << "1.  Open a web browser and go to the Google Classroom website " << endl; cout << endl;
        cout << "2.  Sign in using your Google account (you can use your Gmail or G Suite for Education account)." << endl; cout << endl;
        cout << "3.  If you are a student, click on the + sign in the top-right corner and select Join class." << endl; cout << endl;
        cout << "4.  Enter the class code provided by your teacher and click Join." << endl; cout << endl;
        cout << "5.  Enter the class name, section, subject, and room (optional)." << endl; cout << endl;
        cout << "6.  Choose the appropriate settings and click Create to create the class." << endl; cout << endl;
        cout << "7.  To create an assignment, go to the Classwork tab and click Create and then Assignment." << endl; cout << endl;
        cout << "8.  Students can view assignments in the Classwork tab and click on an assignment to view the details." << endl; cout << endl;
        cout << endl;
    }
    else if (choiceA == 'n' || choiceA == 'N') { system("cls");  cout << "Salam Aliakum !" << endl << endl; }
    else { cout << "wrong input !";    Menu(Class_Students, teacher); }
    char Roles;
GoToStartA:
GoToStartB:
    string Students_Teacher;
    cout << "Login --->" << endl << "" << endl << "1. Teacher Press [ T ]" << endl << "2. Student Press [ S ]" << endl << "3. Go Back [ B ]" << endl << "" << endl << "Choice  :  ";
    cin >> Roles;

    if (Roles == 'T' || Roles == 't')
    {
        system("cls");
        char ChoiceB;
    LoginAgain:
        cout << "Do you wan to Login -> " << endl << "" << endl << "1. Yes Press [ Y ]" << endl << "2. NO Press [ N ]" << endl << "3. Go Back Press [ B ]" << endl << "" << endl << "Choice  :  ";
        cin >> ChoiceB;
        if (ChoiceB == 'Y' || ChoiceB == 'y')
        {

            int User = 0;
            string PersonName;
            cout << endl;
            system("cls");
        GoBackB:
            cout << endl;
            cout << "Enter your User Name : ";
            cin.ignore();
            getline(cin, PersonName);

            system("cls");
            User = TeacherFinder(PersonName, teacher);
            if (User == -1) { cout << "User Name Not Found ! " << endl << endl; goto GoToStartA; }
            cout << endl;
            if (teacher[User].login())
            {
                system("cls");
                cout << "Login Sucessful ! : " << endl;
                char ChoiceC;
                cout << endl;
            GoToChangePassowrd:
                cout << "Chage Password" << endl << "" << endl << "1. Yes Press [ Y ]" << endl << "2. NO And Go To Main Press [ N ]" << endl << "3. Go Back Press [ B ]" << endl << "" << endl << "Choice  :  ";
                cin >> ChoiceC;
                cout << endl;
                if (ChoiceC == 'Y' || ChoiceC == 'y')
                {
                    system("cls");
                    cout << endl;
                    cin >> teacher[User];
                    OverWritePasswords(Class_Students, teacher);
                    system("cls");
                    cout << "Your New Password is : ";
                    cout << teacher[User].getPassword() << endl;
                    cout << endl;
                    char ChoiceD;
                MenuAsk:
                    cout << "Go to Main Menu  : ";
                    cin >> ChoiceD;
                    if (ChoiceD == 'Y' || ChoiceD == 'y')
                    {
                    GoBack:
                        system("cls");
                        cout << endl;
                        cout << "Your Course is : ";
                        cout << teacher[User].getAssignedCourse();
                        Students_Teacher = teacher[User].getAssignedCourse();
                        cout << endl;
                        cout << endl;
                    Main:
                        int ChoiceE;
                        cout << "1. Generate Class : " << endl; cout << endl;
                        cout << "2. Create Assignment : " << endl; cout << endl;
                        cout << "3. Crete Submissions : " << endl; cout << endl;
                        cout << "4. Login as Student or teacher : " << endl; cout << endl;
                        cout << "5. Submite Assignment : " << endl; cout << endl;
                        cout << "6. Give Grades : " << endl; cout << endl;
                        cout << endl;
                        cout << "TASK : ";
                        cin >> ChoiceE;
                        system("cls");
                        if (ChoiceE == 1)
                        {
                            int choiceS = 0;
                            cout << "Do you Want to crete a New Class and overwrite or Edit Previous [ 1 - 0 ] :  ";
                            cin >> choiceS;

                            if (choiceS)
                                teacher[User].CM = new Class_Managment("Summer", teacher[User]);
                            else
                            {
                                teacher[User].CM = new Class_Managment(Class_Students, teacher[User]);
                            }
                        TaskTeacherB:
                            system("cls");
                            int optionCM;
                        AddAgainA:
                        RmoveAgainA:
                            cout << endl;
                            cout << "Class _ Managment --->" << endl;
                            cout << endl;
                            cout << "1. Change Class Name" << endl;
                            cout << "2. Chage Class Subject" << endl;
                            cout << "3. Enrolle Students" << endl;
                            cout << "4. Add New Student" << endl;
                            cout << "5. Remove Existing Student" << endl;
                            cout << "6. Delete Existing Class" << endl;
                            cout << "7. View Class" << endl << endl;
                            cout << "8. Go Back" << endl << endl;
                            cout << "Tasks : "; cin >> optionCM;
                            cin.ignore();
                            if (optionCM == 1) { cout << "Enter New Class Name : "; string Name; getline(cin, Name);  teacher[User].CM->setName(Name);  goto TaskTeacherB; }
                            else if (optionCM == 2) { cout << "Enter New  Subject : "; string Name; getline(cin, Name);  teacher[User].CM->setSubject(Name);  goto TaskTeacherB; }
                            else if (optionCM == 3) { teacher[User].CM->EnrolleStudents(Class_Students, teacher[User]); goto TaskTeacherB; }
                            else if (optionCM == 4)
                            {
                                string Name = "";
                                cout << "Enter Sudent Name To Add : "; getline(cin, Name);
                                int UserAdd = StudentFinder(Name, Class_Students);
                                system("cls");
                                if (UserAdd == -1) {
                                    cout << endl << "User Not Found !" << endl;
                                    char Pause;
                                    cout << endl;
                                    cout << "Press any KEY to go BACK  : " << endl;
                                    Pause = _getch(); goto AddAgainA;
                                }
                                else  teacher[User].CM->AddStudent(Class_Students[UserAdd], teacher[User]); goto TaskTeacherB;
                            }
                            else if (optionCM == 5)
                            {
                                string Name = "";
                                cout << "Enter Sudent Name To Remove : "; getline(cin, Name);
                                int UserAdd = StudentFinder(Name, Class_Students);
                                system("cls");
                                if (UserAdd == -1)
                                {
                                    cout << endl << "User Not Found !" << endl;
                                    char Pause;
                                    cout << endl;
                                    cout << "Press any KEY to go BACK  : " << endl;
                                    Pause = _getch();
                                    goto RmoveAgainA;
                                }
                                else
                                    teacher[User].CM->RemoveStudent(Class_Students[UserAdd], teacher[User]); goto TaskTeacherB;

                            }
                            else if (optionCM == 6) { teacher[User].CM->NUll(teacher[User]); goto TaskTeacherB; }
                            else if (optionCM == 7) { teacher[User].CM->Show(teacher[User]); goto TaskTeacherB; }
                            else if (optionCM == 8) { goto GoBack; }
                            else { cout << "Wrong Input" << endl; goto TaskTeacherB; }

                        }
                        else if (ChoiceE == 2)
                        {
                            int choiceS = 0;
                            cout << "Do you Want to crete a New Assignment and overwrite or Edit other [ 1 - 0 ] :  ";
                            cin >> choiceS;

                            if (choiceS)
                                teacher[User].AM = new Assignment_Managment(teacher[User].getName());
                            else
                            {
                                teacher[User].AM = new Assignment_Managment();
                            }
                        gotoAssignmetB:
                            system("cls");
                            int optionAS;
                            cout << "1. Crete A new Assignment :" << endl;
                            cout << "2. Delete an Existing Assignment :" << endl;
                            cout << "3. Set Submission Deadline :" << endl;
                            cout << "4. View Assignment" << endl << endl;
                            cout << "5. Go Back" << endl << endl;
                            cout << "6. Update Existing Assignmet" << endl << endl;
                            cout << "Tasks : "; cin >> optionAS;
                            cout << endl;
                            if (optionAS == 1)
                            {
                                teacher[User].AM->CreateAssignment(teacher[User].getAssignedCourse(), teacher[User].getName());
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto gotoAssignmetB;

                            }

                            else if (optionAS == 2)
                            {
                                teacher[User].AM->nullAssignment();
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto gotoAssignmetB;
                            }
                            else if (optionAS == 3)
                            {
                                int ChoiceD;
                                cout << "Set Dealine Date & Time" << endl << "" << endl << "1. Yes Press[ 1 ]" << endl << "2. No Press [ 0 ]" << endl << "" << endl << "Choice :  "; cin >> ChoiceD;
                                if (ChoiceD)
                                {
                                    time = new Time();
                                    Time* TimeStore;
                                    cout << endl;
                                    cout << endl << "Enter An Existing Assignment Name to Set Time :  ";
                                    string Name; cin.ignore();
                                    getline(cin, Name);
                                    system("cls");
                                    TimeStore = &(SettingDateTime(*time, Name, teacher[User]));
                                    teacher[User].AM->setDeadline(*TimeStore);
                                }

                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto gotoAssignmetB;
                            }

                            else if (optionAS == 4)
                            {
                                teacher[User].AM->ShowAssignment(teacher[User].getName());
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto gotoAssignmetB;
                            }

                            else if (optionAS == 5) { goto GoBack; }
                            else if (optionAS == 6)
                            {
                                teacher[User].AM->UpdateAssignment(teacher[User].getName());
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto gotoAssignmetB;
                            }
                            else
                            {
                                system("cls");
                                cout << "Wrong Input ! " << endl;
                                goto gotoAssignmetB;
                            }

                        }
                        else if (ChoiceE == 3)
                        {

                            teacher[User].S = new Submissions(&teacher[User]);
                            teacher[User].S->Create_Submission();
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto GoBack;
                        }
                        else if (ChoiceE == 4)
                        {
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            system("cls");
                            goto GoToStartB;

                        }
                        else if (ChoiceE == 5)
                        {
                            teacher[User].CM->SubmiteAssignment(teacher[User]);
                            cout << "Assignmet Submited Successfully " << endl;
                            cout << endl;
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto Main;

                        }
                        else if (ChoiceE == 6)
                        {
                            teacher[User].GB->Grade$Cheak(teacher[User].getName());
                            goto Main;
                        }
                        else { system("cls"); cout << "Wrong Input ! " << endl; goto GoBack; }
                    }
                    else if (ChoiceD == 'B' || ChoiceD == 'b') { system("cls"); goto GoToStartB; }
                    else { system("cls"); cout << "Wrong Input ! " << endl; goto MenuAsk; }
                }
                else if (ChoiceC == 'B' || ChoiceC == 'b')
                {
                    system("cls");
                    Menu(Class_Students, teacher);
                }
                else if (ChoiceC == 'N' || ChoiceC == 'n')
                {
                    system("cls");
                    cout << "Your Course is : ";
                    cout << teacher[User].getAssignedCourse();
                    cout << endl;
                    cout << endl;
                    string Students_Teacher = teacher[User].getAssignedCourse();
                Main2:
                    system("cls");
                    int ChoiceE;
                    cout << "1. Crete Class: " << endl; cout << endl;
                    cout << "2. Create Assignment : " << endl; cout << endl;
                    cout << "3. Crete Submissions : " << endl; cout << endl;
                    cout << "4. Login as Student or teacher : " << endl; cout << endl;
                    cout << "5. Submite Assignment : " << endl; cout << endl;
                    cout << "6. Give Grades : " << endl; cout << endl;
                    cout << endl;
                    cout << "TASK : ";
                    cin >> ChoiceE;
                    system("cls");
                    if (ChoiceE == 1)
                    {
                        int choiceS = 0;
                        cout << "Do you Want to crete a New Class and overwrite or Edit Previous [ 1 - 0 ] :  ";
                        cin >> choiceS;

                        if (choiceS)
                            teacher[User].CM = new Class_Managment("Summer", teacher[User]);
                        else
                        {
                            teacher[User].CM = new Class_Managment(Class_Students, teacher[User]);
                        }
                    TaskTeacherA:
                        system("cls");
                        int optionCM;
                    AddAgainB:
                    RmoveAgainB:
                        system("cls");
                        cout << endl;
                        cout << "Class _ Managment --->" << endl;
                        cout << endl;
                        cout << "1. Change Class Name" << endl;
                        cout << "2. Chage Class Subject" << endl;
                        cout << "3. Enrolle Students" << endl;
                        cout << "4. Add New Student" << endl;
                        cout << "5. Remove Existing Student" << endl;
                        cout << "6. Delete Existing Class" << endl;
                        cout << "7. View Class" << endl << endl;
                        cout << "8. Go Back" << endl << endl;
                        cout << "Tasks : "; cin >> optionCM;
                        cin.ignore();
                        if (optionCM == 1) { cout << "Enter New Class Name : "; string Name; getline(cin, Name);  teacher[User].CM->setName(Name);  goto TaskTeacherA; }
                        else if (optionCM == 2) { cout << "Enter New Subject : "; string Name; getline(cin, Name);  teacher[User].CM->setSubject(Name);  goto TaskTeacherA; }
                        else if (optionCM == 3) { teacher[User].CM->EnrolleStudents(Class_Students, teacher[User]); goto TaskTeacherA; }
                        else if (optionCM == 4)
                        {
                            string Name = "";
                            cout << "Enter Sudent Name To Add : "; getline(cin, Name);
                            int UserAdd = StudentFinder(Name, Class_Students);
                            system("cls");
                            if (UserAdd == -1)
                            {
                                cout << endl << "User Not Found !" << endl;
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto AddAgainB;
                            }
                            else
                                teacher[User].CM->AddStudent(Class_Students[UserAdd], teacher[User]); goto TaskTeacherA;
                        }
                        else if (optionCM == 5)
                        {
                            string Name = "";
                            cout << "Enter Sudent Name To Remove : "; getline(cin, Name);
                            int UserAdd = StudentFinder(Name, Class_Students);
                            system("cls");
                            if (UserAdd == -1)
                            {
                                cout << endl << "User Not Found !" << endl;
                                char Pause;
                                cout << endl;
                                cout << "Press any KEY to go BACK  : " << endl;
                                Pause = _getch();
                                goto RmoveAgainB;
                            }
                            else
                                teacher[User].CM->RemoveStudent(Class_Students[UserAdd], teacher[User]); goto TaskTeacherA;

                        }
                        else if (optionCM == 6) { teacher[User].CM->NUll(teacher[User]); goto TaskTeacherA; }
                        else if (optionCM == 7) { teacher[User].CM->Show(teacher[User]); goto TaskTeacherA; }
                        else if (optionCM == 8) { goto GoBack; }
                        else { cout << "Wrong Input" << endl; goto TaskTeacherA; }


                    }
                    else if (ChoiceE == 2)
                    {
                        int choiceS = 0;
                        cout << "Do you Want to crete a New Assignment and overwrite or Edit Previous [ 1 - 0 ] :  ";
                        cin >> choiceS;

                        if (choiceS)
                            teacher[User].AM = new Assignment_Managment(teacher[User].getName());
                        else
                        {
                            teacher[User].AM = new Assignment_Managment();
                        }
                    gotoAssignmet:
                        int optionAS;
                        system("cls");
                        cout << "1. Crete Assignment :" << endl;
                        cout << "2. Delete an Existing Assignment :" << endl;
                        cout << "3. Set Submission Deadline :" << endl;
                        cout << "4. View Assignment" << endl << endl;
                        cout << "5. Go Back" << endl << endl;
                        cout << "6. Update Existing Assignmet" << endl << endl;
                        cout << "Tasks : "; cin >> optionAS;

                        if (optionAS == 1)
                        {
                            teacher[User].AM->CreateAssignment(teacher[User].getAssignedCourse(), teacher[User].getName());
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto gotoAssignmet;

                        }

                        else if (optionAS == 2)
                        {
                            teacher[User].AM->nullAssignment();
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto gotoAssignmet;
                        }
                        else if (optionAS == 3)
                        {
                            int ChoiceD;
                            cout << "Set Dealine Date & Time" << endl << "" << endl << "1. Yes Press[ 1 ]" << endl << "2. No Press [ 0 ]" << endl << "" << endl << "Choice :  "; cin >> ChoiceD;
                            if (ChoiceD)
                            {
                                time = new Time();
                                Time* TimeStore;
                                cout << endl;
                                cout << endl << "Enter An Existing Assignment Name to Set Time :  ";
                                string Name; cin.ignore();
                                getline(cin, Name);
                                system("cls");
                                TimeStore = &(SettingDateTime(*time, Name, teacher[User]));
                                teacher[User].AM->setDeadline(*TimeStore);
                            }

                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto gotoAssignmet;
                        }

                        else if (optionAS == 4)
                        {
                            teacher[User].AM->ShowAssignment(teacher[User].getName());
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto gotoAssignmet;
                        }

                        else if (optionAS == 5) { goto GoBack; }
                        else if (optionAS == 6)
                        {
                            teacher[User].AM->UpdateAssignment(teacher[User].getName());
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto gotoAssignmet;
                        }
                        else
                        {
                            system("cls");
                            cout << "Wrong Input ! " << endl;
                            goto gotoAssignmet;
                        }

                    }
                    else if (ChoiceE == 3)
                    {
                        teacher[User].S = new Submissions(&teacher[User]);

                        teacher[User].S->Create_Submission();
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto GoBack;
                    }
                    else if (ChoiceE == 4)
                    {

                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        system("cls");
                        goto GoToStartA;

                    }
                    else if (ChoiceE == 5)
                    {
                        teacher[User].CM->SubmiteAssignment(teacher[User]); cout << endl;
                        cout << "Assignmet Submited Successfully " << endl;
                        cout << endl;
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto Main2;
                    }
                    else if (ChoiceE == 6)
                    {
                        teacher[User].GB->Grade$Cheak(teacher[User].getName());
                        goto Main2;
                    }
                    else { system("cls"); cout << "Wrong Input ! " << endl; goto GoBack; }
                }
                else { system("cls"); cout << "Wrong Input ! " << endl; goto GoToChangePassowrd; }
            }
            else
            {
                cout << endl;
                cout << "Login failed ! : " << endl;
                cout << endl;
                cout << "Try Again ! Re - Cheak your User Name  : " << endl;
                cout << endl;
                goto GoBackB;
            }

        }
        else if (ChoiceB == 'N' || ChoiceB == 'n')
        {
            system("cls");
            char ChoiceExit;
        GoBackEx:
            cout << "Exit" << endl << "" << endl << "1.Yes Press[X]" << endl << "2.Go Back Press[B]" << endl << "" << endl << "Choice :  ";
            cin >> ChoiceExit;
            if (ChoiceExit == 'x')                                                         exit(0);
            else if (ChoiceExit == 'b' || ChoiceExit == 'B') { system("cls"); Menu(Class_Students, teacher); }
            else { system("cls"); cout << "Wrong Input!" << endl; goto GoBackEx; }
        }
        else if (ChoiceB == 'B' || ChoiceB == 'b') { system("cls"); Menu(Class_Students, teacher); }
        else { system("cls"); cout << "Wrong Input ! " << endl;     goto LoginAgain; }
    }

    else if (Roles == 'S' || Roles == 's')
    {
        system("cls");
        char ChoiceB;
        cout << "Do you wan to Login ->" << endl << "" << endl << "1. Yes Press [ Y ]" << endl << "2. NO Press [ N ]" << endl << "3. Go Back Press [ B ]" << endl << "" << endl << "Choice  :  ";
        cin >> ChoiceB;

        if (ChoiceB == 'Y' || ChoiceB == 'y')
        {
            system("cls");
        GoBackF:
            cout << endl;
            int User = 0;
            string PersonName;
            cout << "Enter your User Name :  ";
            cin.ignore();
            getline(cin, PersonName);
            system("cls");
            User = StudentFinder(PersonName, Class_Students);
            if (User == -1)
            {
                cout << "User Name Not Found ! " << endl;
                goto GoToStartB;
            }
            cout << endl;

            if (Class_Students[User].login())
            {
                system("cls");
                cout << "Login sucessful ! : " << endl;
                char ChoiceC;
                cout << endl;
            ChangePasswordB:
                cout << "Chage Password" << endl << "" << endl << "1. Yes Press [ Y ]" << endl << "2. NO Press [ N ]" << endl << "3. Go Back Press [ B ]\n4. Exit Press [ X ]" << endl << "" << endl << "Choice  :  ";
                cin >> ChoiceC;
                cout << endl;
                if (ChoiceC == 'Y' || ChoiceC == 'y')
                {
                    system("cls");
                    cout << endl;
                    cin >> Class_Students[User];
                    OverWritePasswords(Class_Students, teacher);
                    system("cls");
                    cout << "Your New Password is : ";
                    cout << Class_Students[User].getPassword() << endl;
                    cout << endl;
                    char ChoiceD;
                GoBackE:
                    cout << "Go To Main-->\n\n1. Yes Press [ Y ]\n2. Go Back press [ B ]\n\nChoice  :  ";
                    cin >> ChoiceD;
                    if (ChoiceD == 'Y' || ChoiceD == 'y')
                    {
                    GoBackAssignmentDo:
                        system("cls");
                        int ChoiceL;
                        cout << "Student Assignment Main --> " << endl << endl;
                        cout << "1. See Assignments" << endl;
                        cout << "2. Do Assignment and Submite Assignment" << endl << endl;
                        cout << "Task : ";
                        cin >> ChoiceL;
                        if (ChoiceL == 1)
                        {
                            system("cls");
                            string* Store;
                            Store = Class_Students[User].Show_Submited_Assignments(Class_Students[User].getStudentCourse());

                            for (int i = 0; i < 10; i++)
                            {
                                cout << Store[i] << endl;
                            } 
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto GoBackAssignmentDo;
                        }
                        else if (ChoiceL == 2)
                        {
                            bool CheakifExits = Class_Students[User].CheakIF_StudentIs_Enrolled(Class_Students[User]);
                            if (CheakifExits == false)
                            {
                                cout << "You Are Not Enrolled in " << Class_Students->getStudentCourse() << " Class ! Ask Teacher of respected Course to enroll you" << endl;
                                cout << endl;
                                goto GoBackE;
                            }
                           
                            string path;
                            cin.ignore();
                            cout << "Copy and Enter The Path From View Assignment Menu" << endl;
                            cout << "Path => "; getline(cin, path);

                            Class_Students[User].Do_Assignment(path, Class_Students[User]);
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto GoBackAssignmentDo;
                        }
                        else if (ChoiceL == 3)
                        {
                           
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            goto GoBackAssignmentDo;
                        }
                        else
                        {
                            system("cls");
                            cout << "Wrong Input!";
                            char Pause;
                            cout << endl;
                            cout << "Press any KEY to go BACK  : " << endl;
                            Pause = _getch();
                            system("cls");
                            goto GoBackE;
                        }

                    }
                    else if (ChoiceD == 'B' || ChoiceD == 'b')
                    {
                        system("cls");
                        goto GoToStartA;
                    }
                    else
                    {
                        system("cls");
                        cout << "Wrong Input ! " << endl;
                        goto GoBackE;
                    }
                }
                else if (ChoiceC == 'N' || ChoiceC == 'n')
                {
                GoBackAssignmentDoB:
                    system("cls");
                    int ChoiceL;
                    cout << "Student Assignment Main --> " << endl << endl;
                    cout << "1. See Assignments" << endl;
                    cout << "2. Do Assignment and Submite Assignment" << endl <<endl;
                    cout << "Task : ";
                    cin >> ChoiceL;
                    if (ChoiceL == 1)
                    {
                        system("cls");
                        string* Store;
                        Store = Class_Students[User].Show_Submited_Assignments(Class_Students[User].getStudentCourse());
                        cout << endl;
                        cout << "Following Assignmetns Are Submited " << endl;
                        cout << endl;
                        for (int i = 0; i < 10; i++)
                        {
                            cout <<"=> " << Store[i] << endl;
                        } 
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto GoBackAssignmentDoB;
                    }
                    else if (ChoiceL == 2)
                    {
                        bool CheakifExits = Class_Students[User].CheakIF_StudentIs_Enrolled(Class_Students[User]);
                        if (CheakifExits == false)
                        {
                            cout << "You Are Not Enrolled in " << Class_Students->getStudentCourse() << " Class ! Ask Teacher of respected Course to enroll you" << endl;
                            cout << endl;
                            goto GoBackE;
                        }

                        string path;
                        cin.ignore();
                        cout << "Copy and Enter The Path From View Assignment Menu" << endl;
                        cout << "Path => "; getline(cin, path);

                        Class_Students[User].Do_Assignment(path, Class_Students[User]);
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto GoBackAssignmentDoB;
                    }
                    else if (ChoiceL == 3)
                    {
                        system("cls");
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto GoBackAssignmentDoB;
                    }
                    else
                    {
                        system("cls");
                        cout << "Wrong Input!";                     
                        char Pause;
                        cout << endl;
                        cout << "Press any KEY to go BACK  : " << endl;
                        Pause = _getch();
                        goto GoBackE;
                    }
                }
                else if (ChoiceC == 'B' || ChoiceC == 'b') { goto  GoToStartA; }
                else if (ChoiceC == 'X' || ChoiceC == 'x')
                {
                    system("cls");
                    char ChoiceExit;
                GoBackC:
                    cout << "Exit" << endl << "" << endl << "1. Yes Press [ X ]" << endl << "2. Go Back Press [ B ]" << endl << "" << endl << "Choice :  ";
                    cin >> ChoiceExit;
                    if (ChoiceExit == 'x') exit(0);
                    else if (ChoiceExit == 'b' || ChoiceExit == 'B') { system("cls"); Menu(Class_Students, teacher); }
                    else { system("cls"); cout << "Wrong Input!" << endl; goto GoBackC; }


                }
                else { system("cls"); cout << "Wrong Input ! " << endl;     goto ChangePasswordB; }
            }
            else
            {
                system("cls");
                cout << endl;
                cout << "Login failed ! : " << endl;
                cout << endl;
                cout << "Try Again ! and Re - Cheak your User Name : " << endl;
                cout << endl;
                goto GoBackF;
            }
        }
        else if (ChoiceB == 'x' || ChoiceB == 'X')
        {
            system("cls");
            char ChoiceExit;
        close:
            cout << "Exit" << endl << "" << endl << "1. Yes Press [ X ]" << endl << "2. Go Back Press [ B ]" << endl << "" << endl << "Choice  :  ";
            cin >> ChoiceExit;
            if (ChoiceExit == 'x')
                exit(0);
            else if (ChoiceExit == 'b' || ChoiceExit == 'B') { system("cls"); Menu(Class_Students, teacher); }
            else { system("cls"); cout << "Wrong Input!" << endl; goto close; }
        }
        else if (ChoiceB == 'B' || ChoiceB == 'b') { system("cls"); Menu(Class_Students, teacher); }
    }
    else if (Roles == 'B' || Roles == 'b') { system("cls"); goto instruction; }
    else { system("cls"); cout << "Wrong Input!" << endl; goto GoToStartA; }
}
//============================================================================================================================================================================


int main()
{
    Student* Class_Students = new Student[220];
    Teacher* teacher = new Teacher[15];

    PasswordGetter(Class_Students, teacher);
    ReadStudentData(Class_Students);
    ReadTeacherData(teacher);
    Menu(Class_Students, teacher);

    /*cout << endl << endl;
    for (int i = 0; i < 217; i++) { cout << Class_Students[i].getName() << "  :  " << Class_Students[i].getID() << "  :  " << Class_Students[i].getStudentCourse() << "  :  " << Class_Students[i].getPassword() << endl; }
    cout << endl << endl;
    for (int i = 0; i < 11; i++) { cout << teacher[i].getName() << "  :  " << teacher[i].getID() << "  :  " << teacher[i].getAssignedCourse() << "  :  " << teacher[i].getPassword() << endl; }
    char Pause;
    cout << "Press any KEY Exit and clear Memmory  : " << endl;
    Pause = _getch();*/
    system("cls");




    return 0;
}


