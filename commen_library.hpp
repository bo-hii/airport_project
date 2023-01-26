//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//كتابخانه مشترك
#ifndef AIRPORT_COMMEN_LIBRARY_H
#define AIRPORT_COMMEN_LIBRARY_H

#include <string.h>
#include <iostream>
using namespace std;

#define max_data_len 30
#define max_large_data_len 60
#define max_flight_count 100
#define max_admin_count 10
#define max_user_count 200
#define max_flight_capacity 250
//--------------------------------------تعريف ركورد ها
struct DATE //تاريخ
{
    int year;  //سال
    int month; //ماه
    int day;   //روز
};
struct TIME //ساعت
{
    int hour;   //ساعت
    int minute; //دقيقه
};
struct FLIGHT //مشخصات پرواز
{
    long long int id;                          //شناسه ي پرواز
    char origin[max_large_data_len];           //مبدا
    char destination[max_large_data_len];      //مقصد
    DATE date;                                 //تاريخ
    TIME time;                                 //ساعت
    char airline_name[max_data_len];           //نام شركت هواپيمايي
    int capacity;                              //ظرفيت
    int num_passengers = 0;                    //تعداد فعلي مسافرن
    int passengers_index[max_flight_capacity]; //مسافران پرواز
};
struct USER
{
    char first_name[max_data_len];      //نام
    char last_name[max_data_len];       //نام خانوادگي
    char phone_number[max_data_len];    //شماره تلفن
    char username[max_data_len];        //نام كاربري
    char password[max_data_len];        //پسورد
    int ticket_index[max_flight_count]; //بليط هاي كاربر
    int num_tickets = 0;                //تعداد بلیط های کاربر
};
//---------------------------------------تعريف متغير هاي جهاني
FLIGHT flight[max_flight_count];
USER User[max_user_count];
int count_flight = 0;
int count_user = 0;
//----------------------------------------------------
int recive_first_name(char f_name[]);
//اين تابع نام را از كاربر دريافت ميكند
int recive_last_name(char l_name[]);
//اين تابع نام خانوادگي را از كاربر دريافت ميكند
int recive_phone_namber(char phone_num[]);
//اين تابع شماره تماس را از كاربر دريافت ميكند
int recive_Password(char pass[]);
//اين تابع پسورد مورد نظر كاربر را از كاربر دريافت ميكند
int Confirm_Password(char pass[]);
//اين تابع از كاربر ميخواهد يك بار ديگر پسوردش را وارد كند و اگر با پسورد قبلي مطابقت داشت آن را تاييد ميكند

int warning();
//اين تابع در صورت وارد كردن اطلاعات غير مجاز به شخص هشدار ميدهد و گزينه هايي براي او نمايش ميدهد
void Print_warning();
//اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطاشده نمايش ميدهد

bool not_being_num(char str[], int n);
//اين تابع چك ميكند كه كاراكتر ورودي  شامل كاراكتر هاي غير عددي هست يا خير
bool powerless_pass(char pass[]);
//اين تابع چك ميكند كه آيا پسورد انتخابي توسط كاربر قوي هست يا نه
bool invalied_phone_number(char phone_num[]);
//اين تابع چك ميكند كه آيا شماره تلفن ورودي كاربر مجاز است يا نه

int warning2();
//اين تابع در صورت وارد كردن اطلاعات غير مجاز براي گزينه هاي موجود ( پس از داشبورد ) به شخص هشدار ميدهد
void Print_warning2();
//(منوي هشدار2)اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطاشده نمايش ميدهد

long long int convert_char_to_num(char str[]);
// اين تابع يك آرايه كاراكتري كه قبلا چك شده فقط شامل عدد است را گرفته و نوع آن را به عدد صحيح تغيير ميدهد

