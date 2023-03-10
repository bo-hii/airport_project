//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400/10/8-1400/10/17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//خرید بلیط
#ifndef BUY_TICKET_H
#define BUY_TICKET_H

#include "commen_library.hpp"
#include "buy_indirect_ticket.hpp"

//-----------------------------------
void buy_ticket_menu(int active_user_i);
//این تابع منو خرید بلیط است
void recive_origin_and_destination(char origin[], char destination[]);
//این تابع مبدا و مقصد را از کاربر دریافت میکند

bool ticket_list(char origin[], char destination[]);
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده را چاپ ميكند
void print_ticket_info1(int index);
//(بدون ذکر مبدا و مقصد)اين تابع مشخصات يك بليط را چاپ ميكند

int buy_ticket(char origin[], char destination[]);
//اين تابع براي خريد بليط توسط كاربر عادي است

int check_input_ID(long long int id, char origin[], char destination[]);
// این تابع برسی میکند که عددی که به عنوان ورودی به آن داده شده شناسه کدام پرواز است و اندیس آن را باز میگرداند

bool ask_indirect_ticket(char origin[], char destination[]);
// این تابع از کاربر میپرسد که آیا مایل به خرید پرواز غیر مستقیم هست یا نه

//------------------------------------
void buy_ticket_menu(int active_user_index)
//این تابع منو خرید بلیط است
{
    int index;
    char origin[max_large_data_len], destination[max_large_data_len];
    cout << "\n Buy ticket : \n";

    recive_origin_and_destination(origin, destination);

    if (ticket_list(origin, destination))
    {
        index = buy_ticket(origin, destination); //اندیس پرواز مورد نظر (خریداری شده)کاربر
        system("cls");
        
        if (index != -1)
        {
            cout << "\n YOU have successfully purchased the ticket with ID : " << flight[index].id << " :) \n";
            User[active_user_index].ticket_index[User[active_user_index].num_tickets] = index;
            //آخرین عنصر خالی آرایه اندیس بلیط های کاربر را برابر اندیس پرواز خریداری شده قرار میدهد
            User[active_user_index].num_tickets++;
            //به تعداد بلیط های خریداری شده توسط کاربر یکی اضافه میکند
            flight[index].passengers_index[flight[index].num_passengers] = active_user_index;
            //آخرین عنصر خالی آرایه اندیس مسافران پرواز را برابر اندیس کاربری که بلیط را خریده قرار میدهد
            flight[index].num_passengers++;
            //به تعداد مسافران پرواز مورد نظر یکی اضافه میکند
        }
    }
    else
    {
        if (ask_indirect_ticket(origin, destination))
            buy_indirect_ticket(origin, destination, active_user_index);
    }
}
//------------------------------------
void recive_origin_and_destination(char origin[], char destination[])
//این تابع مبدا و مقصد را از کاربر دریافت میکند
{
    cin.get();
    cout << "\n Origin : ";
    gets(origin);
    cout << "\n Destinationn : ";
    gets(destination);
    system("cls");
}
//---------------------------------------------------------------------
bool ticket_list(char origin[], char destination[])
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده را چاپ ميكند
{
    int count = 0;
    cout << "\n From " << origin << " to " << destination << " flights : \n";
    for (int i = 0; i < count_flight; i++)
    {
        if (strcmp(flight[i].origin, origin) == 0)
        {
            if (strcmp(flight[i].destination, destination) == 0)
            {
                if (flight[i].num_passengers < flight[i].capacity)
                {
                    count++;
                    print_ticket_info1(i);
                }
            }
        }
    }
    if (count == 0)
    {
        cout << "\n There are no direct flights .\n\n";
        return false;
    }
    return true;
}
//------------------------------------
void print_ticket_info1(int index)
//(بدون ذکر مبدا و مقصد)اين تابع مشخصات يك بليط را چاپ ميكند
{
    cout << "\n Flight ID : " << flight[index].id
         << "\n Date : " << flight[index].date.year << " / " << flight[index].date.month << " / " << flight[index].date.day
         << "\n Time : " << flight[index].time.hour << " : " << flight[index].time.minute
         << "\n Airline Name : " << flight[index].airline_name
         << "\n Remaining capacity : " << flight[index].capacity - flight[index].num_passengers
         << "\n __________________________________________________________________\n";
}
//--------------------------------------
int buy_ticket(char origin[], char destination[])
//اين تابع براي خريد بليط توسط كاربر عادي است
//که از کاربر یک عدد دریافت میکند اگر برابر صفر بود کاربر را به داشبورد کاربر عادی باز میگیرد
//اگر نه برسی میکند که برابر شناسه هیچ یک از پرواز های انتخاب شده هست یا نه
{
    char str[max_data_len];
    int value = 1, index;
    long long int command;

    while (value == 1)
    {
        cout << "\n Please enter the flight ID you want to buy"
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

            index = check_input_ID(command, origin, destination);

            if (index == -1) //اگر شناسه وجود نداشت
                value = warning2();
            else
                return index;
        }
    }
    return -1; //مقداری که توسط تابع هشدار باز گردانده شده 2 بوده است که از حلقه خارج شده
}
//--------------------------------------
int check_input_ID(long long int id, char origin[], char destination[])
// این تابع برسی میکند که عددی که به عنوان ورودی به آن داده شده شناسه کدام پرواز است و اندیس آن را باز میگرداند
//اگر آن شناسه در بین پرواز های انتخاب شده نبود -1 باز میگرداند
{
    for (int i = 0; i < count_flight; i++)
    {
        if (strcmp(flight[i].origin, origin) == 0)
        {
            if (strcmp(flight[i].destination, destination) == 0)
            {
                if (flight[i].num_passengers < flight[i].capacity)
                {
                    if (id == flight[i].id)
                        return i;
                }
            }
        }
    }
    return -1;
}
//---------------------------------------
bool ask_indirect_ticket(char origin[], char destination[])
// این تابع از کاربر میپرسد که آیا مایل به خرید پرواز غیر مستقیم هست یا نه
{
    char str[max_data_len];
    int command;
    while (true)
    {
        cout << "do you want to buy indirect flights from " << origin << " to " << destination << " ?"
             << "\n 1-Yas \t 2-No \n >> ";
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
            case 1:
                return true;
            case 2:
                return false;
            default:
                cout << "\a\n !!! warning : you are not allowed to select this !!!"
                     << "\n Please try again ";
            }
        }
    }
}
//------------------------------------
#endif