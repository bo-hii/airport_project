//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//داشبورد كاربر عادي
#ifndef DASHBOARD_USER_H
#define DASHBOARD_USER_H

#include "sing_up_admin.hpp"
#include "buy_ticket.hpp"
//--------------------------------
int user_dashoard(int active_user_index);
//اين تابع داشبورد كاربر عادي است
void print_user_dashoard();
//اين تابع گزينه هاي موجود در داشبورد مدير را نمابش ميدهد

void view_flights2();
// این تابع اطلاعات همه ی پرواز ها با ظرفیت خالی را به کاربر نشان میدهد
void print_ticket_info2(int index);
//(با ذکر همه ی جزئیات)اين تابع مشخصات يك بليط را براي كاربر چاپ ميكند

void view_tickets(int active_user_index);
//این تابع بلیط های خریداری شده توسط کاربر را نمایش میدهد
void print_ticket_info3(int index);
//( بدون ذکر ظرفیت باقی مانده)اين تابع مشخصات يك بليط را چاپ ميكند

//-----------------------------------------
int user_dashoard(int active_user_index)
//اين تابع داشبورد كاربر عادي است
{
    char str[max_data_len];
    int command;
    while (true)
    {
        print_user_dashoard();
        cin >> str;
        system("cls");

        if (not_being_num(str, strlen(str)))
        {
            cout << "\a\n !!! warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
        else
        {
            command = convert_char_to_num(str);

            switch (command)
            {
            case 1: //خريد بليط
                buy_ticket_menu(active_user_index);
                break;
            case 2: //مشاهده ي پروازها
                view_flights2();
                break;
            case 3: //مشاهده ي بليط ها
                view_tickets(active_user_index);
                break;
            case 4: //بازگشت به منوی کاربر عادی
                return 2;
            case 5: //برگشت به منوي اصلي
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
void print_user_dashoard()
//اين تابع گزينه هاي موجود در داشبورد مدير را نمابش ميدهد
{
    cout << "\n User dashboard :"
         << "\n 1 : Buy ticket"
         << "\n 2 : View flights"
         << "\n 3 : View tickets"
         << "\n 4 : Log out and Return to the user panel"
         << "\n 5 : Log out and Return to the main menu"
         << "\n PLease enter the related number of each command you want : ";
}
//-----------------------------------------------
void view_flights2()
// این تابع اطلاعات همه ی پرواز ها با ظرفیت خالی را به کاربر نشان میدهد
{
    int count = 0;
    cout << "\n View flights : \n";
    for (int i = 0; i < count_flight; i++)
    {
        if (flight[i].num_passengers < flight[i].capacity)
        {
            count++;
            print_ticket_info2(i);
        }
    }
    if (count == 0)
    {
        cout << "\n There are no flights .\n\n";
    }
    system("pause");
    system("cls");
}
//-------------------------------------------------
void print_ticket_info2(int index)
//(با ذکر همه ی جزئیات)اين تابع مشخصات يك بليط را براي كاربر چاپ ميكند
{
    cout << "\n Flight ID : " << flight[index].id
         << "\n From : " << flight[index].origin
         << "\n To : " << flight[index].destination
         << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
         << "\n Time : " << flight[index].time.hour << " : " << flight[index].time.minute
         << "\n Airline Name : " << flight[index].airline_name
         << "\n Remaining capacity : " << flight[index].capacity - flight[index].num_passengers
         << "\n __________________________________________________________________\n";
}
//---------------------------------------
void view_tickets(int active_user_index)
//این تابع بلیط های خریداری شده توسط کاربر را نمایش میدهد
{
    int count = 0, index;
    cout << "\n View your tickets : \n";
    for (int i = 0; i < User[active_user_index].num_tickets; i++)
    {
        count++;
        print_ticket_info3(User[active_user_index].ticket_index[i]);
        //چاپ کردن اطلاعات بلیط با اندیس عنصر آیم آرایه ی اندیس بلیط های کاربر فعال
    }
    if (count == 0)
    {
        cout << "\n You don't have any tickets .\n\n";
    }
    system("pause");
    system("cls");
}
//---------------------------------------------------
void print_ticket_info3(int index)
//( بدون ذکر ظرفیت باقی مانده)اين تابع مشخصات يك بليط را چاپ ميكند
{
    cout << "\n Flight ID : " << flight[index].id
         << "\n From : " << flight[index].origin
         << "\n To : " << flight[index].destination
         << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
         << "\n Time : " << flight[index].time.hour << " : " << flight[index].time.minute
         << "\n Airline Name : " << flight[index].airline_name
         << "\n __________________________________________________________________\n";
}
//------------------------------------------
#endif