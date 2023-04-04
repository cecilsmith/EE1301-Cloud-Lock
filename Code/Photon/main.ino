#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;

class keyCard
{
    private:
        bool lockStatus;
        char inputIoTpsw[7];
        char IoTpsw[7];
    public:
        void getIoTpsw();
        void checkIoTpsw();   
        void checkResult();  
};

void keyCard::getIoTpsw()
{
    cout << "Enter IoT Password: ";
    cin >> inputIoTpsw;
}

void keyCard::checkIoTpsw(char password)
{
    if(inputIoTpsw == IoTpsw)
        lockStatus = 1;
    else
        lockStatus = 0;

    // if correct, return 1
}

void keyCard::checkResult()
{
    if(lockStatus = 1)
        cout << "Correct password." << endl;
    else
        cout << "Incorrect password." << endl;
}

void setup() {

}

void loop() {
    // if Cloud update
        // if cloud.pswd == keycard.pswd
            // lockstatus = !lockstatus;
}