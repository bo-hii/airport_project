//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//ثبت نام كاربر عادي
#ifndef SING_UP_USER_H
#define SING_UP_USER_H

#include "commen_library.hpp"

//-----------------------------------------------
int to_sing_up_as_user();
//اين تابع مشخصات شخص را دريافت و او را به عنوان كاربر عادي ثبت نام ميكند

int recive_user_username();
//اين تابع نام كاربري را از كاربر مدير دريافت ميكند
bool being_repeated_user_username();
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه كاربران انتخاب شده يا نه
//-----------------------------------------------
int to_sing_up_as_user()
//اين تابع مشخصات شخص را دريافت و او را به عنوان كاربر عادي ثبت نام ميكند
// و عددي را بر ميگرداند كه مشخص ميكند پنل كاربر اجرا شود(عدد 2) يا كاربر به منوي اصلي بازگردد (عدد 3)
{
    int valu = 0;
    // اگر در هر مرحله متغير ارزش برابر 2 يا 3 شود از تابع خارج ميشود
    //و اگر صفر شود فرايند ثبت نام ادامه مي يابد

    if (count_user > max_user_count)
    {
        cout << "\n Sorry; You are not allowed to register another user :(";
        return 2; //كاربر را به پنل كاربر عادي بازميگرداند
    }

    cout << "\n Sing up as an user : \n";

    valu = recive_first_name(User[count_user].first_name);

    if (valu == 0)
    {
        valu = recive_last_name(User[count_user].last_name);

        if (valu == 0)
        {
            valu = recive_phone_namber(User[count_user].phone_number);

            if (valu == 0)
            {
                valu = recive_user_username();

                if (valu == 0)
                {
                    valu = recive_Password(User[count_user].password);

                    if (valu == 0)
                    {
                        valu = Confirm_Password(User[count_user].password);

                        system("cls");
                        if (valu == 0)
                        {
                            cout << " Hi " << User[count_user].username << "\n Your registration was successful :) \n";
                            count_user++;
                            valu = 2; //وقتی ارزش ۲ را بازگرداند  وارد پنل كاربر عادي ميشود
                        }
                    }
                }
            }
        }
    }

    return valu;
}
//-------------------------------------------
int recive_user_username()
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
        gets(User[count_user].username);
        len = strlen(User[count_user].username);
        if (len < 2 || 10 < len || being_repeated_user_username())
        {
            cout << "\n The username is not available.\n";
            value = warning();
        }
        else
            value = 0;
    }
    return value;
}
//---------------------------------------------
bool being_repeated_user_username()
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه كاربران انتخاب شده يا نه
{
    for (int i = 0; i < count_user; i++)
    {
        if (strcmp(User[count_user].username, User[i].username) == 0)
            return true;
    }
    return false;
}
//----------------------------------------------------
#endif