//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//ورود كاربر مدير
#ifndef LOG_IN_ADMIN_H
#define LOG_IN_ADMIN_H
#include "sing_up_admin.hpp"
#include "dashboard_admin.hpp"

//----------------------------------------------------
int to_log_in_admin_account();
// اين تابع چك ميكند كاربر مدير قبلا داراي حساب است ياخير و اگر حساب داشت او را وارد داشبوردش ميكند
int check_being_existed_admin_username(char entrance_username[]);
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه مديران وجود دارد يا نه و شماره كاربر با اين نام كاربري را برميگرداند

//---------------------------------------
int to_log_in_admin_account()
//اين تابع چك ميكند كاربر مدير قبلا داراي حساب است ياخير
//و اگر داراي حساب بود او را وارد داشبوردش ميكند
// و عددي را بر ميگرداند كه مشخص ميكند برنامه در كجا ادامه پيدا كند
//(فعلا همواره برنامه در منوي اصلي ادامه پيدا ميكند(عدد 3))
{
    int admin_index, valu = 1;
    char user_name[max_data_len], pass[max_data_len];
    while (valu == 1)
    {
        system("cls");
        cout << "\n Log in as an admin :\n";

        cin.get();
        cout << "\n Please enter your username : ";
        gets(user_name);
        admin_index = check_being_existed_admin_username(user_name);
        if (admin_index == -1)
        {
            cout << "\n!!! Your login username is incorrect !!!\n";
            valu = warning();
            continue;
        }

        cout << "\n Please enter your password : ";
        cin >> pass;
        if (strcmp(Admin[admin_index].password, pass) != 0)
        {
            cout << "\n!!! Your login password is incorrect !!!\n";
            valu = warning();
            continue;
        }

        system("cls");
        cout << "Hi " << Admin[admin_index].username << "\n You have successfully loged in :) \n";
        valu = admin_dashoard(admin_index);
    }
    return valu;
}
//----------------------------------------------
int check_being_existed_admin_username(char entrance_username[])
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه مديران وجود دارد يا نه
// و انديس كاربر با اين نام كاربري را برميگرداند
{
    for (int i = 0; i <= count_admin; i++)
    {
        if (strcmp(entrance_username, Admin[i].username) == 0)
            return i;
    }
    return -1;
}
//-------------------------------------------------
#endif