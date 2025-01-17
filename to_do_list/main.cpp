#include "chrono.h"
#include "task_manager.h"
#include <iostream>

// #include <stdio.h>
// #include "sqlite3.h"

#include <iostream>
#include <fstream>

#include <chrono>
#include <ctime>   


int main()
try
{
    using namespace Chrono_ns;
    using namespace TaskManager_ns;

    // SQLite
    // char* err_msg;
    // std::string command = "CREATE TABLE IF NOT EXISTS TASKS("
    //                       "START_MIN        INT        NOT NULL"
    //                       "START_HOUR        INT        NOT NULL"
    //                       "START_DAY        INT        NOT NULL"
    //                       "START_MONTH        INT        NOT NULL"
    //                       "START_YEAR       INT        NOT NULL"
    //                       "END_MIN        INT        NOT NULL"
    //                       "END_HOUR        INT        NOT NULL"
    //                       "END_DAY        INT        NOT NULL"
    //                       "END_MONTH        INT        NOT NULL"
    //                       "END_YEAR       INT        NOT NULL"
    //                       "NAME           TEXT    NOT NULL, "
    //                       "TEXT          TEXT     NOT NULL);";
    
    // sqlite3 *db;    // указатель на базу данных
    
    // int result  = sqlite3_open("database.db", &db);// открываем подключение к базе данных

    // if(result != SQLITE_OK) 
    // {
    //     std::cout << "Database error: " << sqlite3_errmsg(db) << std::endl;
    //     sqlite3_close(db);
    //     return -1;
    // }
    
    // sqlite3_exec(db,command.c_str(), 0, 0, &err_msg);
    // if(result != SQLITE_OK) 
    // {
    //     std::cout << "Database error: " << err_msg << std::endl;
    //     sqlite3_free(err_msg); //очищаем память, выделенную под err_msg 
    //     sqlite3_close(db);
    //     return -1;
    // }
    // // закрываем подключение
    // sqlite3_close(db);



    // Month m = Month::oct;
    // std::cout << int(m) << std::endl;
    // ++m;
    // std::cout << int(m) << std::endl;
    // ++m;
    // std::cout << int(m) << std::endl;
    // ++m;
    // std::cout << int(m) << std::endl;
    // ++m;
    // std::cout << int(m) << std::endl;
    // --m;
    // std::cout << int(m) << std::endl;
    // --m;
    // std::cout << int(m) << std::endl;
    // --m;
    // std::cout << int(m) << std::endl;
    // --m;
    // std::cout << int(m) << std::endl;

    // Date d1 (1,Month::jan,2033);
    // Date d2 = d1;
    // Date d0 {1,Month::feb,2033};

    // std::cout << d1.day() << std::endl;
    // std::cout << int(d1.month()) << std::endl;
    // std::cout << d1.year() << std::endl;

    // std::cout << d2.day() << std::endl;
    // std::cout << int(d2.month()) << std::endl;
    // std::cout << d2.year() << std::endl;

    // std::cout << (d2 == d1) << std::endl;
    // std::cout << (d2 != d1) << std::endl;    

    // std::cout << (d2 == d0) << std::endl;
    // std::cout << (d2 != d0) << std::endl;


    // std::cout << is_date(1,Month::jan,2033) << std::endl;
    // Date d3;
    // std::cin >> 



// Period tests
    //Period t1(16,10,Date(1,Month::oct,2023), 19,40, Date(2,Month::oct,2023));
    // Period t2(15,30,Date(3,Month::apr,2024), 17,20, Date(5,Month::mar,2021));
    // Period t3(15,30,Date(3,Month::apr,2024), 17,20,Date(3,Month::may,2024));
    // Period t4(15,30,Date(3,Month::apr,2024), 17,20, Date(5,Month::mar,2021));

    // std::cout << (t2 == t1) << std::endl;
    // std::cout << (t2 != t1) << std::endl;

    // std::cout << (t3 == t1) << std::endl;
    // std::cout << (t3 != t1) << std::endl;

    // std::cout << (t4 == t1) << std::endl;
    // std::cout << (t4 != t1) << std::endl;

    // std::cout << t1.start_hour() << std::endl;
    // std::cout << t1.start_min() << std::endl;
    // std::cout << t1.end_hour() << std::endl;
    // std::cout << t1.end_min() << std::endl;
    // std::cout << t1.start_date() << std::endl;
    // std::cout << t1.end_date() << std::endl;
    
// корректность периода
    // std::cout << is_period(16,10,Date(3,Month::apr,2024), 19,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(3,Month::apr,2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(18,10,Date(3,Month::apr,2024), 17,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(18,10,Date(3,Month::apr,2024), 18,00, Date(3,Month::apr,2024)) << std::endl;

    // //std::cout << t3 << std::endl;
    // std::cout << "\n";

    // std::cout << is_period(16,10,Date(3,Month::apr,2024), 19,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(16,10,Date(4,Month::apr,2024), 19,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(16,10,Date(3,Month::jul,2024), 19,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(16,10,Date(3,Month::apr,2025), 19,40, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(16,10,Date(5,Month::dec,2022), 19,40, Date(3,Month::apr,2024)) << std::endl;

    // std::cout << "\n";

    // std::cout << is_period(19,10,Date(4,Month::apr,2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(3,Month::apr,2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(3,Month::apr,2025), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(5,Month::mar,2022), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(3,Month::mar,2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(3,Month::apr,-2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(1,Month::apr,2024), 19,10, Date(3,Month::apr,2024)) << std::endl;
    // std::cout << is_period(19,10,Date(10,Month::nov,2018), 19,10, Date(3,Month::apr,2024)) << std::endl;
 

// Тест сравнения дат

    // Date d1 {10,Month::feb, 2023};
    // Date d2 {10,Month::feb, 2022};
    // Date d3 {10,Month::feb, 2024};
    // Date d4 {10,Month::jan, 2023};
    // Date d5 {10,Month::mar, 2023};
    // Date d6 {8,Month::feb, 2023};
    // Date d7 {15,Month::feb, 2023};
    // Date d8 {10,Month::feb, 2023};

    // Date d9 {10,Month::apr, 2022};
    // Date d10 {10,Month::jan, 2025};
    // Date d11 {17,Month::apr, 2022};
    // Date d12 {19,Month::feb, 2022};
    // Date d13 {5,Month::jan, 2026};

    // std::cout << (d1 > d2) << std::endl; // false
    // std::cout << (d1 > d3) << std::endl;// true
    // std::cout << (d1 > d4) << std::endl;// false
    // std::cout << (d1 > d5) << std::endl;// true
    // std::cout << (d1 > d6) << std::endl;// false
    // std::cout << (d1 > d7) << std::endl;// true
    // std::cout << (d1 > d8) << std::endl;// false
    // std::cout << (d1 > d9) << std::endl;// false
    // std::cout << (d1 > d10) << std::endl;// true
    // std::cout << (d1 > d11) << std::endl;// false
    // std::cout << (d1 > d12) << std::endl;// false
    // std::cout << (d1 > d13) << std::endl;// true

//test days_in_month()
    //std::cout << days_in_month(2024,Month::apr) << std::endl;


    // TaskManager tests
    // TaskManager tm {};
    // Period p(15,30,Date(12,Month::aug,2024),17,20,Date(12,Month::aug,2025));
    // tm.add_task(Task("Name", "Text", p));
    // std::cout << tm.tasks.size() << std::endl;


// Getting time experiments
    // auto start = std::chrono::system_clock::now();
    // // Some computation here
    // auto end = std::chrono::system_clock::now();
 
    // std::chrono::duration<double> elapsed_seconds = end-start;
    // std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    // std::cout << "finished computation at " << std::ctime(&end_time)
    //           << "elapsed time: " << elapsed_seconds.count() << "s"
    //           << std::endl;

    // auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); 
    // std::string time = ctime(&timenow);
    // //std::string time = struct tm * localtime
    // std::cout << timenow << std::endl;

    // system("date");

    // time_t mytime = time(NULL);
    // struct tm *now = localtime(&mytime);
    // std::cout << now->tm_mday << ' ' << 1 + now->tm_mon << ' ' << 1900 + now->tm_year << ' ' << std::endl;
    // std::cout << now->tm_wday << std::endl;

    // std::cout << today() << std::endl;
    // std::cout << monday_date() << std::endl;

// TASK_MANAGER_2
    //int status = remove("tasks.txt");
    TaskManager tm{};
    Period p1{15,30,Date(3,Month::apr,2024), 17,20,Date(3,Month::may,2024)};
    Task task1{"Task 1", "Matvey pozhal 60", p1};
    tm.add_task(task1);
    Period p2{9,30,Date(7,Month::sep,2022), 17,19,Date(3,Month::feb,2024)};
    Task task2{"Task2 how amazing", "Velosiped zimoy eto kruto", p2};
    tm.add_task(task2);
    Period p3{7,50,Date(8,Month::aug,2022), 9,47,Date(8,Month::aug,2022)};
    Task task3{"Task3", "Text3", p3};
    tm.add_task(task3);
    Period p4{8,20,Date(6,Month::aug,2022), 12,16,Date(8,Month::aug,2022)};
    Task task4{"Task 4", "Text4", p4};
    tm.add_task(task4);
    Period p5{23,00,Date(7,Month::aug,2022), 23,47,Date(9,Month::aug,2022)};
    Task task5{"Task5", "Text5", p5};
    tm.add_task(task5);
    std::vector<Task> tasks_list = tm.get_tasks();
    // tm.delete_task();
    // tm.delete_task(tasks_list[0]);
    //tm.delete_task(tasks_list[7]);


    Period p6{9,10,Date(3,Month::apr,2024), 22,13,Date(3,Month::may,2024)};
    //tm.delete_task(tm.get_tasks()[6]);
    // tm.add_task(Task("Task1v2","Updated task1", p6)); // будет ПРОБЛЕМА, ЕСЛИ в тексте задачи или имени ЕСТЬ ПРОБЕЛ
    //tm.delete_task(task4);
    // tm.update_task(tm.get_tasks()[1], Task("CCc v2 go","Updated6 task1", p6));
    // tm.update_task(tm.get_tasks()[8], Task("Ddd v2 go","Updated7 task1", p6));

    std::cout << "all tasks\n";
    for(Task t : tm.get_tasks())
    {
        //std::cout << t.name << std::endl;
        std::cout << t << std::endl;
    }

    // std::cout << "day tasks\n";
    // std::vector<Task> day_tasks = tm.get_tasks(Date(2,Month::oct,2023));
    // std::cout << day_tasks.size() << std::endl;
    // for(Task t : day_tasks)
    // {
    //     std::cout << t << std::endl;
    // }


    //tm.delete_task(task1);
    //tasks_list = tm.get_tasks();
    //std::cout << tasks_list[12].get_id() << std::endl;
    //std::vector<Task> tasks_to_del = std::vector<Task> (tasks_list.begin(), tasks_list.end()-5);

    // for(int i = 0; i < (tasks_list.size()-3); ++i)
    // {
    //     std::cout << tasks_list[i].get_id() << std::endl;
    //     tm.delete_task(tasks_list[i]);
    //     //tm.delete_task(i);
    // }
    
    // std::cout << "id: " << task1.get_id() << std::endl;
    // tm.delete_task(task1);

    // tasks_list = tm.get_tasks();

    // for(Task t : tasks_list)
    //     std::cout << t << std::endl;


    // std::ofstream out("tasks.txt", std::ios::app);
    // std::ifstream in("tasks.txt");
    // std::string line;
    // std::string search = "replace";
    // std::string replace = "success";
    // while(std::getline(in,line)){
    //     if(line == search){
    //         std::cout << "1\n";
    //         out << replace;
    //     }
    //     else {
    //         out << line;
    //     }
    // }

//2

    // size_t len = search.length();
    // while (getline(in, line))
    // {
    //     while (true)
    //     {
    //         size_t pos = line.find(search);
    //         //std::cout << pos << std::endl;
    //         if (pos != std::string::npos)
    //             line.replace(pos, len, replace);
    //         else 
    //             break;
    //     }

    //     out << line << '\n';
    // }


    // while (getline(in, line))
    // {
    //     line.replace(2, 1, "Hih");


    //     out << line << '\n';
    // }

// Date prefix increment
    // Date d1 {3, Month::jul, 2024};
    // std::cout << d1 << std::endl;
    // for(int j = 0; j < 370; ++j)
    //     std::cout << ++d1 << std::endl;

    // std::vector dates = get_week_dates();
    // for(Date d : dates)
    //     std::cout << d << std::endl;

    return 0;
}
catch(std::exception& e){
    std::cerr << e.what() << std::endl;
    return 1;
}
catch(...){
    std::cerr << "Something went wrong..." << std::endl;
    return 2;
}