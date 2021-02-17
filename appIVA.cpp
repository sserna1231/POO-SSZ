#include <iostream>

void appIVA(double& price){
    price += IVA * price;
}

int main(){
    double prodPrice;
    std::cout << "Insert a product price: ";
    std::cin >> prodPrice; 
    appIVA(prodPrice);
    std::cout << "The total price including IVA is: "
        << prodPrice << std::endl; 
    return 0;
}