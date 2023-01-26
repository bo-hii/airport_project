//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.11.04
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//خرید بلیط پرواز غیر مستقیم
#ifndef BUY_INDIRECT_TICKET_H
#define BUY_INDIRECT_TICKET_H

#include "commen_library.hpp"
//-----------------------------------------
void buy_indirect_ticket(char origin[], char destination[], int active_user_index);
//این تابع منو خرید بلیط با  یک توقف بین راهی (پرواز غیر مستقیم) است

bool ticket_list2(char origin[], char destination[]);
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده و توقف در بین راه را چاپ ميكند

bool buy_indirect_ticket(char origin[], char destination[], int index[]);
//اين تابع براي خريد دو بليط همزمان برای پرواز با توقف توسط كاربر عادي است

bool check_invalied_input_ID(long long int id[], int index[], char origin[], char destination[]);
// این تابع برسی میکند که عددهایی که به عنوان ورودی به آن داده شده شناسه غیر مجازی هستند یا نه

//---------------------------------------
void buy_indirect_ticket(char origin[], char destination[], int active_user_index)
//این تابع منو خرید بلیط با  یک توقف بین راهی (پرواز غیر مستقیم) است
{
    int index[2];

    if (ticket_list2(origin, destination))
    {
        if (buy_indirect_ticket(origin, destination, index))
        {
            system("cls");
            cout << "\n You have successfully purchased tow tickets with IDs : \n"
                 << flight[index[0]].id << " and " << flight[index[1]].id << " :)\n";
            for (int i = 0; i < 2; i++)
            {
                User[active_user_index].ticket_index[User[active_user_index].num_tickets] = index[i];
                //آخرین عنصر خالی آرایه اندیس بلیط های کاربر را برابر اندیس پرواز خریداری شده قرار میدهد
                User[active_user_index].num_tickets++;
                //به تعداد بلیط های خریداری شده توسط کاربر یکی اضافه میکند
                flight[index[i]].passengers_index[flight[index[i]].num_passengers] = active_user_index;
                //آخرین عنصر خالی آرایه اندیس مسافران پرواز را برابر اندیس کاربری که بلیط را خریده قرار میدهد
                flight[index[i]].num_passengers++;
                //به تعداد مسافران پرواز مورد نظر یکی اضافه میکند
            }
        }
    }
}
//---------------------------------------------------------------------
bool ticket_list2(char origin[], char destination[])
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده و توقف در بین راه(پرواز های غیر مستقیم) را چاپ ميكند
{
    int count = 0;
    cout << "\n From " << origin << " to " << destination << " indirect flights : \n";
    for (int i = 0; i < count_flight; i++)
    {
        if (strcmp(flight[i].origin, origin) == 0)
        {
            for (int j = 0; j < count_flight; j++)
            {
                if (strcmp(flight[j].destination, destination) == 0)
                {
                    if (strcmp(flight[i].destination, flight[j].origin) == 0)
                    {
                        if (flight[i].num_passengers < flight[i].capacity && flight[j].num_passengers < flight[j].capacity)
                        {
                            count++;
                            print_ticket_info2(i);
                            print_ticket_info2(j);
                            cout << "\n***************************************************************"
                                 << "\n***************************************************************\n";
                        }
                    }
                }
            }
        }
    }
    if (count == 0)
    {
        cout << "\n There are no indirect flights .\n\n";
        system("pause");
        system("cls");
        return false;
    }
    return true;
}
//--------------------------------------
bool buy_indirect_ticket(char origin[], char destination[], int index[])
//اين تابع براي خريد دو بليط همزمان برای پرواز با توقف (پرواز غیر مستقیم) توسط كاربر عادي است
//که از کاربر یک عدد دریافت میکند اگر برابر صفر بود کاربر را به داشبورد کاربر عادی باز میگیرد
//اگر نه برسی میکند که برابر شناسه هیچ یک از پرواز های انتخاب شده هست یا نه
// و اگر بود اندیس آن پرواز  ها را درون آرایه اندیس ها ذخیره میکند
{
    char str[max_data_len];
    long long int command[2];
    while (true)
    {
        int i = 0;
        while (i < 2)
        {
            cout << "\n  Please enter the flight ID you want to buy"
                 << "\n If you want to return to user dashboard enter ( 0 ) ";
            if (i == 0)
                cout << "\n first flight ID (from origin) >> ";
            else
                cout << "\n second flight ID (to destination) >> ";

            cin >> str;

            if (not_being_num(str, strlen(str)))
            {
                cout << "\a\n !!! warning : you are only allowed to enter numbers !!!"
                     << "\n Please try again ";
            }
            else
            {
                command[i] = convert_char_to_num(str);

                if (command[i] == 0)
                {
                    system("cls");
                    return false; //کاربر میخوهد خرید بلیط را متوقف کند و به داشبوردش باز گردد
                }

                i++;
            }
            str[0] = '\0';
        }
        if (check_invalied_input_ID(command, index, origin, destination)) //اگر شناسه وجود نداشت
        {
            if (warning2() == 2)
                return false;
            //مقداری که توسط تابع هشدار باز گردانده شده 2 بوده است پس باید خرید بلیط متوقف شودو به داشبورد کاربر باز گردد
        }
        else
            return true; //کاربر با موفقیت هر دو بلیط را خریداری کرده
    }
    return false; //واسه اینکه بهم هشدار میداد
}
//---------------------------------------------------
bool check_invalied_input_ID(long long int id[], int index[], char origin[], char destination[])
// این تابع برسی میکند که عددهایی که به عنوان ورودی به آن داده شده شناسه غیر مجازی هستند یا نه
// همچین اگر شناسه ها معتبر بودند اندیس پروازآنها را در آرایه ی اندیس ها ی شناسه ها ذخیره میکند
{
    for (int i = 0; i < count_flight; i++)
    {
        if (strcmp(flight[i].origin, origin) == 0)
        {
            for (int j = 0; j < count_flight; j++)
            {
                if (strcmp(flight[j].destination, destination) == 0)
                {
                    if (strcmp(flight[i].destination, flight[j].origin) == 0)
                    {
                        if (flight[i].num_passengers < flight[i].capacity && flight[j].num_passengers < flight[j].capacity)
                        {
                            if (id[0] == flight[i].id && id[1] == flight[j].id)
                            {
                                index[0] = i;
                                index[1] = j;
                                return false;
                                // هر دو شناسه ی وارد شده در بین پرواز های انتخاب شده هست پس غیر مجاز نیست
                            }
                            else if (id[1] == flight[i].id && id[0] == flight[j].id)
                            {
                                index[0] = j;
                                index[1] = i;
                                return false;
                                // هر دو شناسه ی وارد شده در بین پرواز های انتخاب شده هست پس غیر مجاز نیست
                            }
                        }
                    }
                }
            }
        }
    }
    return true; // حداقل یکی از شناسه ی وارد شده در بین پرواز های انتخاب شده نیست پس غیر مجاز است
}
//----------------------------------------
#endif
