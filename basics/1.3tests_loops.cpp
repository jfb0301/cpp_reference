#include <iostream>


bool accept(){
    std::cout << "Do you want to proceed (y or n)?\n";

    char answer =0;
    std::cin >> answer;  // read amswer
    
    if (answer == 'y') return true;
    return false;
}

bool accept2(){
    std::cout << "do you want to proceed (y o n?)\n";

    char answer = 0;
    std::cin >> answer;

    switch(answer){
    case 'y':
        return true;
    case 'x':
        return false;
    default:
        std::cout << "I'll take that for no.\n";
        return false;
    }
}


// Bool3 accept a few tries of acceptable input

bool accept3(){
    int tries = 0;
    while (tries < 4 ) {
        std::cout << "Do you want to proceed (y o n)?\n";
        char answer = 0;
        std::cin >> answer;

        switch(answer){
        case 'y':
            return true;
        case 'x':
            return false;
        case 'n':
            return false;
        default:
            std::cout << "Sorry, I dont understand that\n";
            ++tries;
        }
    }

    std::cout << "I'll take that for no.\n";
    return false;
}

int main(){
    std::cout << "Testing accept():\n";
    bool result3 = accept3();
    std::cout << "Result " << (result3 ? "Accepted" : "Not accepted") << "\n";

    return 0;
}

