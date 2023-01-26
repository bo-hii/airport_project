//بهاره دهقانی
//شماره دانشجويي : 40011973
//فاز دوم پروژه درس مبانی کامپیوتر و برنامه سازی
//1400.10.8-1400.10.17
// استاد درس :دکتر مهدی یزدیان دهکردی
//پروژه هواپيما
//اين برنامه بدون استفاده از كتابخانه هاي ارسال شده اجرا ميشود
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
USER User[max_user_count];
FLIGHT flight[max_flight_count];
int count_admin = 0;
int count_user = 0;
int count_flight = 0;
//--------------------------------------------------
void print_start_menu();
// اين تابع منوي اصلي را نمايش ميدهد

void admin_panel();
// اين تابع پنل مديران است
void print_admin_panel_menu();
//اين تابع منوي پنل  مدير را نمايش ميدهد

void user_panel();
// اين تابع پنل كاربران عادي است
void print_user_panel_menu();
//اين تابع منوي پنل كاربر را نمايش ميدهد

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

int to_sing_up_as_admin();
//اين تابع مشخصات شخص را دريافت و او را به عنوان مدير ثبت نام ميكند

int recive_admin_username();
//اين تابع نام كاربري را از كاربر عادي دريافت ميكند
bool being_repeated_admin_username();
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه مديران انتخاب شده يا نه

int to_sing_up_as_user();
//اين تابع مشخصات شخص را دريافت و او را به عنوان كاربر عادي ثبت نام ميكند

int recive_user_username();
//اين تابع نام كاربري را از كاربر مدير دريافت ميكند
bool being_repeated_user_username();
//اين تابع چك ميكند كه نام كاربري انتخابي توسط شخص قبلا در زيرگروه كاربران انتخاب شده يا نه

int to_log_in_admin_account();
// اين تابع چك ميكند كاربر مدير قبلا داراي حساب است ياخير و اگر حساب داشت او را وارد داشبوردش ميكند
int check_being_existed_admin_username(char entrance_username[]);
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه مديران وجود دارد يا نه و شماره كاربر با اين نام كاربري را برميگرداند

int to_log_in_user_account();
//اين تابع چك ميكند كاربر عادي قبلا داراي حساب است ياخير و اگر حساب داشت او را وارد داشبوردش ميكند
int check_being_existed_user_username(char entrance_username[]);
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه كاربران وجود دارد يا نه شماره كاربر با اين نام كاربري را برميگرداند

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

void buy_ticket_menu(int active_user_i);
//این تابع منو خرید بلیط است
void recive_origine_and_destination(char origine[], char destination[]);
//این تابع مبدا و مقصد را از کاربر دریافت میکند

bool ticket_list(char origin[], char destination[]);
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده را چاپ ميكند
void print_ticket_info1(int index);
//(بدون ذکر مبدا و مقصد)اين تابع مشخصات يك بليط را چاپ ميكند

int buy_ticket(char origine[], char destination[]);
//اين تابع براي خريد بليط توسط كاربر عادي است

int check_input_ID(long long int id, char origine[], char destination[]);
// این تابع برسی میکند که عددی که به عنوان ورودی به آن داده شده شناسه کدام پرواز است و اندیس آن را باز میگرداند

