//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//داشبورد كاربر عادي
#ifndef ADD_FLIGHT_H
#define ADD_FLIGHT_H

#include "commen_library.hpp"
//----------------------------------------
void add_flight();
//اين تابع يك پرواز جديد ايجاد ميكند

int recive_flight_id();
//اين تابع شناسه پرواز را دريافت ميكند
bool being_repeated_id(int index);
//اين تابع چك ميكند كه شناسه پرواز قبلا انتخاب شده يا نه

int recive_flight_origin();
//اين تابع مبدا حركت را دريافت ميكند

int recive_flight_destination();
//اين تابع مقصد حركت را دريافت ميكند

int recive_flight_date();
//اين تابع تاريخ پرواز را دريافت ميكند
bool invalied_date();
//اين تابع مقادير غير مجاز تاريخ را مشخص ميكند

int recive_flight_time();
//اين تابع ساعت پرواز را دريافت ميكند
bool invalied_time();
//اين تابع مقادير غير مجاز ساعت را مشخص ميكند

int recive_flight_airline_name();
//اين تابع نام شركت هواپيمايي  را دريافت ميكند

int recive_flight_capacity();
//اين تابع ظرفيت پرواز را دريافت ميكند

//---------------------------------------
void add_flight()
//اين تابع مشخصات پرواز را ميگيرد و يك پرواز جديد ايجاد ميكند
//اگر ظرفيت پروازها پر شده باشد پيامي چاپ كرده و به داشبورد بازميگردد
//در نهايت اگر پرواز باموفقيت ايجاد شود پيامي چاپ و به داشبورد مدير بازميگردد
{
    int valu = 0;
    // اگر در هر مرحله متغير ارزش برابر 2 يا 3 شود از تابع خارج ميشود
    //و اگر صفر شود فرايند ايجاد پرواز جديد ادامه مي يابد

    if (count_flight > max_flight_count)
    {
        cout << "\n Sorry; You are not allowed to add another flight :(";
    }
    else
    {
        cout << "\n Add new flight : \n";

        if (valu == 0)
        {
            valu = recive_flight_id();

            if (valu == 0)
            {
                valu = recive_flight_origin();

                if (valu == 0)
                {
                    valu = recive_flight_destination();

                    if (valu == 0)
                    {
                        valu = recive_flight_date();

                        if (valu == 0)
                        {
                            valu = recive_flight_time();

                            if (valu == 0)
                            {
                                valu = recive_flight_airline_name();

                                if (valu == 0)
                                {
                                    valu = recive_flight_capacity();

                                    system("cls");
                                    if (valu == 0)
                                    {
                                        flight[count_flight].num_passengers = 0;
                                        count_flight++;
                                        valu = 2; //شرط ادامه حلقه را نادرست كرده و باعث خروج از فرايند ثبت نام و ورود به داشبورد
                                        cout << "\n New flight created successfully :) \n";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
//---------------------------------------------
int recive_flight_id()
//اين تابع شناسه پرواز را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int len, value = 1;
    char id[max_data_len];
    while (value == 1)
    {
        cout << "\n Flight ID (maximum 10 charactors) : ";
        cin >> id;
        len = strlen(id);

        if (len > 10 || not_being_num(id, len)) //بیشنر از ۱۰ کاراکتر داشته باشد یا شامل کاراکتر غیر عددی باشد
            value = warning2();

        else
        {
            flight[count_flight].id = convert_char_to_num(id); //تبدیل یک رشته به یک عدد صحیح و انتساب آن به شناسه ی پرواز

            if (being_repeated_id(count_flight) || flight[count_flight].id == 0) //شناسه تکراری باشد یا برابر صفر باشد
                value = warning2();

            else
                value = 0;
        }
    }
    return value;
}
//------------------------------------------
bool being_repeated_id(int index)
//اين تابع چك ميكند كه شناسه پرواز قبلا انتخاب شده يا نه
{
    for (int i = 0; i < count_flight; i++)
    {
        if (flight[index].id == flight[i].id)
            return true;
    }
    return false;
}
//------------------------------------------
int recive_flight_origin()
//اين تابع مبدا حركت را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n Origin (maximum 50 charactors) : ";
        gets(flight[count_flight].origin);

        if (strlen(flight[count_flight].origin) > 50)
            value = warning2();

        else
            value = 0;
    }
    return value;
}
//------------------------------------------
int recive_flight_destination()
//اين تابع مقصد حركت را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n Destination (maximum 50 charactors) : ";
        gets(flight[count_flight].destination);
        if (strlen(flight[count_flight].destination) > 50)
            value = warning2();

        else
            value = 0;
    }
    return value;
}
//---------------------------------------------
int recive_flight_date()
//اين تابع تاريخ پرواز را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int value = 1;
    while (value == 1)
    {
        cout << "\n Year (2000-3000) : ";
        cin >> flight[count_flight].date.year;
        cout << "\n Month (1-12) : ";
        cin >> flight[count_flight].date.month;
        cout << "\n Day (1-30) : ";
        cin >> flight[count_flight].date.day;

        if (invalied_date())
            value = warning2();

        else
            value = 0;
    }
    return value;
}
//-------------------------------------------
bool invalied_date()
//اين تابع مقادير غير مجاز تاريخ را مشخص ميكند
{
    if (flight[count_flight].date.year < 2000 || flight[count_flight].date.year > 3000)
        return true;
    if (flight[count_flight].date.month < 1 || flight[count_flight].date.month > 12)
        return true;
    if (flight[count_flight].date.day < 1 || flight[count_flight].date.day > 30)
        return true;
    return false;
}
//---------------------------------------------
int recive_flight_time()
//اين تابع ساعت پرواز را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int value = 1;
    while (value == 1)
    {
        cout << "\n Hour (0-23) : ";
        cin >> flight[count_flight].time.hour;
        cout << "\n Minute (0-59) : ";
        cin >> flight[count_flight].time.minute;

        if (invalied_time())
            value = warning2();

        else
            value = 0;
    }
    return value;
}
//----------------------------------------
bool invalied_time()
//اين تابع مقادير غير مجاز ساعت را مشخص ميكند
{
    if (flight[count_flight].time.hour < 0 || flight[count_flight].time.hour > 23)
        return true;
    if (flight[count_flight].time.minute < 0 || flight[count_flight].time.minute > 59)
        return true;
    return false;
}
//------------------------------------------
int recive_flight_airline_name()
//اين تابع نام شركت هواپيمايي  را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    int value = 1;
    while (value == 1)
    {
        cin.get();
        cout << "\n Airline name (maximum 25 charactors) : ";
        gets(flight[count_flight].airline_name);

        if (strlen(flight[count_flight].airline_name) > 25)
            value = warning2();

        else
            value = 0;
    }
    return value;
}
//------------------------------------------
int recive_flight_capacity()
//اين تابع ظرفيت پرواز را دريافت ميكند
// اگر به ارور برخورديم دستور ميگيريم كه براي ادامه دوباره اين فيلد را دريافت كنيم تابع هشدار برابر(1)
// يااز اين تابع خارج شويم و پس از آن به داشبورد بازگرديم تابع هشدار برابر(2)--> بازگرداندن(2)
//اگر مشكلي نداشت به تابع ثبت نام برميگرديم و روند ثبت نام ادامه پيدا ميكند--> بازگرداندن (0)
{
    char capacity[max_data_len];
    int len, value = 1;
    while (value == 1)
    {
        cout << "\n Capacity (maximum 250 people) : ";
        cin >> capacity;
        len = strlen(capacity);

        if (not_being_num(capacity, len))
            value = warning2();

        else
        {
            flight[count_flight].capacity = convert_char_to_num(capacity);

            if (flight[count_flight].capacity > max_flight_capacity)
                value = warning2();

            else
                value = 0;
        }
    }
    return value;
}
//----------------------------------------------
#endif
