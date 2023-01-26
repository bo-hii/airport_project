//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//داشبورد كاربر مدير
#ifndef DASHBOARD_ADMIN_H
#define DASHBOARD_ADMIN_H

#include "sing_up_admin.hpp"
#include "add_flight.hpp"
#include "cancel_flight.hpp"

//----------------------------------
int admin_dashoard(int active_admin_index);
//اين تابع داشبورد كاربر مدير است
void print_admin_dashoard();
//اين تابع گزينه هاي موجود در داشبورد مدير را نمابش ميدهد

void flight_statistics();
//این تابع منوی مربوط به آمارگیری پروازگیری است
int id_index(long long int input_id);
//این تابع یک شناسه پرواز را به عنوان ورودی دریافت میکند و اندیس پرواز با این شناسه را بازمیگرداند
void print_flight_info1(int index);
//(با جزئیات کامل برای مدیر )اين تابع مشخصات يك پرواز را چاپ ميكند
void print_flight_passengers_name(int index);
//این تابع نام مسافران پرواز با اندیسی که به عنوان ورودی به آن داده شده را چاپ میکند

void ticket_confirmation();
//این تابع منوی تایید (اعتبار سنجی ) بلیط است
int username_index(char input_username[]);
//این تابع یک نام کاربری را به عنوان ورودی دریافت میکند و اندیس کاربر عادی با این نام کاربری را بازمیگرداند
bool check_username_and_id(int user_index, int flight_index);
//این تابع چک میکند که آیا کاربر با اندیس ورودی برای پرواز با اندیس ورودی بلیط خریداری کرده یا نه؟

void view_flights1();
//این تابع منوی مربوط مشاهده ی پرواز ها توسط کاربر مدیراست
void print_flight_info2(int index);
//(بدون ذکرنام مسافران آن پرواز برای مدیر )اين تابع مشخصات يك پرواز را چاپ ميكند

