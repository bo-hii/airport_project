//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//ثبت نام كاربر مدير
#ifndef SING_UP_ADMIN_H
#define SING_UP_ADMIN_H

#include "commen_library.hpp"

//--------------------------------------تعريف ركورد ها
struct ADMIN
{
    char first_name[max_data_len];   //نام
    char last_name[max_data_len];    //نام خانوادگي
    char phone_number[max_data_len]; //شماره تلفن
    char username[max_data_len];     //نام كاربري
    char password[max_data_len];     //پسورد
};
//---------------------------------------تعريف متغير هاي جهاني
ADMIN Admin[max_admin_count];
int count_admin = 0;
//----------------------------------------------------
int to_sing_up_as_admin();
//اين تابع مشخصات شخص را دريافت و او را به عنوان مدير ثبت نام ميكند

int recive_admin_username();
//اين تابع نام كاربري را از كاربر عادي دريافت ميكند
bool being_repeated_admin_username();
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه مديران انتخاب شده يا نه

//-----------------------------------------------
int to_sing_up_as_admin()
//اين تابع مشخصات شخص را دريافت و او را به عنوان مدير ثبت نام ميكند
// و عددي را بر ميگرداند كه مشخص ميكند پنل مدير اجرا شود(عدد 2) يا كاربر به منوي اصلي بازگردد (عدد 3)
{
    int valu = 0;
    // اگر در هر مرحله متغير ارزش برابر 2 يا 3 شود از تابع خارج ميشود
    //و اگر صفر شود فرايند ثبت نام ادامه مي يابد

    if (count_admin > max_admin_count)
    {
        cout << "\n Sorry; You are not allowed to register another admin :(";
        return 2; //كاربر را به پنل كاربر عادي بازميگرداند
    }

    cout << "\n Sing up as an admin : \n";

    valu = recive_first_name(Admin[count_admin].first_name);

    if (valu == 0)
    {
        valu = recive_last_name(Admin[count_admin].last_name);

        if (valu == 0)
        {
            valu = recive_phone_namber(Admin[count_admin].phone_number);

            if (valu == 0)
            {
                valu = recive_admin_username();

                if (valu == 0)
                {
                    valu = recive_Password(Admin[count_admin].password);

                    if (valu == 0)
                    {
                        valu = Confirm_Password(Admin[count_admin].password);

                        system("cls");

                        if (valu == 0)
                        {
                            cout << " Hi " << Admin[count_admin].username << "\n Your registration was successful :) \n";
                            count_admin++;
                            valu = 2; //وقتی ارزش ۲ را بازگرداند  وارد پنل كاربر مدیر ميشود
                        }
                    }
                }
            }
        }
    }
    return valu;
}
//-----------------------------------------------
int recive_admin_username()
//اين تابع نام كاربري را از كاربر عادي دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم
// يااز اين تابع خارج شويم و پس از آن براي ادامه به كدام تابع بازگرديم
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند
{
    int len, value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n Choose your username(2_10 charactor) : ";
        gets(Admin[count_admin].username);
        len = strlen(Admin[count_admin].username);
        if (len < 2 || 10 < len || being_repeated_admin_username())
        {
            cout << "\n The username is not available.\n";
            value = warning();
        }
        else
            value = 0;
    }
    return value;
}
//----------------------------------------------------
bool being_repeated_admin_username()
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه مديران انتخاب شده يا نه
{
    for (int i = 0; i < count_admin; i++)
    {
        if (strcmp(Admin[count_admin].username, Admin[i].username) == 0)
            return true;
    }
    return false;
}
//-------------------------------------------------
#endif