#include "Three.hpp"
#include <iostream>

using namespace std;

int main() {

    Three Th;
    Three th("20201");
    //Three therr("54654");
    //Three therr2("-121");
    Three ThMove;
    Three Th1(3,'2');
    //Three Th2(4,'5');
    Three Th3("0");
    Three Th4("0");
    Th = th;
    Three Th5("2121");
    Three Th6("00000211");
    Three Th7("20100");
    Three Th8("20");

    //Вывод
    std::cout << "Th: " << Th << std::endl;
    std::cout << "th: " << th << std::endl;
    ThMove = move(th);
    //std::cout << "therr: " << therr << std::endl;
    //std::cout << "therr2: " << therr2 << std::endl;
    std::cout << "th: " << th << std::endl;
    std::cout << "ThMove: " << ThMove << std::endl;
    std::cout << "Th1: " << Th1 << std::endl;
    //std::cout << "Th2: " << Th3 << std::endl;
    std::cout << "Th3: " << Th3 << std::endl;
    std::cout << "Th4: " << Th4 << std::endl;
    std::cout << "Th5: " << Th5 << std::endl;
    std::cout << "Th6: " << Th6 << std::endl;
    std::cout << "Th7: " << Th7 << std::endl;
    std::cout << "Th8: " << Th8 << std::endl;

    //операции сравнения

    if (Th1 > Th4) {
        std::cout << "Th1 is greater than Th4" << std::endl;
    }

    if (Th3 == Th4) {
        std::cout << "Th3 is equal to Th4" << std::endl;
    }

    if (Th > Th8) {
        std::cout << "Th is greater than Th8" << std::endl;
    }

    //+-
    std::cout << "Sum Th3 - Th4: " << Th3 - Th4 << std::endl;
    std::cout << "Sum Th5 - Th8: " << Th5 - Th8 << std::endl;
    std::cout << "Sum Th - Th4: " << Th - Th4 << std::endl;
    std::cout << "Sum Th1 - Th8: " << Th1 - Th8 << std::endl;
    //std::cout << "Sum Th8 - Th1: " << Th8 - Th1 << std::endl;

    std::cout << "Sum Th3 + Th4: " << Th3 + Th4 << std::endl;
    std::cout << "Sum Th5 + Th8: " << Th5 + Th8 << std::endl;
    std::cout << "Sum Th + Th4: " << Th + Th4 << std::endl;
    std::cout << "Sum Th1 + Th8: " << Th1 + Th8 << std::endl;
    std::cout << "Sum Th6 + Th1: " << Th6 + Th1 << std::endl;


    //delete &Th4;

    try {
        Three a = {'1', '5'};
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
