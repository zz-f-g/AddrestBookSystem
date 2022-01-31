#include <iostream>
// #include <fstream>
#include <string>
#define MAXSIZE 1000
using namespace std;

struct person{
    string name;
    bool gender;
    int age;
    long tel;
    string address;
};

void enterInterface() {
    cout << "**********************************" << endl;
    cout << "****** 1. Add Person        ******" << endl;
    cout << "****** 2. Show Person       ******" << endl;
    cout << "****** 3. Delete Person     ******" << endl;
    cout << "****** 4. Find Person       ******" << endl;
    cout << "****** 5. Change Person     ******" << endl;
    cout << "****** 6. Clear All Persons ******" << endl;
    cout << "****** 0. Exit System       ******" << endl;
    cout << "**********************************" << endl;
}

void addPerson(person* Container, int* ptr_len){
    if (*ptr_len > MAXSIZE - 1) {
        cout << "Persons Overflow" << endl;
        return;
    }
    person newPerson;
    cout << "Input the name:" << endl;
    cin >> newPerson.name;
    cout << "Input the gender: (1 for man and 0 for woman)" << endl;
    cin >> newPerson.gender;
    cout << "Input the age:" << endl;
    cin >> newPerson.age;
    cout << "Input the tel:" << endl;
    cin >> newPerson.tel;
    cout << "Input the address:" << endl;
    cin >> newPerson.address;
    Container[*ptr_len] = newPerson;
    *ptr_len += 1;
}

void showTitle() {
    cout << "|NAME|GENDER|AGE|TEL|ADDRESS|" << endl;
    cout << "|:---:|:---:|:---:|:---:|:---:|" << endl;
}

void showPerson(person* Container, int* ptr_len, int index) {
    cout << "|" << Container[index].name << "|";
    cout << Container[index].gender ? "man" : "woman";
    cout << "|" << Container[index].age << "|";
    cout << Container[index].tel << "|";
    cout << Container[index].address << "|" << endl;
}

void showPersons(person* Container, int* ptr_len){
    showTitle();
    for (int i=0; i<*ptr_len; i++) {
        showPerson(Container, ptr_len, i);
    }
}

void delArr(person* Container, int* ptr_len, int i){
    ; // deletion in Linear Array
}

bool delPerson(person* Container, int* ptr_len){
    int flag;
    flag = findPerson(Container, ptr_len);
    if (flag < 0) {
        return false;
    } else {
        delArr(Container, ptr_len, flag);
        return true;
    }
}

int findPerson(person* Container, int* ptr_len){
    int flag = -1;
    string delName;
    cin >> delName;
    for (int i=0; i<*ptr_len; i++) {
        if (delName == Container[i].name) {
            flag = i;
            break;
        }
    }
    return flag;
}

void find_show(person* Container, int* ptr_len){
    int flag = findPerson(Container, ptr_len);
    showTitle();
    showPerson(Container, ptr_len, flag);
}

bool changePerson(person* Container, int* ptr_len){
    int i = findPerson(Container, ptr_len);
    if (i < 0) {
        return false;
    } else {
        cout << "Input the name:" << endl;
        cin >> Container[i].name;
        cout << "Input the gender: (1 for man and 0 for woman)" << endl;
        cin >> Container[i].gender;
        cout << "Input the age:" << endl;
        cin >> Container[i].age;
        cout << "Input the tel:" << endl;
        cin >> Container[i].tel;
        cout << "Input the address:" << endl;
        cin >> Container[i].address;
        return true;
    }
}

void clearAll(int* ptr_len){
    *ptr_len = 0;
}

void exitSystem(person* Container, int* ptr_len){
    ;
}

void switchFunc(person* Container,int* ptr_len) {
    int funcType;
    cout << "Select the func:" << endl;
    cin >> funcType;
    switch (funcType)
    {
    case 0:
        exitSystem(Container, ptr_len);
        break;
    case 1:
        addPerson(Container, ptr_len);
        switchFunc(Container, ptr_len);
        break;
    case 2:
        showPersons(Container, ptr_len);
        switchFunc(Container, ptr_len);
        break;
    case 3:
        delPerson(Container, ptr_len);
        switchFunc(Container, ptr_len);
        break;
    case 4:
        find_show(Container, ptr_len);
        switchFunc(Container, ptr_len);
        break;
    case 5:
        changePerson(Container, ptr_len);
        switchFunc(Container, ptr_len);
        break;
    case 6:
        clearAll(ptr_len);
        switchFunc(Container, ptr_len);
        break;
    default:
        cout << "Invalid Input!" << endl;
        cout << "Plz Input Again!" << endl;
        switchFunc(Container, ptr_len);
        break;
    }
}

int main() {
    enterInterface();
    person Container[MAXSIZE];
    int len = 0;
    switchFunc(Container, &len);
    cout << "Exit the system!" << endl;
    return 0;
}