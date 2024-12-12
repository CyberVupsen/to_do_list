#include "task_manager.h"
#include "chrono.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <sstream>

namespace TaskManager_ns
{
    static unsigned long long counter {0};

    void download_counter()
    {
        if(counter == 0)
        {
            std::ifstream in_id("id_counter.txt");
            in_id.exceptions(in_id.exceptions() | std::ios_base::badbit);
            if(!in_id)
            {
                std::ofstream out_id("id_counter.txt");
            }
                
            in_id.open("id_counter.txt");
            in_id.clear();

            if(!in_id.is_open())
                throw std::runtime_error("Can't open file with ids");

            in_id >> counter;
            in_id.close();
        }
    }

// Task
    Task::Task(std::string task_name, std::string task_text, Chrono_ns::Period period)
            : name {task_name}, text {task_text}, period {period}
    {
        download_counter();
        
        ++counter;
        id = counter;

        std::ofstream out_id("id_counter.txt");
        out_id << counter;

        if(!out_id)
            throw std::runtime_error("Can't add amount of ids to file");
        out_id.close();
    }


    std::ostream& operator << (std::ostream& os, const Task& t)
    {
        return os << "Task name: " << t.name << "\nTask period: " << t.period << "\nTask text:\n" << t.text << std::endl;
    }

    bool operator == (const Task& t1, const Task& t2)
    {
        return t1.name == t2.name && t1.text == t2.text && t1.period == t2.period;
    }

    bool operator != (const Task& t1, const Task& t2)
    {
        return !(t1 == t2);
    }

// Task Manager
    TaskManager::TaskManager()
    {
        if(!in.is_open())
        {
            std::ofstream out("tasks.txt", std::ios_base::app);
            out.close();
        }
        std::ifstream in("tasks.txt");
        in.exceptions(in.exceptions() | std::ios_base::badbit);
        out.exceptions(out.exceptions() | std::ios_base::badbit);

        if(!in)
            throw std::runtime_error("Can't open file");

        download_tasks();
    }


    void TaskManager::download_tasks()
    {
        using namespace Chrono_ns;
        std::string line;

        in.open("tasks.txt");
        in.clear();
        in.seekg(0, std::ios::beg);

        if(!in.is_open())
            throw std::runtime_error("File isn't open");

        unsigned long long id;
        unsigned start_hour;
        unsigned start_min;
        unsigned start_day;
        unsigned start_month;
        unsigned start_year;
        unsigned end_hour;
        unsigned end_min;
        unsigned end_day;
        unsigned end_month;
        unsigned end_year;
        std::string task_name;
        std::string task_text;

        std::string whole_line;
        while (std::getline(in, whole_line)) {
            std::istringstream iss(whole_line);
            iss.seekg(0, std::ios::beg);
            iss >> id >> start_hour >> start_min >> start_day >> start_month >> start_year
                    >> end_hour >> end_min >> end_day >> end_month >> end_year;

            Date start_date {start_day, static_cast<Month>(start_month), start_year};
            Date end_date {end_day, static_cast<Month>(end_month), end_year};

            std::string name_line;
            task_name = "";
            std::getline(iss, task_name, ';');
            task_name.erase(task_name.begin());

            std::string text_line;
            task_text = "";
            while (iss >> text_line) {
                task_text += text_line + ' ';
            }
            task_text.pop_back();

            Period p {start_hour, start_min, start_date, end_hour, end_min, end_date};
            Task t {task_name, task_text, p};
            t.set_id(id);
            tasks.push_back(t);
            --counter;
        }
        std::ofstream out_id("id_counter.txt");
        out_id << counter;
        if(!out_id)
            throw std::runtime_error("Can't add amount of ids to file");
        out_id.close();

        if(in.eof())
        {
            in.close();
            return;
        }
        if(in.fail())
            throw std::runtime_error("Uncorrect data in file");
    }


    void TaskManager::add_task(Task task)
    {
        out.open("tasks.txt", std::ios::app);
        out.clear();
        out.seekp(0, std::ios::end);

        if(!out)
            throw std::runtime_error("Can't get access to file");
        if(!out.is_open())
            throw std::runtime_error("Can't open file");

        out << task.get_id() << ' ' << task.period.start_hour() << ' ' << task.period.start_min() << ' '
            << task.period.start_date().day() << ' ' << int(task.period.start_date().month()) << ' '
            << task.period.start_date().year() << ' '  << task.period.end_hour() << ' '
            << task.period.end_min() << ' ' << task.period.end_date().day() << ' '
            << int(task.period.end_date().month()) << ' ' << task.period.end_date().year() << ' '
            << task.name << ';' << task.text << std::endl;

        tasks.push_back(task);
        out.close();
    }

    void TaskManager::delete_task(Task task)
    {
        using namespace Chrono_ns;

        for (size_t i {0}; i < tasks.size(); ++i)
        {
            if(tasks[i].get_id() == task.get_id()) {
                tasks.erase(tasks.begin() + i);
                break;
            }
        }

        out.open("tasks.txt");
        out.clear();
        out.seekp(0, std::ios::beg);
        for (Task t : tasks)
        {
            std::string task_text_1 = std::to_string(t.get_id()) + ' ' +
                std::to_string(t.period.start_hour()) + ' ' +
                std::to_string(t.period.start_min()) + ' ' +
                std::to_string(t.period.start_date().day()) + ' ' +
                std::to_string(int(t.period.start_date().month())) + ' ' +
                std::to_string(t.period.start_date().year()) + ' ' +
                std::to_string(t.period.end_hour()) + ' ' +
                std::to_string(t.period.end_min()) + ' ' +
                std::to_string(t.period.end_date().day()) + ' ' +
                std::to_string(int(t.period.end_date().month())) + ' ' +
                std::to_string(t.period.end_date().year()) + ' ' +
                t.name + ';' + t.text;
            out << task_text_1 << '\n';
        }
        if(!out)
            throw std::runtime_error("Buf_out failed on last line");
        out.close();
    }

    void TaskManager::update_task(Task old_task, Task new_task)
    {
        delete_task(old_task);
        add_task(new_task);
    }

    std::vector<Task> TaskManager::get_tasks() const
    {
        return tasks;
    }

    std::vector<Task> TaskManager::get_tasks(Chrono_ns::Date date) const
    {
        std::vector<Task> day_tasks;
        for(Task task : tasks)
        {
            if(date.in_period(task.period))
            {
                day_tasks.push_back(task);
            }
        }
        return day_tasks;
    }
}
