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

//LinkedList<int> randomList(5);
//cout << randomList << "\nRandom constructor works.\n" << endl;


//LinkedList<int> assignedList;
//assignedList = studentsList;
//cout << assignedList << "\nAssignment operator works.\n" << endl;

//
//studentsList.push_tail(new Node<int>("Ivanov", "Ivan", 1, 4.5));
//cout << studentsList << "\nPush_tail works.\n" << endl;


//studentsList.push_tail(randomList);
//cout << studentsList << "\nPush_tail(overloaded) works.\n" << endl;


//studentsList.push_head(new Node<int>("Danila", "Ivanovich", 2, 5));
//cout << studentsList << "\nPush_head works.\n" << endl;


//studentsList.push_head(studentsList);
//cout << studentsList << "\nPush_head (overloaded) works.\n" << endl;


//studentsList.pop_head();
//cout << studentsList << "\nPop_head works.\n" << endl;


//studentsList.pop_tail();
//cout << studentsList << "\nPop_tail works.\n" << endl;


//studentsList.delete_node("Ivanov", "Ivan", 1); // Удалим ученика с указанными данными
//cout << studentsList << "\nDelete_node works.\n" << endl;


//Node<int>* firstStudent = studentsList[0];
//if (firstStudent != nullptr) {
//    cout << "\nFirst student: " << firstStudent->lastName << "\n" << endl;
//} else {
//    cout << "\nList is empty." << "\n" << endl;
//}


//studentsList[0]->averageScore = 4.8; 
//cout << "\nAverage score of the first student changed to: " << studentsList[0]->averageScore << endl;
