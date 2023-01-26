//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//ورود كاربر عادي
#ifndef LOG_IN_USER_H
#define LOG_IN_USER_H
#include "sing_up_user.hpp"
#include "dashboard_user.hpp"

//--------------------------------------------------
int to_log_in_user_account();
//اين تابع چك ميكند كاربر عادي قبلا داراي حساب است ياخير و اگر حساب داشت او را وارد داشبوردش ميكند
int check_being_existed_user_username(char entrance_username[]);
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه كاربران وجود دارد يا نه شماره كاربر با اين نام كاربري را برميگرداند

//---------------------------------------
int to_log_in_user_account()
//اين تابع چك ميكند كاربر عادي قبلا داراي حساب است ياخير
//و اگر داراي حساب بود او را وارد داشبوردش ميكند
// و عددي را بر ميگرداند كه مشخص ميكند برنامه در كجا ادامه پيدا كند
//(فعلا همواره برنامه در منوي اصلي ادامه پيدا ميكند(عدد 3))
{
    int user_index, valu = 1;
    char user_name[max_data_len], pass[max_data_len];
    while (valu == 1)
    {
        cout << "\n Log in as an user :\n";

        cin.get();
        cout << "\n Please enter your username : ";
        gets(user_name);
        user_index = check_being_existed_user_username(user_name);
        if (user_index == -1)
        {
            cout << "\n!!! Your login username is incorrect !!!\n";
            valu = warning();
            continue;
        }
        cout << "\n Please enter your password : ";
        cin >> pass;
        if (strcmp(User[user_index].password, pass) != 0)
        {
            cout << "\n!!! Your login password is incorrect !!!\n";
            valu = warning();
            continue;
        }

        system("cls");
        cout << "Hi " << User[user_index].username << "\n You have successfully loged in :) \n";
        valu = user_dashoard(user_index);
    }
    return valu;
}
//----------------------------------------------
int check_being_existed_user_username(char entrance_username[])
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه كاربران وجود دارد يا نه
// و انديس كاربر با اين نام كاربري را برميگرداند
{
    for (int i = 0; i <= count_user; i++)
    {
        if (strcmp(entrance_username, User[i].username) == 0)
            return i;
    }
    return -1;
}
//-------------------------------------------------
#endif