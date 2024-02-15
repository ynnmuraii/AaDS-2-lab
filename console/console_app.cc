#include <functions/functions.h>
#include <iostream>
#include <stdexcept>
#include <random>
#include <string>

using namespace std;
using namespace linkedList;

int main() {
    LinkedList<int> studentsList;

    studentsList.addStudent(new Node<int>("Ivanov", "Ivan", 1, 2.553));
    studentsList.addStudent(new Node<int>("Petrov", "Petr", 2, 3.2));
    studentsList.addStudent(new Node<int>("Kozlov", "Andrey", 3, 2.92));
    studentsList.addStudent(new Node<int>("Smirnov", "Sergey", 4, 2.1));
    studentsList.addStudent(new Node<int>("Sidorov", "Sidor", 5, 2.7222));
    studentsList.addStudent(new Node<int>("Alekov", "Vova", 4, 3.6743));
    studentsList.addStudent(new Node<int>("Malik", "Petya", 3, 4.1));

    studentsList.removeFailingStudents();
    cout << studentsList << "\nRemove failing students works.\n" << endl;



    return 0;
}