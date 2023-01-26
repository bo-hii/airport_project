//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//منو
#ifndef NENU_H
#define MENU_H

#include "sing_up_admin.hpp"
#include "sing_up_user.hpp"
#include "log_in_admin.hpp"
#include "log_in_user.hpp"

//--------------------------------------
void admin_panel();
// اين تابع پنل مديران است
void print_admin_panel_menu();
//اين تابع منوي پنل  مدير را نمايش ميدهد

void user_panel();
// اين تابع پنل كاربران عادي است
void print_user_panel_menu();
//اين تابع منوي پنل كاربر را نمايش ميدهد
//---------------------------------------------
void admin_panel()
// اين تابع پنل مديران است
{
    char str[max_data_len];
    int valu = 1, command;
    while (valu != 3)
    {
        print_admin_panel_menu();
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
            case 1: //ورود
                valu = to_log_in_admin_account();
                //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
                break;
            case 2: //ثبت نام
                valu = to_sing_up_as_admin();
                //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
                break;
            case 3: //بازگشت به منوي اصلي
                valu = 3;
                break;
            default:
                cout << "\a\n !!! warning : You are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
}
//---------------------------------------------
void user_panel()
//اين تابع منوي پنل كاربر را نمايش ميدهد
{
    char str[max_data_len];
    int valu = 1, command;
    while (valu != 3)
    {
        print_user_panel_menu();
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
            case 1: //ورود
                valu = to_log_in_user_account();
                //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
                break;
            case 2: //ثبت نام
                valu = to_sing_up_as_user();
                //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
                break;
            case 3: //بازگشت به منوي اصلي
                valu = 3;
                break;
            default:
                cout << "\a\n !!! warning : You are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
}
//-------------------------------------------
void print_admin_panel_menu()
//اين تابع منوي پنل  مدير را نمايش ميدهد
{
    cout << "\n Admin Panel : "
         << "\n 1 : Log in(As Admin)"
         << "\n 2 : Sing up(As Admin)"
         << "\n 3 : Return to the main menu "
         << "\n PLease enter the related number of each command you want : ";
}
//-------------------------------------------
void print_user_panel_menu()
//اين تابع منوي پنل كاربر را نمايش ميدهد
{
    cout << "\n User Panel : "
         << "\n 1 : Log in(As User)"
         << "\n 2 : Sing up(As User)"
         << "\n 3 : Return to the main menu "
         << "\n PLease enter the related number of each command you want : ";
}
//-----------------------------------------------
#endif