//---------------------------------------------
int admin_dashoard(int active_admin_index)
//اين تابع داشبورد كاربر مدير است
{
    char str[max_data_len];
    int command;
    while (true)
    {
        print_admin_dashoard();
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
            case 1: //افزودن پرواز
                add_flight();
                break;
            case 2: //آمارگيري پرواز
                flight_statistics();
                break;
            case 3: //تاييد بليط
                ticket_confirmation();
                break;
            case 4: //مشاهده ي پرواز ها
                view_flights1();
                break;
            case 5: //لغو پرواز
                cancel_flight_menu();
                break;
            case 6: //بازگشت به منوی کاربر مدیر
                return 2;
            case 7: //برگشت به منوي اصلي
                return 3;
            default:
                cout << "\a\n !!! warning : you are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
    return 0;
}
//-------------------------------------------
void print_admin_dashoard()
//اين تابع گزينه هاي موجود در داشبورد مدير را نمابش ميدهد
{
    cout << "\n  Admin dashboard :"
         << "\n 1 : Add flight"
         << "\n 2 : Flight statistics"
         << "\n 3 : Ticket confirmation"
         << "\n 4 : View flights"
         << "\n 5 : Cancel flight"
         << "\n 6 : Log out and Return to the admin panel"
         << "\n 7 : Log out and Return to the main menu"
         << "\n PLease enter the related number of each command you want : ";
}
//-----------------------------------------------
void flight_statistics()
//این تابع منوی مربوط به آمارگیری پروازگیری است
{
    int value = 1, flight_index;
    long long int input_id;

    while (value == 1)
    {
        cout << "\n Flight statistics : \n";

        cout << "\n Please enter the flight ID : ";
        cin >> input_id;
        flight_index = id_index(input_id);
        if (flight_index == -1)
        {
            value = warning2();
        }

        else
            value = 0;
    }
    if (value == 0)
    {
        print_flight_info1(flight_index);
        cout << "\n \n";
        system("pause");
    }
    system("cls");
}
//------------------------------------------------
int id_index(long long int input_id)
//این تابع یک شناسه پرواز را به عنوان ورودی دریافت میکند و اندیس پرواز با این شناسه را بازمیگرداند
//اگر این شناسه وجود نداشت عدد -1 را بازمیگرداند
{
    for (int i = 0; i < count_flight; i++)
    {
        if (input_id == flight[i].id)
            return i;
    }
    return -1;
}
//-------------------------------------------------
void print_flight_info1(int index)
//(با جزئیات کامل برای مدیر )اين تابع مشخصات يك پرواز را چاپ ميكند
{
    cout << "\n From : " << flight[index].origin
         << "\n To : " << flight[index].destination
         << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
         << "\n time : " << flight[index].time.hour << " : " << flight[index].time.minute
         << "\n Airline Name : " << flight[index].airline_name
         << "\n Current number of passengers : " << flight[index].num_passengers
         << "\n Capacity : " << flight[index].capacity;
    print_flight_passengers_name(index);
}
//------------------------------------------
void print_flight_passengers_name(int index)
//این تابع نام مسافران پرواز با اندیسی که به عنوان ورودی به آن داده شده را چاپ میکند
{
    if (flight[index].num_passengers > 0)
    {
        cout << "\n\n Name of pasengers : \n";
        for (int i = 0; i < flight[index].num_passengers; i++)
        {
            cout << i + 1 << "- " << User[flight[index].passengers_index[i]].first_name << " "
                 << User[flight[index].passengers_index[i]].last_name << "\n";
            //چاپ نام کاربر با اندیس آیُم مسافران پرواز با اندیس ورودی
        }
    }
    else
        cout << "\n\n This flight hasn't any pasengers .\n";
}
//---------------------------------------------------
void ticket_confirmation()
//این تابع منوی تایید (اعتبار سنجی ) بلیط است
{
    char input_username[max_data_len];
    int flight_index, user_index;
    long long int input_id;

    cout << "\n Ticket confirmation : \n"
         << "\n Please enter the pasenger username : ";
    cin >> input_username;
    cout << "\n Please enter the flight ID : ";
    cin >> input_id;
    user_index = username_index(input_username);
    if (user_index != -1)
    {
        flight_index = id_index(input_id);
        if (flight_index != -1)
        {
            if (check_username_and_id(user_index, flight_index))
                cout << "\n This ticket is valid .";
            else
                cout << "\n This ticket is invalid .";
        }
        else
            cout << "\n There are no flights with this ID"
                 << "\n This ticket is invalid .";
    }
    else
        cout << "\n There is no user with this username"
             << "\n This ticket is invalid .";
    cout << "\n \n";
    system("pause");
    system("cls");
}
//-------------------------------------------
int username_index(char input_username[])
//این تابع یک نام کاربری را به عنوان ورودی دریافت میکند و اندیس کاربر عادی با این نام کاربری را بازمیگرداند
//اگر این نام کاربری برای هیچ یک از کاربران عادی وجود نداشت عدد -1 را بازمیگرداند
{
    for (int i = 0; i < count_user; i++)
    {
        if (strcmp(input_username, User[i].username) == 0)
            return i;
    }
    return -1;
}
//-----------------------------------------------
bool check_username_and_id(int user_index, int flight_index)
//این تابع اندیس یک کاربر عادی و اندیس یک پرواز را دریافت میکند
//و چک میکند که آیا کاربر با اندیس ورودی برای پرواز با اندیس ورودی بلیط خریداری کرده یا نه؟
{
    for (int i = 0; i < User[user_index].num_tickets; i++)
    {
        if (User[user_index].ticket_index[i] == flight_index)
            return true;
    }
    return false;
}
//------------------------------------------------
void view_flights1()
//این تابع منوی مربوط مشاهده ی پرواز ها توسط کاربر مدیراست
{
    cout << "\n View flights : \n";

    if (count_flight == 0)
    {
        cout << "\n No flights are registered in the system . \n \n";
    }

    for (int i = 0; i < count_flight; i++)
    {
        print_flight_info2(i);
    }
    system("pause");
    system("cls");
}
//-----------------------------------------------
void print_flight_info2(int index)
//(بدون ذکرنام مسافران آن پرواز برای مدیر )اين تابع مشخصات يك پرواز را چاپ ميكند
{
    cout << "\n Flight ID : " << flight[index].id
         << "\n From : " << flight[index].origin
         << "\n To : " << flight[index].destination
         << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
         << "\n Time : " << flight[index].time.hour << " : " << flight[index].time.minute
         << "\n Airline Name : " << flight[index].airline_name
         << "\n Current number of passengers : " << flight[index].num_passengers
         << "\n Capacity : " << flight[index].capacity
         << "\n __________________________________________________________________\n";
}

//---------------------------------------------
#endif