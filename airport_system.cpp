//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//اين برنامه براي اجرا به 10 كتابخانه پيوست نياز دارد
//این برنامه شامل قابلیت های اضافه است
//رابط CLI
#include "menu.hpp"
//--------------------------------------
void print_start_menu();
// اين تابع منوي اصلي را نمايش ميدهد
//------------------------------------------
int main()
{

    char str[max_data_len];
    int command;
    while (true)
    {
        print_start_menu();
        cin >> str;
        system("cls");

        if (not_being_num(str, strlen(str)))
        {
            cout << "\a\n !!! warning : you are only allowed to enter numbers !!!"
                 << "\n Please try again ";
        }
        else
        {
            command = convert_char_to_num(str);

            switch (command)
            {
            case 1: //ورود به پنل مديران
                admin_panel();
                break;
            case 2: //ورود به پنل كاربران
                user_panel();
                break;
            case 3: //خروج از برنامه
                return 0;
            default:
                cout << "\a\n !!! warning : You are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
}
//-------------------------------------------
void print_start_menu()
//اين تابع منوي اوليه را نمايش ميدهد
{
    cout << "\n Menu : "
         << "\n 1 : Go to the admin panel"
         << "\n 2 : Go to the user panel"
         << "\n 3 : Exit"
         << "\n PLease enter the related number of each command you want : ";
}
