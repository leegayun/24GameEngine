#include <iostream>
using namespace std;
enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37
};

int main()
{
    int num = 0;
    //cout << "\x1b[033m" << "■";
    cout << "화면에 그림을 그리는 프로그램입니다." << endl;
    cout << "학번 : 202327001" << endl;
    cout << "이름 : 이가윤" << endl;
    while (num!=64) {
        cout << "\x1b[037m" << "화면에 그릴 물체코드를 입력하세요 : ";
        cin >> num;


        if (num == 1) {
            cout << "\x1b[037m" << "■" << endl;
        }
        else if (num == 2){
            cout << "\x1b[031m" << "■"<<endl;
        }
        else if (num == 4) {
            cout << "\x1b[032m" << "■" << endl;
        }
        else if (num == 8) {
            cout << "\x1b[033m" << "■" << endl;
        }
        else if (num == 16) {
            cout << "\x1b[036m" << "■" << endl;
        }
        else if (num == 32) {
            cout << "\x1b[035m" << "■" << endl;
        }
        else if (num == 64) {
            break;
        }
        else
        {
            cout << "잘못 입력되었습니다." << endl;
        }
    }


    return 0;
}
