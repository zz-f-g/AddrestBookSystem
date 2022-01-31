#include <iostream>

void enterInterface() {
    std::cout << "**********************************" << std::endl;
    std::cout << "****** 1. Add Person        ******" << std::endl;
    std::cout << "****** 2. Show Person       ******" << std::endl;
    std::cout << "****** 3. Delete Person     ******" << std::endl;
    std::cout << "****** 4. Find Person       ******" << std::endl;
    std::cout << "****** 5. Change Person     ******" << std::endl;
    std::cout << "****** 6. Clear All Persons ******" << std::endl;
    std::cout << "****** 0. Exit System       ******" << std::endl;
    std::cout << "**********************************" << std::endl;
}

void addPerson();
void showPerson();
void delPerson();
void findPerson();
void changePerson();
void clearAll();

void switchFunc() {
    int funcType;
    std::cin >> funcType;
    switch (funcType)
    {
    case 0:
        break;
    
    case 1:
        addPerson();
        break;

    case 2:
        showPerson();
        break;

    case 3:
        delPerson();
        break;

    case 4:
        findPerson();
        break;

    case 5:
        changePerson();
        break;

    case 6:
        clearAll();
        break;

    default:
        std::cout << "Invalid Input!" << std::endl;
        std::cout << "Plz Input Again!" << std::endl;
        switchFunc();
        break;
    }
}