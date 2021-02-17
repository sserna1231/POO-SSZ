#include <iostream>
constexpr double IVA = 0.16;

typedef struct{
    int age; 
    char sex;
    float height;
} Customer_t;

int readInfo(Customer_t &c){
    std::cout << "Enter your age: ";
    std::cin >> c.age;

    char sex;
    std::cout << "Enter your sex: ";
    std::cin >> sex;
    switch(sex){
        case 'M':
        case 'm':
            c.sex = 'm'; 
            break;
        case 'F':
        case 'f':
            c.sex = 'f';
            break;
        default: 
            std::cout << "We don't accept other sexes. We're very chatolic\n";
            return 1;
    }

    std::cout << "Enter your height: ";
    std::cin >> c.height;
    return 0;
}

void displayInfo(const Customer_t& c){
    std::cout << "\n=======================\n";
    std::cout << "Client info:\n";
    std::cout << "Age: " << c.age << std::endl;
    std::cout << "Sex: " << c.sex << std::endl;
    std::cout << "Height: " << c.height << std::endl;
    std::cout << std::endl;
}

int main(){
    Customer_t client;
    if(readInfo(client))
        std::cout << "Client info couldn't be read\n";
    else displayInfo(client);
    return 0;
}