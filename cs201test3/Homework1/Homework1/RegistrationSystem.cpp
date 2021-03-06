#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem()
{

    noOfStudents = 0;
    students = new Student[noOfStudents];

}

void RegistrationSystem::addStudent( const int studentId, const string firstName, const string lastName )
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId)
        {
            cout << "Student "<< studentId <<" already exists" << endl;
            return;
        }
    }

    Student student(firstName, lastName, studentId);
    if(noOfStudents == 0)
    {
        noOfStudents++;
        delete [] students;
        students = NULL;
        students = new Student[noOfStudents];
        students[noOfStudents - 1] = student;
        cout << "Student " << studentId << " has been added" << endl;
    }
    else
    {
        noOfStudents++;
        Student *tempStudents = new Student[noOfStudents];

        for(unsigned int i = 0; i < noOfStudents - 1 ; i++)
        {
            tempStudents[i] = students[i];
        }
        delete[] students;
        students = NULL;

        students = new Student[noOfStudents];

        for(unsigned int j = 0; j < noOfStudents; j++)
        {
            students[j] = tempStudents[j];
        }

        students[noOfStudents - 1] = student;
        cout << "Student " << studentId << " has been added"<<endl;
        //cout << students[noOfStudents - 1].getStudentFirstName()<<endl;
        sortStudentsArray();
        delete [] tempStudents;
        tempStudents = NULL;
    }
}
void RegistrationSystem::deleteStudent( const int studentId )
{
    if(noOfStudents >= 1)
    {
        for(unsigned int i = 0; i < noOfStudents; i++)
        {
            if(students[i].getStudentId() == studentId )
            {
                for(unsigned int k = i; k < noOfStudents - 1; k++)
                {
                    students[k] = students[k + 1];
                }
                noOfStudents--;
                cout << "Student " << studentId << " has been deleted" << endl;
                return;
            }
        }
        cout << "Student " << studentId << " does not exist." << endl;
    }
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName )
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId )
        {
            students[i].addStudentCourse(studentId, courseId, courseName);
            return;
        }
    }
    cout<< "The student does not exist, please enter an existing student"<<endl;
}
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId)
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId )
        {
            students[i].withdrawStudentCourse(studentId, courseId);
            return;
        }
    }
    cout<< "Student " << studentId << " does not exist"<<endl;
}


void RegistrationSystem::cancelCourse( const int courseId )
{
    bool a;
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        a = students[i].deleteCourse(courseId);
    }

    if(a)
    {
        cout <<"Course " << courseId << " has been cancelled" <<endl;
    }
    else
    {
        cout << "Course " << courseId << " does not exist" <<endl;
    }
}

void RegistrationSystem::showStudent( const int studentId )
{
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].getStudentId() == studentId )
        {
            cout<< "Student id" << "\t"   <<"First name"    <<  "\t"<<"Last name"<<endl;
            cout << students[i].getStudentId()<< "\t\t"<<students[i].getStudentFirstName()<<"\t\t"<< students[i].getStudentLastName()<<endl;
            students[i].printCourses();
            return;
        }
    }
    cout << "Student " << studentId <<" does not exist"<< endl;

}


void RegistrationSystem::showCourse( const int courseId)
{

    bool x = false;

    for(unsigned int k = 0; k < noOfStudents; k++)
    {
        if(students[k].printStudent(courseId))
        {
            x = true;
        }

    }
    if(x)
    {
        cout << "Course id" << "\t" << "Course name "<<endl;
        cout << courseId << "\t\t"<<"CS" << courseId << endl;
    }
    else
    {
        cout << "Course " << courseId << " does not exist"<< endl;
        return;

    }
    cout<< "Student id" << "\t"   <<"First name"    <<  "\t"<<"Last name"<<endl;
    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        if(students[i].printStudent(courseId))
        {

            cout << students[i].getStudentId() << "\t\t" << students[i].getStudentFirstName() << "\t\t" << students[i].getStudentLastName()<<endl;
        }
    }
}



void RegistrationSystem::showAllStudents()
{
    if(noOfStudents == 0)
    {
        cout << "There are no students in the system"<<endl;
    }
    else
        {
    cout << "Student id" << "\t" << "First name" << "\t" << "Last name" <<endl;

    for(unsigned int i = 0; i < noOfStudents; i++)
    {
        cout << students[i].getStudentId() << "\t\t" << students[i].getStudentFirstName() << "\t\t" << students[i].getStudentLastName()<<endl;
        students[i].printStudentCourses();
    }
    }
}


void RegistrationSystem::sortStudentsArray()
{
    int var;
    Student temp;
    for (unsigned int i = 0; i < noOfStudents - 1; i++)
    {
        var = i;
        for (unsigned int j = i + 1; j < noOfStudents; j++)
        {
            if (students[j].getStudentId() < students[var].getStudentId())
            {
                var = j;
            }
        }
        temp = students[i];
        students[i] = students[var];
        students[var] = temp;


    }
}

RegistrationSystem::~RegistrationSystem()
{
    if(students)
    {
        delete[] students;
    }

}
