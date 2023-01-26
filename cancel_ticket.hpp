//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//لغو کردن بلیط
#ifndef CANCEL_TICKET_H
#define CANCEL_TICKET_H

#include "commen_library.hpp"
//-----------------------------
void cancel_ticket_menu(int active_user_index);
//این تابع منو لغو بلیط است
bool ticket_list(int active_user_index);
//اين تابع ليست بلیط ها ی کاربر را چاپ ميكند
int cancel_ticket(int active_user_index);
//اين تابع براي لغو بليط كاربر توسط خودش است

//-----------------------------------------------
void cancel_ticket_menu(int active_user_index)
//این تابع منو لغو بلیط است
{
    int index;
    cout << "\n Cancel ticket : \n";

    if (ticket_list(active_user_index))
    {
        index = cancel_ticket(active_user_index); //اندیس بلیط مورد نظر (لغو شده)کاربر
        system("cls");

        if (index != -1)
        {
            cout << "\n YOU have successfully cancel the ticket with ID : " << flight[index].id << endl;
            for (int i = index; i < User[active_user_index].num_tickets - 1; i++)
            {
                User[active_user_index].ticket_index[i] = User[active_user_index].ticket_index[i + 1];
                flight[index].passengers_index[i] = flight[index].passengers_index[i + 1];
            }

            User[active_user_index].num_tickets--;
            //از تعداد بلیط های خریداری شده توسط کاربر یکی کم میکند
            flight[index].num_passengers--;
            //از تعداد مسافران پرواز مورد نظر یکی کم میکند
        }
    }
}
//---------------------------------------------------------------------
bool ticket_list(int active_user_index)
//اين تابع ليست بلیط ها ی کاربر را چاپ ميكند
{
    int index;
    if (User[active_user_index].num_tickets == 0)
    {
        cout << "\n You don't have any tickets .\n\n";
        return false;
    }

    for (int i = 0; i < User[active_user_index].num_tickets; i++)
    {
        index = User[active_user_index].ticket_index[i];
        cout << "\n Flight ID : " << flight[index].id
             << "\n From : " << flight[index].origin
             << "\n To : " << flight[index].destination
             << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
             << "\n Time : " << flight[index].time.hour << " : " << flight[index].time.minute
             << "\n Airline Name : " << flight[index].airline_name
             << "\n __________________________________________________________________\n";
    }
    return true;
}
//--------------------------------------
int cancel_ticket(int active_user_index)
//اين تابع براي لغو بليط كاربر توسط خودش است
//که از کاربر یک عدد دریافت میکند اگر برابر صفر بود کاربر را به داشبورد کاربر عادی باز میگیرد
//اگر نه برسی میکند که برابر شناسه هیچ یک از بلیط ها ی کاربر هست یا نه
{
    char str[max_data_len];
    long long int command;

    while (true)
    {
        cout << "\n Please enter the flight ID of the ticket you want to cancel"
             << "\n If you want to return to user dashboard enter ( 0 ) "
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

            for (int i = 0; i < User[active_user_index].num_tickets; i++)
            {
                if (command == flight[User[active_user_index].ticket_index[i]].id)
                {
                    return i;
                }
            }

            if (warning2() == 2)
                return -1; //مقداری که توسط تابع هشدار باز گردانده شده 2 بوده است و کاربر باید به داشبورد بازگردد
        }
    }
}
//-------------------------------------------------------
#endif