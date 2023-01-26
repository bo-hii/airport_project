//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//لغو کردن پرواز
#ifndef CANCEL_FLIGHT_H
#define CANCEL_FLIGHT_H

#include "commen_library.hpp"

//-----------------------------------
void cancel_flight_menu();
//این تابع منو لغو پرواز است
bool flight_list();
//اين تابع ليست پرواز ها را چاپ ميكند
int cancel_flight();
//اين تابع براي لغو بليط توسط كاربر مدیر است

//------------------------------------
void cancel_flight_menu()
//این تابع منو لغو پرواز است
{
    int index;
    cout << "\n Cancel flight : \n";

    if (flight_list())
    {
        index = cancel_flight(); //اندیس پرواز مورد نظر (لغو شده)کاربر
        system("cls");

        if (index != -1)
        {
            cout << "\n YOU have successfully cancel the flight with ID : " << flight[index].id << endl;
            for (int i = index; i < count_flight - 1; i++)
            {
                flight[i] = flight[i + 1];
            }
            count_flight--;
        }
    }
}
//---------------------------------------------------------------------
bool flight_list()
//اين تابع ليست پرواز ها را چاپ ميكند
{
    if (count_flight == 0)
    {
        cout << "\n No flights are registered in the system . \n \n";
        system("pause");
        system("cls");
        return false;
    }

    for (int i = 0; i < count_flight; i++)
    {
        cout << "\n Flight ID : " << flight[i].id
             << "\n From : " << flight[i].origin
             << "\n To : " << flight[i].destination
             << "\n Date : " << flight[i].date.year << " / " << flight[i].date.month << " / " << flight[i].date.day
             << "\n Time : " << flight[i].time.hour << " : " << flight[i].time.minute
             << "\n Airline Name : " << flight[i].airline_name
             << "\n Current number of passengers : " << flight[i].num_passengers
             << "\n Capacity : " << flight[i].capacity
             << "\n __________________________________________________________________\n";
    }
    return true;
}
//--------------------------------------
int cancel_flight()
//اين تابع براي لغو پرواز توسط كاربر مدیر است
//که از کاربر یک عدد دریافت میکند اگر برابر صفر بود کاربر را به داشبورد کاربر مدبر باز میگیرد
//اگر نه برسی میکند که برابر شناسه هیچ یک از پرواز هاهست یا نه
{
    char str[max_data_len];
    int value = 1;
    long long int command;

    while (value == 1)
    {
        cout << "\n Please enter the flight ID you want to cancel"
             << "\n If you want to return to admin dashboard enter ( 0 ) "
             << "\n >> ";
        cin >> str;

        if (not_being_num(str, strlen(str)))
        {
            cout << "\a\n !!! warning : you are only allowed to enter numbers !!!"
                 << "\n Please try again ";
        }
        else
        {
            command = convert_char_to_num(str);

            if (command == 0)
                return -1;

            for (int i = 0; i < count_flight; i++)
            {
                if (command == flight[i].id)
                {
                    return i;
                }
            }

            value = warning2();
        }
    }
    return -1; //مقداری که توسط تابع هشدار باز گردانده شده 2 بوده است که از حلقه خارج شده
}
//--------------------------------------
#endif