//------------------------------------------
int main()
{
    int command;
    while (true)
    {
        print_start_menu();
        cin >> command;
        system("cls");

        switch (command)
        {
        case 1: //ورود به پنل مديران
            admin_panel();
            break;
        case 2: //ورود به پنل كاربران
            user_panel();
            break;
        case 3: //خروج از برنامه
            return 0;
        default:
            cout << "\n !!! Warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
    }
}
//-------------------------------------------
void print_start_menu()
//اين تابع منوي اوليه را نمايش ميدهد
{
    cout << "\n Menu : "
         << "\n 1 : Go to the admin panel"
         << "\n 2 : Go to the user panel"
         << "\n 3 : Exit"
         << "\n PLease enter the related number of each command you want : ";
}
//---------------------------------------------
void admin_panel()
// اين تابع پنل مديران است
{
    int command;
    int valu = 1;
    while (valu != 3)
    {
        print_admin_panel_menu();
        cin >> command;
        system("cls");

        switch (command)
        {
        case 1: //ورود
            valu = to_log_in_admin_account();
            //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
            break;
        case 2: //ثبت نام
            valu = to_sing_up_as_admin();
            //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
            break;
        case 3: //بازگشت به منوي اصلي
            valu = 3;
            break;
        default:
            cout << "\n !!! Warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
    }
}
//---------------------------------------------
void user_panel()
//اين تابع منوي پنل كاربر را نمايش ميدهد
{
    int command;
    int valu = 1;
    while (valu != 3)
    {
        print_user_panel_menu();
        cin >> command;
        system("cls");

        switch (command)
        {
        case 1: //ورود
            valu = to_log_in_user_account();
            //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
            break;
        case 2: //ثبت نام
            valu = to_sing_up_as_user();
            //اگر تابع مقدار 2 را برگرداند پنل اجرا ميشود و اگر 3 را برگرداند از پنل خارج و وارد منوي اوليه ميشود
            break;
        case 3: //بازگشت به منوي اصلي
            valu = 3;
            break;
        default:
            cout << "\n !!! Warning : You are not allowed to select this !!!"
                 << "\n Please try again ";
        }
    }
}
//-------------------------------------------
void print_admin_panel_menu()
//اين تابع منوي پنل  مدير را نمايش ميدهد
{
    cout << "\n Admin Panel : "
         << "\n 1 : Log in(As Admin)"
         << "\n 2 : Sing up(As Admin)"
         << "\n 3 : Return to the main menu "
         << "\n PLease enter the related number of each command you want : ";
}
//-------------------------------------------
void print_user_panel_menu()
//اين تابع منوي پنل كاربر را نمايش ميدهد
{
    cout << "\n User Panel : "
         << "\n 1 : Log in(As User)"
         << "\n 2 : Sing up(As User)"
         << "\n 3 : Return to the main menu "
         << "\n PLease enter the related number of each command you want : ";
}
//-----------------------------------------------
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
        {
            value = warning();
        }
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
    int command;
    while (true)
    {
        Print_warning();
        cin >> command;
        switch (command)
        {
        case 1: //تلاش مجدد
            return command;
            break;
        case 2: //بازگشت به منو پنل
        case 3: //بازگشت به منو اوليه
            system("cls");
            return command;
            break;
        default:
            system("cls");
            cout << "\n !!! Warning : you are not allowed to select this !!!"
                 << "\n Please try again ";
        }
    }
    return 0;
}
//--------------------------------------------
void Print_warning()
//اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطا در ثبت نام شده نمايش ميدهد
{
    cout << "\n !!! Warning : you are not allowed to select this !!!"
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
    int command;
    while (true)
    {
        Print_warning2();
        cin >> command;
        switch (command)
        {
        case 1: //تلاش مجدد
            return 1;
            break;
        case 2: //بازگشت به داشبورد مدير
            system("cls");
            return 2;
            break;
        default:
            system("cls");
            cout << "\n !!! Warning : you are not allowed to select this !!!"
                 << "\n Please try again ";
        }
    }
    return 0;
}
//--------------------------------------------------
void Print_warning2()
//(منوي هشدار2)اين تابع هشداري را نمايش ميدهد و منويي براي كاربري كه دچار خطاشده نمايش ميدهد
{
    cout << "\n !!! Warning : you are not allowed to select this !!!"
         << "\n PLease enter the related number of each command you want : "
         << "\n 1 : Try again"
         << "\n 2 : Return to the dashboard \n >> ";
}
//-------------------------------------------
long long int convert_char_to_num(char str[])
// اين تابع يك آرايه كاراكتري كه قبلا چك شده فقط شامل عدد است را گرفته و نوع آن را به عدد صحيح تغيير ميدهد
//و آن عدد صحيح را بازميگرداند
{
    int len, digit = 0;
    long long int num = 0;
    len = strlen(str);
    for (int i = 0; i < len; i++)
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

    if (valu == 0)
        valu = recive_first_name(Admin[count_admin].first_name);

    if (valu == 0)
        valu = recive_last_name(Admin[count_admin].last_name);

    if (valu == 0)
        valu = recive_phone_namber(Admin[count_admin].phone_number);

    if (valu == 0)
        valu = recive_admin_username();

    if (valu == 0)
        valu = recive_Password(Admin[count_admin].password);
    if (valu == 0)
        valu = Confirm_Password(Admin[count_admin].password);

    system("cls");
    if (valu == 0)
    {
        cout << " Hi " << Admin[count_admin].username << "\n Your registration was successful :) \n";
        count_admin++;
        valu = 2; //شرط ادامه حلقه را نادرست كرده و باعث خروج از فرايند ثبت نام و ورود به پنل
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
//-------------------------------------------
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

    if (valu == 0)
        valu = recive_first_name(User[count_user].first_name);

    if (valu == 0)
        valu = recive_last_name(User[count_user].last_name);

    if (valu == 0)
        valu = recive_phone_namber(User[count_user].phone_number);

    if (valu == 0)
        valu = recive_user_username();

    if (valu == 0)
        valu = recive_Password(User[count_user].password);
    if (valu == 0)
        valu = Confirm_Password(User[count_user].password);

    system("cls");
    if (valu == 0)
    {
        cout << " Hi " << User[count_user].username << "\n Your registration was successful :) \n";
        count_user++;
        valu = 2; //شرط ادامه حلقه را نادرست كرده و باعث خروج از فرايند ثبت نام و ورود به پنل كاربر عادي ميشود
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
//---------------------------------------
int to_log_in_admin_account()
//اين تابع چك ميكند كاربر مدير قبلا داراي حساب است ياخير
//و اگر داراي حساب بود او را وارد داشبوردش ميكند
// و عددي را بر ميگرداند كه مشخص ميكند برنامه در كجا ادامه پيدا كند
//(فعلا همواره برنامه در منوي اصلي ادامه پيدا ميكند(عدد 3))
{
    int admin_index, valu = 1;
    char user_name[max_data_len], pass[max_data_len];
    while (valu == 1)
    {
        system("cls");
        cout << "\n Log in as an admin :\n";

        cin.get();
        cout << "\n Please enter your username : ";
        gets(user_name);
        admin_index = check_being_existed_admin_username(user_name);
        if (admin_index == -1)
        {
            cout << "\n!!! Your login username is incorrect !!!\n";
            valu = warning();
            continue;
        }

        cout << "\n Please enter your password : ";
        cin >> pass;
        if (strcmp(Admin[admin_index].password, pass) != 0)
        {
            cout << "\n!!! Your login password is incorrect !!!\n";
            valu = warning();
            continue;
        }

        system("cls");
        cout << "Hi " << Admin[admin_index].username << "\n You have successfully loged in :) \n";
        valu = admin_dashoard(admin_index);
    }
    return valu;
}
//----------------------------------------------
int check_being_existed_admin_username(char entrance_username[])
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه مديران وجود دارد يا نه
// و انديس كاربر با اين نام كاربري را برميگرداند
{
    for (int i = 0; i <= count_admin; i++)
    {
        if (strcmp(entrance_username, Admin[i].username) == 0)
            return i;
    }
    return -1;
}
//---------------------------------------
int to_log_in_user_account()
//اين تابع چك ميكند كاربر عادي قبلا داراي حساب است ياخير
//و اگر داراي حساب بود او را وارد داشبوردش ميكند
// و عددي را بر ميگرداند كه مشخص ميكند برنامه در كجا ادامه پيدا كند
//(فعلا همواره برنامه در منوي اصلي ادامه پيدا ميكند(عدد 3))
{
    int user_index, valu = 1;
    char user_name[max_data_len], pass[max_data_len];
    while (valu == 1)
    {
        cout << "\n Log in as an user :\n";

        cin.get();
        cout << "\n Please enter your username : ";
        gets(user_name);
        user_index = check_being_existed_user_username(user_name);
        if (user_index == -1)
        {
            cout << "\n!!! Your login username is incorrect !!!\n";
            valu = warning();
            continue;
        }
        cout << "\n Please enter your password : ";
        cin >> pass;
        if (strcmp(User[user_index].password, pass) != 0)
        {
            cout << "\n!!! Your login password is incorrect !!!\n";
            valu = warning();
            continue;
        }

        system("cls");
        cout << "Hi " << User[user_index].username << "\n You have successfully loged in :) \n";
        valu = user_dashoard(user_index);
    }
    return valu;
}
//----------------------------------------------
int check_being_existed_user_username(char entrance_username[])
// اين تابع چك ميكند كه نام كاربري ورودي قبلا در زيرگروه كاربران وجود دارد يا نه
// و انديس كاربر با اين نام كاربري را برميگرداند
{
    for (int i = 0; i <= count_user; i++)
    {
        if (strcmp(entrance_username, User[i].username) == 0)
            return i;
    }
    return -1;
}
//-------------------------------------------------------
int admin_dashoard(int active_admin_index)
//اين تابع داشبورد كاربر مدير است
{
    int value, command;
    while (true)
    {
        print_admin_dashoard();
        cin >> command;
        system("cls");
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
        case 5: //بازگشت به منوی کاربر مدیر
            return 2;
        case 6: //برگشت به منوي اصلي
            return 3;
        default:
            cout << "\n !!! Warning : you are not allowed to select this !!!"
                 << "\n Please try again ";
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
         << "\n 5 : Log out and Return to the admin panel"
         << "\n 6 : Log out and Return to the main menu"
         << "\n PLease enter the related number of each command you want : ";
}
//-----------------------------------------------
void flight_statistics()
//این تابع منوی مربوط به آمارگیری پروازگیری است
{
    int value = 1, flight_index;
    long long int input_id;
    cout << "\n Flight statistics : \n";

    while (value == 1)
    {
        cout << "\n Please enter the flight ID : ";
        cin >> input_id;
        flight_index = id_index(input_id);
        if (flight_index == -1)
            value = warning2();
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
        cout << "\n\n This flight hasn't any pasengers. \n";
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
                cout << "\n This ticket is invalid . ";
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
    for (int i = 0; i < count_flight; i++)
    {
        print_flight_info2(i);
    }
    if (count_flight == 0)
    {
        cout << "\n No flights are registered in the system . \n \n";
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
//----------------------------------------------------
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
            valu = recive_flight_id();

        if (valu == 0)
            valu = recive_flight_origin();

        if (valu == 0)
            valu = recive_flight_destination();

        if (valu == 0)
            valu = recive_flight_date();

        if (valu == 0)
            valu = recive_flight_time();

        if (valu == 0)
            valu = recive_flight_airline_name();

        if (valu == 0)
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
        {
            value = warning2();
        }
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
//---------------------------------------------------------
int user_dashoard(int active_user_index)
//اين تابع داشبورد كاربر عادي است
{
    int command;
    while (true)
    {
        print_user_dashoard();
        cin >> command;
        system("cls");
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
            cout << "\n !!! Warning : you are not allowed to select this !!!"
                 << "\n Please try again ";
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
//------------------------------------
void buy_ticket_menu(int active_user_index)
//این تابع منو خرید بلیط است
{
    int index;
    char origin[max_large_data_len], destination[max_large_data_len];
    cout << "\n Buy ticket : \n";

    recive_origine_and_destination(origin, destination);

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
}
//------------------------------------
void recive_origine_and_destination(char origine[], char destination[])
//این تابع مبدا و مقصد را از کاربر دریافت میکند
{
    cin.get();
    cout << "\n Origin : ";
    gets(origine);
    cout << "\n Destinationn : ";
    gets(destination);
    system("cls");
}
//---------------------------------------------------------------------
bool ticket_list(char origin[], char destination[])
//اين تابع ليست بليط ها با مبدا و مقصد وارد شده را چاپ ميكند
{
    bool value = true;
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
        cout << "\n There are no flights .\n";
        value = false;
    }
    return value;
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
int buy_ticket(char origine[], char destination[])
//اين تابع براي خريد بليط توسط كاربر عادي است
//که از کاربر یک عدد دریافت میکند اگر برابر صفر بود کاربر را به داشبورد کاربر عادی باز میگیرد
//اگر نه برسی میکند که برابر شناسه هیچ یک از پرواز های انتخاب شده هست یا نه
{
    int value = 1, index;
    long long int command;
    while (value == 1)
    {
        cout << "\n Please enter the ticket ID you want to buy"
             << "\n If you want to return to user dashboard enter ( 0 ) "
             << "\n >> ";
        cin >> command;
        if (command == 0)
            return -1;

        index = check_input_ID(command, origine, destination);

        if (index == -1) //اگر شناسه وجود نداشت
            value = warning2();
        else
            return index;
    }
    return -1; //مقداری که توسط تابع هشدار باز گردانده شده 2 بوده است که از حلقه خارج شده
}
//--------------------------------------
int check_input_ID(long long int id, char origine[], char destination[])
// این تابع برسی میکند که عددی که به عنوان ورودی به آن داده شده شناسه کدام پرواز است و اندیس آن را باز میگرداند
//اگر آن شناسه در بین پرواز های انتخاب شده نبود -1 باز میگرداند
{
    for (int i = 0; i < count_flight; i++)
    {
        if (strcmp(flight[i].origin, origine) == 0)
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