//--------------------------------------
int recive_first_name(char f_name[])
//اين تابع نام را از كاربر دريافت ميكند
// (اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم-- (تابع هشدار=1
// يااز اين تابع خارج شويم--(تابع هشدار =2 يا 3) و پس از آن براي ادامه به كدام تابع بازگرديم->( 2 يا3) را بازميگرداند
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند->(0) را بازميگرداند
{
    int value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n First Name (maximum 25 charactors) : ";
        gets(f_name);
        if (strlen(f_name) > 25)
            value = warning();

        else
            value = 0;
    }
    return value;
}
//----------------------------------------
int recive_last_name(char l_name[])
//اين تابع نام خانوادگي را از كاربر دريافت ميكند
// (اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم-- (تابع هشدار=1
// يااز اين تابع خارج شويم--(تابع هشدار =2 يا 3) و پس از آن براي ادامه به كدام تابع بازگرديم->( 2 يا3) را بازميگرداند
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند->(0) را بازميگرداند
{
    int value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n Last Name (maximum 25 charactors) : ";
        gets(l_name);
        if (strlen(l_name) > 25)
            value = warning();

        else
            value = 0;
    }
    return value;
}
//-----------------------------------
int recive_phone_namber(char phone_num[])
//اين تابع شماره تماس را از كاربر دريافت ميكند
// (اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم-- (تابع هشدار=1
// يااز اين تابع خارج شويم--(تابع هشدار =2 يا 3) و پس از آن براي ادامه به كدام تابع بازگرديم->( 2 يا3) را بازميگرداند
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند->(0) را بازميگرداند
{
    int value = 1;
    while (value == 1)
    {
        cout << "\n Phone Number : ";
        cin >> phone_num;
        if (invalied_phone_number(phone_num))
            value = warning();

        else
            value = 0;
    }
    return value;
}
//---------------------------------------------
int recive_Password(char pass[])
//اين تابع پسورد مورد نظر كاربر را از كاربر دريافت ميكند
// (اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم-- (تابع هشدار=1
// يااز اين تابع خارج شويم--(تابع هشدار =2 يا 3) و پس از آن براي ادامه به كدام تابع بازگرديم->( 2 يا3) را بازميگرداند
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند->(0) را بازميگرداند
{
    int len, value = 1;
    while (value == 1)
    {
        cout << "\n Creat a password(5_25 charactor) : ";
        cin >> pass;
        len = strlen(pass);
        if (len < 5 || 25 < len || powerless_pass(pass))
        {
            cout << "\n Your password must be between 5 and 25 charactors long"
                 << "\n and contain at least a small letter, a captal letter, a number and one other charactor . \n\n";
            value = warning();
        }
        else
            value = 0;
    }
    return value;
}
//-----------------------------------------------------
int Confirm_Password(char pass[])
//اين تابع از كاربر ميخواهد يك بار ديگر پسوردش را وارد كند و اگر با پسورد قبلي مطابقت داشت آن را تاييد ميكند
// (اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم-- (تابع هشدار=1
// يااز اين تابع خارج شويم--(تابع هشدار =2 يا 3) و پس از آن براي ادامه به كدام تابع بازگرديم->( 2 يا3) را بازميگرداند
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند->(0) را بازميگرداند
{
    int value = 1;
    char check_pass[max_data_len];
    while (value == 1)
    {
        cout << "\n Confirm your password : ";
        cin >> check_pass;
        if (strcmp(pass, check_pass) != 0)
            value = warning();

        else
            value = 0;
    }
    return value;
}
//-------------------------------------------------
int warning()
//اين تابع در صورت وارد كردن اطلاعات غير مجاز براي حساب كاربري  به شخص هشدار ميدهد
// و گزينه هايي براي ادامه ي برنامه به او نمايش ميدهد
{
    char str[max_data_len];
    int command;
    while (true)
    {
        Print_warning();
        cin >> str;

        if (not_being_num(str, strlen(str)))
        {
            cout << "\n !!! Warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
        else
        {
            command = convert_char_to_num(str);

            switch (command)
            {
            case 1: //تلاش مجدد
                return command;

            case 2: //بازگشت به منو پنل
            case 3: //بازگشت به منو اوليه
                system("cls");
                return command;

            default:
                cout << "\n !!! Warning : you are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
    return 0;
}
//--------------------------------------------
void Print_warning()
//اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطا در ثبت نام شده نمايش ميدهد
{
    cout << "\a\n !!! Warning : you are not allowed to select this !!!"
         << "\n PLease enter the related number of each command you want : "
         << "\n 1 : Try again"
         << "\n 2 : Return to the panel"
         << "\n 3 : Return to the main menu \n >> ";
}
//-------------------------------------------
bool not_being_num(char str[], int n)
//اين تابع چك ميكند كه كاراكتر ورودي شامل كاراكتر هاي غير عددي هست يا خير
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return true;
    }
    return false;
}
//-------------------------------------------
bool invalied_phone_number(char phone_num[])
//اين تابع چك ميكند كه آيا شماره تلفن ورودي كاربر مجاز است يا نه
{
    if (phone_num[0] != '0') //اولين رقم صفر نباشد
    {
        return true;
    }
    if (strlen(phone_num) != 11) // شماره دقيقا 11 كاراكتر نباشد
    {
        return true;
    }
    if (not_being_num(phone_num, 11)) //شماره فقط شامل عدد نباشد(شامل كاراكتر هاي غير عددي هم باشد)
    {
        return true;
    }
    return false;
}
//-----------------------------------------------
bool powerless_pass(char pass[])
//اين تابع چك ميكند كه آيا پسورد انتخابي توسط كاربر ضعيف هست يا نه
//  اگر تابع همزمان شامل حروف بزرگ و كوچك و عدد باشد اين تابع به عنوان مقداري نادرست بازگردانده ميشود
{
    int point_Captal = 0, point_small = 0, point_num = 0, point_else = 0;
    for (int i = 0; pass[i] != 0; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z') //شامل حروف بزرگ باشد
        {
            point_Captal++;
        }
        else if (pass[i] >= 'a' && pass[i] <= 'z') //شامل حروف كوچك باشد
        {
            point_small++;
        }
        else if (pass[i] >= '0' && pass[i] <= '9') //شامل عدد باشد
        {
            point_num++;
        }
        else //شامل كاراكتر غير عددي و غير حرفي باشه
        {
            point_else++;
        }
        if (point_Captal >= 1 && point_small >= 1 && point_num >= 1 && point_else >= 1) //شامل هر 4 مورد با هم باشد
        {
            return false;
        }
    }
    return true;
}
//-------------------------------------------------
int warning2()
//اين تابع در صورت وارد كردن اطلاعات غير مجاز براي گزينه هاي موجود ( پس از داشبورد ) به شخص هشدار ميدهد
// و گزينه هايي براي ادامه ي برنامه به او نمايش ميدهد
{
    char str[max_data_len];
    int command;
    while (true)
    {
        Print_warning2();
        cin >> str;

        if (not_being_num(str, strlen(str)))
        {
            cout << "\n !!! Warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
        else
        {
            command = convert_char_to_num(str);

            switch (command)
            {
            case 1: //تلاش مجدد
                return 1;

            case 2: //بازگشت به داشبورد مدير
                system("cls");
                return 2;

            default:
                cout << "\n !!! Warning : you are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
    return 0;
}
//--------------------------------------------------
void Print_warning2()
//(منوي هشدار2)اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطاشده نمايش ميدهد
{
    cout << "\a\n !!! Warning : you are not allowed to select this !!!"
         << "\n PLease enter the related number of each command you want : "
         << "\n 1 : Try again"
         << "\n 2 : Return to the dashboard \n >> ";
}
//-------------------------------------------
long long int convert_char_to_num(char str[])
// اين تابع يك آرايه كاراكتري كه قبلا چك شده فقط شامل عدد است را گرفته و نوع آن را به عدد صحيح تغيير ميدهد
//و آن عدد صحيح را بازميگرداند
{
    int digit = 0;
    long long int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (char j = '0'; j <= '9'; j++)
        {
            if (str[i] == j)
            {
                num = num * 10 + digit;
                digit = 0;
                break;
            }
            else
                digit++;
        }
    }
    return num;
}
//--------------------------------------------------------
#endif